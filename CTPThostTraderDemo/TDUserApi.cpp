#include <assert.h>
#include <chrono>

#include "TDUserApi.h"

TDUserApi::~TDUserApi()
{
	if (!checkAPIInitialized()) {
		return;
	}

	pApi->Release();
	pApi = NULL;
}

void TDUserApi::setFlag(bool* flag, bool value)
{
	std::lock_guard<std::mutex> locker(g_lock);

	*flag = value;

	g_cond.notify_one();
}

bool TDUserApi::checkRspError(const char* msgTemplate, CThostFtdcRspInfoField* rspInfo)
{
	if (NULL != rspInfo && 0 != rspInfo->ErrorID) {
		printf(msgTemplate, rspInfo->ErrorID, rspInfo->ErrorMsg);

		return true;
	}

	return false;
}

void TDUserApi::waitUntil(bool(TDUserApi::* checkFn)(), bool expect, int timeout)
{
	std::unique_lock<std::mutex> locker(g_lock);
	bool expired = false;

	while ((this->*checkFn)() != expect && !expired) {
		if (timeout > 0) {
			g_cond.wait_for(locker, std::chrono::milliseconds(timeout));
			timeout = true;
		}
		else {
			g_cond.wait(locker);
		}
	}
}

std::vector<CThostFtdcInstrumentField*> TDUserApi::GetInstruments(std::string ExchangeID, std::string ProductID, std::string InstrumentID)
{
	return instrumentCache->GetInstrumentList(ExchangeID, ProductID, InstrumentID);
}

void TDUserApi::OnFrontConnected()
{
	printf("Front connected.\n");

	setFlag(&connected, true);
}

void TDUserApi::OnFrontDisconnected(int nReason)
{
	printf("Front disconnected: %d\n", nReason);

	setFlag(&connected, false);
}

void TDUserApi::OnHeartBeatWarning(int nTimeLapse)
{
	printf("HeartBeat warning: %d\n", nTimeLapse);
}

void TDUserApi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Authentication failed[%d]: %s\n", pRspInfo)) {
		pApi->Release();

		return;
	}

	if (pRspAuthenticateField != NULL) {
		printf("Authentication succeed: %s, %s, %s\n", pRspAuthenticateField->BrokerID, pRspAuthenticateField->UserID, pRspAuthenticateField->AppID);
	}

	setFlag(&authenticated, true);
}

void TDUserApi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Login failed[%d]: %s\n", pRspInfo)) {
		pApi->Release();

		return;
	}

	if (pRspUserLogin != NULL) {
		memcpy(&User, pRspUserLogin, sizeof(CThostFtdcRspUserLoginField));

		maxOrderRef = atoi(pRspUserLogin->MaxOrderRef);
		
		printf(
			"Login[%s.%s] succeed on front%d@0x%X: %s %s\n", 
			pRspUserLogin->BrokerID, pRspUserLogin->UserID,
			pRspUserLogin->FrontID, pRspUserLogin->SessionID,
			pRspUserLogin->TradingDay, pRspUserLogin->LoginTime
		);

		setFlag(&login, true);
	}
}

void TDUserApi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	checkRspError("Request order insert failed[%d]: %s\n", pRspInfo);

	if (NULL != pInputOrder) {
		printf(
			"Input order is:\n"
			"\tOrderRef: %s\n"
			"\tInstrumentID: %s\n"
			"\tDirection: %s\n"
			"\tPrice: %.2lf\n"
			"\tVolume: %d\n",
			pInputOrder->OrderRef, pInputOrder->InstrumentID,
			THOST_FTDC_D_Buy == pInputOrder->Direction ? "Buy" : "Sell",
			pInputOrder->LimitPrice, pInputOrder->VolumeTotalOriginal
		);
	}

	setFlag(&responsed, true);
}

void TDUserApi::QueryMarginRateAll(const char* brokerID, const char* investorID)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	queryAllMarginRate = true;

	queryCache->CheckAndWait();
	instrumentCache->QueryNextMarginRate(brokerID, investorID);
}

void TDUserApi::QueryCommRateAll(const char* brokerID, const char* investorID)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	queryAllCommRate = true;
	
	queryCache->CheckAndWait();
	instrumentCache->QueryNextCommRate(brokerID, investorID);
}

void TDUserApi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	checkRspError("Request order action failed[%d]: %s\n", pRspInfo);

	setFlag(&responsed, true);
}

void TDUserApi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query order failed[%d]: %s\n", pRspInfo)) {
		setFlag(&qryFinished, true);

		return;
	}

	if (NULL != pOrder) {
		CThostFtdcOrderField* ord = new(CThostFtdcOrderField);
		memcpy(ord, pOrder, sizeof(CThostFtdcOrderField));

		orderDictByRef.insert_or_assign(pOrder->OrderRef, ord);
		orderDictBySysID.insert_or_assign(pOrder->OrderSysID, ord);

		printf(
			"Symbol[%s.%s] %s %s: Direction[%c] Offset[%s] %d@%.2f\n",
			pOrder->ExchangeID, pOrder->InstrumentID, pOrder->OrderRef, pOrder->OrderSysID,
			pOrder->Direction, pOrder->CombOffsetFlag, 
			pOrder->VolumeTotalOriginal, pOrder->LimitPrice
		);
	}

	if (bIsLast) {
		printf("Query order finished.\n");

		queryCache->FinishQuery(nRequestID);
	}
}

void TDUserApi::OnRspQryInvestorPosition(
	CThostFtdcInvestorPositionField* pInvestorPosition, 
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query investor's position failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pInvestorPosition) {
		std::string symbol;
		symbol.append(pInvestorPosition->ExchangeID);
		symbol.append(".");
		symbol.append(pInvestorPosition->InstrumentID);

		CThostFtdcInvestorPositionField* pos = new(CThostFtdcInvestorPositionField);
		memcpy(pos, pInvestorPosition, sizeof(CThostFtdcInvestorPositionField));

		positionCache.insert_or_assign(symbol, pos);

		printf(
			"Symbol[%s.%s]: Direction[%c] YdPos[%d] Pos[%d]\n", 
			pInvestorPosition->ExchangeID, pInvestorPosition->InstrumentID,
			pInvestorPosition->PosiDirection, pInvestorPosition->YdPosition, pInvestorPosition->Position
		);
	}

	if (bIsLast) {
		printf("Query investor's position finished.\n");

		queryCache->FinishQuery(nRequestID);
	}
}

void TDUserApi::OnRspQryInstrumentMarginRate(
	CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, 
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query instrument margin rate failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pInstrumentMarginRate) {
		printf("Instrument[%s.%s] margin rate: "
			"LongRatioByMoney[%.2lf] LongRatioByVolume[%.2lf] "
			"ShortRatioByMoney[%.2lf] ShortRatioByVolume[%.2lf]\n",
			pInstrumentMarginRate->ExchangeID, pInstrumentMarginRate->InstrumentID,
			pInstrumentMarginRate->LongMarginRatioByMoney, pInstrumentMarginRate->LongMarginRatioByVolume, 
			pInstrumentMarginRate->ShortMarginRatioByMoney, pInstrumentMarginRate->ShortMarginRatioByVolume
		);

		queryCache->FinishQuery(nRequestID);

		instrumentCache->InsertMarginRate(pInstrumentMarginRate);

		if (queryAllMarginRate) {
			instrumentCache->QueryNextMarginRate(User.BrokerID, User.UserID);
		}
	}
}

void TDUserApi::OnRspQryInstrumentCommissionRate(
	CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, 
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query instrument comm rate failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pInstrumentCommissionRate) {
		printf("Instrument[%s.%s] comm rate: "
			"OpenRatioByMoney[%.2lf] OpenRatioByVolume[%.2lf] "
			"CloseRatioByMoney[%.2lf] CloseRatioByVolume[%.2lf] "
			"CloseTodayRatioByMoney[%.2lf] CloseTodayRatioByVolume[%.2lf]\n",
			pInstrumentCommissionRate->ExchangeID, pInstrumentCommissionRate->InstrumentID,
			pInstrumentCommissionRate->OpenRatioByMoney, pInstrumentCommissionRate->OpenRatioByVolume,
			pInstrumentCommissionRate->CloseRatioByMoney, pInstrumentCommissionRate->CloseRatioByVolume,
			pInstrumentCommissionRate->CloseTodayRatioByMoney, pInstrumentCommissionRate->CloseTodayRatioByVolume
		);

		queryCache->FinishQuery(nRequestID);

		instrumentCache->InsertCommRate(pInstrumentCommissionRate);

		if (queryAllCommRate) {
			instrumentCache->QueryNextCommRate(User.BrokerID, User.UserID);
		}
	}
}

void TDUserApi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query instrument failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pInstrument) { 
		CThostFtdcInstrumentField* ins = new(CThostFtdcInstrumentField);
		memcpy(ins, pInstrument, sizeof(CThostFtdcInstrumentField));
		instrumentCache->InsertInstrument(ins);
	}

	if (bIsLast) {
		printf("Query instrument info finished.\n");

		queryCache->FinishQuery(nRequestID);
	}
}

void TDUserApi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	fprintf(stderr, "Request[%d] responsed Error[%d]: %s\n", nRequestID, pRspInfo->ErrorID, pRspInfo->ErrorMsg);

	switch (pRspInfo->ErrorID) {
	case 90:
		SLEEP(100);
		queryCache->RedoQuery(nRequestID);
	}
}

void TDUserApi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
	printf(
		"%s.%s @ %s %s: "
		"OrderRef[%s], Status[%c], Direction[%s], Price[%.2lf], Volume[%d] Traded[%d] "
		"Updated @ %s\n",
		pOrder->ExchangeID, pOrder->InstrumentID, pOrder->InsertDate, pOrder->InsertTime,  
		pOrder->OrderRef, pOrder->OrderStatus, 
		THOST_FTDC_D_Buy == pOrder->Direction ? "Buy" : "Sell",
		pOrder->LimitPrice, pOrder->VolumeTotalOriginal, pOrder->VolumeTraded,
		pOrder->UpdateTime
	);
}

void TDUserApi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
	printf("Order rejected: %s\n", pRspInfo->ErrorMsg);
}

void TDUserApi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
	printf(
		"%s.%s Enter status[%c]: %s\n", 
		pInstrumentStatus->ExchangeID, pInstrumentStatus->InstrumentID, 
		pInstrumentStatus->InstrumentStatus, pInstrumentStatus->EnterTime
	);
}

void TDUserApi::CreateFtdcTraderApi(const char* pszFlowPath)
{
	assert(!checkAPIInitialized());

	MKDIR(pszFlowPath);

	pApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
	
	if (pApi == NULL) { return; }

	pApi->RegisterSpi(this);
}

const char* TDUserApi::GetApiVersion()
{
	return CThostFtdcTraderApi::GetApiVersion();
}

void TDUserApi::Release()
{
	assert(checkAPIInitialized());

	pApi->Release();

	pApi = NULL;
}

void TDUserApi::Init()
{
	assert(checkAPIInitialized());

	pApi->Init();
}

int TDUserApi::Join()
{
	assert(checkAPIInitialized());
	
	return pApi->Join();
}

const char* TDUserApi::GetTradingDay()
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return pApi->GetTradingDay();
}

void TDUserApi::RegisterFront(char* pszFrontAddress)
{
	assert(checkAPIInitialized());

	return pApi->RegisterFront(pszFrontAddress);
}

void TDUserApi::RegisterNameServer(char* pszNsAddress)
{
	assert(checkAPIInitialized());

	pApi->RegisterNameServer(pszNsAddress);
}

void TDUserApi::RegisterFensUserInfo(CThostFtdcFensUserInfoField* pFensUserInfo)
{
	assert(checkAPIInitialized());

	pApi->RegisterFensUserInfo(pFensUserInfo);
}

void TDUserApi::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	assert(checkAPIInitialized());

	pApi->SubscribePrivateTopic(nResumeType);
}

void TDUserApi::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	assert(checkAPIInitialized());

	pApi->SubscribePublicTopic(nResumeType);
}

int TDUserApi::ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField)
{
	waitUntil(&TDUserApi::checkConnected, true);

	authenticated = false;
	
	return pApi->ReqAuthenticate(pReqAuthenticateField, ++nRequestID);
}

int TDUserApi::RegisterUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
	waitUntil(&TDUserApi::checkAuthenticated, true);
	
	return pApi->RegisterUserSystemInfo(pUserSystemInfo);
}

int TDUserApi::SubmitUserSystemInfo(CThostFtdcUserSystemInfoField* pUserSystemInfo)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return pApi->SubmitUserSystemInfo(pUserSystemInfo);
}

int TDUserApi::ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField)
{
	waitUntil(&TDUserApi::checkAuthenticated, true);

	// waitUntil(&TDUserApi::checkConnected, true);

	login = false;

	return pApi->ReqUserLogin(pReqUserLoginField, ++nRequestID);
}

int TDUserApi::ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqUserLogout(pUserLogout, ++nRequestID);
}

int TDUserApi::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqUserPasswordUpdate(pUserPasswordUpdate, ++nRequestID);
}

int TDUserApi::ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, ++nRequestID);
}

int TDUserApi::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return 0;
}

int TDUserApi::ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder)
{
	/*waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);*/

	/*TThostFtdcOrderRefType orderRef = { 0 };
	sprintf(orderRef, "%d", ++maxOrderRef);
	strcpy_s(pInputOrder->OrderRef, orderRef);*/
	setFlag(&responsed, false);

	return pApi->ReqOrderInsert(pInputOrder, ++nRequestID);
}

int TDUserApi::ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction)
{
	/*waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);*/

	setFlag(&responsed, false);
	
	return pApi->ReqOrderAction(pInputOrderAction, ++nRequestID);
}

int TDUserApi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return queryCache->StartQuery(QueryFlag::QryOrder, pQryOrder);
}

int TDUserApi::ReqQryTrade(CThostFtdcQryTradeField* pQryTrade)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryTrade(pQryTrade, ++nRequestID);
}

int TDUserApi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return queryCache->StartQuery(QueryFlag::QryPosition, pQryInvestorPosition);
}

int TDUserApi::ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryTradingAccount(pQryTradingAccount, ++nRequestID);
}

int TDUserApi::ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryInvestor(pQryInvestor, ++nRequestID);
}

int TDUserApi::ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryTradingCode(pQryTradingCode, ++nRequestID);
}

int TDUserApi::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return queryCache->StartQuery(QueryFlag::QryMarginRate, pQryInstrumentMarginRate);
}

int TDUserApi::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return queryCache->StartQuery(QueryFlag::QryCommissionRate, pQryInstrumentCommissionRate);
}

int TDUserApi::ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryExchange(pQryExchange, ++nRequestID);
}

int TDUserApi::ReqQryProduct(CThostFtdcQryProductField* pQryProduct)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryProduct(pQryProduct, ++nRequestID);
}

int TDUserApi::ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return queryCache->StartQuery(QueryFlag::QryInstrument, pQryInstrument);
}

int TDUserApi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryDepthMarketData(pQryDepthMarketData, ++nRequestID);
}

int TDUserApi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQrySettlementInfo(pQrySettlementInfo, ++nRequestID);
}

int TDUserApi::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, ++nRequestID);
}

int TDUserApi::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, ++nRequestID);
}

int TDUserApi::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, ++nRequestID);
}

int TDUserApi::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, ++nRequestID);
}

int TDUserApi::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, ++nRequestID);
}

bool InstrumentCache::InsertInstrument(CThostFtdcInstrumentField* ins)
{
	if (NULL == ins) { return false; }

	instrumentDict.insert_or_assign(ins->InstrumentID, ins);
	instrumentList.push_back(ins);

	return true;
}

CThostFtdcInstrumentField* InstrumentCache::GetNextInstrument(int& idx)
{
	if (idx >= instrumentList.size()) {
		return NULL;
	}

	return instrumentList[idx++];
}

bool InstrumentCache::InsertMarginRate(CThostFtdcInstrumentMarginRateField* marginRate)
{
	if (NULL == marginRate) {
		return false;
	}

	marginRateDict.insert_or_assign(marginRate->InstrumentID, marginRate);

	return true;
}

bool InstrumentCache::InsertCommRate(CThostFtdcInstrumentCommissionRateField* commRate)
{
	if (NULL == commRate) {
		return false;
	}

	commRateDict.insert_or_assign(commRate->InstrumentID, commRate);

	return true;
}

void InstrumentCache::QueryNextMarginRate(const char* brokerID, const char* investorID)
{
	assert(api != NULL);

	CThostFtdcInstrumentField* ins = GetNextInstrument(marginRateQryIdx);

	while (NULL != ins) {
		// 目前仅支持期货合约的保证金查询
		// TODO： 支持其他类型的合约保证金查询
		if (marginRateDict.find(ins->InstrumentID) == marginRateDict.end() &&
			THOST_FTDC_APC_FutureSingle == ins->ProductClass) {
			printf("Quering instrument[%s] margin rate.\n", ins->InstrumentID);

			CThostFtdcQryInstrumentMarginRateField qryMargin = { 0 };
			strncpy(qryMargin.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
			strncpy(qryMargin.InvestorID, investorID, sizeof(TThostFtdcInvestorIDType) - 1);
			strncpy(qryMargin.InstrumentID, ins->InstrumentID, sizeof(TThostFtdcInstrumentIDType) - 1);
			qryMargin.HedgeFlag = THOST_FTDC_HF_Speculation;

			api->ReqQryInstrumentMarginRate(&qryMargin);

			return;
		}

		ins = GetNextInstrument(marginRateQryIdx);
	}

	api->queryAllMarginRate = false;
	marginRateQryIdx = 0;

	printf("Quering instrument margin rate finisehd.\n");
}

void InstrumentCache::QueryNextCommRate(const char* brokerID, const char* investorID)
{
	assert(api != NULL);

	CThostFtdcInstrumentField* ins = GetNextInstrument(commRateQryIdx);

	while (NULL != ins) {
		// 目前仅支持期货合约的手续费查询
		// TODO： 支持其他类型的合约手续费查询
		if (commRateDict.find(ins->InstrumentID) == commRateDict.end() &&
			THOST_FTDC_APC_FutureSingle == ins->ProductClass) {
			printf("Quering instrument[%s] comm rate.\n", ins->InstrumentID);

			CThostFtdcQryInstrumentCommissionRateField qryComm = { 0 };
			strncpy(qryComm.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
			strncpy(qryComm.InvestorID, investorID, sizeof(TThostFtdcInvestorIDType) - 1);
			strncpy(qryComm.InstrumentID, ins->InstrumentID, sizeof(TThostFtdcInstrumentIDType) - 1);

			api->ReqQryInstrumentCommissionRate(&qryComm);

			return;
		}

		ins = GetNextInstrument(commRateQryIdx);
	}

	api->queryAllCommRate = false;
	commRateQryIdx = 0;

	printf("Quering instrument comm rate finished.\n");
}

std::vector<CThostFtdcInstrumentField*> InstrumentCache::GetInstrumentList(std::string ExchangeID, std::string ProductID, std::string InstrumentID)
{
	std::vector<CThostFtdcInstrumentField*> result;

	if (InstrumentID != "") {
		auto ins = instrumentDict.at(InstrumentID);
		result.push_back(ins);

		return result;
	}
	
	for (auto ins : instrumentList) {
		if ((ExchangeID != "" && ins->ExchangeID != ExchangeID) ||
			(ProductID != "" && ins->ProductID != ProductID)) {
			continue;
		}

		result.push_back(ins);
	}

	return result;
}

void QueryCache::RedoQuery(int requestID)
{
	if (qryCache.find(requestID) == qryCache.end()) {
		fprintf(stderr, "Request[%d] not in query cache.\n", requestID);
		return;
	}
	
	flag = QueryFlag::QryFinished;
	auto qry = qryCache.at(requestID);
	qryCount -= int(qryCache.erase(requestID));
	if (qryCount < 0) {
		qryCount = 0;
	}
	
	StartQuery(qry->flag, qry->qry, false);
	delete qry;
}

int QueryCache::StartQuery(QueryFlag flag, void* qry, bool copyQry)
{
	assert(api != NULL);

	CheckAndWait();

	lastQryTS = get_ms_ts();
	this->flag = flag;
	int requestID = ++api->nRequestID;

	int rtn = 0;
	Query* query = new(Query);
	query->flag = flag;

	while (true) {
		switch (flag)
		{
		case QueryFlag::QryFinished:
			FinishQuery(requestID);
			return 0;
		case QueryFlag::QryAccount:
			rtn = api->pApi->ReqQryTradingAccount((CThostFtdcQryTradingAccountField*)qry, requestID);
			
			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryTradingAccountField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryTradingAccountField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryOrder:
			rtn = api->pApi->ReqQryOrder((CThostFtdcQryOrderField*)qry, requestID);
			
			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryOrderField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryOrderField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryPosition:
			rtn = api->pApi->ReqQryInvestorPosition((CThostFtdcQryInvestorPositionField*)qry, requestID);
			
			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInvestorPositionField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInvestorPositionField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryExecution:
			break;
		case QueryFlag::QryInstrument:
			rtn = api->pApi->ReqQryInstrument((CThostFtdcQryInstrumentField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryMarginRate:
			rtn = api->pApi->ReqQryInstrumentMarginRate((CThostFtdcQryInstrumentMarginRateField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentMarginRateField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentMarginRateField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryCommissionRate:
			rtn = api->pApi->ReqQryInstrumentCommissionRate((CThostFtdcQryInstrumentCommissionRateField*)qry, requestID);
			
			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentCommissionRateField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentCommissionRateField));
			}
			else {
				query->qry = qry;
			}
			
			break;
		default:
			fprintf(stderr, "Invalid query flag: %x\n", flag);
			return 255;
		}

		if (0 == rtn) {
			break;
		}
		else {
			SLEEP(100);
		}
	}

	qryCache.insert_or_assign(requestID, query);
	qryCount++;

	return rtn;
}

void QueryCache::FinishQuery(int requestID) {
	if (qryCache.find(requestID) == qryCache.end()) {
		return;
	}

	auto qry = qryCache.at(requestID);
	free(qry->qry);
	delete qry;

	qryCount -= int(qryCache.erase(requestID));
	if (qryCount < 0) {
		qryCount = 0;
	}
	
	flag = QueryFlag::QryFinished;
	g_cond.notify_one();
}

bool QueryCache::CheckStatus()
{
	if (flag != QueryFlag::QryFinished) {
		return false;
	}

	long long ms = get_ms_ts();
	if (ms - lastQryTS < 1000 && qryCount >= qryFreq) {
		return false;
	}

	return true;
}

void QueryCache::CheckAndWait() {
	std::unique_lock<std::mutex> locker(g_lock);

	while (!CheckStatus()) {
		g_cond.wait(locker);
	}
}

long long get_ms_ts()
{
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		);

	return ms.count();
}
