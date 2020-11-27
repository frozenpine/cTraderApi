#include <assert.h>

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

void TDUserApi::waitUntil(bool(TDUserApi::* checkFn)(), bool expect)
{
	std::unique_lock<std::mutex> locker(g_lock);

	while ((this->*checkFn)() != expect) {
		g_cond.wait(locker);
	}
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
			"Input order is:"
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
}

void TDUserApi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query order failed[%d]: %s\n", pRspInfo)) {
		setFlag(&qryFinished, true);

		return;
	}

	if (NULL != pOrder) {
		orderDictByRef.insert_or_assign(pOrder->OrderRef, pOrder);
		orderDictBySysID.insert_or_assign(pOrder->OrderSysID, pOrder);

		printf(
			"Symbol[%s.%s] %s %s: Direction[%c] Offset[%s] %d@%.2f\n",
			pOrder->ExchangeID, pOrder->InstrumentID, pOrder->OrderRef, pOrder->OrderSysID,
			pOrder->Direction, pOrder->CombOffsetFlag, 
			pOrder->VolumeTotalOriginal, pOrder->LimitPrice
		);
	}

	if (bIsLast) {
		printf("Query order finished.\n");

		setFlag(&qryFinished, true);
	}
}

void TDUserApi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query investor's position failed[%d]: %s\n", pRspInfo)) {
		setFlag(&qryFinished, true);

		return;
	}

	if (NULL != pInvestorPosition) {
		std::string symbol;
		symbol.append(pInvestorPosition->ExchangeID);
		symbol.append(".");
		symbol.append(pInvestorPosition->InstrumentID);

		positionCache.insert_or_assign(symbol, pInvestorPosition);

		printf(
			"Symbol[%s.%s]: Direction[%c] YdPos[%d] Pos[%d]\n", 
			pInvestorPosition->ExchangeID, pInvestorPosition->InstrumentID,
			pInvestorPosition->PosiDirection, pInvestorPosition->YdPosition, pInvestorPosition->Position
		);
	}

	if (bIsLast) {
		printf("Query investor's position finished.\n");

		setFlag(&qryFinished, true);
	}
}

void TDUserApi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (checkRspError("Query instrument failed[%d]: %s\n", pRspInfo)) {
		setFlag(&qryFinished, true);

		return;
	}

	if (NULL != pInstrument) { 
		std::string symbol;
		symbol.append(pInstrument->ExchangeID);
		symbol.append(".");
		symbol.append(pInstrument->InstrumentID);

		symbolCache.insert_or_assign(symbol, pInstrument);
	}

	if (bIsLast) {
		printf("Query instrument info finished.\n");

		setFlag(&qryFinished, true);
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
	printf("Order rejected: %s", pRspInfo->ErrorMsg);
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

	return pApi->ReqOrderInsert(pInputOrder, ++nRequestID);
}

int TDUserApi::ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction)
{
	/*waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);*/
	
	return pApi->ReqOrderAction(pInputOrderAction, ++nRequestID);
}

int TDUserApi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryOrder(pQryOrder, ++nRequestID);
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
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryInvestorPosition(pQryInvestorPosition, ++nRequestID);
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
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, ++nRequestID);
}

int TDUserApi::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, ++nRequestID);
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
	waitUntil(&TDUserApi::checkQryStatus, true);

	setFlag(&qryFinished, false);

	return pApi->ReqQryInstrument(pQryInstrument, ++nRequestID);
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
