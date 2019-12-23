// cTraderApi.cpp : 定义 DLL 应用程序的导出函数。
//

# include "ThostFtcTraderApiWrapper.h"

C_API void SetCallbackOnFrontConnected(InstanceID id, CbOnFrontConnected handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi*)id)->SetCallbackOnFrontConnected(handler);
};

C_API void SetCallbackOnFrontDisconnected(InstanceID id, CbOnFrontDisconnected handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnFrontDisconnected(handler);
};

C_API void SetCallbackOnHeartBeatWarning(InstanceID id, CbOnHeartBeatWarning handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnHeartBeartWarning(handler);
};

C_API void SetCallbackOnRspAuthenticate(InstanceID id, CbOnRspAuthenticate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspAuthenticate(handler);
};

C_API void SetCallbackOnRspUserLogin(InstanceID id, CbOnRspUserLogin handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspUserLogin(handler);
};

C_API void SetCallbackOnRspUserLogout(InstanceID id, CbOnRspUserLogout handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspUserLogout(handler);
};

C_API void SetCallbackOnRspUserPasswordUpdate(InstanceID id, CbOnRspUserPasswordUpdate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspUserPasswordUpdate(handler);
};

C_API void SetCallbackOnRspTradingAccountPasswordUpdate(
	InstanceID id, CbOnRspTradingAccountPasswordUpdate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspTradingAccountPasswordUpdate(handler);
};

C_API void SetCallbackOnRspOrderInsert(InstanceID id, CbOnRspOrderInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOrderInsert(handler);
};

C_API void SetCallbackOnRspParkedOrderInsert(InstanceID id, CbOnRspParkedOrderInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspParkedOrderInsert(handler);
};

C_API void SetCallbackOnRspParkedOrderAction(InstanceID id, CbOnRspParkedOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspParketOrderAction(handler);
};

C_API void SetCallbackOnRspOrderAction(InstanceID id, CbOnRspOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOrderAction(handler);
};

C_API void SetCallbackOnRspQueryMaxOrderVolume(InstanceID id, CbOnRspQueryMaxOrderVolume handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQueryMaxOrderVolume(handler);
};

C_API void SetCallbackOnRspSettlementInfoConfirm(InstanceID id, CbOnRspSettlementInfoConfirm handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspSettlementInfoConfirm(handler);
};

C_API void SetCallbackOnRspRemoveParkedOrder(InstanceID id, CbOnRspRemoveParkedOrder handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspRemoveParketOrder(handler);
};

C_API void SetCallbackOnRspRemoveParkedOrderAction(InstanceID id, CbOnRspRemoveParkedOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspRemoveParkedOrderAction(handler);
};

C_API void SetCallbackOnRspExecOrderInsert(InstanceID id, CbOnRspExecOrderInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspExecOrderInsert(handler);
};

C_API void SetCallbackOnRspExecOrderAction(InstanceID id, CbOnRspExecOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspExecOrderAction(handler);
};

C_API void SetCallbackOnRspForQuoteInsert(InstanceID id, CbOnRspForQuoteInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspForQuoteInsert(handler);
};

C_API void SetCallbackOnRspQuoteInsert(InstanceID id, CbOnRspQuoteInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQuoteInsert(handler);
};

C_API void SetCallbackOnRspQuoteAction(InstanceID id, CbOnRspQuoteAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQuoteAction(handler);
};

C_API void SetCallbackOnRspBatchOrderAction(InstanceID id, CbOnRspBatchOrderAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspBatchOrderAction(handler);
};

C_API void SetCallbackOnRspOptionSelfCloseInsert(InstanceID id, CbOnRspOptionSelfCloseInsert handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOptionSelfCloseInsert(handler);
};

C_API void SetCallbackOnRspOptionSelfCloseAction(InstanceID id, CbOnRspOptionSelfCloseAction handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspOptioinSelfCloseAction(handler);
};

C_API void SetCallbackOnRspTransFund(InstanceID id, CbOnRspTransFund handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspTransFund(handler);
};

C_API void SetCallbackOnRspQryOrder(InstanceID id, CbOnRspQryOrder handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOrder(handler);
};

C_API void SetCallbackOnRspQryTrade(InstanceID id, CbOnRspQryTrade handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTrade(handler);
};

C_API void SetCallbackOnRspQryInvestorPosition(InstanceID id, CbOnRspQryInvestorPosition handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorPosition(handler);
};

C_API void SetCallbackOnRspQryTradingAccount(InstanceID id, CbOnRspQryTradingAccount handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTradingAccount(handler);
};

C_API void SetCallbackOnRspQryInvestor(InstanceID id, CbOnRspQryInvestor handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestor(handler);
};

C_API void SetCallbackOnRspQryTradingCode(InstanceID id, CbOnRspQryTradingCode handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTradingCode(handler);
};

C_API void SetCallbackOnRspQryInstrumentMarginRate(InstanceID id, CbOnRspQryInstrumentMarginRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrumentMarginRate(handler);
};

C_API void SetCallbackOnRspQryInstrumentCommissionRate(
	InstanceID id, CbOnRspQryInstrumentCommissionRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrumentCommissionRate(handler);
};

C_API void SetCallbackOnRspQryExchange(InstanceID id, CbOnRspQryExchange handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchange(handler);
};

C_API void SetCallbackOnRspQryProduct(InstanceID id, CbOnRspQryProduct handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryProduct(handler);
};

C_API void SetCallbackOnRspQryInstrument(InstanceID id, CbOnRspQryInstrument handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrument(handler);
};

C_API void SetCallbackOnRspQryDepthMarketData(InstanceID id, CbOnRspQryDepthMarketData handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryDepthMarketData(handler);
};

C_API void SetCallbackOnRspQrySettlementInfo(InstanceID id, CbOnRspQrySettlementInfo handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQrySettlementInfo(handler);
};

C_API void SetCallbackOnRspQryInstrumentStatus(InstanceID id, CbOnRspQryInstrumentStatus handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInstrumentStatus(handler);
};

C_API void SetCallbackOnRspQryTransferBank(InstanceID id, CbOnRspQryTransferBank handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTransferBank(handler);
};

C_API void SetCallbackOnRspQryInvestorPositionDetail(
	InstanceID id, CbOnRspQryInvestorPositionDetail handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorPositionDetail(handler);
};

C_API void SetCallbackOnRspQryNotice(InstanceID id, CbOnRspQryNotice handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryNotice(handler);
};

C_API void SetCallbackOnRspQrySettlementInfoConfirm(InstanceID id, CbOnRspQrySettlementInfoConfirm handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQrySettlementInfoConfirm(handler);
};

C_API void SetCallbackOnRspQryInvestorPositionCombineDetail(
	InstanceID id, CbOnRspQryInvestorPositionCombineDetail handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorPositionCombineDetail(handler);
};

C_API void SetCallbackOnRspQryCFMMCTradingAccountKey(
	InstanceID id, CbOnRspQryCFMMCTradingAccountKey handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryCFMMCTradingAccountKey(handler);
};

C_API void SetCallbackOnRspQryEWarrantOffset(InstanceID id, CbOnRspQryEWarrantOffset handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryEWarrantOffset(handler);
};

C_API void SetCallbackOnRspQryInvestorProductGroupMargin(
	InstanceID id, CbOnRspQryInvestorProductGroupMargin handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryInvestorProductGroupMargin(handler);
};

C_API void SetCallbackOnRspQryExchangeMarginRate(InstanceID id, CbOnRspQryExchangeMarginRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchangeMarginRate(handler);
};

C_API void SetCallbackOnRspQryExchangeMarginRateAdjust(
	InstanceID id, CbOnRspQryExchangeMarginRateAdjust handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchangeMarginRateAdjust(handler);
};

C_API void SetCallbackOnRspQryExchangeRate(InstanceID id, CbOnRspQryExchangeRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExchangeRate(handler);
};

C_API void SetCallbackOnRspQrySecAgentACIDMap(InstanceID id, CbOnRspQrySecAgentACIDMap handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQrySecAgentACIDMap(handler);
};

C_API void SetCallbackOnRspQryOptionInstrTradeCost(InstanceID id, CbOnRspQryOptionInstrTradeCost handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOptionInstrTradeCost(handler);
};

C_API void SetCallbackOnRspQryOptionInstrCommRate(InstanceID id, CbOnRspQryOptionInstrCommRate handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOptionInstrCommRate(handler);
};

C_API void SetCallbackOnRspQryExecOrder(InstanceID id, CbOnRspQryExecOrder handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryExecOrder(handler);
};

C_API void SetCallbackOnRspQryForQuote(InstanceID id, CbOnRspQryForQuote handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryForQuote(handler);
};

C_API void SetCallbackOnRspQryQuote(InstanceID id, CbOnRspQryQuote handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryQuote(handler);
};

C_API void SetCallbackOnRspQryOptionSelfClose(InstanceID id, CbOnRspQryOptionSelfClose handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryOptionSelfClose(handler);
};

C_API void SetCallbackOnRspQryTransferSerial(InstanceID id, CbOnRspQryTransferSerial handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTransferSerial(handler);
};

C_API void SetCallbackOnRspQryAccountregister(InstanceID id, CbOnRspQryAccountregister handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryAccountregister(handler);
};

C_API void SetCallbackOnRspError(InstanceID id, CbOnRspError handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspError(handler);
};

C_API void SetCallbackOnRtnOrder(InstanceID id, CbOnRtnOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnOrder(handler);
};

C_API void SetCallbackOnRtnTrade(InstanceID id, CbOnRtnTrade handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnTrade(handler);
};

C_API void SetCallbackOnErrRtnOrderInsert(InstanceID id, CbOnErrRtnOrderInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOrderInsert(handler);
};

C_API void SetCallbackOnErrRtnOrderAction(InstanceID id, CbOnErrRtnOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOrderAction(handler);
};

C_API void SetCallbackOnRtnInstrumentStatus(InstanceID id, CbOnRtnInstrumentStatus handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnInstrumentStatus(handler);
};

C_API void SetCallbackOnRtnTradingNotice(InstanceID id, CbOnRtnTradingNotice handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnTradingNotice(handler);
};

C_API void SetCallbackOnRtnErrorConditionalOrder(InstanceID id, CbOnRtnErrorConditionalOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnErrorConditionalOrder(handler);
};

C_API void SetCallbackOnRtnExecOrder(InstanceID id, CbOnRtnExecOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnExecOrder(handler);
};

C_API void SetCallbackOnErrRtnExecOrderInsert(InstanceID id, CbOnErrRtnExecOrderInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnExecOrderInsert(handler);
};

C_API void SetCallbackOnErrRtnExecOrderAction(InstanceID id, CbOnErrRtnExecOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnExecOrderAction(handler);
};

C_API void SetCallbackOnErrRtnForQuoteInsert(InstanceID id, CbOnErrRtnForQuoteInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnForQuoteInsert(handler);
};

C_API void SetCallbackOnRtnQuote(InstanceID id, CbOnRtnQuote handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnQuote(handler);
};

C_API void SetCallbackOnErrRtnQuoteInsert(InstanceID id, CbOnErrRtnQuoteInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnQuoteInsert(handler);
};

C_API void SetCallbackOnErrRtnQuoteAction(InstanceID id, CbOnErrRtnQuoteAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnQuoteAction(handler);
};

C_API void SetCallbackOnRtnForQuoteRsp(InstanceID id, CbOnRtnForQuoteRsp handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnForQuoteRsp(handler);
};

C_API void SetCallbackOnErrRtnBatchOrderAction(InstanceID id, CbOnErrRtnBatchOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnBatchOrderAction(handler);
};

C_API void SetCallbackOnRtnOptionSelfClose(InstanceID id, CbOnRtnOptionSelfClose handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnOptionSelfClose(handler);
};

C_API void SetCallbackOnErrRtnOptionSelfCloseInsert(InstanceID id, CbOnErrRtnOptionSelfCloseInsert handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOptionSelfCloseInsert(handler);
};

C_API void SetCallbackOnErrRtnOptionSelfCloseAction(InstanceID id, CbOnErrRtnOptionSelfCloseAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnOptionSelfCloseAction(handler);
};

C_API void SetCallbackOnRspQryContractBank(InstanceID id, CbOnRspQryContractBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryContractBank(handler);
};

C_API void SetCallbackOnRspQryParkedOrder(InstanceID id, CbOnRspQryParkedOrder handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryParkedOrder(handler);
};

C_API void SetCallbackOnRspQryParkedOrderAction(InstanceID id, CbOnRspQryParkedOrderAction handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryparketOrderAction(handler);
};

C_API void SetCallbackOnRspQryTradingNotice(InstanceID id, CbOnRspQryTradingNotice handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryTradingNotice(handler);
};

C_API void SetCallbackOnRspQryBrokerTradingParams(InstanceID id, CbOnRspQryBrokerTradingParams handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryBrokerTradingParams(handler);
};

C_API void SetCallbackOnRspQRyBrokerTradingAlgos(InstanceID id, CbOnRspQryBrokerTradingAlgos handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQryBrokerTradingAlgos(handler);
};

C_API void SetCallbackOnRtnFromBankToFutureByBank(InstanceID id, CbOnRtnFromBankToFutureByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromBankToFutureByBank(handler);
};

C_API void SetCallbackOnRtnFromFutureToBankByBank(InstanceID id, CbOnRtnFromFutureToBankByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromFutureToBankByBank(handler);
};

C_API void SetCallbackOnRtnRepealFromBankToFutureByBank(
	InstanceID id, CbOnRtnRepealFromBankToFutureByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromBankToFutureByBank(handler);
};

C_API void SetCallbackOnRtnRepealFromFutureToBankByBank(
	InstanceID id, CbOnRtnRepealFromFutureToBankByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromFutureToBankByBank(handler);
};

C_API void SetCallbackOnRtnFromBankToFutureByFuture(InstanceID id, CbOnRtnFromBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromBankToFutureByFuture(handler);
};

C_API void SetCallbackOnRtnFromFutureToBankByFuture(InstanceID id, CbOnRtnFromFutureToBankByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnFromFutureToBankByFuture(handler);
};

C_API void SetCallbackOnRtnRepealFromBankToFutureByFutureManual(
	InstanceID id, CbOnRtnRepealFromBankToFutureByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromBankToFutureByFutureManual(handler);
};

C_API void SetCallbackOnRtnRepealFromFutureToBankByFutureManual(
	InstanceID id, CbOnRtnRepealFromFutureToBankByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromFutureToBankByFutureManual(handler);
};

C_API void SetCallbackOnRtnQueryBankBalanceByFuture(InstanceID id, CbOnRtnQueryBankBalanceByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnQueryBankBalanceByFuture(handler);
};

C_API void SetCallbackOnErrRtnBankToFutureByFuture(InstanceID id, CbOnErrRtnBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnBankToFutureByFuture(handler);
};

C_API void SetCallbackOnErrRtnFutureToBankByFuture(InstanceID id, CbOnErrRtnFutureToBankByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnFutureToBankByFuture(handler);
};

C_API void SetCallbackOnErrRtnRepealBankToFutureByFutureManual(
	InstanceID id, CbOnErrRtnRepealBankToFutureByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnRepealBankToFutureByFutureManual(handler);
};

C_API void SetCallbackOnErrRtnRepealFutureToBankByFutureManual(
	InstanceID id, CbOnErrRtnRepealFutureToBankByFutureManual handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnRepealFutureToBankByFutureManual(handler);
};

C_API void SetCallbackOnErrRtnQueryBankBalanceByFuture(
	InstanceID id, CbOnErrRtnQueryBankBalanceByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnErrRtnQueryBankBalanceByFuture(handler);
};

C_API void SetCallbackOnRtnRepealFromBankToFutureByFuture(
	InstanceID id, CbOnRtnRepealFromBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnRepealFromBankToFutureByFuture(handler);
};

C_API void SetCallbackOnRtnRepealFromFutureToBankByFuture(
	InstanceID id, CbOnRtnRepealFromFutureToBankByFuture handler)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi*)id)->SetCallbackOnRtnRepealFromBankToFutureByFuture(handler);
};

C_API void SetCallbackOnRspFromBankToFutureByFuture(InstanceID id, CbOnRspFromBankToFutureByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspFromBankToFutureByFuture(handler);
};

C_API void SetCallbackOnRspFromFutureToBankByFuture(InstanceID id, CbOnRspFromFutureToBankByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspFromFutureToBankByFuture(handler);
};

C_API void SetCallbackOnRspQueryBankAccountMoneyByFuture(
	InstanceID id, CbOnRspQueryBankAccountMoneyByFuture handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRspQueryBankAccountMoneyByFuture(handler);
};

C_API void SetCallbackOnRtnOpenAccountByBank(InstanceID id, CbOnRtnOpenAccountByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnOpenAccountByBank(handler);
};

C_API void SetCallbackOnRtnCancelAccountByBank(InstanceID id, CbOnRtnCancelAccountByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnCancelAccountByBank(handler);
};

C_API void SetCallbackOnRtnChangeAccountByBank(InstanceID id, CbOnRtnChangeAccountByBank handler)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackOnRtnChangeAccountByBank(handler);
};

C_API void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SetCallbackVirtualTable(vt);
};

C_API InstanceID CreateApi()
{
	cTraderApi *api = new cTraderApi;
	return (InstanceID)api;
};

C_API const char *GetApiVersion()
{
	return cTraderApi::GetApiVersion();
};

C_API void Release(InstanceID id)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->Release();
};

C_API void Init(InstanceID id, const char *pszFlowPath, bool bContinuous)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->Init(pszFlowPath, bContinuous);
};

C_API int Join(InstanceID id)
{
	if (id == NULL) {
		throw id;
	}

	return ((cTraderApi *)id)->Join();
};

C_API const char *GetTradingDay(InstanceID id)
{
	if (id == NULL) {
		throw id;
	}

	return ((cTraderApi *)id)->GetTradingDay();
};

C_API void RegisterFront(InstanceID id, char *pszFrontAddress)
{
	if (id == NULL) {
		throw id;
	}

	((cTraderApi *)id)->RegisterFront(pszFrontAddress);
};

C_API void RegisterNameServer(InstanceID id, char *pszNsAddress)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->RegisterNameServer(pszNsAddress);
};

C_API void RegisterFensUserInfo(InstanceID id, CThostFtdcFensUserInfoField *pFensUserInfo)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->RegisterFensUserInfo(pFensUserInfo);
};

C_API void SubscribePrivateTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SubscribePrivateTopic(nResumeType);
};

C_API void SubscribePublicTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType)
{
	if (id == NULL)
	{
		throw id;
	}

	((cTraderApi *)id)->SubscribePublicTopic(nResumeType);
};

C_API int ReqAuthenticate(InstanceID id, CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqAuthenticate(pReqAuthenticateField, nRequestID);
};

C_API int ReqUserLogin(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserLogin(pReqUserLoginField, nRequestID);
};

C_API int ReqUserLoginEncrypt(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserLoginEncrypt(pReqUserLoginField, nRequestID);
};

C_API int ReqUserLogout(InstanceID id, CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserLogout(pUserLogout, nRequestID);
};

C_API int ReqUserPasswordUpdate(
	InstanceID id, CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
};

C_API int ReqTradingAccountPasswordUpdate(
	InstanceID id, CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
};

C_API int ReqOrderInsert(InstanceID id, CThostFtdcInputOrderField *pInputOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOrderInsert(pInputOrder, nRequestID);
};

C_API int ReqParkedOrderInsert(InstanceID id, CThostFtdcParkedOrderField *pParkedOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqParkedOrderInsert(pParkedOrder, nRequestID);
};

C_API int ReqParkedOrderAction(
	InstanceID id, CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
};

C_API int ReqOrderAction(InstanceID id, CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOrderAction(pInputOrderAction, nRequestID);
};

C_API int C_API ReqQueryMaxOrderVolume(
	InstanceID id, CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQueryMaxOrderVolume(pQueryMaxOrderVolume, nRequestID);
};

C_API int ReqSettlementInfoConfirm(
	InstanceID id, CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
};

C_API int ReqRemoveParkedOrder(
	InstanceID id, CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
};

C_API int ReqRemoveParkedOrderAction(
	InstanceID id, CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
};

C_API int ReqExecOrderInsert(InstanceID id, CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqExecOrderInsert(pInputExecOrder, nRequestID);
};

C_API int ReqExecOrderAction(
	InstanceID id, CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
};

C_API int ReqForQuoteInsert(InstanceID id, CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqForQuoteInsert(pInputForQuote, nRequestID);
};

C_API int ReqQuoteInsert(InstanceID id, CThostFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQuoteInsert(pInputQuote, nRequestID);
};

C_API int ReqQuoteAction(InstanceID id, CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQuoteAction(pInputQuoteAction, nRequestID);
};

C_API int ReqBatchOrderAction(
	InstanceID id, CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
};

C_API int ReqOptionSelfCloseInsert(
	InstanceID id, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
};

C_API int ReqOptionSelfCloseAction(
	InstanceID id, CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
};

C_API int ReqTransFund(InstanceID id, CThostFtdcTransFundField *pFtdcTransFund, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqTransFund(pFtdcTransFund, nRequestID);
};

C_API int ReqQryOrder(InstanceID id, CThostFtdcQryOrderField *pQryOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOrder(pQryOrder, nRequestID);
};

C_API int ReqQryTrade(InstanceID id, CThostFtdcQryTradeField *pQryTrade, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTrade(pQryTrade, nRequestID);
};

C_API int ReqQryInvestorPosition(
	InstanceID id, CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
};

C_API int ReqQryTradingAccount(
	InstanceID id, CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
};

C_API int ReqQryInvestor(InstanceID id, CThostFtdcQryInvestorField *pQryInvestor, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestor(pQryInvestor, nRequestID);
};

C_API int ReqQryTradingCode(InstanceID id, CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTradingCode(pQryTradingCode, nRequestID);
};

C_API int ReqQryInstrumentMarginRate(
	InstanceID id, CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
};

C_API int ReqQryInstrumentCommissionRate(
	InstanceID id, CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
};

C_API int ReqQryExchange(InstanceID id, CThostFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchange(pQryExchange, nRequestID);
};

C_API int ReqQryProduct(InstanceID id, CThostFtdcQryProductField *pQryProduct, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryProduct(pQryProduct, nRequestID);
};

C_API int ReqQryInstrument(InstanceID id, CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrument(pQryInstrument, nRequestID);
};

C_API int ReqQryDepthMarketData(
	InstanceID id, CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
};

C_API int ReqQryOptionSelfClose(
	InstanceID id, CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
};

C_API int ReqQrySettlementInfo(
	InstanceID id, CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
};

C_API int ReqQryInstrumentStatus(
	InstanceID id, CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInstrumentStatus(pQryInstrumentStatus, nRequestID);
};

C_API int ReqQryTransferBank(InstanceID id, CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTransferBank(pQryTransferBank, nRequestID);
};

C_API int ReqQryInvestorPositionDetail(
	InstanceID id, CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
};

C_API int ReqQryNotice(InstanceID id, CThostFtdcQryNoticeField *pQryNotice, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryNotice(pQryNotice, nRequestID);
};

C_API int ReqQrySettlementInfoConfirm(
	InstanceID id, CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
};

C_API int ReqQryInvestorPositionCombineDetail(
	InstanceID id, CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
};

C_API int ReqQryCFMMCTradingAccountKey(
	InstanceID id, CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
};

C_API int ReqQryEWarrantOffset(
	InstanceID id, CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
};

C_API int ReqQryInvestorProductGroupMargin(
	InstanceID id, CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
};

C_API int ReqQryExchangeMarginRate(
	InstanceID id, CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
};

C_API int ReqQryExchangeMarginRateAdjust(
	InstanceID id, CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
};

C_API int ReqQryExchangeRate(InstanceID id, CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
};

C_API int ReqQrySecAgentACIDMap(
	InstanceID id, CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
};

C_API int ReqQryOptionInstrTradeCost(
	InstanceID id, CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
};

C_API int ReqQryOptionInstrCommRate(
	InstanceID id, CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
};

C_API int ReqQryExecOrder(InstanceID id, CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryExecOrder(pQryExecOrder, nRequestID);
};

C_API int ReqQryForQuote(InstanceID id, CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryForQuote(pQryForQuote, nRequestID);
};

C_API int ReqQryQuote(InstanceID id, CThostFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryQuote(pQryQuote, nRequestID);
};

C_API int ReqQryTransferSerial(
	InstanceID id, CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
};

C_API int ReqQryAccountregister(
	InstanceID id, CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryAccountregister(pQryAccountregister, nRequestID);
};

C_API int ReqQryContractBank(InstanceID id, CThostFtdcQryContractBankField *pQryContractBank, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryContractBank(pQryContractBank, nRequestID);
};

C_API int ReqQryParkedOrder(InstanceID id, CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
};

C_API int ReqQryParkedOrderAction(
	InstanceID id, CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
};

C_API int ReqQryTradingNotice(InstanceID id, CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
};

C_API int ReqQryBrokerTradingParams(
	InstanceID id, CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
};

C_API int ReqQryBrokerTradingAlgos(
	InstanceID id, CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
};

C_API int ReqFromBankToFutureByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
};

C_API int ReqFromFutureToBankByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
};

C_API int ReqQueryBankAccountMoneyByFuture(
	InstanceID id, CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID)
{
	if (id == NULL)
	{
		throw id;
	}

	return ((cTraderApi *)id)->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
};

