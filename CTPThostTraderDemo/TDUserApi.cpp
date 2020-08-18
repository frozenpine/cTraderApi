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

bool TDUserApi::checkAPIInitialized()
{
	return pApi != NULL;
}

bool TDUserApi::checkConnected()
{
	return connected;
}

bool TDUserApi::checkAuthenticated()
{
	return authenticated;
}

bool TDUserApi::checkUserLogin()
{
	return login;
}

void TDUserApi::waitUntil(bool(TDUserApi::* checkFn)(), bool expect)
{
	while (true) {
		std::lock_guard<std::recursive_mutex> locker(g_lock);

		if ((this->*checkFn)() == expect) {
			break;
		}

		SLEEP(500);
	}
}

void TDUserApi::OnFrontConnected()
{
	printf("Front connected.\n");

	connected = true;
}

void TDUserApi::OnFrontDisconnected(int nReason)
{
	printf("Front disconnected: %d\n", nReason);
}

void TDUserApi::OnHeartBeatWarning(int nTimeLapse)
{
	printf("HeartBeat warning: %d\n", nTimeLapse);
}

void TDUserApi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo != NULL && pRspInfo->ErrorID != 0) {
		printf("Authentication failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);

		pApi->Release();
		
		return;
	}

	if (pRspAuthenticateField != NULL) {
		printf("Authentication succeed: %s, %s, %s\n", pRspAuthenticateField->BrokerID, pRspAuthenticateField->UserID, pRspAuthenticateField->AppID);
	}

	authenticated = true;
}

void TDUserApi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo != NULL && pRspInfo->ErrorID != 0) {
		printf("Login failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);

		pApi->Release();

		return;
	}

	if (pRspUserLogin != NULL) {
		printf("Login succeed[%s]: %s, %s\n", pRspUserLogin->TradingDay, pRspUserLogin->BrokerID, pRspUserLogin->UserID);
	}

	login = true;
}

void TDUserApi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo != NULL && pRspInfo->ErrorID != 0) {
		printf("Query instrument failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);

		return;
	}

	if (pInstrument != NULL) {
		printf("%s.%s: \n", pInstrument->ExchangeID, pInstrument->InstrumentID);
	}

	if (bIsLast) {
		printf("All instrument query response finished.\n");
	}
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

int TDUserApi::ReqQryOrder(CThostFtdcQryOrderField* pQryOrder)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryOrder(pQryOrder, ++nRequestID);
}

int TDUserApi::ReqQryTrade(CThostFtdcQryTradeField* pQryTrade)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryTrade(pQryTrade, ++nRequestID);
}

int TDUserApi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryInvestorPosition(pQryInvestorPosition, ++nRequestID);
}

int TDUserApi::ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryTradingAccount(pQryTradingAccount, ++nRequestID);
}

int TDUserApi::ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryInvestor(pQryInvestor, ++nRequestID);
}

int TDUserApi::ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryTradingCode(pQryTradingCode, ++nRequestID);
}

int TDUserApi::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, ++nRequestID);
}

int TDUserApi::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, ++nRequestID);
}

int TDUserApi::ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryExchange(pQryExchange, ++nRequestID);
}

int TDUserApi::ReqQryProduct(CThostFtdcQryProductField* pQryProduct)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryProduct(pQryProduct, ++nRequestID);
}

int TDUserApi::ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryInstrument(pQryInstrument, ++nRequestID);
}

int TDUserApi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryDepthMarketData(pQryDepthMarketData, ++nRequestID);
}

int TDUserApi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQrySettlementInfo(pQrySettlementInfo, ++nRequestID);
}

int TDUserApi::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, ++nRequestID);
}

int TDUserApi::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, ++nRequestID);
}

int TDUserApi::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, ++nRequestID);
}

int TDUserApi::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, ++nRequestID);
}

int TDUserApi::ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust)
{
	waitUntil(&TDUserApi::checkUserLogin, true);

	return pApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, ++nRequestID);
}
