#include <assert.h>

#include "tools.h"
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

std::vector<CThostFtdcOrderField*> TDUserApi::GetOrders(std::string orderRef, std::string orderSysID)
{
	return orderCache->GetOrders(orderRef, orderSysID);
}

std::vector<CThostFtdcInvestorPositionField*> TDUserApi::GetPositions(std::string ExchangeID, std::string ProductID, std::string InstrumentID)
{
	return positionCache->GetPositions(ExchangeID, ProductID, InstrumentID);
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

		CThostFtdcSettlementInfoConfirmField confirm = { 0 };
		memcpy(confirm.BrokerID, User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
		memcpy(confirm.InvestorID, User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);

		ReqSettlementInfoConfirm(&confirm);
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

void TDUserApi::QueryMarginRateAll()
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	queryAllMarginRate = true;

	queryCache->CheckAndWait();
	instrumentCache->QueryNextMarginRate();
}

void TDUserApi::QueryCommRateAll()
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	queryAllCommRate = true;
	
	queryCache->CheckAndWait();
	instrumentCache->QueryNextCommRate();
}

void TDUserApi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	checkRspError("Request order action failed[%d]: %s\n", pRspInfo);

	if (NULL != pInputOrderAction) {
		printf(
			"Action order is:\n"
			"\tOrderRef: %s\n"
			"\tActionRef: %d\n"
			"\tInstrumentID: %s\n"
			"\tPrice: %.2lf\n"
			"\tVolumeChange: %d\n"
			"\tActionFlag: %c\n",
			pInputOrderAction->OrderRef, pInputOrderAction->OrderActionRef, 
			pInputOrderAction->InstrumentID, pInputOrderAction->LimitPrice, 
			pInputOrderAction->VolumeChange, pInputOrderAction->ActionFlag
		);
	}

	setFlag(&responsed, true);
}

void TDUserApi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Settlement info confirm failed[%d]: %s\n", pRspInfo)) {
		return;
	}

	if (NULL != pSettlementInfoConfirm) {
		printf("Settlement info confirmed on: %s %s\n", 
			pSettlementInfoConfirm->ConfirmDate, pSettlementInfoConfirm->ConfirmTime);
		setFlag(&settlementConfirmed, true);
	}
	else {
		printf("Settlement info not confirmed, querying settlement info.");

		CThostFtdcQrySettlementInfoField qry = { 0 };
		memcpy(qry.BrokerID, User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
		memcpy(qry.InvestorID, User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);
		memcpy(qry.TradingDay, GetTradingDay(), sizeof(TThostFtdcDateType) - 1);

		ReqQrySettlementInfo(&qry);
	}
}

void TDUserApi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query order failed[%d]: %s\n", pRspInfo)) {
		setFlag(&qryFinished, true);

		return;
	}

	if (NULL != pOrder) {
		orderCache->InsertOrAssignOrder(pOrder);
		
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

	if (NULL != pInvestorPosition && pInvestorPosition->Position > 0) {
		positionCache->InsertOrAssign(pInvestorPosition);

		/*printf(
			"Symbol[%s.%s]: Direction[%c] YdPos[%d] Pos[%d]\n", 
			pInvestorPosition->ExchangeID, pInvestorPosition->InstrumentID,
			pInvestorPosition->PosiDirection, pInvestorPosition->YdPosition, pInvestorPosition->Position
		);*/
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
	queryCache->FinishQuery(nRequestID);

	if (checkRspError("Query instrument margin rate failed[%d]: %s\n", pRspInfo)) {
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

		instrumentCache->InsertOrAssignMarginRate(pInstrumentMarginRate);

		if (queryAllMarginRate) {
			instrumentCache->QueryNextMarginRate();
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

		instrumentCache->InsertOrAssignCommRate(pInstrumentCommissionRate);

		queryCache->FinishQuery(nRequestID);

		if (queryAllCommRate) {
			instrumentCache->QueryNextCommRate();
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
		/*printf(
			"[%s.%s]: PriceTick[%.2lf] VolumeMultiple[%d]\n", 
			pInstrument->ExchangeID, pInstrument->InstrumentID, 
			pInstrument->PriceTick, pInstrument->VolumeMultiple
		);*/

		instrumentCache->InsertOrAssignInstrument(pInstrument);
	}

	if (bIsLast) {
		printf("Query instrument info finished.\n");

		queryCache->FinishQuery(nRequestID);

		instrumentCache->BuildInstrumentList();
	}
}

void TDUserApi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query depth market data failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pDepthMarketData) {
		instrumentCache->InsertOrAssignMarketData(pDepthMarketData);
	}

	if (bIsLast) {
		printf("Query depth market data finished.\n");

		queryCache->FinishQuery(nRequestID);
	}
}

void TDUserApi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{

	if (checkRspError("Query settlement info failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pSettlementInfo) {
		printf("Settlement info for %s.%s on %s\n",
			pSettlementInfo->BrokerID, pSettlementInfo->InvestorID, pSettlementInfo->TradingDay);

		printf("%s\n", pSettlementInfo->Content);
	}

	if (bIsLast) {
		queryCache->FinishQuery(nRequestID);
	}
}

void TDUserApi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query settlment confirm failed[%d]: %s\n", pRspInfo)) {
		queryCache->FinishQuery(nRequestID);

		return;
	}

	if (NULL != pSettlementInfoConfirm) {
		if (strlen(pSettlementInfoConfirm->ConfirmDate) > 0 && 
			strlen(pSettlementInfoConfirm->ConfirmTime) > 0) {
			printf("Settlement info already confirmed.\n");
			setFlag(&settlementConfirmed, true);
		}
		else {
			setFlag(&settlementConfirmed, false);
		}
	}

	if (bIsLast) {
		queryCache->FinishQuery(nRequestID);
	}
}

void TDUserApi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	fprintf(stderr, "Request[%d] responsed Error[%d]: %s\n", nRequestID, pRspInfo->ErrorID, pRspInfo->ErrorMsg);

	switch (pRspInfo->ErrorID) {
	case 90:
		SLEEP(500);
		queryCache->RedoQuery(nRequestID);
	}
}

void TDUserApi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
	orderCache->InsertOrAssignOrder(pOrder);

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

void TDUserApi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
	if (NULL == pTrade) {
		return;
	}
}

void TDUserApi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
	printf("Order insert rejected: %s\n", pRspInfo->ErrorMsg);
}

void TDUserApi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
	printf("Order action rejected: %s\n", pRspInfo->ErrorMsg);
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

int TDUserApi::ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	setFlag(&responsed, false);

	return pApi->ReqOrderInsert(pInputOrder, ++nRequestID);
}

int TDUserApi::ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	setFlag(&responsed, false);
	
	return pApi->ReqOrderAction(pInputOrderAction, ++nRequestID);
}

int TDUserApi::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	if (checkSettlementConfirmed()) {
		return 0;
	}

	printf("Send request to confirm settlement info.\n");

	return pApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, ++nRequestID);
}

int TDUserApi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return queryCache->StartQuery(QueryFlag::QryOrder, pQryOrder);
}

int TDUserApi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return queryCache->StartQuery(QueryFlag::QryPosition, pQryInvestorPosition);
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

int TDUserApi::ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	
	return queryCache->StartQuery(QueryFlag::QryInstrument, pQryInstrument);
}

int TDUserApi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return queryCache->StartQuery(QueryFlag::QryMarketData, pQryDepthMarketData);
}

int TDUserApi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	if (checkSettlementConfirmed()) {
		return 0;
	}

	printf("Send request to get settlement info.\n");

	return queryCache->StartQuery(QueryFlag::QrySettlementInfo, pQrySettlementInfo);
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

	return queryCache->StartQuery(QueryFlag::QrySettlementConfirm, pQrySettlementInfoConfirm);
}
