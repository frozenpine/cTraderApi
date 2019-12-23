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

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	typedef void (APPWINAPI *CbOnFrontConnected)(InstanceID id);
	C_API void SetCallbackOnFrontConnected(InstanceID id, CbOnFrontConnected handler);

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	typedef void (APPWINAPI *CbOnFrontDisconnected)(InstanceID id, int nReason);
	C_API void SetCallbackOnFrontDisconnected(InstanceID id, CbOnFrontDisconnected handler);

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	typedef void (APPWINAPI *CbOnHeartBeatWarning)(InstanceID id, int nTimeLapse);
	C_API void SetCallbackOnHeartBeatWarning(InstanceID id, CbOnHeartBeatWarning handler);

	///�ͻ�����֤��Ӧ
	typedef void (APPWINAPI *CbOnRspAuthenticate)(
		InstanceID id,
		CThostFtdcRspAuthenticateField *pRspAuthenticateField,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspAuthenticate(InstanceID id, CbOnRspAuthenticate handler);

	///��¼������Ӧ
	typedef void (APPWINAPI *CbOnRspUserLogin)(
		InstanceID id,
		CThostFtdcRspUserLoginField *pRspUserLogin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspUserLogin(InstanceID id, CbOnRspUserLogin handler);

	///�ǳ�������Ӧ
	typedef void (APPWINAPI *CbOnRspUserLogout)(
		InstanceID id,
		CThostFtdcUserLogoutField *pUserLogout,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspUserLogout(InstanceID id, CbOnRspUserLogout handler);

	///�û��������������Ӧ
	typedef void (APPWINAPI *CbOnRspUserPasswordUpdate)(
		InstanceID id,
		CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspUserPasswordUpdate(InstanceID id, CbOnRspUserPasswordUpdate handler);

	///�ʽ��˻��������������Ӧ
	typedef void (APPWINAPI *CbOnRspTradingAccountPasswordUpdate)(
		InstanceID id,
		CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspTradingAccountPasswordUpdate(
		InstanceID id, CbOnRspTradingAccountPasswordUpdate handler);

	///����¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspOrderInsert)(
		InstanceID id,
		CThostFtdcInputOrderField *pInputOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOrderInsert(InstanceID id, CbOnRspOrderInsert handler);

	///Ԥ��¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspParkedOrderInsert)(
		InstanceID id,
		CThostFtdcParkedOrderField *pParkedOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspParkedOrderInsert(InstanceID id, CbOnRspParkedOrderInsert handler);

	///Ԥ�񳷵�¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspParkedOrderAction)(
		InstanceID id,
		CThostFtdcParkedOrderActionField *pParkedOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspParkedOrderAction(InstanceID id, CbOnRspParkedOrderAction handler);

	///��������������Ӧ
	typedef void (APPWINAPI *CbOnRspOrderAction)(
		InstanceID id,
		CThostFtdcInputOrderActionField *pInputOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOrderAction(InstanceID id, CbOnRspOrderAction handler);

	///��ѯ��󱨵�������Ӧ
	typedef void (APPWINAPI *CbOnRspQueryMaxOrderVolume)(
		InstanceID id,
		CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQueryMaxOrderVolume(InstanceID id, CbOnRspQueryMaxOrderVolume handler);

	///Ͷ���߽�����ȷ����Ӧ
	typedef void (APPWINAPI *CbOnRspSettlementInfoConfirm)(
		InstanceID id,
		CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspSettlementInfoConfirm(InstanceID id, CbOnRspSettlementInfoConfirm handler);

	///ɾ��Ԥ����Ӧ
	typedef void (APPWINAPI *CbOnRspRemoveParkedOrder)(
		InstanceID id,
		CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspRemoveParkedOrder(InstanceID id, CbOnRspRemoveParkedOrder handler);

	///ɾ��Ԥ�񳷵���Ӧ
	typedef void (APPWINAPI *CbOnRspRemoveParkedOrderAction)(
		InstanceID id,
		CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspRemoveParkedOrderAction(InstanceID id, CbOnRspRemoveParkedOrderAction handler);

	///ִ������¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspExecOrderInsert)(
		InstanceID id,
		CThostFtdcInputExecOrderField *pInputExecOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspExecOrderInsert(InstanceID id, CbOnRspExecOrderInsert handler);

	///ִ���������������Ӧ
	typedef void (APPWINAPI *CbOnRspExecOrderAction)(
		InstanceID id,
		CThostFtdcInputExecOrderActionField *pInputExecOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspExecOrderAction(InstanceID id, CbOnRspExecOrderAction handler);

	///ѯ��¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspForQuoteInsert)(
		InstanceID id,
		CThostFtdcInputForQuoteField *pInputForQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspForQuoteInsert(InstanceID id, CbOnRspForQuoteInsert handler);

	///����¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspQuoteInsert)(
		InstanceID id,
		CThostFtdcInputQuoteField *pInputQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQuoteInsert(InstanceID id, CbOnRspQuoteInsert handler);

	///���۲���������Ӧ
	typedef void (APPWINAPI *CbOnRspQuoteAction)(
		InstanceID id,
		CThostFtdcInputQuoteActionField *pInputQuoteAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQuoteAction(InstanceID id, CbOnRspQuoteAction handler);

	///������������������Ӧ
	typedef void (APPWINAPI *CbOnRspBatchOrderAction)(
		InstanceID id,
		CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspBatchOrderAction(InstanceID id, CbOnRspBatchOrderAction handler);

	///��Ȩ�ԶԳ�¼��������Ӧ
	typedef void (APPWINAPI *CbOnRspOptionSelfCloseInsert)(
		InstanceID id,
		CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOptionSelfCloseInsert(InstanceID id, CbOnRspOptionSelfCloseInsert handler);

	///��Ȩ�ԶԳ����������Ӧ
	typedef void (APPWINAPI *CbOnRspOptionSelfCloseAction)(
		InstanceID id,
		CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspOptionSelfCloseAction(InstanceID id, CbOnRspOptionSelfCloseAction handler);

	///������ļ��ʽ�ת����Ӧ
	typedef void(APPWINAPI *CbOnRspTransFund)(
		InstanceID id,
		CThostFtdcTransFundField *pTransFund,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspTransFund(InstanceID id, CbOnRspTransFund handler);

	///�����ѯ������Ӧ
	typedef void(APPWINAPI *CbOnRspQryOrder)(
		InstanceID id,
		CThostFtdcOrderField *pOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOrder(InstanceID id, CbOnRspQryOrder handler);

	///�����ѯ�ɽ���Ӧ
	typedef void(APPWINAPI *CbOnRspQryTrade)(
		InstanceID id,
		CThostFtdcTradeField *pTrade,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTrade(InstanceID id, CbOnRspQryTrade handler);

	///�����ѯͶ���ֲ߳���Ӧ
	typedef void(APPWINAPI *CbOnRspQryInvestorPosition)(
		InstanceID id,
		CThostFtdcInvestorPositionField *pInvestorPosition,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorPosition(InstanceID id, CbOnRspQryInvestorPosition handler);

	///�����ѯ�ʽ��˻���Ӧ
	typedef void(APPWINAPI *CbOnRspQryTradingAccount)(
		InstanceID id,
		CThostFtdcTradingAccountField *pTradingAccount,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTradingAccount(InstanceID id, CbOnRspQryTradingAccount handler);

	///�����ѯͶ������Ӧ
	typedef void(APPWINAPI *CbOnRspQryInvestor)(
		InstanceID id,
		CThostFtdcInvestorField *pInvestor,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestor(InstanceID id, CbOnRspQryInvestor handler);

	///�����ѯ���ױ�����Ӧ
	typedef void(APPWINAPI *CbOnRspQryTradingCode)(
		InstanceID id,
		CThostFtdcTradingCodeField *pTradingCode,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTradingCode(InstanceID id, CbOnRspQryTradingCode handler);

	///�����ѯ��Լ��֤������Ӧ
	typedef void(APPWINAPI *CbOnRspQryInstrumentMarginRate)(
		InstanceID id,
		CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrumentMarginRate(InstanceID id, CbOnRspQryInstrumentMarginRate handler);

	///�����ѯ��Լ����������Ӧ
	typedef void(APPWINAPI *CbOnRspQryInstrumentCommissionRate)(
		InstanceID id,
		CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrumentCommissionRate(
		InstanceID id, CbOnRspQryInstrumentCommissionRate handler);

	///�����ѯ��������Ӧ
	typedef void(APPWINAPI *CbOnRspQryExchange)(
		InstanceID id,
		CThostFtdcExchangeField *pExchange,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchange(InstanceID id, CbOnRspQryExchange handler);

	///�����ѯ��Ʒ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryProduct)(
		InstanceID id,
		CThostFtdcProductField *pProduct,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryProduct(InstanceID id, CbOnRspQryProduct handler);

	///�����ѯ��Լ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryInstrument)(
		InstanceID id,
		CThostFtdcInstrumentField *pInstrument,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrument(InstanceID id, CbOnRspQryInstrument handler);

	///�����ѯ������Ӧ
	typedef void(APPWINAPI *CbOnRspQryDepthMarketData)(
		InstanceID id,
		CThostFtdcDepthMarketDataField *pDepthMarketData,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryDepthMarketData(InstanceID id, CbOnRspQryDepthMarketData handler);

	///�����ѯͶ���߽�������Ӧ
	typedef void(APPWINAPI *CbOnRspQrySettlementInfo)(
		InstanceID id,
		CThostFtdcSettlementInfoField *pSettlementInfo,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQrySettlementInfo(InstanceID id, CbOnRspQrySettlementInfo handler);

	///�����ѯ��Լ״̬��Ӧ
	typedef void(APPWINAPI *CbOnRspQryInstrumentStatus)(
		InstanceID id,
		CThostFtdcInstrumentStatusField *pInstrumentStatus,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInstrumentStatus(InstanceID id, CbOnRspQryInstrumentStatus handler);

	///�����ѯת��������Ӧ
	typedef void(APPWINAPI *CbOnRspQryTransferBank)(
		InstanceID id,
		CThostFtdcTransferBankField *pTransferBank,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTransferBank(InstanceID id, CbOnRspQryTransferBank handler);

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryInvestorPositionDetail)(
		InstanceID id,
		CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorPositionDetail(
		InstanceID id, CbOnRspQryInvestorPositionDetail handler);

	///�����ѯ�ͻ�֪ͨ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryNotice)(
		InstanceID id,
		CThostFtdcNoticeField *pNotice,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryNotice(InstanceID id, CbOnRspQryNotice handler);

	///�����ѯ������Ϣȷ����Ӧ
	typedef void(APPWINAPI *CbOnRspQrySettlementInfoConfirm)(
		InstanceID id,
		CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQrySettlementInfoConfirm(InstanceID id, CbOnRspQrySettlementInfoConfirm handler);

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryInvestorPositionCombineDetail)(
		InstanceID id,
		CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorPositionCombineDetail(
		InstanceID id, CbOnRspQryInvestorPositionCombineDetail handler);

	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryCFMMCTradingAccountKey)(
		InstanceID id,
		CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryCFMMCTradingAccountKey(
		InstanceID id, CbOnRspQryCFMMCTradingAccountKey handler);

	///�����ѯ�ֵ��۵���Ϣ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryEWarrantOffset)(
		InstanceID id,
		CThostFtdcEWarrantOffsetField *pEWarrantOffset,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryEWarrantOffset(InstanceID id, CbOnRspQryEWarrantOffset handler);

	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
	typedef void(APPWINAPI *CbOnRspQryInvestorProductGroupMargin)(
		InstanceID id,
		CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryInvestorProductGroupMargin(
		InstanceID id, CbOnRspQryInvestorProductGroupMargin handler);

	///�����ѯ��������֤������Ӧ
	typedef void(APPWINAPI *CbOnRspQryExchangeMarginRate)(
		InstanceID id,
		CThostFtdcExchangeMarginRateField *pExchangeMarginRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchangeMarginRate(InstanceID id, CbOnRspQryExchangeMarginRate handler);

	///�����ѯ������������֤������Ӧ
	typedef void(APPWINAPI *CbOnRspQryExchangeMarginRateAdjust)(
		InstanceID id,
		CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchangeMarginRateAdjust(
		InstanceID id, CbOnRspQryExchangeMarginRateAdjust handler);

	///�����ѯ������Ӧ
	typedef void(APPWINAPI *CbOnRspQryExchangeRate)(
		InstanceID id,
		CThostFtdcExchangeRateField *pExchangeRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExchangeRate(InstanceID id, CbOnRspQryExchangeRate handler);

	///�����ѯ�����������Ա����Ȩ����Ӧ
	typedef void(APPWINAPI *CbOnRspQrySecAgentACIDMap)(
		InstanceID id,
		CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQrySecAgentACIDMap(InstanceID id, CbOnRspQrySecAgentACIDMap handler);

	///�����ѯ��Ȩ���׳ɱ���Ӧ
	typedef void(APPWINAPI *CbOnRspQryOptionInstrTradeCost)(
		InstanceID id,
		CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOptionInstrTradeCost(InstanceID id, CbOnRspQryOptionInstrTradeCost handler);

	///�����ѯ��Ȩ��Լ��������Ӧ
	typedef void(APPWINAPI *CbOnRspQryOptionInstrCommRate)(
		InstanceID id,
		CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOptionInstrCommRate(InstanceID id, CbOnRspQryOptionInstrCommRate handler);

	///�����ѯִ��������Ӧ
	typedef void(APPWINAPI *CbOnRspQryExecOrder)(
		InstanceID id,
		CThostFtdcExecOrderField *pExecOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryExecOrder(InstanceID id, CbOnRspQryExecOrder handler);

	///�����ѯѯ����Ӧ
	typedef void(APPWINAPI *CbOnRspQryForQuote)(
		InstanceID id,
		CThostFtdcForQuoteField *pForQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryForQuote(InstanceID id, CbOnRspQryForQuote handler);

	///�����ѯ������Ӧ
	typedef void(APPWINAPI *CbOnRspQryQuote)(
		InstanceID id,
		CThostFtdcQuoteField *pQuote,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryQuote(InstanceID id, CbOnRspQryQuote handler);

	///�����ѯ��Ȩ�ԶԳ���Ӧ
	typedef void(APPWINAPI *CbOnRspQryOptionSelfClose)(
		InstanceID id,
		CThostFtdcOptionSelfCloseField *pOptionSelfClose,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryOptionSelfClose(InstanceID id, CbOnRspQryOptionSelfClose handler);

	///�����ѯת����ˮ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryTransferSerial)(
		InstanceID id,
		CThostFtdcTransferSerialField *pTransferSerial,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTransferSerial(InstanceID id, CbOnRspQryTransferSerial handler);

	///�����ѯ����ǩԼ��ϵ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryAccountregister)(
		InstanceID id,
		CThostFtdcAccountregisterField *pAccountregister,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryAccountregister(InstanceID id, CbOnRspQryAccountregister handler);

	///����Ӧ��
	typedef void (APPWINAPI *CbOnRspError)(
		InstanceID id, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspError(InstanceID id, CbOnRspError handler);

	///����֪ͨ
	typedef void (APPWINAPI *CbOnRtnOrder)(InstanceID id, CThostFtdcOrderField *pOrder);
	C_API void SetCallbackOnRtnOrder(InstanceID id, CbOnRtnOrder handler);

	///�ɽ�֪ͨ
	typedef void (APPWINAPI *CbOnRtnTrade)(InstanceID id, CThostFtdcTradeField *pTrade);
	C_API void SetCallbackOnRtnTrade(InstanceID id, CbOnRtnTrade handler);

	///����¼�����ر�
	typedef void (APPWINAPI *CbOnErrRtnOrderInsert)(
		InstanceID id, CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOrderInsert(InstanceID id, CbOnErrRtnOrderInsert handler);

	///������������ر�
	typedef void (APPWINAPI *CbOnErrRtnOrderAction)(
		InstanceID id, CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOrderAction(InstanceID id, CbOnErrRtnOrderAction handler);

	///��Լ����״̬֪ͨ
	typedef void(APPWINAPI *CbOnRtnInstrumentStatus)(
		InstanceID id, CThostFtdcInstrumentStatusField *pInstrumentStatus);
	C_API void SetCallbackOnRtnInstrumentStatus(InstanceID id, CbOnRtnInstrumentStatus handler);

	///����֪ͨ
	typedef void (APPWINAPI *CbOnRtnTradingNotice)(InstanceID id, CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	C_API void SetCallbackOnRtnTradingNotice(InstanceID id, CbOnRtnTradingNotice handler);

	///��ʾ������У�����
	typedef void(APPWINAPI *CbOnRtnErrorConditionalOrder)(
		InstanceID id, CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	C_API void SetCallbackOnRtnErrorConditionalOrder(InstanceID id, CbOnRtnErrorConditionalOrder handler);

	///ִ������֪ͨ
	typedef void(APPWINAPI *CbOnRtnExecOrder)(InstanceID id, CThostFtdcExecOrderField *pExecOrder);
	C_API void SetCallbackOnRtnExecOrder(InstanceID id, CbOnRtnExecOrder handler);

	///ִ������¼�����ر�
	typedef void(APPWINAPI *CbOnErrRtnExecOrderInsert)(
		InstanceID id, CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnExecOrderInsert(InstanceID id, CbOnErrRtnExecOrderInsert handler);

	///ִ�������������ر�
	typedef void(APPWINAPI *CbOnErrRtnExecOrderAction)(
		InstanceID id, CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnExecOrderAction(InstanceID id, CbOnErrRtnExecOrderAction handler);

	///ѯ��¼�����ر�
	typedef void(APPWINAPI *CbOnErrRtnForQuoteInsert)(
		InstanceID id, CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnForQuoteInsert(InstanceID id, CbOnErrRtnForQuoteInsert handler);

	///����֪ͨ
	typedef void(APPWINAPI *CbOnRtnQuote)(InstanceID id, CThostFtdcQuoteField *pQuote);
	C_API void SetCallbackOnRtnQuote(InstanceID id, CbOnRtnQuote handler);

	///����¼�����ر�
	typedef void(APPWINAPI *CbOnErrRtnQuoteInsert)(
		InstanceID id, CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnQuoteInsert(InstanceID id, CbOnErrRtnQuoteInsert handler);

	///���۲�������ر�
	typedef void(APPWINAPI *CbOnErrRtnQuoteAction)(
		InstanceID id, CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnQuoteAction(InstanceID id, CbOnErrRtnQuoteAction handler);

	///ѯ��֪ͨ
	typedef void(APPWINAPI *CbOnRtnForQuoteRsp)(InstanceID id, CThostFtdcForQuoteRspField *pForQuoteRsp);
	C_API void SetCallbackOnRtnForQuoteRsp(InstanceID id, CbOnRtnForQuoteRsp handler);

	///����������������ر�
	typedef void(APPWINAPI *CbOnErrRtnBatchOrderAction)(
		InstanceID id, CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnBatchOrderAction(InstanceID id, CbOnErrRtnBatchOrderAction handler);

	///��Ȩ�ԶԳ�֪ͨ
	typedef void(APPWINAPI *CbOnRtnOptionSelfClose)(InstanceID id, CThostFtdcOptionSelfCloseField *pOptionSelfClose);
	C_API void SetCallbackOnRtnOptionSelfClose(InstanceID id, CbOnRtnOptionSelfClose handler);

	///��Ȩ�ԶԳ�¼�����ر�
	typedef void(APPWINAPI *CbOnErrRtnOptionSelfCloseInsert)(
		InstanceID id, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOptionSelfCloseInsert(InstanceID id, CbOnErrRtnOptionSelfCloseInsert handler);

	///��Ȩ�ԶԳ��������ر�
	typedef void(APPWINAPI *CbOnErrRtnOptionSelfCloseAction)(
		InstanceID id, CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnOptionSelfCloseAction(InstanceID id, CbOnErrRtnOptionSelfCloseAction handler);

	///�����ѯǩԼ������Ӧ
	typedef void(APPWINAPI *CbOnRspQryContractBank)(
		InstanceID id,
		CThostFtdcContractBankField *pContractBank,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryContractBank(InstanceID id, CbOnRspQryContractBank handler);

	///�����ѯԤ����Ӧ
	typedef void(APPWINAPI *CbOnRspQryParkedOrder)(
		InstanceID id,
		CThostFtdcParkedOrderField *pParkedOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryParkedOrder(InstanceID id, CbOnRspQryParkedOrder handler);

	///�����ѯԤ�񳷵���Ӧ
	typedef void(APPWINAPI *CbOnRspQryParkedOrderAction)(
		InstanceID id,
		CThostFtdcParkedOrderActionField *pParkedOrderAction,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryParkedOrderAction(InstanceID id, CbOnRspQryParkedOrderAction handler);

	///�����ѯ����֪ͨ��Ӧ
	typedef void(APPWINAPI *CbOnRspQryTradingNotice)(
		InstanceID id,
		CThostFtdcTradingNoticeField *pTradingNotice,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryTradingNotice(InstanceID id, CbOnRspQryTradingNotice handler);

	///�����ѯ���͹�˾���ײ�����Ӧ
	typedef void(APPWINAPI *CbOnRspQryBrokerTradingParams)(
		InstanceID id,
		CThostFtdcBrokerTradingParamsField *pBrokerTradingParams,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQryBrokerTradingParams(InstanceID id, CbOnRspQryBrokerTradingParams handler);

	///�����ѯ���͹�˾�����㷨��Ӧ
	typedef void(APPWINAPI *CbOnRspQryBrokerTradingAlgos)(
		InstanceID id,
		CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQRyBrokerTradingAlgos(InstanceID id, CbOnRspQryBrokerTradingAlgos handler);

	///���з��������ʽ�ת�ڻ�֪ͨ
	typedef void(APPWINAPI *CbOnRtnFromBankToFutureByBank)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromBankToFutureByBank(InstanceID id, CbOnRtnFromBankToFutureByBank handler);

	///���з����ڻ��ʽ�ת����֪ͨ
	typedef void(APPWINAPI *CbOnRtnFromFutureToBankByBank)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromFutureToBankByBank(InstanceID id, CbOnRtnFromFutureToBankByBank handler);

	///���з����������ת�ڻ�֪ͨ
	typedef void(APPWINAPI *CbOnRtnRepealFromBankToFutureByBank)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromBankToFutureByBank(
		InstanceID id, CbOnRtnRepealFromBankToFutureByBank handler);

	///���з�������ڻ�ת����֪ͨ
	typedef void(APPWINAPI *CbOnRtnRepealFromFutureToBankByBank)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromFutureToBankByBank(
		InstanceID id, CbOnRtnRepealFromFutureToBankByBank handler);

	///�ڻ����������ʽ�ת�ڻ�֪ͨ
	typedef void(APPWINAPI *CbOnRtnFromBankToFutureByFuture)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromBankToFutureByFuture(InstanceID id, CbOnRtnFromBankToFutureByFuture handler);

	///�ڻ������ڻ��ʽ�ת����֪ͨ
	typedef void(APPWINAPI *CbOnRtnFromFutureToBankByFuture)(InstanceID id, CThostFtdcRspTransferField *pRspTransfer);
	C_API void SetCallbackOnRtnFromFutureToBankByFuture(InstanceID id, CbOnRtnFromFutureToBankByFuture handler);

	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
	typedef void(APPWINAPI *CbOnRtnRepealFromBankToFutureByFutureManual)(
		InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromBankToFutureByFutureManual(
		InstanceID id, CbOnRtnRepealFromBankToFutureByFutureManual handler);

	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
	typedef void(APPWINAPI *CbOnRtnRepealFromFutureToBankByFutureManual)(
		InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromFutureToBankByFutureManual(
		InstanceID id, CbOnRtnRepealFromFutureToBankByFutureManual handler);

	///�ڻ������ѯ�������֪ͨ
	typedef void(APPWINAPI *CbOnRtnQueryBankBalanceByFuture)(
		InstanceID id, CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	C_API void SetCallbackOnRtnQueryBankBalanceByFuture(InstanceID id, CbOnRtnQueryBankBalanceByFuture handler);

	///�ڻ����������ʽ�ת�ڻ�����ر�
	typedef void(APPWINAPI *CbOnErrRtnBankToFutureByFuture)(
		InstanceID id, CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnBankToFutureByFuture(InstanceID id, CbOnErrRtnBankToFutureByFuture handler);

	///�ڻ������ڻ��ʽ�ת���д���ر�
	typedef void(APPWINAPI *CbOnErrRtnFutureToBankByFuture)(
		InstanceID id, CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnFutureToBankByFuture(InstanceID id, CbOnErrRtnFutureToBankByFuture handler);

	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
	typedef void(APPWINAPI *CbOnErrRtnRepealBankToFutureByFutureManual)(
		InstanceID id, CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnRepealBankToFutureByFutureManual(
		InstanceID id, CbOnErrRtnRepealBankToFutureByFutureManual handler);

	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
	typedef void(APPWINAPI *CbOnErrRtnRepealFutureToBankByFutureManual)(
		InstanceID id, CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnRepealFutureToBankByFutureManual(
		InstanceID id, CbOnErrRtnRepealFutureToBankByFutureManual handler);

	///�ڻ������ѯ����������ر�
	typedef void(APPWINAPI *CbOnErrRtnQueryBankBalanceByFuture)(
		InstanceID id, CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	C_API void SetCallbackOnErrRtnQueryBankBalanceByFuture(
		InstanceID id, CbOnErrRtnQueryBankBalanceByFuture handler);

	///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
	typedef void(APPWINAPI *CbOnRtnRepealFromBankToFutureByFuture)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromBankToFutureByFuture(
		InstanceID id, CbOnRtnRepealFromBankToFutureByFuture handler);

	///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
	typedef void(APPWINAPI *CbOnRtnRepealFromFutureToBankByFuture)(InstanceID id, CThostFtdcRspRepealField *pRspRepeal);
	C_API void SetCallbackOnRtnRepealFromFutureToBankByFuture(
		InstanceID id, CbOnRtnRepealFromFutureToBankByFuture handler);

	///�ڻ����������ʽ�ת�ڻ�Ӧ��
	typedef void(APPWINAPI *CbOnRspFromBankToFutureByFuture)(
		InstanceID id,
		CThostFtdcReqTransferField *pReqTransfer,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspFromBankToFutureByFuture(InstanceID id, CbOnRspFromBankToFutureByFuture handler);

	///�ڻ������ڻ��ʽ�ת����Ӧ��
	typedef void(APPWINAPI *CbOnRspFromFutureToBankByFuture)(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspFromFutureToBankByFuture(InstanceID id, CbOnRspFromFutureToBankByFuture handler);

	///�ڻ������ѯ�������Ӧ��
	typedef void(APPWINAPI *CbOnRspQueryBankAccountMoneyByFuture)(
		InstanceID id,
		CThostFtdcReqQueryAccountField *pReqQueryAccount,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	C_API void SetCallbackOnRspQueryBankAccountMoneyByFuture(
		InstanceID id, CbOnRspQueryBankAccountMoneyByFuture handler);

	///���з������ڿ���֪ͨ
	typedef void(APPWINAPI *CbOnRtnOpenAccountByBank)(InstanceID id, CThostFtdcOpenAccountField *pOpenAccount);
	C_API void SetCallbackOnRtnOpenAccountByBank(InstanceID id, CbOnRtnOpenAccountByBank handler);

	///���з�����������֪ͨ
	typedef void(APPWINAPI *CbOnRtnCancelAccountByBank)(InstanceID id, CThostFtdcCancelAccountField *pCancelAccount);
	C_API void SetCallbackOnRtnCancelAccountByBank(InstanceID id, CbOnRtnCancelAccountByBank handler);

	///���з����������˺�֪ͨ
	typedef void(APPWINAPI *CbOnRtnChangeAccountByBank)(InstanceID id, CThostFtdcChangeAccountField *pChangeAccount);
	C_API void SetCallbackOnRtnChangeAccountByBank(InstanceID id, CbOnRtnChangeAccountByBank handler);

	typedef struct {
		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		CbOnFrontConnected onFrontConnected;

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		CbOnFrontDisconnected onFrontDisconnected;

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		CbOnHeartBeatWarning onHeartBeatWarning;

		///�ͻ�����֤��Ӧ
		CbOnRspAuthenticate onRspAuthenticate;

		///��¼������Ӧ
		CbOnRspUserLogin onRspUserLogin;

		///�ǳ�������Ӧ
		CbOnRspUserLogout onRspUserLogout;

		///�û��������������Ӧ
		CbOnRspUserPasswordUpdate onRspUserPasswordUpdate;

		///�ʽ��˻��������������Ӧ
		CbOnRspTradingAccountPasswordUpdate onRspTradingAccountPasswordUpdate;

		///����¼��������Ӧ
		CbOnRspOrderInsert onRspOrderInsert;

		///Ԥ��¼��������Ӧ
		CbOnRspParkedOrderInsert onRspParkedOrderInsert;

		///Ԥ�񳷵�¼��������Ӧ
		CbOnRspParkedOrderAction onRspParkedOrderAction;

		///��������������Ӧ
		CbOnRspOrderAction onRspOrderAction;

		///��ѯ��󱨵�������Ӧ
		CbOnRspQueryMaxOrderVolume onRspQueryMaxOrderVolume;

		///Ͷ���߽�����ȷ����Ӧ
		CbOnRspSettlementInfoConfirm onRspSettlementInfoConfirm;

		///ɾ��Ԥ����Ӧ
		CbOnRspRemoveParkedOrder onRspRemoveParkedOrder;

		///ɾ��Ԥ�񳷵���Ӧ
		CbOnRspRemoveParkedOrderAction onRspRemoveParkedOrderAction;

		///ִ������¼��������Ӧ
		CbOnRspExecOrderInsert onRspExecOrderInsert;

		///ִ���������������Ӧ
		CbOnRspExecOrderAction onRspExecOrderAction;

		///ѯ��¼��������Ӧ
		CbOnRspForQuoteInsert onRspForQuoteInsert;

		///����¼��������Ӧ
		CbOnRspQuoteInsert onRspQuoteInsert;

		///���۲���������Ӧ
		CbOnRspQuoteAction onRspQuoteAction;

		///������������������Ӧ
		CbOnRspBatchOrderAction onRspBatchOrderAction;

		///��Ȩ�ԶԳ�¼��������Ӧ
		CbOnRspOptionSelfCloseInsert onRspOptionSelfCloseInsert;

		///��Ȩ�ԶԳ����������Ӧ
		CbOnRspOptionSelfCloseAction onRspOptionSelfCloseAction;

		///������ļ��ʽ�ת����Ӧ
		CbOnRspTransFund onRspTransFund;

		///�����ѯ������Ӧ
		CbOnRspQryOrder onRspQryOrder;

		///�����ѯ�ɽ���Ӧ
		CbOnRspQryTrade onRspQryTrade;

		///�����ѯͶ���ֲ߳���Ӧ
		CbOnRspQryInvestorPosition onRspQryInvestorPosition;

		///�����ѯ�ʽ��˻���Ӧ
		CbOnRspQryTradingAccount onRspQryTradingAccount;

		///�����ѯͶ������Ӧ
		CbOnRspQryInvestor onRspQryInvestor;

		///�����ѯ���ױ�����Ӧ
		CbOnRspQryTradingCode onRspQryTradingCode;

		///�����ѯ��Լ��֤������Ӧ
		CbOnRspQryInstrumentMarginRate onRspQryInstrumentMarginRate;

		///�����ѯ��Լ����������Ӧ
		CbOnRspQryInstrumentCommissionRate onRspQryInstrumentCommissionRate;

		///�����ѯ��������Ӧ
		CbOnRspQryExchange onRspQryExchange;

		///�����ѯ��Ʒ��Ӧ
		CbOnRspQryProduct onRspQryProduct;

		///�����ѯ��Լ��Ӧ
		CbOnRspQryInstrument onRspQryInstrument;

		///�����ѯ������Ӧ
		CbOnRspQryDepthMarketData onRspQryDepthMarketData;

		///�����ѯͶ���߽�������Ӧ
		CbOnRspQrySettlementInfo onRspQrySettlementInfo;

		///�����ѯ��Լ״̬��Ӧ
		CbOnRspQryInstrumentStatus onRspQryInstrumentStatus;

		///�����ѯת��������Ӧ
		CbOnRspQryTransferBank onRspQryTransferBank;

		///�����ѯͶ���ֲ߳���ϸ��Ӧ
		CbOnRspQryInvestorPositionDetail onRspQryInvestorPositionDetail;

		///�����ѯ�ͻ�֪ͨ��Ӧ
		CbOnRspQryNotice onRspQryNotice;

		///�����ѯ������Ϣȷ����Ӧ
		CbOnRspQrySettlementInfoConfirm onRspQrySettlementInfoConfirm;

		///�����ѯͶ���ֲ߳���ϸ��Ӧ
		CbOnRspQryInvestorPositionCombineDetail onRspQryInvestorPositionCombineDetail;

		///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
		CbOnRspQryCFMMCTradingAccountKey onRspQryCFMMCTradingAccountKey;

		///�����ѯ�ֵ��۵���Ϣ��Ӧ
		CbOnRspQryEWarrantOffset onRspQryEWarrantOffset;

		///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
		CbOnRspQryInvestorProductGroupMargin onRspQryInvestorProductGroupMargin;

		///�����ѯ��������֤������Ӧ
		CbOnRspQryExchangeMarginRate onRspQryExchangeMarginRate;

		///�����ѯ������������֤������Ӧ
		CbOnRspQryExchangeMarginRateAdjust onRspQryExchangeMarginRateAdjust;

		///�����ѯ������Ӧ
		CbOnRspQryExchangeRate onRspQryExchangeRate;

		///�����ѯ�����������Ա����Ȩ����Ӧ
		CbOnRspQrySecAgentACIDMap onRspQrySecAgentACIDMap;

		///�����ѯ��Ȩ���׳ɱ���Ӧ
		CbOnRspQryOptionInstrTradeCost onRspQryOptionInstrTradeCost;

		///�����ѯ��Ȩ��Լ��������Ӧ
		CbOnRspQryOptionInstrCommRate onRspQryOptionInstrCommRate;

		///�����ѯִ��������Ӧ
		CbOnRspQryExecOrder onRspQryExecOrder;

		///�����ѯѯ����Ӧ
		CbOnRspQryForQuote onRspQryForQuote;

		///�����ѯ������Ӧ
		CbOnRspQryQuote onRspQryQuote;

		///�����ѯ��Ȩ�ԶԳ���Ӧ
		CbOnRspQryOptionSelfClose onRspQryOptionSelfClose;

		///�����ѯת����ˮ��Ӧ
		CbOnRspQryTransferSerial onRspQryTransferSerial;

		///�����ѯ����ǩԼ��ϵ��Ӧ
		CbOnRspQryAccountregister onRspQryAccountregister;

		///����Ӧ��
		CbOnRspError onRspError;

		///����֪ͨ
		CbOnRtnOrder onRtnOrder;

		///�ɽ�֪ͨ
		CbOnRtnTrade onRtnTrade;

		///����¼�����ر�
		CbOnErrRtnOrderInsert onErrRtnOrderInsert;

		///������������ر�
		CbOnErrRtnOrderAction onErrRtnOrderAction;

		///��Լ����״̬֪ͨ
		CbOnRtnInstrumentStatus onRtnInstrumentStatus;

		///����֪ͨ
		CbOnRtnTradingNotice onRtnTradingNotice;

		///��ʾ������У�����
		CbOnRtnErrorConditionalOrder onRtnErrorConditionalOrder;

		///ִ������֪ͨ
		CbOnRtnExecOrder onRtnExecOrder;

		///ִ������¼�����ر�
		CbOnErrRtnExecOrderInsert onErrRtnExecOrderInsert;

		///ִ�������������ر�
		CbOnErrRtnExecOrderAction onErrRtnExecOrderAction;

		///ѯ��¼�����ر�
		CbOnErrRtnForQuoteInsert onErrRtnForQuoteInsert;

		///����֪ͨ
		CbOnRtnQuote onRtnQuote;

		///����¼�����ر�
		CbOnErrRtnQuoteInsert onErrRtnQuoteInsert;

		///���۲�������ر�
		CbOnErrRtnQuoteAction onErrRtnQuoteAction;

		///ѯ��֪ͨ
		CbOnRtnForQuoteRsp onRtnForQuoteRsp;

		///����������������ر�
		CbOnErrRtnBatchOrderAction onErrRtnBatchOrderAction;

		///��Ȩ�ԶԳ�֪ͨ
		CbOnRtnOptionSelfClose onRtnOptionSelfClose;

		///��Ȩ�ԶԳ�¼�����ر�
		CbOnErrRtnOptionSelfCloseInsert onErrRtnOptionSelfCloseInsert;

		///��Ȩ�ԶԳ��������ر�
		CbOnErrRtnOptionSelfCloseAction onErrRtnOptionSelfCloseAction;

		///�����ѯǩԼ������Ӧ
		CbOnRspQryContractBank onRspQryContractBank;

		///�����ѯԤ����Ӧ
		CbOnRspQryParkedOrder onRspQryParkedOrder;

		///�����ѯԤ�񳷵���Ӧ
		CbOnRspQryParkedOrderAction onRspQryParkedOrderAction;

		///�����ѯ����֪ͨ��Ӧ
		CbOnRspQryTradingNotice onRspQryTradingNotice;

		///�����ѯ���͹�˾���ײ�����Ӧ
		CbOnRspQryBrokerTradingParams onRspQryBrokerTradingParams;

		///�����ѯ���͹�˾�����㷨��Ӧ
		CbOnRspQryBrokerTradingAlgos onRspQryBrokerTradingAlgos;

		///���з��������ʽ�ת�ڻ�֪ͨ
		CbOnRtnFromBankToFutureByBank onRtnFromBankToFutureByBank;

		///���з����ڻ��ʽ�ת����֪ͨ
		CbOnRtnFromFutureToBankByBank onRtnFromFutureToBankByBank;

		///���з����������ת�ڻ�֪ͨ
		CbOnRtnRepealFromBankToFutureByBank onRtnRepealFromBankToFutureByBank;

		///���з�������ڻ�ת����֪ͨ
		CbOnRtnRepealFromFutureToBankByBank onRtnRepealFromFutureToBankByBank;

		///�ڻ����������ʽ�ת�ڻ�֪ͨ
		CbOnRtnFromBankToFutureByFuture onRtnFromBankToFutureByFuture;

		///�ڻ������ڻ��ʽ�ת����֪ͨ
		CbOnRtnFromFutureToBankByFuture onRtnFromFutureToBankByFuture;

		///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
		CbOnRtnRepealFromBankToFutureByFutureManual onRtnRepealFromBankToFutureByFutureManual;

		///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
		CbOnRtnRepealFromFutureToBankByFutureManual onRtnRepealFromFutureToBankByFutureManual;

		///�ڻ������ѯ�������֪ͨ
		CbOnRtnQueryBankBalanceByFuture onRtnQueryBankBalanceByFuture;

		///�ڻ����������ʽ�ת�ڻ�����ر�
		CbOnErrRtnBankToFutureByFuture onErrRtnBankToFutureByFuture;

		///�ڻ������ڻ��ʽ�ת���д���ر�
		CbOnErrRtnFutureToBankByFuture onErrRtnFutureToBankByFuture;

		///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
		CbOnErrRtnRepealBankToFutureByFutureManual onErrRtnRepealBankToFutureByFutureManual;

		///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
		CbOnErrRtnRepealFutureToBankByFutureManual onErrRtnRepealFutureToBankByFutureManual;

		///�ڻ������ѯ����������ر�
		CbOnErrRtnQueryBankBalanceByFuture onErrRtnQueryBankBalanceByFuture;

		///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
		CbOnRtnRepealFromBankToFutureByFuture onRtnRepealFromBankToFutureByFuture;

		///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
		CbOnRtnRepealFromFutureToBankByFuture onRtnRepealFromFutureToBankByFuture;

		///�ڻ����������ʽ�ת�ڻ�Ӧ��
		CbOnRspFromBankToFutureByFuture onRspFromBankToFutureByFuture;

		///�ڻ������ڻ��ʽ�ת����Ӧ��
		CbOnRspFromFutureToBankByFuture onRspFromFutureToBankByFuture;

		///�ڻ������ѯ�������Ӧ��
		CbOnRspQueryBankAccountMoneyByFuture onRspQueryBankAccountMoneyByFuture;

		///���з������ڿ���֪ͨ
		CbOnRtnOpenAccountByBank onRtnOpenAccountByBank;

		///���з�����������֪ͨ
		CbOnRtnCancelAccountByBank onRtnCancelAccountByBank;

		///���з����������˺�֪ͨ
		CbOnRtnChangeAccountByBank onRtnChangeAccountByBank;
	} callbackVirtualTable;

	C_API void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt);

	///����API�ӿ�ʵ��
	///@return �ӿ�ʵ����
	C_API InstanceID CreateApi();

	///��ȡAPI�İ汾��Ϣ
	///@retrun ��ȡ���İ汾��
	C_API const char *GetApiVersion();

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	C_API void Release(InstanceID id);

	///��ʼ��
	///@param bContinuous Ϊtrue��ʾ�̲߳�����
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	C_API void Init(InstanceID id, const char *pszFlowPath, bool bContinuous);

	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	C_API int Join(InstanceID id);

	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	C_API const char *GetTradingDay(InstanceID id);

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001����
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	C_API void RegisterFront(InstanceID id, char *pszFrontAddress);

	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001����
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterNameServer������RegisterFront
	C_API void RegisterNameServer(InstanceID id, char *pszNsAddress);

	///ע�����ַ������û���Ϣ
	///@param pFensUserInfo���û���Ϣ��
	C_API void RegisterFensUserInfo(InstanceID id, CThostFtdcFensUserInfoField *pFensUserInfo);

	///����˽������
	///@param nResumeType ˽�����ش���ʽ
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	C_API void SubscribePrivateTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType);

	///���Ĺ�������
	///@param nResumeType �������ش���ʽ
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	C_API void SubscribePublicTopic(InstanceID id, THOST_TE_RESUME_TYPE nResumeType);

	///�ͻ�����֤����
	C_API int ReqAuthenticate(InstanceID id, CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID);

	///�û���¼����
	C_API int ReqUserLogin(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///�û����ܵ�¼����
	C_API int ReqUserLoginEncrypt(InstanceID id, CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///�ǳ�����
	C_API int ReqUserLogout(InstanceID id, CThostFtdcUserLogoutField *pUserLogout, int nRequestID);

	///�û������������
	C_API int ReqUserPasswordUpdate(InstanceID id, CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///�ʽ��˻������������
	C_API int ReqTradingAccountPasswordUpdate(InstanceID id, CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID);

	///����¼������
	C_API int ReqOrderInsert(InstanceID id, CThostFtdcInputOrderField *pInputOrder, int nRequestID);

	///Ԥ��¼������
	C_API int ReqParkedOrderInsert(InstanceID id, CThostFtdcParkedOrderField *pParkedOrder, int nRequestID);

	///Ԥ�񳷵�¼������
	C_API int ReqParkedOrderAction(InstanceID id, CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID);

	///������������
	C_API int ReqOrderAction(InstanceID id, CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID);

	///��ѯ��󱨵���������
	C_API int ReqQueryMaxOrderVolume(InstanceID id, CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID);

	///Ͷ���߽�����ȷ��
	C_API int ReqSettlementInfoConfirm(InstanceID id, CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID);

	///����ɾ��Ԥ��
	C_API int ReqRemoveParkedOrder(InstanceID id, CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID);

	///����ɾ��Ԥ�񳷵�
	C_API int ReqRemoveParkedOrderAction(InstanceID id, CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID);

	///ִ������¼������
	C_API int ReqExecOrderInsert(InstanceID id, CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///ִ�������������
	C_API int ReqExecOrderAction(InstanceID id, CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID);

	///ѯ��¼������
	C_API int ReqForQuoteInsert(InstanceID id, CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID);

	///����¼������
	C_API int ReqQuoteInsert(InstanceID id, CThostFtdcInputQuoteField *pInputQuote, int nRequestID);

	///���۲�������
	C_API int ReqQuoteAction(InstanceID id, CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID);

	///����������������
	C_API int ReqBatchOrderAction(InstanceID id, CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID);

	///��Ȩ�ԶԳ�¼������
	C_API int ReqOptionSelfCloseInsert(InstanceID id, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID);

	///��Ȩ�ԶԳ��������
	C_API int ReqOptionSelfCloseAction(InstanceID id, CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID);

	///������ļ��ʽ�ת��
	C_API int ReqTransFund(InstanceID id, CThostFtdcTransFundField *pFtdcTransFund, int nRequestID);

	///�����ѯ����
	C_API int ReqQryOrder(InstanceID id, CThostFtdcQryOrderField *pQryOrder, int nRequestID);

	///�����ѯ�ɽ�
	C_API int ReqQryTrade(InstanceID id, CThostFtdcQryTradeField *pQryTrade, int nRequestID);

	///�����ѯͶ���ֲ߳�
	C_API int ReqQryInvestorPosition(InstanceID id, CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID);

	///�����ѯ�ʽ��˻�
	C_API int ReqQryTradingAccount(InstanceID id, CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID);

	///�����ѯͶ����
	C_API int ReqQryInvestor(InstanceID id, CThostFtdcQryInvestorField *pQryInvestor, int nRequestID);

	///�����ѯ���ױ���
	C_API int ReqQryTradingCode(InstanceID id, CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID);

	///�����ѯ��Լ��֤����
	C_API int ReqQryInstrumentMarginRate(InstanceID id, CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID);

	///�����ѯ��Լ��������
	C_API int ReqQryInstrumentCommissionRate(InstanceID id, CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID);

	///�����ѯ������
	C_API int ReqQryExchange(InstanceID id, CThostFtdcQryExchangeField *pQryExchange, int nRequestID);

	///�����ѯ��Ʒ
	C_API int ReqQryProduct(InstanceID id, CThostFtdcQryProductField *pQryProduct, int nRequestID);

	///�����ѯ��Լ
	C_API int ReqQryInstrument(InstanceID id, CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///�����ѯ����
	C_API int ReqQryDepthMarketData(InstanceID id, CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID);

	///�����ѯ��Ȩ�ԶԳ�
	C_API int ReqQryOptionSelfClose(InstanceID id, CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID);

	///�����ѯͶ���߽�����
	C_API int ReqQrySettlementInfo(InstanceID id, CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID);

	///�����ѯ��Լ״̬
	C_API int ReqQryInstrumentStatus(InstanceID id, CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///�����ѯת������
	C_API int ReqQryTransferBank(InstanceID id, CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID);

	///�����ѯͶ���ֲ߳���ϸ
	C_API int ReqQryInvestorPositionDetail(InstanceID id, CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID);

	///�����ѯ�ͻ�֪ͨ
	C_API int ReqQryNotice(InstanceID id, CThostFtdcQryNoticeField *pQryNotice, int nRequestID);

	///�����ѯ������Ϣȷ��
	C_API int ReqQrySettlementInfoConfirm(InstanceID id, CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID);

	///�����ѯͶ���ֲ߳���ϸ
	C_API int ReqQryInvestorPositionCombineDetail(InstanceID id, CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID);

	///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
	C_API int ReqQryCFMMCTradingAccountKey(InstanceID id, CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID);

	///�����ѯ�ֵ��۵���Ϣ
	C_API int ReqQryEWarrantOffset(InstanceID id, CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID);

	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
	C_API int ReqQryInvestorProductGroupMargin(InstanceID id, CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID);

	///�����ѯ��������֤����
	C_API int ReqQryExchangeMarginRate(InstanceID id, CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID);

	///�����ѯ������������֤����
	C_API int ReqQryExchangeMarginRateAdjust(InstanceID id, CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID);

	///�����ѯ����
	C_API int ReqQryExchangeRate(InstanceID id, CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);

	///�����ѯ�����������Ա����Ȩ��
	C_API int ReqQrySecAgentACIDMap(InstanceID id, CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID);

	///�����ѯ��Ȩ���׳ɱ�
	C_API int ReqQryOptionInstrTradeCost(InstanceID id, CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID);

	///�����ѯ��Ȩ��Լ������
	C_API int ReqQryOptionInstrCommRate(InstanceID id, CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID);

	///�����ѯִ������
	C_API int ReqQryExecOrder(InstanceID id, CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///�����ѯѯ��
	C_API int ReqQryForQuote(InstanceID id, CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID);

	///�����ѯ����
	C_API int ReqQryQuote(InstanceID id, CThostFtdcQryQuoteField *pQryQuote, int nRequestID);

	///�����ѯת����ˮ
	C_API int ReqQryTransferSerial(InstanceID id, CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID);

	///�����ѯ����ǩԼ��ϵ
	C_API int ReqQryAccountregister(InstanceID id, CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID);

	///�����ѯǩԼ����
	C_API int ReqQryContractBank(InstanceID id, CThostFtdcQryContractBankField *pQryContractBank, int nRequestID);

	///�����ѯԤ��
	C_API int ReqQryParkedOrder(InstanceID id, CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID);

	///�����ѯԤ�񳷵�
	C_API int ReqQryParkedOrderAction(InstanceID id, CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID);

	///�����ѯ����֪ͨ
	C_API int ReqQryTradingNotice(InstanceID id, CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID);

	///�����ѯ���͹�˾���ײ���
	C_API int ReqQryBrokerTradingParams(InstanceID id, CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID);

	///�����ѯ���͹�˾�����㷨
	C_API int ReqQryBrokerTradingAlgos(InstanceID id, CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID);

	///�ڻ����������ʽ�ת�ڻ�����
	C_API int ReqFromBankToFutureByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///�ڻ������ڻ��ʽ�ת��������
	C_API int ReqFromFutureToBankByFuture(InstanceID id, CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///�ڻ������ѯ�����������
	C_API int ReqQueryBankAccountMoneyByFuture(InstanceID id, CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID);
#ifdef __cplusplus
}
#endif

