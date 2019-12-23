#include <stdint.h>

#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"

#ifdef __GNUC__
#ifdef CTRADERAPI_EXPORTS
#define C_API __attribute__((dllexport))
#else
#define C_API __attribute__((dllimport))
#endif
#else
#ifdef CTRADERAPI_EXPORTS
#define C_API __declspec(dllexport)
#else
#define C_API __declspec(dllimport)
#endif
#endif

#ifndef _WIN32
#define __stdcall
#endif
#define APPWINAPI __stdcall

#ifdef __cplusplus
#define NULL 0
extern "C"
{
#else
#define NULL ((void *)0)
#endif
	// C API instance id
	typedef uintptr_t InstanceID;

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	typedef void (APPWINAPI *CbOnFrontConnected)(InstanceID id);
	C_API void SetCallbackOnFrontConnected(InstanceID id, CbOnFrontConnected handler);

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	typedef void (APPWINAPI *CbOnFrontDisconnected)(InstanceID id, int nReason);
	C_API void SetCallbackOnFrontDisconnected(InstanceID id, CbOnFrontDisconnected handler);

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	typedef void (APPWINAPI *CbOnHeartBeatWarning)(InstanceID id, int nTimeLapse);
	C_API void SetCallbackOnHeartBeatWarning(InstanceID id, CbOnHeartBeatWarning handler);

	///客户端认证响应
	typedef void (APPWINAPI *CbOnRspAuthenticate)(
		InstanceID id,
		CThostFtdcRspAuthenticateField *pRspAuthenticateField,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspAuthenticate(InstanceID id, CbOnRspAuthenticate handler);

	///登录请求响应
	typedef void (APPWINAPI *CbOnRspUserLogin)(
		InstanceID id,
		CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspUserLogin(InstanceID id, CbOnRspUserLogin handler);

	///登出请求响应
	typedef void (APPWINAPI *CbOnRspUserLogout)(
		InstanceID id,
		CThostFtdcUserLogoutField *pUserLogout,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspUserLogout(InstanceID id, CbOnRspUserLogout handler);

	///用户口令更新请求响应
	typedef void (APPWINAPI *CbOnRspUserPasswordUpdate)(
		InstanceID id,
		CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspUserPasswordUpdate(InstanceID id, CbOnRspUserPasswordUpdate handler);

	///资金账户口令更新请求响应
	typedef void (APPWINAPI *CbOnRspTradingAccountPasswordUpdate)(
		InstanceID id,
		CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspTradingAccountPasswordUpdate(
		InstanceID id, CbOnRspTradingAccountPasswordUpdate handler);

	///报单录入请求响应
	typedef void (APPWINAPI *CbOnRspOrderInsert)(
		InstanceID id,
		CThostFtdcInputOrderField *pInputOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOrderInsert(InstanceID id, CbOnRspOrderInsert handler);

	///预埋单录入请求响应
	typedef void (APPWINAPI *CbOnRspParkedOrderInsert)(
		InstanceID id,
		CThostFtdcParkedOrderField *pParkedOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspParkedOrderInsert(InstanceID id, CbOnRspParkedOrderInsert handler);

	///预埋撤单录入请求响应
	typedef void (APPWINAPI *CbOnRspParkedOrderAction)(
		InstanceID id,
		CThostFtdcParkedOrderActionField *pParkedOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspParkedOrderAction(InstanceID id, CbOnRspParkedOrderAction handler);

	///报单操作请求响应
	typedef void (APPWINAPI *CbOnRspOrderAction)(
		InstanceID id,
		CThostFtdcInputOrderActionField *pInputOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOrderAction(InstanceID id, CbOnRspOrderAction handler);

	///查询最大报单数量响应
	typedef void (APPWINAPI *CbOnRspQueryMaxOrderVolume)(
		InstanceID id,
		CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQueryMaxOrderVolume(InstanceID id, CbOnRspQueryMaxOrderVolume handler);

	///投资者结算结果确认响应
	typedef void (APPWINAPI *CbOnRspSettlementInfoConfirm)(
		InstanceID id,
		CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspSettlementInfoConfirm(InstanceID id, CbOnRspSettlementInfoConfirm handler);

	///删除预埋单响应
	typedef void (APPWINAPI *CbOnRspRemoveParkedOrder)(
		InstanceID id,
		CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspRemoveParkedOrder(InstanceID id, CbOnRspRemoveParkedOrder handler);

	///删除预埋撤单响应
	typedef void (APPWINAPI *CbOnRspRemoveParkedOrderAction)(
		InstanceID id,
		CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspRemoveParkedOrderAction(InstanceID id, CbOnRspRemoveParkedOrderAction handler);

	///执行宣告录入请求响应
	typedef void (APPWINAPI *CbOnRspExecOrderInsert)(
		InstanceID id,
		CThostFtdcInputExecOrderField *pInputExecOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspExecOrderInsert(InstanceID id, CbOnRspExecOrderInsert handler);

	///执行宣告操作请求响应
	typedef void (APPWINAPI *CbOnRspExecOrderAction)(
		InstanceID id,
		CThostFtdcInputExecOrderActionField *pInputExecOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspExecOrderAction(InstanceID id, CbOnRspExecOrderAction handler);

	///询价录入请求响应
	typedef void (APPWINAPI *CbOnRspForQuoteInsert)(
		InstanceID id,
		CThostFtdcInputForQuoteField *pInputForQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspForQuoteInsert(InstanceID id, CbOnRspForQuoteInsert handler);

	///报价录入请求响应
	typedef void (APPWINAPI *CbOnRspQuoteInsert)(
		InstanceID id,
		CThostFtdcInputQuoteField *pInputQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQuoteInsert(InstanceID id, CbOnRspQuoteInsert handler);

	///报价操作请求响应
	typedef void (APPWINAPI *CbOnRspQuoteAction)(
		InstanceID id,
		CThostFtdcInputQuoteActionField *pInputQuoteAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQuoteAction(InstanceID id, CbOnRspQuoteAction handler);

	///批量报单操作请求响应
	typedef void (APPWINAPI *CbOnRspBatchOrderAction)(
		InstanceID id,
		CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspBatchOrderAction(InstanceID id, CbOnRspBatchOrderAction handler);

	///期权自对冲录入请求响应
	typedef void (APPWINAPI *CbOnRspOptionSelfCloseInsert)(
		InstanceID id,
		CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOptionSelfCloseInsert(InstanceID id, CbOnRspOptionSelfCloseInsert handler);

	///期权自对冲操作请求响应
	typedef void (APPWINAPI *CbOnRspOptionSelfCloseAction)(
		InstanceID id,
		CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOptionSelfCloseAction(InstanceID id, CbOnRspOptionSelfCloseAction handler);

	///请求核心间资金转移响应
	typedef void(APPWINAPI *CbOnRspTransFund)(
		InstanceID id,
		CThostFtdcTransFundField *pTransFund,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspTransFund(InstanceID id, CbOnRspTransFund handler);

	///请求查询报单响应
	typedef void(APPWINAPI *CbOnRspQryOrder)(
		InstanceID id,
		CThostFtdcOrderField *pOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOrder(InstanceID id, CbOnRspQryOrder handler);

	///请求查询成交响应
	typedef void(APPWINAPI *CbOnRspQryTrade)(
		InstanceID id,
		CThostFtdcTradeField *pTrade,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTrade(InstanceID id, CbOnRspQryTrade handler);

	///请求查询投资者持仓响应
	typedef void(APPWINAPI *CbOnRspQryInvestorPosition)(
		InstanceID id,
		CThostFtdcInvestorPositionField *pInvestorPosition,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorPosition(InstanceID id, CbOnRspQryInvestorPosition handler);

	///请求查询资金账户响应
	typedef void(APPWINAPI *CbOnRspQryTradingAccount)(
		InstanceID id,
		CThostFtdcTradingAccountField *pTradingAccount,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTradingAccount(InstanceID id, CbOnRspQryTradingAccount handler);

	///请求查询投资者响应
	typedef void(APPWINAPI *CbOnRspQryInvestor)(
		InstanceID id,
		CThostFtdcInvestorField *pInvestor,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestor(InstanceID id, CbOnRspQryInvestor handler);

	///请求查询交易编码响应
	typedef void(APPWINAPI *CbOnRspQryTradingCode)(
		InstanceID id,
		CThostFtdcTradingCodeField *pTradingCode,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTradingCode(InstanceID id, CbOnRspQryTradingCode handler);

	///请求查询合约保证金率响应
	typedef void(APPWINAPI *CbOnRspQryInstrumentMarginRate)(
		InstanceID id,
		CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrumentMarginRate(InstanceID id, CbOnRspQryInstrumentMarginRate handler);

	///请求查询合约手续费率响应
	typedef void(APPWINAPI *CbOnRspQryInstrumentCommissionRate)(
		InstanceID id,
		CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrumentCommissionRate(
		InstanceID id, CbOnRspQryInstrumentCommissionRate handler);

	///请求查询交易所响应
	typedef void(APPWINAPI *CbOnRspQryExchange)(
		InstanceID id,
		CThostFtdcExchangeField *pExchange,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchange(InstanceID id, CbOnRspQryExchange handler);

	///请求查询产品响应
	typedef void(APPWINAPI *CbOnRspQryProduct)(
		InstanceID id,
		CThostFtdcProductField *pProduct,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryProduct(InstanceID id, CbOnRspQryProduct handler);

	///请求查询合约响应
	typedef void(APPWINAPI *CbOnRspQryInstrument)(
		InstanceID id,
		CThostFtdcInstrumentField *pInstrument,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrument(InstanceID id, CbOnRspQryInstrument handler);

	///请求查询行情响应
	typedef void(APPWINAPI *CbOnRspQryDepthMarketData)(
		InstanceID id,
		CThostFtdcDepthMarketDataField *pDepthMarketData,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryDepthMarketData(InstanceID id, CbOnRspQryDepthMarketData handler);

	///请求查询投资者结算结果响应
	typedef void(APPWINAPI *CbOnRspQrySettlementInfo)(
		InstanceID id,
		CThostFtdcSettlementInfoField *pSettlementInfo,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQrySettlementInfo(InstanceID id, CbOnRspQrySettlementInfo handler);

	///请求查询合约状态响应
	typedef void(APPWINAPI *CbOnRspQryInstrumentStatus)(
		InstanceID id,
		CThostFtdcInstrumentStatusField *pInstrumentStatus,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrumentStatus(InstanceID id, CbOnRspQryInstrumentStatus handler);

	///请求查询转帐银行响应
	typedef void(APPWINAPI *CbOnRspQryTransferBank)(
		InstanceID id,
		CThostFtdcTransferBankField *pTransferBank,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTransferBank(InstanceID id, CbOnRspQryTransferBank handler);

	///请求查询投资者持仓明细响应
	typedef void(APPWINAPI *CbOnRspQryInvestorPositionDetail)(
		InstanceID id,
		CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorPositionDetail(
		InstanceID id, CbOnRspQryInvestorPositionDetail handler);

	///请求查询客户通知响应
	typedef void(APPWINAPI *CbOnRspQryNotice)(
		InstanceID id,
		CThostFtdcNoticeField *pNotice,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryNotice(InstanceID id, CbOnRspQryNotice handler);

	///请求查询结算信息确认响应
	typedef void(APPWINAPI *CbOnRspQrySettlementInfoConfirm)(
		InstanceID id,
		CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQrySettlementInfoConfirm(InstanceID id, CbOnRspQrySettlementInfoConfirm handler);

	///请求查询投资者持仓明细响应
	typedef void(APPWINAPI *CbOnRspQryInvestorPositionCombineDetail)(
		InstanceID id,
		CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorPositionCombineDetail(
		InstanceID id, CbOnRspQryInvestorPositionCombineDetail handler);

	///查询保证金监管系统经纪公司资金账户密钥响应
	typedef void(APPWINAPI *CbOnRspQryCFMMCTradingAccountKey)(
		InstanceID id,
		CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryCFMMCTradingAccountKey(
		InstanceID id, CbOnRspQryCFMMCTradingAccountKey handler);

	///请求查询仓单折抵信息响应
	typedef void(APPWINAPI *CbOnRspQryEWarrantOffset)(
		InstanceID id,
		CThostFtdcEWarrantOffsetField *pEWarrantOffset,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryEWarrantOffset(InstanceID id, CbOnRspQryEWarrantOffset handler);

	///请求查询投资者品种/跨品种保证金响应
	typedef void(APPWINAPI *CbOnRspQryInvestorProductGroupMargin)(
		InstanceID id,
		CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorProductGroupMargin(
		InstanceID id, CbOnRspQryInvestorProductGroupMargin handler);

	///请求查询交易所保证金率响应
	typedef void(APPWINAPI *CbOnRspQryExchangeMarginRate)(
		InstanceID id,
		CThostFtdcExchangeMarginRateField *pExchangeMarginRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchangeMarginRate(InstanceID id, CbOnRspQryExchangeMarginRate handler);

	///请求查询交易所调整保证金率响应
	typedef void(APPWINAPI *CbOnRspQryExchangeMarginRateAdjust)(
		InstanceID id,
		CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchangeMarginRateAdjust(
		InstanceID id, CbOnRspQryExchangeMarginRateAdjust handler);

	///请求查询汇率响应
	typedef void(APPWINAPI *CbOnRspQryExchangeRate)(
		InstanceID id,
		CThostFtdcExchangeRateField *pExchangeRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchangeRate(InstanceID id, CbOnRspQryExchangeRate handler);

	///请求查询二级代理操作员银期权限响应
	typedef void(APPWINAPI *CbOnRspQrySecAgentACIDMap)(
		InstanceID id,
		CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQrySecAgentACIDMap(InstanceID id, CbOnRspQrySecAgentACIDMap handler);

	///请求查询期权交易成本响应
	typedef void(APPWINAPI *CbOnRspQryOptionInstrTradeCost)(
		InstanceID id,
		CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOptionInstrTradeCost(InstanceID id, CbOnRspQryOptionInstrTradeCost handler);

	///请求查询期权合约手续费响应
	typedef void(APPWINAPI *CbOnRspQryOptionInstrCommRate)(
		InstanceID id,
		CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOptionInstrCommRate(InstanceID id, CbOnRspQryOptionInstrCommRate handler);

	///请求查询执行宣告响应
	typedef void(APPWINAPI *CbOnRspQryExecOrder)(
		InstanceID id,
		CThostFtdcExecOrderField *pExecOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExecOrder(InstanceID id, CbOnRspQryExecOrder handler);

	///请求查询询价响应
	typedef void(APPWINAPI *CbOnRspQryForQuote)(
		InstanceID id,
		CThostFtdcForQuoteField *pForQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryForQuote(InstanceID id, CbOnRspQryForQuote handler);

	///请求查询报价响应
	typedef void(APPWINAPI *CbOnRspQryQuote)(
		InstanceID id,
		CThostFtdcQuoteField *pQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryQuote(InstanceID id, CbOnRspQryQuote handler);

	///请求查询期权自对冲响应
	typedef void(APPWINAPI *CbOnRspQryOptionSelfClose)(
		InstanceID id,
		CThostFtdcOptionSelfCloseField *pOptionSelfClose,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOptionSelfClose(InstanceID id, CbOnRspQryOptionSelfClose handler);

	///请求查询转帐流水响应
	typedef void(APPWINAPI *CbOnRspQryTransferSerial)(
		InstanceID id,
		CThostFtdcTransferSerialField *pTransferSerial,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTransferSerial(InstanceID id, CbOnRspQryTransferSerial handler);

	///请求查询银期签约关系响应
	typedef void(APPWINAPI *CbOnRspQryAccountregister)(
		InstanceID id,
		CThostFtdcAccountregisterField *pAccountregister,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryAccountregister(InstanceID id, CbOnRspQryAccountregister handler);

	///错误应答
	typedef void (APPWINAPI *CbOnRspError)(
		InstanceID id, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspError(InstanceID id, CbOnRspError handler);

	///报单通知
	typedef void (APPWINAPI *CbOnRtnOrder)(InstanceID id, CThostFtdcOrderField *pOrder);
	C_API void SetCallbackOnRtnOrder(InstanceID id, CbOnRtnOrder handler);

	///成交通知
	typedef void (APPWINAPI *CbOnRtnTrade)(InstanceID id, CThostFtdcTradeField *pTrade);
	C_API void SetCallbackOnRtnTrade(InstanceID id, CbOnRtnTrade handler);

	///报单录入错误回报
	typedef void (APPWINAPI *CbOnErrRtnOrderInsert)(
		InstanceID id, CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOrderInsert(InstanceID id, CbOnErrRtnOrderInsert handler);

	///报单操作错误回报
	typedef void (APPWINAPI *CbOnErrRtnOrderAction)(
		InstanceID id, CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOrderAction(InstanceID id, CbOnErrRtnOrderAction handler);

	///合约交易状态通知
	typedef void(APPWINAPI *CbOnRtnInstrumentStatus)(
		InstanceID id, CThostFtdcInstrumentStatusField *pInstrumentStatus);
	C_API void SetCallbackOnRtnInstrumentStatus(InstanceID id, CbOnRtnInstrumentStatus handler);

	///交易通知
	typedef void (APPWINAPI *CbOnRtnTradingNotice)(InstanceID id, CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	C_API void SetCallbackOnRtnTradingNotice(InstanceID id, CbOnRtnTradingNotice handler);

	///提示条件单校验错误
	typedef void(APPWINAPI *CbOnRtnErrorConditionalOrder)(
		InstanceID id, CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	C_API void SetCallbackOnRtnErrorConditionalOrder(InstanceID id, CbOnRtnErrorConditionalOrder handler);

	///执行宣告通知
	typedef void(APPWINAPI *CbOnRtnExecOrder)(InstanceID id, CThostFtdcExecOrderField *pExecOrder);
	C_API void SetCallbackOnRtnExecOrder(InstanceID id, CbOnRtnExecOrder handler);

	///执行宣告录入错误回报
	typedef void(APPWINAPI *CbOnErrRtnExecOrderInsert)(
		InstanceID id, CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnExecOrderInsert(InstanceID id, CbOnErrRtnExecOrderInsert handler);

	///执行宣告操作错误回报
	typedef void(APPWINAPI *CbOnErrRtnExecOrderAction)(
		InstanceID id, CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnExecOrderAction(InstanceID id, CbOnErrRtnExecOrderAction handler);

	///询价录入错误回报
	typedef void(APPWINAPI *CbOnErrRtnForQuoteInsert)(
		InstanceID id, CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnForQuoteInsert(InstanceID id, CbOnErrRtnForQuoteInsert handler);

	///报价通知
	typedef void(APPWINAPI *CbOnRtnQuote)(InstanceID id, CThostFtdcQuoteField *pQuote);
	C_API void SetCallbackOnRtnQuote(InstanceID id, CbOnRtnQuote handler);

	///报价录入错误回报
	typedef void(APPWINAPI *CbOnErrRtnQuoteInsert)(
		InstanceID id, CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnQuoteInsert(InstanceID id, CbOnErrRtnQuoteInsert handler);

	///报价操作错误回报
	typedef void(APPWINAPI *CbOnErrRtnQuoteAction)(
		InstanceID id, CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnQuoteAction(InstanceID id, CbOnErrRtnQuoteAction handler);

	///询价通知
	typedef void(APPWINAPI *CbOnRtnForQuoteRsp)(InstanceID id, CThostFtdcForQuoteRspField *pForQuoteRsp);
	C_API void SetCallbackOnRtnForQuoteRsp(InstanceID id, CbOnRtnForQuoteRsp handler);

	///批量报单操作错误回报
	typedef void(APPWINAPI *CbOnErrRtnBatchOrderAction)(
		InstanceID id, CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnBatchOrderAction(InstanceID id, CbOnErrRtnBatchOrderAction handler);

	///期权自对冲通知
	typedef void(APPWINAPI *CbOnRtnOptionSelfClose)(InstanceID id, CThostFtdcOptionSelfCloseField *pOptionSelfClose);
	C_API void SetCallbackOnRtnOptionSelfClose(InstanceID id, CbOnRtnOptionSelfClose handler);

	///期权自对冲录入错误回报
	typedef void(APPWINAPI *CbOnErrRtnOptionSelfCloseInsert)(
		InstanceID id, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOptionSelfCloseInsert(InstanceID id, CbOnErrRtnOptionSelfCloseInsert handler);

	///期权自对冲操作错误回报
	typedef void(APPWINAPI *CbOnErrRtnOptionSelfCloseAction)(
		InstanceID id, CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOptionSelfCloseAction(InstanceID id, CbOnErrRtnOptionSelfCloseAction handler);

	///请求查询签约银行响应
	typedef void(APPWINAPI *CbOnRspQryContractBank)(
		InstanceID id,
		CThostFtdcContractBankField *pContractBank,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryContractBank(InstanceID id, CbOnRspQryContractBank handler);

	///请求查询预埋单响应
	typedef void(APPWINAPI *CbOnRspQryParkedOrder)(
		InstanceID id,
		CThostFtdcParkedOrderField *pParkedOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryParkedOrder(InstanceID id, CbOnRspQryParkedOrder handler);

	///请求查询预埋撤单响应
	typedef void(APPWINAPI *CbOnRspQryParkedOrderAction)(
		InstanceID id,
		CThostFtdcParkedOrderActionField *pParkedOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryParkedOrderAction(InstanceID id, CbOnRspQryParkedOrderAction handler);

	///请求查询交易通知响应
	typedef void(APPWINAPI *CbOnRspQryTradingNotice)(
		InstanceID id,
		CThostFtdcTradingNoticeField *pTradingNotice,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTradingNotice(InstanceID id, CbOnRspQryTradingNotice handler);

	///请求查询经纪公司交易参数响应
	typedef void(APPWINAPI *CbOnRspQryBrokerTradingParams)(
		InstanceID id,
		CThostFtdcBrokerTradingParamsField *pBrokerTradingParams,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryBrokerTradingParams(InstanceID id, CbOnRspQryBrokerTradingParams handler);

	///请求查询经纪公司交易算法响应
	typedef void(APPWINAPI *CbOnRspQryBrokerTradingAlgos)(
		InstanceID id,
		CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQRyBrokerTradingAlgos(InstanceID id, CbOnRspQryBrokerTradingAlgos handler);

	///银行发起银行资金转期货通知
	typedef void(APPWINAPI *CbOnRtnFromBankToFutureByBank)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromBankToFutureByBank(InstanceID id, CbOnRtnFromBankToFutureByBank handler);

	///银行发起期货资金转银行通知
	typedef void(APPWINAPI *CbOnRtnFromFutureToBankByBank)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromFutureToBankByBank(InstanceID id, CbOnRtnFromFutureToBankByBank handler);

	///银行发起冲正银行转期货通知
	typedef void(APPWINAPI *CbOnRtnRepealFromBankToFutureByBank)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromBankToFutureByBank(
		InstanceID id, CbOnRtnRepealFromBankToFutureByBank handler);

	///银行发起冲正期货转银行通知
	typedef void(APPWINAPI *CbOnRtnRepealFromFutureToBankByBank)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromFutureToBankByBank(
		InstanceID id, CbOnRtnRepealFromFutureToBankByBank handler);

	///期货发起银行资金转期货通知
	typedef void(APPWINAPI *CbOnRtnFromBankToFutureByFuture)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromBankToFutureByFuture(InstanceID id, CbOnRtnFromBankToFutureByFuture handler);

	///期货发起期货资金转银行通知
	typedef void(APPWINAPI *CbOnRtnFromFutureToBankByFuture)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromFutureToBankByFuture(InstanceID id, CbOnRtnFromFutureToBankByFuture handler);

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	typedef void(APPWINAPI *CbOnRtnRepealFromBankToFutureByFutureManual)(
		InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromBankToFutureByFutureManual(
		InstanceID id, CbOnRtnRepealFromBankToFutureByFutureManual handler);

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	typedef void(APPWINAPI *CbOnRtnRepealFromFutureToBankByFutureManual)(
		InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromFutureToBankByFutureManual(
		InstanceID id, CbOnRtnRepealFromFutureToBankByFutureManual handler);

	///期货发起查询银行余额通知
	typedef void(APPWINAPI *CbOnRtnQueryBankBalanceByFuture)(
		InstanceID id, CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	C_API void SetCallbackOnRtnQueryBankBalanceByFuture(InstanceID id, CbOnRtnQueryBankBalanceByFuture handler);

	///期货发起银行资金转期货错误回报
	typedef void(APPWINAPI *CbOnErrRtnBankToFutureByFuture)(
		InstanceID id, CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnBankToFutureByFuture(InstanceID id, CbOnErrRtnBankToFutureByFuture handler);

	///期货发起期货资金转银行错误回报
	typedef void(APPWINAPI *CbOnErrRtnFutureToBankByFuture)(
		InstanceID id, CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnFutureToBankByFuture(InstanceID id, CbOnErrRtnFutureToBankByFuture handler);

	///系统运行时期货端手工发起冲正银行转期货错误回报
	typedef void(APPWINAPI *CbOnErrRtnRepealBankToFutureByFutureManual)(
		InstanceID id, CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnRepealBankToFutureByFutureManual(
		InstanceID id, CbOnErrRtnRepealBankToFutureByFutureManual handler);

	///系统运行时期货端手工发起冲正期货转银行错误回报
	typedef void(APPWINAPI *CbOnErrRtnRepealFutureToBankByFutureManual)(
		InstanceID id, CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnRepealFutureToBankByFutureManual(
		InstanceID id, CbOnErrRtnRepealFutureToBankByFutureManual handler);

	///期货发起查询银行余额错误回报
	typedef void(APPWINAPI *CbOnErrRtnQueryBankBalanceByFuture)(
		InstanceID id, CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnQueryBankBalanceByFuture(
		InstanceID id, CbOnErrRtnQueryBankBalanceByFuture handler);

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	typedef void(APPWINAPI *CbOnRtnRepealFromBankToFutureByFuture)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromBankToFutureByFuture(
		InstanceID id, CbOnRtnRepealFromBankToFutureByFuture handler);

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	typedef void(APPWINAPI *CbOnRtnRepealFromFutureToBankByFuture)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromFutureToBankByFuture(
		InstanceID id, CbOnRtnRepealFromFutureToBankByFuture handler);

	///期货发起银行资金转期货应答
	typedef void(APPWINAPI *CbOnRspFromBankToFutureByFuture)(
		InstanceID id,
		CThostFtdcReqTransferField *pReqTransfer,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspFromBankToFutureByFuture(InstanceID id, CbOnRspFromBankToFutureByFuture handler);

	///期货发起期货资金转银行应答
	typedef void(APPWINAPI *CbOnRspFromFutureToBankByFuture)(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspFromFutureToBankByFuture(InstanceID id, CbOnRspFromFutureToBankByFuture handler);

	///期货发起查询银行余额应答
	typedef void(APPWINAPI *CbOnRspQueryBankAccountMoneyByFuture)(
		InstanceID id,
		CThostFtdcReqQueryAccountField *pReqQueryAccount,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQueryBankAccountMoneyByFuture(
		InstanceID id, CbOnRspQueryBankAccountMoneyByFuture handler);

	///银行发起银期开户通知
	typedef void(APPWINAPI *CbOnRtnOpenAccountByBank)(InstanceID id, CThostFtdcOpenAccountField *pOpenAccount);
	C_API void SetCallbackOnRtnOpenAccountByBank(InstanceID id, CbOnRtnOpenAccountByBank handler);

	///银行发起银期销户通知
	typedef void(APPWINAPI *CbOnRtnCancelAccountByBank)(InstanceID id, CThostFtdcCancelAccountField *pCancelAccount);
	C_API void SetCallbackOnRtnCancelAccountByBank(InstanceID id, CbOnRtnCancelAccountByBank handler);

	///银行发起变更银行账号通知
	typedef void(APPWINAPI *CbOnRtnChangeAccountByBank)(InstanceID id, CThostFtdcChangeAccountField *pChangeAccount);
	C_API void SetCallbackOnRtnChangeAccountByBank(InstanceID id, CbOnRtnChangeAccountByBank handler);

	typedef struct {
		///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		CbOnFrontConnected onFrontConnected;

		///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		///@param nReason 错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文
		CbOnFrontDisconnected onFrontDisconnected;

		///心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		CbOnHeartBeatWarning onHeartBeatWarning;

		///客户端认证响应
		CbOnRspAuthenticate onRspAuthenticate;

		///登录请求响应
		CbOnRspUserLogin onRspUserLogin;

		///登出请求响应
		CbOnRspUserLogout onRspUserLogout;

		///用户口令更新请求响应
		CbOnRspUserPasswordUpdate onRspUserPasswordUpdate;

		///资金账户口令更新请求响应
		CbOnRspTradingAccountPasswordUpdate onRspTradingAccountPasswordUpdate;

		///报单录入请求响应
		CbOnRspOrderInsert onRspOrderInsert;

		///预埋单录入请求响应
		CbOnRspParkedOrderInsert onRspParkedOrderInsert;

		///预埋撤单录入请求响应
		CbOnRspParkedOrderAction onRspParkedOrderAction;

		///报单操作请求响应
		CbOnRspOrderAction onRspOrderAction;

		///查询最大报单数量响应
		CbOnRspQueryMaxOrderVolume onRspQueryMaxOrderVolume;

		///投资者结算结果确认响应
		CbOnRspSettlementInfoConfirm onRspSettlementInfoConfirm;

		///删除预埋单响应
		CbOnRspRemoveParkedOrder onRspRemoveParkedOrder;

		///删除预埋撤单响应
		CbOnRspRemoveParkedOrderAction onRspRemoveParkedOrderAction;

		///执行宣告录入请求响应
		CbOnRspExecOrderInsert onRspExecOrderInsert;

		///执行宣告操作请求响应
		CbOnRspExecOrderAction onRspExecOrderAction;

		///询价录入请求响应
		CbOnRspForQuoteInsert onRspForQuoteInsert;

		///报价录入请求响应
		CbOnRspQuoteInsert onRspQuoteInsert;

		///报价操作请求响应
		CbOnRspQuoteAction onRspQuoteAction;

		///批量报单操作请求响应
		CbOnRspBatchOrderAction onRspBatchOrderAction;

		///期权自对冲录入请求响应
		CbOnRspOptionSelfCloseInsert onRspOptionSelfCloseInsert;

		///期权自对冲操作请求响应
		CbOnRspOptionSelfCloseAction onRspOptionSelfCloseAction;

		///请求核心间资金转移响应
		CbOnRspTransFund onRspTransFund;

		///请求查询报单响应
		CbOnRspQryOrder onRspQryOrder;

		///请求查询成交响应
		CbOnRspQryTrade onRspQryTrade;

		///请求查询投资者持仓响应
		CbOnRspQryInvestorPosition onRspQryInvestorPosition;

		///请求查询资金账户响应
		CbOnRspQryTradingAccount onRspQryTradingAccount;

		///请求查询投资者响应
		CbOnRspQryInvestor onRspQryInvestor;

		///请求查询交易编码响应
		CbOnRspQryTradingCode onRspQryTradingCode;

		///请求查询合约保证金率响应
		CbOnRspQryInstrumentMarginRate onRspQryInstrumentMarginRate;

		///请求查询合约手续费率响应
		CbOnRspQryInstrumentCommissionRate onRspQryInstrumentCommissionRate;

		///请求查询交易所响应
		CbOnRspQryExchange onRspQryExchange;

		///请求查询产品响应
		CbOnRspQryProduct onRspQryProduct;

		///请求查询合约响应
		CbOnRspQryInstrument onRspQryInstrument;

		///请求查询行情响应
		CbOnRspQryDepthMarketData onRspQryDepthMarketData;

		///请求查询投资者结算结果响应
		CbOnRspQrySettlementInfo onRspQrySettlementInfo;

		///请求查询合约状态响应
		CbOnRspQryInstrumentStatus onRspQryInstrumentStatus;

		///请求查询转帐银行响应
		CbOnRspQryTransferBank onRspQryTransferBank;

		///请求查询投资者持仓明细响应
		CbOnRspQryInvestorPositionDetail onRspQryInvestorPositionDetail;

		///请求查询客户通知响应
		CbOnRspQryNotice onRspQryNotice;

		///请求查询结算信息确认响应
		CbOnRspQrySettlementInfoConfirm onRspQrySettlementInfoConfirm;

		///请求查询投资者持仓明细响应
		CbOnRspQryInvestorPositionCombineDetail onRspQryInvestorPositionCombineDetail;

		///查询保证金监管系统经纪公司资金账户密钥响应
		CbOnRspQryCFMMCTradingAccountKey onRspQryCFMMCTradingAccountKey;

		///请求查询仓单折抵信息响应
		CbOnRspQryEWarrantOffset onRspQryEWarrantOffset;

		///请求查询投资者品种/跨品种保证金响应
		CbOnRspQryInvestorProductGroupMargin onRspQryInvestorProductGroupMargin;

		///请求查询交易所保证金率响应
		CbOnRspQryExchangeMarginRate onRspQryExchangeMarginRate;

		///请求查询交易所调整保证金率响应
		CbOnRspQryExchangeMarginRateAdjust onRspQryExchangeMarginRateAdjust;

		///请求查询汇率响应
		CbOnRspQryExchangeRate onRspQryExchangeRate;

		///请求查询二级代理操作员银期权限响应
		CbOnRspQrySecAgentACIDMap onRspQrySecAgentACIDMap;

		///请求查询期权交易成本响应
		CbOnRspQryOptionInstrTradeCost onRspQryOptionInstrTradeCost;

		///请求查询期权合约手续费响应
		CbOnRspQryOptionInstrCommRate onRspQryOptionInstrCommRate;

		///请求查询执行宣告响应
		CbOnRspQryExecOrder onRspQryExecOrder;

		///请求查询询价响应
		CbOnRspQryForQuote onRspQryForQuote;

		///请求查询报价响应
		CbOnRspQryQuote onRspQryQuote;

		///请求查询期权自对冲响应
		CbOnRspQryOptionSelfClose onRspQryOptionSelfClose;

		///请求查询转帐流水响应
		CbOnRspQryTransferSerial onRspQryTransferSerial;

		///请求查询银期签约关系响应
		CbOnRspQryAccountregister onRspQryAccountregister;

		///错误应答
		CbOnRspError onRspError;

		///报单通知
		CbOnRtnOrder onRtnOrder;

		///成交通知
		CbOnRtnTrade onRtnTrade;

		///报单录入错误回报
		CbOnErrRtnOrderInsert onErrRtnOrderInsert;

		///报单操作错误回报
		CbOnErrRtnOrderAction onErrRtnOrderAction;

		///合约交易状态通知
		CbOnRtnInstrumentStatus onRtnInstrumentStatus;

		///交易通知
		CbOnRtnTradingNotice onRtnTradingNotice;

		///提示条件单校验错误
		CbOnRtnErrorConditionalOrder onRtnErrorConditionalOrder;

		///执行宣告通知
		CbOnRtnExecOrder onRtnExecOrder;

		///执行宣告录入错误回报
		CbOnErrRtnExecOrderInsert onErrRtnExecOrderInsert;

		///执行宣告操作错误回报
		CbOnErrRtnExecOrderAction onErrRtnExecOrderAction;

		///询价录入错误回报
		CbOnErrRtnForQuoteInsert onErrRtnForQuoteInsert;

		///报价通知
		CbOnRtnQuote onRtnQuote;

		///报价录入错误回报
		CbOnErrRtnQuoteInsert onErrRtnQuoteInsert;

		///报价操作错误回报
		CbOnErrRtnQuoteAction onErrRtnQuoteAction;

		///询价通知
		CbOnRtnForQuoteRsp onRtnForQuoteRsp;

		///批量报单操作错误回报
		CbOnErrRtnBatchOrderAction onErrRtnBatchOrderAction;

		///期权自对冲通知
		CbOnRtnOptionSelfClose onRtnOptionSelfClose;

		///期权自对冲录入错误回报
		CbOnErrRtnOptionSelfCloseInsert onErrRtnOptionSelfCloseInsert;

		///期权自对冲操作错误回报
		CbOnErrRtnOptionSelfCloseAction onErrRtnOptionSelfCloseAction;

		///请求查询签约银行响应
		CbOnRspQryContractBank onRspQryContractBank;

		///请求查询预埋单响应
		CbOnRspQryParkedOrder onRspQryParkedOrder;

		///请求查询预埋撤单响应
		CbOnRspQryParkedOrderAction onRspQryParkedOrderAction;

		///请求查询交易通知响应
		CbOnRspQryTradingNotice onRspQryTradingNotice;

		///请求查询经纪公司交易参数响应
		CbOnRspQryBrokerTradingParams onRspQryBrokerTradingParams;

		///请求查询经纪公司交易算法响应
		CbOnRspQryBrokerTradingAlgos onRspQryBrokerTradingAlgos;

		///银行发起银行资金转期货通知
		CbOnRtnFromBankToFutureByBank onRtnFromBankToFutureByBank;

		///银行发起期货资金转银行通知
		CbOnRtnFromFutureToBankByBank onRtnFromFutureToBankByBank;

		///银行发起冲正银行转期货通知
		CbOnRtnRepealFromBankToFutureByBank onRtnRepealFromBankToFutureByBank;

		///银行发起冲正期货转银行通知
		CbOnRtnRepealFromFutureToBankByBank onRtnRepealFromFutureToBankByBank;

		///期货发起银行资金转期货通知
		CbOnRtnFromBankToFutureByFuture onRtnFromBankToFutureByFuture;

		///期货发起期货资金转银行通知
		CbOnRtnFromFutureToBankByFuture onRtnFromFutureToBankByFuture;

		///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		CbOnRtnRepealFromBankToFutureByFutureManual onRtnRepealFromBankToFutureByFutureManual;

		///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		CbOnRtnRepealFromFutureToBankByFutureManual onRtnRepealFromFutureToBankByFutureManual;

		///期货发起查询银行余额通知
		CbOnRtnQueryBankBalanceByFuture onRtnQueryBankBalanceByFuture;

		///期货发起银行资金转期货错误回报
		CbOnErrRtnBankToFutureByFuture onErrRtnBankToFutureByFuture;

		///期货发起期货资金转银行错误回报
		CbOnErrRtnFutureToBankByFuture onErrRtnFutureToBankByFuture;

		///系统运行时期货端手工发起冲正银行转期货错误回报
		CbOnErrRtnRepealBankToFutureByFutureManual onErrRtnRepealBankToFutureByFutureManual;

		///系统运行时期货端手工发起冲正期货转银行错误回报
		CbOnErrRtnRepealFutureToBankByFutureManual onErrRtnRepealFutureToBankByFutureManual;

		///期货发起查询银行余额错误回报
		CbOnErrRtnQueryBankBalanceByFuture onErrRtnQueryBankBalanceByFuture;

		///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		CbOnRtnRepealFromBankToFutureByFuture onRtnRepealFromBankToFutureByFuture;

		///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		CbOnRtnRepealFromFutureToBankByFuture onRtnRepealFromFutureToBankByFuture;

		///期货发起银行资金转期货应答
		CbOnRspFromBankToFutureByFuture onRspFromBankToFutureByFuture;

		///期货发起期货资金转银行应答
		CbOnRspFromFutureToBankByFuture onRspFromFutureToBankByFuture;

		///期货发起查询银行余额应答
		CbOnRspQueryBankAccountMoneyByFuture onRspQueryBankAccountMoneyByFuture;

		///银行发起银期开户通知
		CbOnRtnOpenAccountByBank onRtnOpenAccountByBank;

		///银行发起银期销户通知
		CbOnRtnCancelAccountByBank onRtnCancelAccountByBank;

		///银行发起变更银行账号通知
		CbOnRtnChangeAccountByBank onRtnChangeAccountByBank;
	} callbackVirtualTable;

	C_API void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt);

	///创建API接口实例
	///@return 接口实例号
	C_API InstanceID CreateApi();

	///获取API的版本信息
	///@retrun 获取到的版本号
	C_API const char *GetApiVersion();

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	C_API void Release(InstanceID id);

	///初始化
	///@param bContinuous 为true表示线程不休眠
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	C_API void Init(InstanceID id, const char *pszFlowPath, bool bContinuous);

	///等待接口线程结束运行
	///@return 线程退出代码
	C_API int Join(InstanceID id);

	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	C_API const char *GetTradingDay(InstanceID id);

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	C_API void RegisterFront(InstanceID id, char *pszFrontAddress);

	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterNameServer优先于RegisterFront
	C_API void RegisterNameServer(InstanceID id, char *pszNsAddress);

	///注册名字服务器用户信息
	///@param pFensUserInfo：用户信息。
	C_API void RegisterFensUserInfo(InstanceID id, CThostFtdcFensUserInfoField *pFensUserInfo);

	///订阅私有流。
	///@param nResumeType 私有流重传方式
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	C_API void SubscribePrivateTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType);

	///订阅公共流。
	///@param nResumeType 公共流重传方式
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	C_API void SubscribePublicTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType);

	///客户端认证请求
	C_API int ReqAuthenticate(InstanceID id, CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID);

	///用户登录请求
	C_API int ReqUserLogin(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///用户加密登录请求
	C_API int ReqUserLoginEncrypt(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///登出请求
	C_API int ReqUserLogout(InstanceID id, CThostFtdcUserLogoutField *pUserLogout, int nRequestID);

	///用户口令更新请求
	C_API int ReqUserPasswordUpdate(InstanceID id, CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///资金账户口令更新请求
	C_API int ReqTradingAccountPasswordUpdate(InstanceID id, CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID);

	///报单录入请求
	C_API int ReqOrderInsert(InstanceID id, CThostFtdcInputOrderField *pInputOrder, int nRequestID);

	///预埋单录入请求
	C_API int ReqParkedOrderInsert(InstanceID id, CThostFtdcParkedOrderField *pParkedOrder, int nRequestID);

	///预埋撤单录入请求
	C_API int ReqParkedOrderAction(InstanceID id, CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID);

	///报单操作请求
	C_API int ReqOrderAction(InstanceID id, CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID);

	///查询最大报单数量请求
	C_API int ReqQueryMaxOrderVolume(InstanceID id, CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID);

	///投资者结算结果确认
	C_API int ReqSettlementInfoConfirm(InstanceID id, CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID);

	///请求删除预埋单
	C_API int ReqRemoveParkedOrder(InstanceID id, CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID);

	///请求删除预埋撤单
	C_API int ReqRemoveParkedOrderAction(InstanceID id, CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID);

	///执行宣告录入请求
	C_API int ReqExecOrderInsert(InstanceID id, CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///执行宣告操作请求
	C_API int ReqExecOrderAction(InstanceID id, CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID);

	///询价录入请求
	C_API int ReqForQuoteInsert(InstanceID id, CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID);

	///报价录入请求
	C_API int ReqQuoteInsert(InstanceID id, CThostFtdcInputQuoteField *pInputQuote, int nRequestID);

	///报价操作请求
	C_API int ReqQuoteAction(InstanceID id, CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID);

	///批量报单操作请求
	C_API int ReqBatchOrderAction(InstanceID id, CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID);

	///期权自对冲录入请求
	C_API int ReqOptionSelfCloseInsert(InstanceID id, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID);

	///期权自对冲操作请求
	C_API int ReqOptionSelfCloseAction(InstanceID id, CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID);

	///请求核心间资金转移
	C_API int ReqTransFund(InstanceID id, CThostFtdcTransFundField *pFtdcTransFund, int nRequestID);

	///请求查询报单
	C_API int ReqQryOrder(InstanceID id, CThostFtdcQryOrderField *pQryOrder, int nRequestID);

	///请求查询成交
	C_API int ReqQryTrade(InstanceID id, CThostFtdcQryTradeField *pQryTrade, int nRequestID);

	///请求查询投资者持仓
	C_API int ReqQryInvestorPosition(InstanceID id, CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID);

	///请求查询资金账户
	C_API int ReqQryTradingAccount(InstanceID id, CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID);

	///请求查询投资者
	C_API int ReqQryInvestor(InstanceID id, CThostFtdcQryInvestorField *pQryInvestor, int nRequestID);

	///请求查询交易编码
	C_API int ReqQryTradingCode(InstanceID id, CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID);

	///请求查询合约保证金率
	C_API int ReqQryInstrumentMarginRate(InstanceID id, CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID);

	///请求查询合约手续费率
	C_API int ReqQryInstrumentCommissionRate(InstanceID id, CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID);

	///请求查询交易所
	C_API int ReqQryExchange(InstanceID id, CThostFtdcQryExchangeField *pQryExchange, int nRequestID);

	///请求查询产品
	C_API int ReqQryProduct(InstanceID id, CThostFtdcQryProductField *pQryProduct, int nRequestID);

	///请求查询合约
	C_API int ReqQryInstrument(InstanceID id, CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///请求查询行情
	C_API int ReqQryDepthMarketData(InstanceID id, CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID);

	///请求查询期权自对冲
	C_API int ReqQryOptionSelfClose(InstanceID id, CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID);

	///请求查询投资者结算结果
	C_API int ReqQrySettlementInfo(InstanceID id, CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID);

	///请求查询合约状态
	C_API int ReqQryInstrumentStatus(InstanceID id, CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///请求查询转帐银行
	C_API int ReqQryTransferBank(InstanceID id, CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID);

	///请求查询投资者持仓明细
	C_API int ReqQryInvestorPositionDetail(InstanceID id, CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID);

	///请求查询客户通知
	C_API int ReqQryNotice(InstanceID id, CThostFtdcQryNoticeField *pQryNotice, int nRequestID);

	///请求查询结算信息确认
	C_API int ReqQrySettlementInfoConfirm(InstanceID id, CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID);

	///请求查询投资者持仓明细
	C_API int ReqQryInvestorPositionCombineDetail(InstanceID id, CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID);

	///请求查询保证金监管系统经纪公司资金账户密钥
	C_API int ReqQryCFMMCTradingAccountKey(InstanceID id, CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID);

	///请求查询仓单折抵信息
	C_API int ReqQryEWarrantOffset(InstanceID id, CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID);

	///请求查询投资者品种/跨品种保证金
	C_API int ReqQryInvestorProductGroupMargin(InstanceID id, CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID);

	///请求查询交易所保证金率
	C_API int ReqQryExchangeMarginRate(InstanceID id, CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID);

	///请求查询交易所调整保证金率
	C_API int ReqQryExchangeMarginRateAdjust(InstanceID id, CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID);

	///请求查询汇率
	C_API int ReqQryExchangeRate(InstanceID id, CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);

	///请求查询二级代理操作员银期权限
	C_API int ReqQrySecAgentACIDMap(InstanceID id, CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID);

	///请求查询期权交易成本
	C_API int ReqQryOptionInstrTradeCost(InstanceID id, CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID);

	///请求查询期权合约手续费
	C_API int ReqQryOptionInstrCommRate(InstanceID id, CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID);

	///请求查询执行宣告
	C_API int ReqQryExecOrder(InstanceID id, CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///请求查询询价
	C_API int ReqQryForQuote(InstanceID id, CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID);

	///请求查询报价
	C_API int ReqQryQuote(InstanceID id, CThostFtdcQryQuoteField *pQryQuote, int nRequestID);

	///请求查询转帐流水
	C_API int ReqQryTransferSerial(InstanceID id, CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID);

	///请求查询银期签约关系
	C_API int ReqQryAccountregister(InstanceID id, CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID);

	///请求查询签约银行
	C_API int ReqQryContractBank(InstanceID id, CThostFtdcQryContractBankField *pQryContractBank, int nRequestID);

	///请求查询预埋单
	C_API int ReqQryParkedOrder(InstanceID id, CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID);

	///请求查询预埋撤单
	C_API int ReqQryParkedOrderAction(InstanceID id, CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID);

	///请求查询交易通知
	C_API int ReqQryTradingNotice(InstanceID id, CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID);

	///请求查询经纪公司交易参数
	C_API int ReqQryBrokerTradingParams(InstanceID id, CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID);

	///请求查询经纪公司交易算法
	C_API int ReqQryBrokerTradingAlgos(InstanceID id, CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID);

	///期货发起银行资金转期货请求
	C_API int ReqFromBankToFutureByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///期货发起期货资金转银行请求
	C_API int ReqFromFutureToBankByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///期货发起查询银行余额请求
	C_API int ReqQueryBankAccountMoneyByFuture(InstanceID id, CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID);
#ifdef __cplusplus
}
#endif

