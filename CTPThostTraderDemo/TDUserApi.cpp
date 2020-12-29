#include <assert.h>
#include <chrono>
#include <string>

#include "TDUserApi.h"
#include "tools.h"

#define JOIN_REF(session, front, ref) (session) + "." + (front) + "." + (ref)

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
	}

	if (bIsLast) {
		setFlag(&settlementConfirmed, true);
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

		instrumentCache->InsertOrAssignMarginRate(pInstrumentMarginRate);

		queryCache->FinishQuery(nRequestID);

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
		CThostFtdcSettlementInfoConfirmField confirm = { 0 };
		memcpy(confirm.BrokerID, User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
		memcpy(confirm.InvestorID, User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);

		ReqSettlementInfoConfirm(&confirm);

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

		CThostFtdcQrySettlementInfoField qry = { 0 };
		memcpy(qry.BrokerID, User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
		memcpy(qry.InvestorID, User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);
		memcpy(qry.TradingDay, GetTradingDay(), sizeof(TThostFtdcDateType) - 1);

		ReqQrySettlementInfo(&qry);
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

bool InstrumentCache::InsertOrAssignInstrument(CThostFtdcInstrumentField* pInstrument)
{
	if (NULL == pInstrument) { return false; }

	CThostFtdcInstrumentField* ins;

	if (instrumentDict.find(pInstrument->InstrumentID) == instrumentDict.end()) {
		ins = new(CThostFtdcInstrumentField);
		instrumentDict.insert_or_assign(ins->InstrumentID, ins);
	}
	else {
		ins = instrumentDict.at(pInstrument->InstrumentID);
	}

	assert(ins != NULL);
	memcpy(ins, pInstrument, sizeof(CThostFtdcInstrumentField));
	return true;
}

bool InstrumentCache::InsertOrAssignMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
	if (NULL == pDepthMarketData) {
		return false;
	}

	CThostFtdcDepthMarketDataField* md;

	if (marketDataDict.find(pDepthMarketData->InstrumentID) == marketDataDict.end()) {
		md = new(CThostFtdcDepthMarketDataField);
		marketDataDict.insert_or_assign(pDepthMarketData->InstrumentID, md);
	}
	else {
		md = marketDataDict.at(pDepthMarketData->InstrumentID);
	}

	assert(md != NULL);
	memcpy(md, pDepthMarketData, sizeof(CThostFtdcDepthMarketDataField));
	return true;
}

CThostFtdcInstrumentField* InstrumentCache::getNextInstrument(int& idx)
{
	if (idx >= instrumentList.size()) {
		return NULL;
	}

	return instrumentList[idx++];
}

bool InstrumentCache::InsertOrAssignMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate)
{
	if (NULL == pInstrumentMarginRate) {
		return false;
	}

	CThostFtdcInstrumentMarginRateField* marginRate;

	if (marginRateDict.find(pInstrumentMarginRate->InstrumentID) == marginRateDict.end()) {
		marginRate = new(CThostFtdcInstrumentMarginRateField);
		marginRateDict.insert_or_assign(pInstrumentMarginRate->InstrumentID, marginRate);
	}
	else {
		marginRate = marginRateDict.at(pInstrumentMarginRate->InstrumentID);
	}

	assert(marginRate != NULL);
	memcpy(marginRate, pInstrumentMarginRate, sizeof(CThostFtdcInstrumentMarginRateField));
	return true;
}

bool InstrumentCache::InsertOrAssignCommRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate)
{
	if (NULL == pInstrumentCommissionRate) {
		return false;
	}

	CThostFtdcInstrumentCommissionRateField* commRate;

	if (commRateDict.find(pInstrumentCommissionRate->InstrumentID) == commRateDict.end()) {
		commRate = new(CThostFtdcInstrumentCommissionRateField);
		commRateDict.insert_or_assign(pInstrumentCommissionRate->InstrumentID, commRate);
	}
	else {
		commRate = commRateDict.at(pInstrumentCommissionRate->InstrumentID);
	}

	assert(commRate != NULL);
	memcpy(commRate, pInstrumentCommissionRate, sizeof(CThostFtdcInstrumentCommissionRateField));
	return true;
}

void InstrumentCache::QueryNextMarginRate()
{
	assert(api != NULL);

	CThostFtdcInstrumentField* ins = getNextInstrument(marginRateQryIdx);

	while (NULL != ins) {
		// 目前仅支持期货合约的保证金查询
		// TODO： 支持其他类型的合约保证金查询
		if (marginRateDict.find(ins->InstrumentID) == marginRateDict.end() &&
			THOST_FTDC_APC_FutureSingle == ins->ProductClass) {

			CThostFtdcQryInstrumentMarginRateField qryMargin = { 0 };
			strncpy(qryMargin.BrokerID, api->User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
			strncpy(qryMargin.InvestorID, api->User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);
			strncpy(qryMargin.InstrumentID, ins->InstrumentID, sizeof(TThostFtdcInstrumentIDType) - 1);
			qryMargin.HedgeFlag = THOST_FTDC_HF_Speculation;

			api->ReqQryInstrumentMarginRate(&qryMargin);

			return;
		}

		ins = getNextInstrument(marginRateQryIdx);
	}

	api->queryAllMarginRate = false;
	marginRateQryIdx = 0;

	printf("Quering instrument margin rate finisehd.\n");
}

void InstrumentCache::QueryNextCommRate()
{
	assert(api != NULL);

	CThostFtdcInstrumentField* ins = getNextInstrument(commRateQryIdx);

	while (NULL != ins) {
		// 目前仅支持期货合约的手续费查询
		// TODO： 支持其他类型的合约手续费查询
		if (commRateDict.find(ins->InstrumentID) == commRateDict.end() &&
			THOST_FTDC_APC_FutureSingle == ins->ProductClass) {

			CThostFtdcQryInstrumentCommissionRateField qryComm = { 0 };
			strncpy(qryComm.BrokerID, api->User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
			strncpy(qryComm.InvestorID, api->User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);
			strncpy(qryComm.InstrumentID, ins->InstrumentID, sizeof(TThostFtdcInstrumentIDType) - 1);

			api->ReqQryInstrumentCommissionRate(&qryComm);

			return;
		}

		ins = getNextInstrument(commRateQryIdx);
	}

	api->queryAllCommRate = false;
	commRateQryIdx = 0;

	printf("Quering instrument comm rate finished.\n");
}

void InstrumentCache::BuildInstrumentList()
{
	if (instrumentList.size() > 0) {
		instrumentList.clear();
	}

	for (auto &iter : instrumentDict) {
		instrumentList.push_back(iter.second);
	}
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
	g_cond.notify_one();
	
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
		case QueryFlag::QrySettlementInfo:
			rtn = api->pApi->ReqQrySettlementInfo((CThostFtdcQrySettlementInfoField*)qry, requestID);
			
			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQrySettlementInfoField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQrySettlementInfoField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QrySettlementConfirm:
			rtn = api->pApi->ReqQrySettlementInfoConfirm((CThostFtdcQrySettlementInfoConfirmField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQrySettlementInfoConfirmField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQrySettlementInfoConfirmField));
			}
			else {
				query->qry = qry;
			}

			break;
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
		{
			auto pQryInstrumentMarginRate = (CThostFtdcQryInstrumentMarginRateField*)qry;
			printf("Quering instrument[%s] margin rate.\n", pQryInstrumentMarginRate->InstrumentID);
			rtn = api->pApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentMarginRateField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentMarginRateField));
			}
			else {
				query->qry = qry;
			}

			break;
		}
		case QueryFlag::QryCommissionRate:
		{
			auto pQryInstrumentCommissionRate = (CThostFtdcQryInstrumentCommissionRateField*)qry;
			printf("Quering instrument[%s] comm rate.\n", pQryInstrumentCommissionRate->InstrumentID);
			rtn = api->pApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentCommissionRateField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentCommissionRateField));
			}
			else {
				query->qry = qry;
			}

			break;
		}
		case QueryFlag::QryMarketData:
			rtn = api->pApi->ReqQryDepthMarketData((CThostFtdcQryDepthMarketDataField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryDepthMarketDataField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryDepthMarketDataField));
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
		
		if (-2 == rtn){
			fprintf(stderr, "Inflight request exceeded.\n");
		}
		else if (-3 == rtn) {
			fprintf(stderr, "Flow control exceeded.\n");
		}
		else {
			fprintf(stderr, "Unknown request rtn code: %d\n", rtn);
			return rtn;
		}

		SLEEP(500);
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

bool QueryCache::chkStatus(long long& timeout)
{
	if (flag != QueryFlag::QryFinished) {
		// fprintf(stderr, "Last query not finished.\n");
		timeout = 0;
		return false;
	}

	timeout = get_ms_ts() - lastQryTS;
	if (timeout < 1000 && qryCount >= qryFreq) {
		// fprintf(stderr, "Query frequence exceeded.\n");
		return false;
	}

	timeout = 0;
	return true;
}

void QueryCache::CheckAndWait() {
	std::unique_lock<std::mutex> locker(g_lock);
	
	long long timeout;
	
	while (!chkStatus(timeout)) {
		if (timeout > 0) {
			g_cond.wait_for(locker, std::chrono::milliseconds(timeout));
		}
		else {
			g_cond.wait(locker);
		}
	}
}

long long get_ms_ts()
{
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	);

	return ms.count();
}

void OrderCache::InsertOrAssignOrder(CThostFtdcOrderField* pOrder)
{
	if (NULL == pOrder) {
		return;
	}

	std::string sysID = ltrim(pOrder->OrderSysID);
	std::string orderRef = ltrim(pOrder->OrderRef);
	std::string sessionID = std::to_string(pOrder->SessionID);
	std::string frontID = std::to_string(pOrder->FrontID);

	CThostFtdcOrderField* ord;

	if (sysID != "") {
		if (orderDictBySysID.find(sysID) == orderDictBySysID.end()) {
			ord = new(CThostFtdcOrderField);

			orderDictBySysID.insert_or_assign(sysID, ord);

			if (orderRef != "") {				
				orderDictByRef.insert_or_assign(JOIN_REF(sessionID, frontID, orderRef), ord);
			}

			orderList.push_back(ord);
		}
		else {
			ord = orderDictBySysID.at(sysID);
		}
	}
	else if (orderRef != "") {
		std::string ref = JOIN_REF(sessionID, frontID, orderRef);
		if (orderDictByRef.find(ref) == orderDictByRef.end()) {
			ord = new(CThostFtdcOrderField);

			orderDictByRef.insert_or_assign(ref, ord);

			orderList.push_back(ord);
		}
		else {
			ord = orderDictByRef.at(ref);
		}
	}
	else {
		return;
	}

	assert(NULL != ord);
	memcpy(ord, pOrder, sizeof(CThostFtdcOrderField));
}

std::vector<CThostFtdcOrderField*> OrderCache::GetOrders(std::string orderRef, std::string orderSysID)
{
	std::vector<CThostFtdcOrderField*> result;

	if (orderSysID != "") {
		int count = 0;
		char** idList = split(orderSysID.c_str(), count);
		
		for (int i = 0; i < count; i++) {
			if (orderDictBySysID.find(idList[i]) == orderDictBySysID.end()) {
				continue;
			}

			result.push_back(orderDictBySysID.at(idList[i]));
		}
	} else if (orderRef != "") {
		int count = 0;
		char** refList = split(orderRef.c_str(), count);

		for (int i = 0; i < count; i++) {
			std::string sessionID = std::to_string(api->User.SessionID);
			std::string frontID = std::to_string(api->User.FrontID);
			std::string ref = JOIN_REF(sessionID, frontID, refList[i]);
			
			if (orderDictByRef.find(ref) == orderDictByRef.end()) {
				continue;
			}

			result.push_back(orderDictByRef.at(ref));
		}
	}
	else {
		result = orderList;
	}

	return result;
}
