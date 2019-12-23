// cTraderApi.cpp : 定义 DLL 应用程序的导出函数。
//

# include "ThostFtcTraderApiWrapper.h"

C_API_EXPORT void SetCallbackOnFrontConnected(InstanceID id, CbOnFrontConnected handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi*)id)->SetCallbackOnFrontConnected(handler);
};

C_API_EXPORT void SetCallbackOnFrontDisconnected(InstanceID id, CbOnFrontDisconnected handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnFrontDisconnected(handler);
};

C_API_EXPORT void SetCallbackOnHeartBeatWarning(InstanceID id, CbOnHeartBeatWarning handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnHeartBeartWarning(handler);
};

C_API_EXPORT void SetCallbackOnRspAuthenticate(InstanceID id, CbOnRspAuthenticate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspAuthenticate(handler);
};

C_API_EXPORT void SetCallbackOnRspUserLogin(InstanceID id, CbOnRspUserLogin handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspUserLogin(handler);
};

C_API_EXPORT void SetCallbackOnRspUserLogout(InstanceID id, CbOnRspUserLogout handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspUserLogout(handler);
};

C_API_EXPORT void SetCallbackOnRspUserPasswordUpdate(InstanceID id, CbOnRspUserPasswordUpdate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspUserPasswordUpdate(handler);
};

C_API_EXPORT void SetCallbackOnRspTradingAccountPasswordUpdate(
	InstanceID id, CbOnRspTradingAccountPasswordUpdate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspTradingAccountPasswordUpdate(handler);
};

C_API_EXPORT void SetCallbackOnRspOrderInsert(InstanceID id, CbOnRspOrderInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOrderInsert(handler);
};

C_API_EXPORT void SetCallbackOnRspParkedOrderInsert(InstanceID id, CbOnRspParkedOrderInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspParkedOrderInsert(handler);
};

C_API_EXPORT void SetCallbackOnRspParkedOrderAction(InstanceID id, CbOnRspParkedOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspParketOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRspOrderAction(InstanceID id, CbOnRspOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRspQueryMaxOrderVolume(InstanceID id, CbOnRspQueryMaxOrderVolume handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQueryMaxOrderVolume(handler);
};

C_API_EXPORT void SetCallbackOnRspSettlementInfoConfirm(InstanceID id, CbOnRspSettlementInfoConfirm handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspSettlementInfoConfirm(handler);
};

C_API_EXPORT void SetCallbackOnRspRemoveParkedOrder(InstanceID id, CbOnRspRemoveParkedOrder handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspRemoveParketOrder(handler);
};

C_API_EXPORT void SetCallbackOnRspRemoveParkedOrderAction(InstanceID id, CbOnRspRemoveParkedOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspRemoveParkedOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRspExecOrderInsert(InstanceID id, CbOnRspExecOrderInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspExecOrderInsert(handler);
};

C_API_EXPORT void SetCallbackOnRspExecOrderAction(InstanceID id, CbOnRspExecOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspExecOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRspForQuoteInsert(InstanceID id, CbOnRspForQuoteInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspForQuoteInsert(handler);
};

C_API_EXPORT void SetCallbackOnRspQuoteInsert(InstanceID id, CbOnRspQuoteInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQuoteInsert(handler);
};

C_API_EXPORT void SetCallbackOnRspQuoteAction(InstanceID id, CbOnRspQuoteAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQuoteAction(handler);
};

C_API_EXPORT void SetCallbackOnRspBatchOrderAction(InstanceID id, CbOnRspBatchOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspBatchOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRspOptionSelfCloseInsert(InstanceID id, CbOnRspOptionSelfCloseInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOptionSelfCloseInsert(handler);
};

C_API_EXPORT void SetCallbackOnRspOptionSelfCloseAction(InstanceID id, CbOnRspOptionSelfCloseAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOptioinSelfCloseAction(handler);
};

C_API_EXPORT void SetCallbackOnRspTransFund(InstanceID id, CbOnRspTransFund handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspTransFund(handler);
};

C_API_EXPORT void SetCallbackOnRspQryOrder(InstanceID id, CbOnRspQryOrder handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOrder(handler);
};

C_API_EXPORT void SetCallbackOnRspQryTrade(InstanceID id, CbOnRspQryTrade handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTrade(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInvestorPosition(InstanceID id, CbOnRspQryInvestorPosition handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorPosition(handler);
};

C_API_EXPORT void SetCallbackOnRspQryTradingAccount(InstanceID id, CbOnRspQryTradingAccount handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTradingAccount(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInvestor(InstanceID id, CbOnRspQryInvestor handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestor(handler);
};

C_API_EXPORT void SetCallbackOnRspQryTradingCode(InstanceID id, CbOnRspQryTradingCode handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTradingCode(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInstrumentMarginRate(InstanceID id, CbOnRspQryInstrumentMarginRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrumentMarginRate(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInstrumentCommissionRate(
	InstanceID id, CbOnRspQryInstrumentCommissionRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrumentCommissionRate(handler);
};

C_API_EXPORT void SetCallbackOnRspQryExchange(InstanceID id, CbOnRspQryExchange handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchange(handler);
};

C_API_EXPORT void SetCallbackOnRspQryProduct(InstanceID id, CbOnRspQryProduct handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryProduct(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInstrument(InstanceID id, CbOnRspQryInstrument handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrument(handler);
};

C_API_EXPORT void SetCallbackOnRspQryDepthMarketData(InstanceID id, CbOnRspQryDepthMarketData handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryDepthMarketData(handler);
};

C_API_EXPORT void SetCallbackOnRspQrySettlementInfo(InstanceID id, CbOnRspQrySettlementInfo handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQrySettlementInfo(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInstrumentStatus(InstanceID id, CbOnRspQryInstrumentStatus handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrumentStatus(handler);
};

C_API_EXPORT void SetCallbackOnRspQryTransferBank(InstanceID id, CbOnRspQryTransferBank handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTransferBank(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInvestorPositionDetail(
	InstanceID id, CbOnRspQryInvestorPositionDetail handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorPositionDetail(handler);
};

C_API_EXPORT void SetCallbackOnRspQryNotice(InstanceID id, CbOnRspQryNotice handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryNotice(handler);
};

C_API_EXPORT void SetCallbackOnRspQrySettlementInfoConfirm(InstanceID id, CbOnRspQrySettlementInfoConfirm handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQrySettlementInfoConfirm(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInvestorPositionCombineDetail(
	InstanceID id, CbOnRspQryInvestorPositionCombineDetail handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorPositionCombineDetail(handler);
};

C_API_EXPORT void SetCallbackOnRspQryCFMMCTradingAccountKey(
	InstanceID id, CbOnRspQryCFMMCTradingAccountKey handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryCFMMCTradingAccountKey(handler);
};

C_API_EXPORT void SetCallbackOnRspQryEWarrantOffset(InstanceID id, CbOnRspQryEWarrantOffset handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryEWarrantOffset(handler);
};

C_API_EXPORT void SetCallbackOnRspQryInvestorProductGroupMargin(
	InstanceID id, CbOnRspQryInvestorProductGroupMargin handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorProductGroupMargin(handler);
};

C_API_EXPORT void SetCallbackOnRspQryExchangeMarginRate(InstanceID id, CbOnRspQryExchangeMarginRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchangeMarginRate(handler);
};

C_API_EXPORT void SetCallbackOnRspQryExchangeMarginRateAdjust(
	InstanceID id, CbOnRspQryExchangeMarginRateAdjust handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchangeMarginRateAdjust(handler);
};

C_API_EXPORT void SetCallbackOnRspQryExchangeRate(InstanceID id, CbOnRspQryExchangeRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchangeRate(handler);
};

C_API_EXPORT void SetCallbackOnRspQrySecAgentACIDMap(InstanceID id, CbOnRspQrySecAgentACIDMap handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQrySecAgentACIDMap(handler);
};

C_API_EXPORT void SetCallbackOnRspQryOptionInstrTradeCost(InstanceID id, CbOnRspQryOptionInstrTradeCost handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOptionInstrTradeCost(handler);
};

C_API_EXPORT void SetCallbackOnRspQryOptionInstrCommRate(InstanceID id, CbOnRspQryOptionInstrCommRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOptionInstrCommRate(handler);
};

C_API_EXPORT void SetCallbackOnRspQryExecOrder(InstanceID id, CbOnRspQryExecOrder handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExecOrder(handler);
};

C_API_EXPORT void SetCallbackOnRspQryForQuote(InstanceID id, CbOnRspQryForQuote handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryForQuote(handler);
};

C_API_EXPORT void SetCallbackOnRspQryQuote(InstanceID id, CbOnRspQryQuote handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryQuote(handler);
};

C_API_EXPORT void SetCallbackOnRspQryOptionSelfClose(InstanceID id, CbOnRspQryOptionSelfClose handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOptionSelfClose(handler);
};

C_API_EXPORT void SetCallbackOnRspQryTransferSerial(InstanceID id, CbOnRspQryTransferSerial handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTransferSerial(handler);
};

C_API_EXPORT void SetCallbackOnRspQryAccountregister(InstanceID id, CbOnRspQryAccountregister handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryAccountregister(handler);
};

C_API_EXPORT void SetCallbackOnRspError(InstanceID id, CbOnRspError handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspError(handler);
};

C_API_EXPORT void SetCallbackOnRtnOrder(InstanceID id, CbOnRtnOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnOrder(handler);
};

C_API_EXPORT void SetCallbackOnRtnTrade(InstanceID id, CbOnRtnTrade handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnTrade(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnOrderInsert(InstanceID id, CbOnErrRtnOrderInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOrderInsert(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnOrderAction(InstanceID id, CbOnErrRtnOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRtnInstrumentStatus(InstanceID id, CbOnRtnInstrumentStatus handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnInstrumentStatus(handler);
};

C_API_EXPORT void SetCallbackOnRtnTradingNotice(InstanceID id, CbOnRtnTradingNotice handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnTradingNotice(handler);
};

C_API_EXPORT void SetCallbackOnRtnErrorConditionalOrder(InstanceID id, CbOnRtnErrorConditionalOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnErrorConditionalOrder(handler);
};

C_API_EXPORT void SetCallbackOnRtnExecOrder(InstanceID id, CbOnRtnExecOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnExecOrder(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnExecOrderInsert(InstanceID id, CbOnErrRtnExecOrderInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnExecOrderInsert(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnExecOrderAction(InstanceID id, CbOnErrRtnExecOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnExecOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnForQuoteInsert(InstanceID id, CbOnErrRtnForQuoteInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnForQuoteInsert(handler);
};

C_API_EXPORT void SetCallbackOnRtnQuote(InstanceID id, CbOnRtnQuote handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnQuote(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnQuoteInsert(InstanceID id, CbOnErrRtnQuoteInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnQuoteInsert(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnQuoteAction(InstanceID id, CbOnErrRtnQuoteAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnQuoteAction(handler);
};

C_API_EXPORT void SetCallbackOnRtnForQuoteRsp(InstanceID id, CbOnRtnForQuoteRsp handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnForQuoteRsp(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnBatchOrderAction(InstanceID id, CbOnErrRtnBatchOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnBatchOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRtnOptionSelfClose(InstanceID id, CbOnRtnOptionSelfClose handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnOptionSelfClose(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnOptionSelfCloseInsert(InstanceID id, CbOnErrRtnOptionSelfCloseInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOptionSelfCloseInsert(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnOptionSelfCloseAction(InstanceID id, CbOnErrRtnOptionSelfCloseAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOptionSelfCloseAction(handler);
};

C_API_EXPORT void SetCallbackOnRspQryContractBank(InstanceID id, CbOnRspQryContractBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryContractBank(handler);
};

C_API_EXPORT void SetCallbackOnRspQryParkedOrder(InstanceID id, CbOnRspQryParkedOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryParkedOrder(handler);
};

C_API_EXPORT void SetCallbackOnRspQryParkedOrderAction(InstanceID id, CbOnRspQryParkedOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryparketOrderAction(handler);
};

C_API_EXPORT void SetCallbackOnRspQryTradingNotice(InstanceID id, CbOnRspQryTradingNotice handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTradingNotice(handler);
};

C_API_EXPORT void SetCallbackOnRspQryBrokerTradingParams(InstanceID id, CbOnRspQryBrokerTradingParams handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryBrokerTradingParams(handler);
};

C_API_EXPORT void SetCallbackOnRspQRyBrokerTradingAlgos(InstanceID id, CbOnRspQryBrokerTradingAlgos handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryBrokerTradingAlgos(handler);
};

C_API_EXPORT void SetCallbackOnRtnFromBankToFutureByBank(InstanceID id, CbOnRtnFromBankToFutureByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromBankToFutureByBank(handler);
};

C_API_EXPORT void SetCallbackOnRtnFromFutureToBankByBank(InstanceID id, CbOnRtnFromFutureToBankByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromFutureToBankByBank(handler);
};

C_API_EXPORT void SetCallbackOnRtnRepealFromBankToFutureByBank(
	InstanceID id, CbOnRtnRepealFromBankToFutureByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromBankToFutureByBank(handler);
};

C_API_EXPORT void SetCallbackOnRtnRepealFromFutureToBankByBank(
	InstanceID id, CbOnRtnRepealFromFutureToBankByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromFutureToBankByBank(handler);
};

C_API_EXPORT void SetCallbackOnRtnFromBankToFutureByFuture(InstanceID id, CbOnRtnFromBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromBankToFutureByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRtnFromFutureToBankByFuture(InstanceID id, CbOnRtnFromFutureToBankByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromFutureToBankByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRtnRepealFromBankToFutureByFutureManual(
	InstanceID id, CbOnRtnRepealFromBankToFutureByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromBankToFutureByFutureManual(handler);
};

C_API_EXPORT void SetCallbackOnRtnRepealFromFutureToBankByFutureManual(
	InstanceID id, CbOnRtnRepealFromFutureToBankByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromFutureToBankByFutureManual(handler);
};

C_API_EXPORT void SetCallbackOnRtnQueryBankBalanceByFuture(InstanceID id, CbOnRtnQueryBankBalanceByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnQueryBankBalanceByFuture(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnBankToFutureByFuture(InstanceID id, CbOnErrRtnBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnBankToFutureByFuture(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnFutureToBankByFuture(InstanceID id, CbOnErrRtnFutureToBankByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnFutureToBankByFuture(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnRepealBankToFutureByFutureManual(
	InstanceID id, CbOnErrRtnRepealBankToFutureByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnRepealBankToFutureByFutureManual(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnRepealFutureToBankByFutureManual(
	InstanceID id, CbOnErrRtnRepealFutureToBankByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnRepealFutureToBankByFutureManual(handler);
};

C_API_EXPORT void SetCallbackOnErrRtnQueryBankBalanceByFuture(
	InstanceID id, CbOnErrRtnQueryBankBalanceByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnQueryBankBalanceByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRtnRepealFromBankToFutureByFuture(
	InstanceID id, CbOnRtnRepealFromBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromBankToFutureByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRtnRepealFromFutureToBankByFuture(
	InstanceID id, CbOnRtnRepealFromFutureToBankByFuture handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi*)id)->SetCallbackOnRtnRepealFromBankToFutureByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRspFromBankToFutureByFuture(InstanceID id, CbOnRspFromBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspFromBankToFutureByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRspFromFutureToBankByFuture(InstanceID id, CbOnRspFromFutureToBankByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspFromFutureToBankByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRspQueryBankAccountMoneyByFuture(
	InstanceID id, CbOnRspQueryBankAccountMoneyByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQueryBankAccountMoneyByFuture(handler);
};

C_API_EXPORT void SetCallbackOnRtnOpenAccountByBank(InstanceID id, CbOnRtnOpenAccountByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnOpenAccountByBank(handler);
};

C_API_EXPORT void SetCallbackOnRtnCancelAccountByBank(InstanceID id, CbOnRtnCancelAccountByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnCancelAccountByBank(handler);
};

C_API_EXPORT void SetCallbackOnRtnChangeAccountByBank(InstanceID id, CbOnRtnChangeAccountByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnChangeAccountByBank(handler);
};

C_API_EXPORT void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackVirtualTable(vt);
};

C_API_EXPORT InstanceID CreateApi()
{
	cTraderApi *api = new cTraderApi;
	return (InstanceID)api;
};

C_API_EXPORT const char *GetApiVersion()
{
	return cTraderApi::GetApiVersion();
};

C_API_EXPORT void Release(InstanceID id)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->Release();
};

C_API_EXPORT void Init(InstanceID id, const char *pszFlowPath, bool bContinuous)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->Init(pszFlowPath, bContinuous);
};

C_API_EXPORT int Join(InstanceID id)
{
	if (id == NULL) {
		throw id;
	}

	return ((cTraderApi *)id)->Join();
};

C_API_EXPORT const char *GetTradingDay(InstanceID id)
{
	if (id == NULL) {
		throw id;
	}

	return ((cTraderApi *)id)->GetTradingDay();
};

C_API_EXPORT void RegisterFront(InstanceID id, char *pszFrontAddress)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->RegisterFront(pszFrontAddress);
};

C_API_EXPORT void RegisterNameServer(InstanceID id, char *pszNsAddress)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->RegisterNameServer(pszNsAddress);
};

C_API_EXPORT void RegisterFensUserInfo(InstanceID id, CThostFtdcFensUserInfoField *pFensUserInfo)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->RegisterFensUserInfo(pFensUserInfo);
};

C_API_EXPORT void SubscribePrivateTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SubscribePrivateTopic(nResumeType);
};

C_API_EXPORT void SubscribePublicTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SubscribePublicTopic(nResumeType);
};

C_API_EXPORT int ReqAuthenticate(InstanceID id, CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqAuthenticate(pReqAuthenticateField, nRequestID);
};

C_API_EXPORT int ReqUserLogin(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserLogin(pReqUserLoginField, nRequestID);
};

C_API_EXPORT int ReqUserLoginEncrypt(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserLoginEncrypt(pReqUserLoginField, nRequestID);
};

C_API_EXPORT int ReqUserLogout(InstanceID id, CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserLogout(pUserLogout, nRequestID);
};

C_API_EXPORT int ReqUserPasswordUpdate(
	InstanceID id, CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
};

C_API_EXPORT int ReqTradingAccountPasswordUpdate(
	InstanceID id, CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
};

C_API_EXPORT int ReqOrderInsert(InstanceID id, CThostFtdcInputOrderField *pInputOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOrderInsert(pInputOrder, nRequestID);
};

C_API_EXPORT int ReqParkedOrderInsert(InstanceID id, CThostFtdcParkedOrderField *pParkedOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqParkedOrderInsert(pParkedOrder, nRequestID);
};

C_API_EXPORT int ReqParkedOrderAction(
	InstanceID id, CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
};

C_API_EXPORT int ReqOrderAction(InstanceID id, CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOrderAction(pInputOrderAction, nRequestID);
};

C_API_EXPORT int C_API_EXPORT ReqQueryMaxOrderVolume(
	InstanceID id, CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQueryMaxOrderVolume(pQueryMaxOrderVolume, nRequestID);
};

C_API_EXPORT int ReqSettlementInfoConfirm(
	InstanceID id, CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
};

C_API_EXPORT int ReqRemoveParkedOrder(
	InstanceID id, CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
};

C_API_EXPORT int ReqRemoveParkedOrderAction(
	InstanceID id, CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
};

C_API_EXPORT int ReqExecOrderInsert(InstanceID id, CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqExecOrderInsert(pInputExecOrder, nRequestID);
};

C_API_EXPORT int ReqExecOrderAction(
	InstanceID id, CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
};

C_API_EXPORT int ReqForQuoteInsert(InstanceID id, CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqForQuoteInsert(pInputForQuote, nRequestID);
};

C_API_EXPORT int ReqQuoteInsert(InstanceID id, CThostFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQuoteInsert(pInputQuote, nRequestID);
};

C_API_EXPORT int ReqQuoteAction(InstanceID id, CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQuoteAction(pInputQuoteAction, nRequestID);
};

C_API_EXPORT int ReqBatchOrderAction(
	InstanceID id, CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
};

C_API_EXPORT int ReqOptionSelfCloseInsert(
	InstanceID id, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
};

C_API_EXPORT int ReqOptionSelfCloseAction(
	InstanceID id, CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
};

C_API_EXPORT int ReqTransFund(InstanceID id, CThostFtdcTransFundField *pFtdcTransFund, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqTransFund(pFtdcTransFund, nRequestID);
};

C_API_EXPORT int ReqQryOrder(InstanceID id, CThostFtdcQryOrderField *pQryOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOrder(pQryOrder, nRequestID);
};

C_API_EXPORT int ReqQryTrade(InstanceID id, CThostFtdcQryTradeField *pQryTrade, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTrade(pQryTrade, nRequestID);
};

C_API_EXPORT int ReqQryInvestorPosition(
	InstanceID id, CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
};

C_API_EXPORT int ReqQryTradingAccount(
	InstanceID id, CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
};

C_API_EXPORT int ReqQryInvestor(InstanceID id, CThostFtdcQryInvestorField *pQryInvestor, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestor(pQryInvestor, nRequestID);
};

C_API_EXPORT int ReqQryTradingCode(InstanceID id, CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTradingCode(pQryTradingCode, nRequestID);
};

C_API_EXPORT int ReqQryInstrumentMarginRate(
	InstanceID id, CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
};

C_API_EXPORT int ReqQryInstrumentCommissionRate(
	InstanceID id, CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
};

C_API_EXPORT int ReqQryExchange(InstanceID id, CThostFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchange(pQryExchange, nRequestID);
};

C_API_EXPORT int ReqQryProduct(InstanceID id, CThostFtdcQryProductField *pQryProduct, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryProduct(pQryProduct, nRequestID);
};

C_API_EXPORT int ReqQryInstrument(InstanceID id, CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrument(pQryInstrument, nRequestID);
};

C_API_EXPORT int ReqQryDepthMarketData(
	InstanceID id, CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
};

C_API_EXPORT int ReqQryOptionSelfClose(
	InstanceID id, CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
};

C_API_EXPORT int ReqQrySettlementInfo(
	InstanceID id, CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
};

C_API_EXPORT int ReqQryInstrumentStatus(
	InstanceID id, CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrumentStatus(pQryInstrumentStatus, nRequestID);
};

C_API_EXPORT int ReqQryTransferBank(InstanceID id, CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTransferBank(pQryTransferBank, nRequestID);
};

C_API_EXPORT int ReqQryInvestorPositionDetail(
	InstanceID id, CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
};

C_API_EXPORT int ReqQryNotice(InstanceID id, CThostFtdcQryNoticeField *pQryNotice, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryNotice(pQryNotice, nRequestID);
};

C_API_EXPORT int ReqQrySettlementInfoConfirm(
	InstanceID id, CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
};

C_API_EXPORT int ReqQryInvestorPositionCombineDetail(
	InstanceID id, CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
};

C_API_EXPORT int ReqQryCFMMCTradingAccountKey(
	InstanceID id, CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
};

C_API_EXPORT int ReqQryEWarrantOffset(
	InstanceID id, CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
};

C_API_EXPORT int ReqQryInvestorProductGroupMargin(
	InstanceID id, CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
};

C_API_EXPORT int ReqQryExchangeMarginRate(
	InstanceID id, CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
};

C_API_EXPORT int ReqQryExchangeMarginRateAdjust(
	InstanceID id, CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
};

C_API_EXPORT int ReqQryExchangeRate(InstanceID id, CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
};

C_API_EXPORT int ReqQrySecAgentACIDMap(
	InstanceID id, CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
};

C_API_EXPORT int ReqQryOptionInstrTradeCost(
	InstanceID id, CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
};

C_API_EXPORT int ReqQryOptionInstrCommRate(
	InstanceID id, CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
};

C_API_EXPORT int ReqQryExecOrder(InstanceID id, CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExecOrder(pQryExecOrder, nRequestID);
};

C_API_EXPORT int ReqQryForQuote(InstanceID id, CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryForQuote(pQryForQuote, nRequestID);
};

C_API_EXPORT int ReqQryQuote(InstanceID id, CThostFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryQuote(pQryQuote, nRequestID);
};

C_API_EXPORT int ReqQryTransferSerial(
	InstanceID id, CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
};

C_API_EXPORT int ReqQryAccountregister(
	InstanceID id, CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryAccountregister(pQryAccountregister, nRequestID);
};

C_API_EXPORT int ReqQryContractBank(InstanceID id, CThostFtdcQryContractBankField *pQryContractBank, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryContractBank(pQryContractBank, nRequestID);
};

C_API_EXPORT int ReqQryParkedOrder(InstanceID id, CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
};

C_API_EXPORT int ReqQryParkedOrderAction(
	InstanceID id, CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
};

C_API_EXPORT int ReqQryTradingNotice(InstanceID id, CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
};

C_API_EXPORT int ReqQryBrokerTradingParams(
	InstanceID id, CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
};

C_API_EXPORT int ReqQryBrokerTradingAlgos(
	InstanceID id, CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
};

C_API_EXPORT int ReqFromBankToFutureByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
};

C_API_EXPORT int ReqFromFutureToBankByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
};

C_API_EXPORT int ReqQueryBankAccountMoneyByFuture(
	InstanceID id, CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
};

