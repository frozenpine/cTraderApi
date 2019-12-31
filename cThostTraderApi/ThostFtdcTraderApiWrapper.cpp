# include "ThostFtcTraderApiWrapper.h"

const char *cTraderApi::GetApiVersion()
{
	return CThostFtdcTraderApi::GetApiVersion();
}

void cTraderApi::Init(bool bContinuous)
{
	pApi->Init(bContinuous);
}

int cTraderApi::CreateApi(const char * pszFlowPath)
{
	if (pApi != NULL) {
		return -1;
	}

	pApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
	pApi->RegisterSpi(this);

	return 0;
}

void cTraderApi::Release()
{
	pApi->Release();
}

int cTraderApi::Join()
{
	return pApi->Join();
}

const char *cTraderApi::GetTradingDay()
{
	return pApi->GetTradingDay();
}

void cTraderApi::RegisterFront(char *pszFrontAddress)
{
	pApi->RegisterFront(pszFrontAddress);
}

void cTraderApi::RegisterNameServer(char *pszNsAddress)
{
	pApi->RegisterNameServer(pszNsAddress);
}

void cTraderApi::RegisterFensUserInfo(CThostFtdcFensUserInfoField *pFensUserInfo)
{
	pApi->RegisterFensUserInfo(pFensUserInfo);
}

void cTraderApi::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	pApi->SubscribePrivateTopic(nResumeType);
}

void cTraderApi::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	pApi->SubscribePublicTopic(nResumeType);
}

int cTraderApi::ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID)
{
	return pApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

int cTraderApi::ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	return pApi->ReqUserLogin(pReqUserLoginField, nRequestID);
};

int cTraderApi::ReqUserLoginEncrypt(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	return pApi->ReqUserLoginEncrypt(pReqUserLoginField, nRequestID);
};

int cTraderApi::ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	return pApi->ReqUserLogout(pUserLogout, nRequestID);
};

int cTraderApi::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	return pApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
};

int cTraderApi::ReqTradingAccountPasswordUpdate(
	CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID)
{
	return pApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
};

int cTraderApi::ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID)
{
	return pApi->ReqOrderInsert(pInputOrder, nRequestID);
};

int cTraderApi::ReqParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, int nRequestID)
{
	return pApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
};

int cTraderApi::ReqParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID)
{
	return pApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
};

int cTraderApi::ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID)
{
	return pApi->ReqOrderAction(pInputOrderAction, nRequestID);
};

int cTraderApi::ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID)
{
	return pApi->ReqQueryMaxOrderVolume(pQueryMaxOrderVolume, nRequestID);
};

int cTraderApi::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID)
{
	return pApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
};

int cTraderApi::ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID)
{
	return pApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
};

int cTraderApi::ReqRemoveParkedOrderAction(
	CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID)
{
	return pApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
};

int cTraderApi::ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	return pApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
};

int cTraderApi::ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID)
{
	return pApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
};

int cTraderApi::ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID)
{
	return pApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
};

int cTraderApi::ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	return pApi->ReqQuoteInsert(pInputQuote, nRequestID);
};

int cTraderApi::ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID)
{
	return pApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
};

int cTraderApi::ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID)
{
	return pApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
};

int cTraderApi::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID)
{
	return pApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
};

int cTraderApi::ReqOptionSelfCloseAction(
	CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID)
{
	return pApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
};

int cTraderApi::ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID)
{
	return pApi->ReqQryOrder(pQryOrder, nRequestID);
};

int cTraderApi::ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID)
{
	return pApi->ReqQryTrade(pQryTrade, nRequestID);
};

int cTraderApi::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	return pApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
};

int cTraderApi::ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	return pApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
};

int cTraderApi::ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID)
{
	return pApi->ReqQryInvestor(pQryInvestor, nRequestID);
};

int cTraderApi::ReqQryTradingCode(CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID)
{
	return pApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
};

int cTraderApi::ReqQryInstrumentMarginRate(
	CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID)
{
	return pApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
};

int cTraderApi::ReqQryInstrumentCommissionRate(
	CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID)
{
	return pApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
};

int cTraderApi::ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	return pApi->ReqQryExchange(pQryExchange, nRequestID);
};

int cTraderApi::ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID)
{
	return pApi->ReqQryProduct(pQryProduct, nRequestID);
};

int cTraderApi::ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	return pApi->ReqQryInstrument(pQryInstrument, nRequestID);
};

int cTraderApi::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID)
{
	return pApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
};

int cTraderApi::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID)
{
	return pApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
};

int cTraderApi::ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID)
{
	return pApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
};

int cTraderApi::ReqQryInvestorPositionDetail(
	CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID)
{
	return pApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
};

int cTraderApi::ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID)
{
	return pApi->ReqQryNotice(pQryNotice, nRequestID);
};

int cTraderApi::ReqQrySettlementInfoConfirm(
	CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID)
{
	return pApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
};

int cTraderApi::ReqQryInvestorPositionCombineDetail(
	CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID)
{
	return pApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
};

int cTraderApi::ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID)
{
	return pApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
};

int cTraderApi::ReqQryInvestorProductGroupMargin(
	CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID)
{
	return pApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
};

int cTraderApi::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID)
{
	return pApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
};

int cTraderApi::ReqQryExchangeMarginRateAdjust(
	CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID)
{
	return pApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
};

int cTraderApi::ReqQryExchangeRate(CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	return pApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
};

int cTraderApi::ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID)
{
	return pApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
};

int cTraderApi::ReqQryOptionInstrTradeCost(
	CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID)
{
	return pApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
};

int cTraderApi::ReqQryOptionInstrCommRate(
	CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID)
{
	return pApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
};

int cTraderApi::ReqQryExecOrder(CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	return pApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
};

int cTraderApi::ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID)
{
	return pApi->ReqQryForQuote(pQryForQuote, nRequestID);
};

int cTraderApi::ReqQryQuote(CThostFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	return pApi->ReqQryQuote(pQryQuote, nRequestID);
};

int cTraderApi::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID)
{
	return pApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
};

int cTraderApi::ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID)
{
	return pApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
};

int cTraderApi::ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID)
{
	return pApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
};

int cTraderApi::ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID)
{
	return pApi->ReqQryContractBank(pQryContractBank, nRequestID);
};

int cTraderApi::ReqQryParkedOrder(CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID)
{
	return pApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
};

int cTraderApi::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID)
{
	return pApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
};

int cTraderApi::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID)
{
	return pApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
};

int cTraderApi::ReqQryBrokerTradingParams(
	CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID)
{
	return pApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
};

int cTraderApi::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID)
{
	return pApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
};

int cTraderApi::ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	return pApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
};

int cTraderApi::ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	return pApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
};

int cTraderApi::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID)
{
	return pApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
};

int cTraderApi::ReqTransFund(CThostFtdcTransFundField *pFtdcTransFund, int nRequestID)
{
	return pApi->ReqTransFund(pFtdcTransFund, nRequestID);
};

int cTraderApi::ReqQryInstrumentStatus(CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID)
{
	return pApi->ReqQryInstrumentStatus(pQryInstrumentStatus, nRequestID);
};

int cTraderApi::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID)
{
	return pApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
};

void cTraderApi::OnFrontConnected()
{
	if (vtCallback.onFrontConnected == NULL) {
		return;
	}

	vtCallback.onFrontConnected((InstanceID)this);
};

void cTraderApi::OnFrontDisconnected(int nReason)
{
	if (vtCallback.onFrontDisconnected == NULL) {
		return;
	}

	vtCallback.onFrontDisconnected((InstanceID)this, nReason);
};

void cTraderApi::OnHeartBeatWarning(int nTimeLapse)
{
	if (vtCallback.onHeartBeatWarning == NULL) {
		return;
	}

	vtCallback.onHeartBeatWarning((InstanceID)this, nTimeLapse);
};

void cTraderApi::OnRspAuthenticate(
	CThostFtdcRspAuthenticateField *pRspAuthenticateField,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspAuthenticate == NULL) {
		return;
	}

	vtCallback.onRspAuthenticate((InstanceID)this, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspUserLogin(
	CThostFtdcRspUserLoginField *pRspUserLogin,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspUserLogin == NULL) {
		return;
	}

	vtCallback.onRspUserLogin((InstanceID)this, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspUserLogout(
	CThostFtdcUserLogoutField *pUserLogout,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspUserLogout == NULL) {
		return;
	}

	vtCallback.onRspUserLogout((InstanceID)this, pUserLogout, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspUserPasswordUpdate(
	CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspUserPasswordUpdate == NULL) {
		return;
	}

	vtCallback.onRspUserPasswordUpdate((InstanceID)this, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspTradingAccountPasswordUpdate(
	CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspTradingAccountPasswordUpdate == NULL) {
		return;
	}

	vtCallback.onRspTradingAccountPasswordUpdate(
		(InstanceID)this, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspOrderInsert(
	CThostFtdcInputOrderField *pInputOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspOrderInsert == NULL)
	{
		return;
	}

	vtCallback.onRspOrderInsert((InstanceID)this, pInputOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspParkedOrderInsert(
	CThostFtdcParkedOrderField *pParkedOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspParkedOrderInsert == NULL)
	{
		return;
	}

	vtCallback.onRspParkedOrderInsert((InstanceID)this, pParkedOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspParkedOrderAction(
	CThostFtdcParkedOrderActionField *pParkedOrderAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspParkedOrderAction == NULL)
	{
		return;
	}

	vtCallback.onRspParkedOrderAction((InstanceID)this, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspOrderAction(
	CThostFtdcInputOrderActionField *pInputOrderAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspOrderAction == NULL)
	{
		return;
	}

	vtCallback.onRspOrderAction((InstanceID)this, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQueryMaxOrderVolume(
	CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQueryMaxOrderVolume == NULL)
	{
		return;
	}

	vtCallback.onRspQueryMaxOrderVolume((InstanceID)this, pQueryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspSettlementInfoConfirm(
	CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspSettlementInfoConfirm == NULL)
	{
		return;
	}

	vtCallback.onRspSettlementInfoConfirm((InstanceID)this, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspRemoveParkedOrder(
	CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspRemoveParkedOrder == NULL)
	{
		return;
	}

	vtCallback.onRspRemoveParkedOrder((InstanceID)this, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspRemoveParkedOrderAction(
	CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspRemoveParkedOrderAction == NULL)
	{
		return;
	}

	vtCallback.onRspRemoveParkedOrderAction((InstanceID)this, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspExecOrderInsert(
	CThostFtdcInputExecOrderField *pInputExecOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspExecOrderInsert == NULL)
	{
		return;
	}

	vtCallback.onRspExecOrderInsert((InstanceID)this, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspExecOrderAction(
	CThostFtdcInputExecOrderActionField *pInputExecOrderAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspExecOrderAction == NULL)
	{
		return;
	}

	vtCallback.onRspExecOrderAction((InstanceID)this, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspForQuoteInsert(
	CThostFtdcInputForQuoteField *pInputForQuote,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspForQuoteInsert == NULL)
	{
		return;
	}

	vtCallback.onRspForQuoteInsert((InstanceID)this, pInputForQuote, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQuoteInsert(
	CThostFtdcInputQuoteField *pInputQuote,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQuoteInsert == NULL)
	{
		return;
	}

	vtCallback.onRspQuoteInsert((InstanceID)this, pInputQuote, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQuoteAction(
	CThostFtdcInputQuoteActionField *pInputQuoteAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQuoteAction == NULL)
	{
		return;
	}

	vtCallback.onRspQuoteAction((InstanceID)this, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspBatchOrderAction(
	CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspBatchOrderAction == NULL)
	{
		return;
	}

	vtCallback.onRspBatchOrderAction((InstanceID)this, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspOptionSelfCloseInsert(
	CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspOptionSelfCloseInsert == NULL)
	{
		return;
	}

	vtCallback.onRspOptionSelfCloseInsert((InstanceID)this, pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspOptionSelfCloseAction(
	CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspOptionSelfCloseAction == NULL)
	{
		return;
	}

	vtCallback.onRspOptionSelfCloseAction((InstanceID)this, pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspTransFund(
	CThostFtdcTransFundField *pTransFund,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspTransFund == NULL)
	{
		return;
	}

	vtCallback.onRspTransFund((InstanceID)this, pTransFund, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryOrder(
	CThostFtdcOrderField *pOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryOrder == NULL)
	{
		return;
	}

	vtCallback.onRspQryOrder((InstanceID)this, pOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryTrade(
	CThostFtdcTradeField *pTrade,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryTrade == NULL)
	{
		return;
	}

	vtCallback.onRspQryTrade((InstanceID)this, pTrade, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInvestorPosition(
	CThostFtdcInvestorPositionField *pInvestorPosition,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInvestorPosition == NULL)
	{
		return;
	}

	vtCallback.onRspQryInvestorPosition((InstanceID)this, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryTradingAccount(
	CThostFtdcTradingAccountField *pTradingAccount,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryTradingAccount == NULL)
	{
		return;
	}

	vtCallback.onRspQryTradingAccount((InstanceID)this, pTradingAccount, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInvestor(
	CThostFtdcInvestorField *pInvestor,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInvestor == NULL)
	{
		return;
	}

	vtCallback.onRspQryInvestor((InstanceID)this, pInvestor, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryTradingCode(
	CThostFtdcTradingCodeField *pTradingCode,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryTradingCode == NULL)
	{
		return;
	}

	vtCallback.onRspQryTradingCode((InstanceID)this, pTradingCode, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInstrumentMarginRate(
	CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInstrumentMarginRate == NULL)
	{
		return;
	}

	vtCallback.onRspQryInstrumentMarginRate((InstanceID)this, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInstrumentCommissionRate(
	CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInstrumentCommissionRate == NULL)
	{
		return;
	}

	vtCallback.onRspQryInstrumentCommissionRate(
		(InstanceID)this, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryExchange(
	CThostFtdcExchangeField *pExchange,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryExchange == NULL)
	{
		return;
	}

	vtCallback.onRspQryExchange((InstanceID)this, pExchange, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryProduct(
	CThostFtdcProductField *pProduct,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryProduct == NULL)
	{
		return;
	}

	vtCallback.onRspQryProduct((InstanceID)this, pProduct, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInstrument(
	CThostFtdcInstrumentField *pInstrument,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInstrument == NULL)
	{
		return;
	}

	vtCallback.onRspQryInstrument((InstanceID)this, pInstrument, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryDepthMarketData(
	CThostFtdcDepthMarketDataField *pDepthMarketData,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryDepthMarketData == NULL)
	{
		return;
	}

	vtCallback.onRspQryDepthMarketData((InstanceID)this, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQrySettlementInfo(
	CThostFtdcSettlementInfoField *pSettlementInfo,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQrySettlementInfo == NULL)
	{
		return;
	}

	vtCallback.onRspQrySettlementInfo((InstanceID)this, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInstrumentStatus(
	CThostFtdcInstrumentStatusField *pInstrumentStatus,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInstrumentStatus == NULL)
	{
		return;
	}

	vtCallback.onRspQryInstrumentStatus((InstanceID)this, pInstrumentStatus, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryTransferBank(
	CThostFtdcTransferBankField *pTransferBank,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryTransferBank == NULL)
	{
		return;
	}

	vtCallback.onRspQryTransferBank((InstanceID)this, pTransferBank, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInvestorPositionDetail(
	CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInvestorPositionDetail == NULL)
	{
		return;
	}

	vtCallback.onRspQryInvestorPositionDetail((InstanceID)this, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryNotice(
	CThostFtdcNoticeField *pNotice,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryNotice == NULL)
	{
		return;
	}

	vtCallback.onRspQryNotice((InstanceID)this, pNotice, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQrySettlementInfoConfirm(
	CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQrySettlementInfoConfirm == NULL)
	{
		return;
	}

	vtCallback.onRspQrySettlementInfoConfirm((InstanceID)this, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInvestorPositionCombineDetail(
	CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInvestorPositionCombineDetail == NULL)
	{
		return;
	}

	vtCallback.onRspQryInvestorPositionCombineDetail(
		(InstanceID)this, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryCFMMCTradingAccountKey(
	CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryCFMMCTradingAccountKey == NULL)
	{
		return;
	}

	vtCallback.onRspQryCFMMCTradingAccountKey((InstanceID)this, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryEWarrantOffset(
	CThostFtdcEWarrantOffsetField *pEWarrantOffset,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryEWarrantOffset == NULL)
	{
		return;
	}

	vtCallback.onRspQryEWarrantOffset((InstanceID)this, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryInvestorProductGroupMargin(
	CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryInvestorProductGroupMargin == NULL)
	{
		return;
	}

	vtCallback.onRspQryInvestorProductGroupMargin(
		(InstanceID)this, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryExchangeMarginRate(
	CThostFtdcExchangeMarginRateField *pExchangeMarginRate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryExchangeMarginRate == NULL)
	{
		return;
	}

	vtCallback.onRspQryExchangeMarginRate((InstanceID)this, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryExchangeMarginRateAdjust(
	CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryExchangeMarginRateAdjust == NULL)
	{
		return;
	}

	vtCallback.onRspQryExchangeMarginRateAdjust(
		(InstanceID)this, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryExchangeRate(
	CThostFtdcExchangeRateField *pExchangeRate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryExchangeRate == NULL)
	{
		return;
	}

	vtCallback.onRspQryExchangeRate((InstanceID)this, pExchangeRate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQrySecAgentACIDMap(
	CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQrySecAgentACIDMap == NULL)
	{
		return;
	}

	vtCallback.onRspQrySecAgentACIDMap((InstanceID)this, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryOptionInstrTradeCost(
	CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryOptionInstrTradeCost == NULL)
	{
		return;
	}

	vtCallback.onRspQryOptionInstrTradeCost((InstanceID)this, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryOptionInstrCommRate(
	CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryOptionInstrCommRate == NULL)
	{
		return;
	}

	vtCallback.onRspQryOptionInstrCommRate((InstanceID)this, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryExecOrder(
	CThostFtdcExecOrderField *pExecOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryExecOrder == NULL)
	{
		return;
	}

	vtCallback.onRspQryExecOrder((InstanceID)this, pExecOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryForQuote(
	CThostFtdcForQuoteField *pForQuote,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryForQuote == NULL)
	{
		return;
	}

	vtCallback.onRspQryForQuote((InstanceID)this, pForQuote, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryQuote(
	CThostFtdcQuoteField *pQuote,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryQuote == NULL)
	{
		return;
	}

	vtCallback.onRspQryQuote((InstanceID)this, pQuote, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryOptionSelfClose(
	CThostFtdcOptionSelfCloseField *pOptionSelfClose,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryOptionSelfClose == NULL)
	{
		return;
	}

	vtCallback.onRspQryOptionSelfClose((InstanceID)this, pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryTransferSerial(
	CThostFtdcTransferSerialField *pTransferSerial,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryTransferSerial == NULL)
	{
		return;
	}

	vtCallback.onRspQryTransferSerial((InstanceID)this, pTransferSerial, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryAccountregister(
	CThostFtdcAccountregisterField *pAccountregister,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryAccountregister == NULL)
	{
		return;
	}

	vtCallback.onRspQryAccountregister((InstanceID)this, pAccountregister, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspError == NULL)
	{
		return;
	}

	vtCallback.onRspError((InstanceID)this, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	if (vtCallback.onRtnOrder == NULL)
	{
		return;
	}

	vtCallback.onRtnOrder((InstanceID)this, pOrder);
};

void cTraderApi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	if (vtCallback.onRtnTrade == NULL)
	{
		return;
	}

	vtCallback.onRtnTrade((InstanceID)this, pTrade);
};

void cTraderApi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnOrderInsert == NULL)
	{
		return;
	}

	vtCallback.onErrRtnOrderInsert((InstanceID)this, pInputOrder, pRspInfo);
};

void cTraderApi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnOrderAction == NULL)
	{
		return;
	}

	vtCallback.onErrRtnOrderAction((InstanceID)this, pOrderAction, pRspInfo);
};

void cTraderApi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
{
	if (vtCallback.onRtnInstrumentStatus == NULL)
	{
		return;
	}

	vtCallback.onRtnInstrumentStatus((InstanceID)this, pInstrumentStatus);
};

void cTraderApi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
{
	if (vtCallback.onRtnTradingNotice == NULL)
	{
		return;
	}

	vtCallback.onRtnTradingNotice((InstanceID)this, pTradingNoticeInfo);
};

void cTraderApi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
{
	if (vtCallback.onRtnErrorConditionalOrder == NULL)
	{
		return;
	}

	vtCallback.onRtnErrorConditionalOrder((InstanceID)this, pErrorConditionalOrder);
};

void cTraderApi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder)
{
	if (vtCallback.onRtnExecOrder == NULL)
	{
		return;
	}

	vtCallback.onRtnExecOrder((InstanceID)this, pExecOrder);
};

void cTraderApi::OnErrRtnExecOrderInsert(
	CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnExecOrderInsert == NULL)
	{
		return;
	}

	vtCallback.onErrRtnExecOrderInsert((InstanceID)this, pInputExecOrder, pRspInfo);
};

void cTraderApi::OnErrRtnExecOrderAction(
	CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnExecOrderAction == NULL)
	{
		return;
	}

	vtCallback.onErrRtnExecOrderAction((InstanceID)this, pExecOrderAction, pRspInfo);
};

void cTraderApi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnForQuoteInsert == NULL)
	{
		return;
	}

	vtCallback.onErrRtnForQuoteInsert((InstanceID)this, pInputForQuote, pRspInfo);
};

void cTraderApi::OnRtnQuote(CThostFtdcQuoteField *pQuote)
{
	if (vtCallback.onRtnQuote == NULL)
	{
		return;
	}

	vtCallback.onRtnQuote((InstanceID)this, pQuote);
};

void cTraderApi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnQuoteInsert == NULL)
	{
		return;
	}

	vtCallback.onErrRtnQuoteInsert((InstanceID)this, pInputQuote, pRspInfo);
};

void cTraderApi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnQuoteAction == NULL)
	{
		return;
	}

	vtCallback.onErrRtnQuoteAction((InstanceID)this, pQuoteAction, pRspInfo);
};

void cTraderApi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	if (vtCallback.onRtnForQuoteRsp == NULL)
	{
		return;
	}

	vtCallback.onRtnForQuoteRsp((InstanceID)this, pForQuoteRsp);
};

void cTraderApi::OnErrRtnBatchOrderAction(
	CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnBatchOrderAction == NULL)
	{
		return;
	}

	vtCallback.onErrRtnBatchOrderAction((InstanceID)this, pBatchOrderAction, pRspInfo);
};

void cTraderApi::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose)
{
	if (vtCallback.onRtnOptionSelfClose == NULL)
	{
		return;
	}

	vtCallback.onRtnOptionSelfClose((InstanceID)this, pOptionSelfClose);
};

void cTraderApi::OnErrRtnOptionSelfCloseInsert(
	CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnOptionSelfCloseInsert == NULL)
	{
		return;
	}

	vtCallback.onErrRtnOptionSelfCloseInsert((InstanceID)this, pInputOptionSelfClose, pRspInfo);
};

void cTraderApi::OnErrRtnOptionSelfCloseAction(
	CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnOptionSelfCloseAction == NULL)
	{
		return;
	}

	vtCallback.onErrRtnOptionSelfCloseAction((InstanceID)this, pOptionSelfCloseAction, pRspInfo);
};

void cTraderApi::OnRspQryContractBank(
	CThostFtdcContractBankField *pContractBank,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryContractBank == NULL)
	{
		return;
	}

	vtCallback.onRspQryContractBank((InstanceID)this, pContractBank, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryParkedOrder(
	CThostFtdcParkedOrderField *pParkedOrder,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryParkedOrder == NULL)
	{
		return;
	}

	vtCallback.onRspQryParkedOrder((InstanceID)this, pParkedOrder, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryParkedOrderAction(
	CThostFtdcParkedOrderActionField *pParkedOrderAction,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryParkedOrderAction == NULL)
	{
		return;
	}

	vtCallback.onRspQryParkedOrderAction((InstanceID)this, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryTradingNotice(
	CThostFtdcTradingNoticeField *pTradingNotice,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryTradingNotice == NULL)
	{
		return;
	}

	vtCallback.onRspQryTradingNotice((InstanceID)this, pTradingNotice, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryBrokerTradingParams(
	CThostFtdcBrokerTradingParamsField *pBrokerTradingParams,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryBrokerTradingParams == NULL)
	{
		return;
	}

	vtCallback.onRspQryBrokerTradingParams((InstanceID)this, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQryBrokerTradingAlgos(
	CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQryBrokerTradingAlgos == NULL)
	{
		return;
	}

	vtCallback.onRspQryBrokerTradingAlgos((InstanceID)this, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	if (vtCallback.onRtnFromBankToFutureByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnFromBankToFutureByBank((InstanceID)this, pRspTransfer);
};

void cTraderApi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	if (vtCallback.onRtnFromFutureToBankByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnFromFutureToBankByBank((InstanceID)this, pRspTransfer);
};

void cTraderApi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	if (vtCallback.onRtnRepealFromBankToFutureByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnRepealFromBankToFutureByBank((InstanceID)this, pRspRepeal);
};

void cTraderApi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	if (vtCallback.onRtnRepealFromFutureToBankByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnRepealFromFutureToBankByBank((InstanceID)this, pRspRepeal);
};

void cTraderApi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	if (vtCallback.onRtnFromBankToFutureByFuture == NULL)
	{
		return;
	}

	vtCallback.onRtnFromBankToFutureByFuture((InstanceID)this, pRspTransfer);
};

void cTraderApi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	if (vtCallback.onRtnFromFutureToBankByFuture == NULL)
	{
		return;
	}

	vtCallback.onRtnFromFutureToBankByFuture((InstanceID)this, pRspTransfer);
};

void cTraderApi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	if (vtCallback.onRtnRepealFromBankToFutureByFuture == NULL)
	{
		return;
	}

	vtCallback.onRtnRepealFromBankToFutureByFuture((InstanceID)this, pRspRepeal);
};

void cTraderApi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	if (vtCallback.onRtnRepealFromFutureToBankByFutureManual == NULL)
	{
		return;
	}

	vtCallback.onRtnRepealFromFutureToBankByFutureManual((InstanceID)this, pRspRepeal);
};

void cTraderApi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
{
	if (vtCallback.onRtnQueryBankBalanceByFuture == NULL)
	{
		return;
	}

	vtCallback.onRtnQueryBankBalanceByFuture((InstanceID)this, pNotifyQueryAccount);
};

void cTraderApi::OnErrRtnBankToFutureByFuture(
	CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnBankToFutureByFuture == NULL)
	{
		return;
	}

	vtCallback.onErrRtnBankToFutureByFuture((InstanceID)this, pReqTransfer, pRspInfo);
};

void cTraderApi::OnErrRtnFutureToBankByFuture(
	CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnFutureToBankByFuture == NULL)
	{
		return;
	}

	vtCallback.onErrRtnFutureToBankByFuture((InstanceID)this, pReqTransfer, pRspInfo);
};

void cTraderApi::OnErrRtnRepealBankToFutureByFutureManual(
	CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnRepealBankToFutureByFutureManual == NULL)
	{
		return;
	}

	vtCallback.onErrRtnRepealBankToFutureByFutureManual((InstanceID)this, pReqRepeal, pRspInfo);
};

void cTraderApi::OnErrRtnRepealFutureToBankByFutureManual(
	CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnRepealFutureToBankByFutureManual == NULL)
	{
		return;
	}

	vtCallback.onErrRtnRepealFutureToBankByFutureManual((InstanceID)this, pReqRepeal, pRspInfo);
};

void cTraderApi::OnErrRtnQueryBankBalanceByFuture(
	CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
{
	if (vtCallback.onErrRtnQueryBankBalanceByFuture == NULL)
	{
		return;
	}

	vtCallback.onErrRtnQueryBankBalanceByFuture((InstanceID)this, pReqQueryAccount, pRspInfo);
};

void cTraderApi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	if (vtCallback.onRtnRepealFromBankToFutureByFuture == NULL)
	{
		return;
	}

	vtCallback.onRtnRepealFromBankToFutureByFuture((InstanceID)this, pRspRepeal);
};

void cTraderApi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	if (vtCallback.onRtnRepealFromFutureToBankByFuture == NULL)
	{
		return;
	}

	vtCallback.onRtnRepealFromFutureToBankByFuture((InstanceID)this, pRspRepeal);
};

void cTraderApi::OnRspFromBankToFutureByFuture(
	CThostFtdcReqTransferField *pReqTransfer,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspFromBankToFutureByFuture == NULL)
	{
		return;
	}

	vtCallback.onRspFromBankToFutureByFuture((InstanceID)this, pReqTransfer, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspFromFutureToBankByFuture(
	CThostFtdcReqTransferField *pReqTransfer,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspFromFutureToBankByFuture == NULL)
	{
		return;
	}

	vtCallback.onRspFromFutureToBankByFuture((InstanceID)this, pReqTransfer, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRspQueryBankAccountMoneyByFuture(
	CThostFtdcReqQueryAccountField *pReqQueryAccount,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (vtCallback.onRspQueryBankAccountMoneyByFuture == NULL)
	{
		return;
	}

	vtCallback.onRspQueryBankAccountMoneyByFuture((InstanceID)this, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
};

void cTraderApi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount)
{
	if (vtCallback.onRtnOpenAccountByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnOpenAccountByBank((InstanceID)this, pOpenAccount);
};

void cTraderApi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount)
{
	if (vtCallback.onRtnCancelAccountByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnCancelAccountByBank((InstanceID)this, pCancelAccount);
};

void cTraderApi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount)
{
	if (vtCallback.onRtnChangeAccountByBank == NULL)
	{
		return;
	}

	vtCallback.onRtnChangeAccountByBank((InstanceID)this, pChangeAccount);
};
