#pragma once
#include <string.h>

#include "cThostTraderApi.h"
#include "ThostFtdcTraderApi.h"

C_API class cTraderApi : public CThostFtdcTraderSpi
{
public:
	cTraderApi() { initVTCallback(); };
	cTraderApi(const char *pszFlowPath) {
		CreateApi(pszFlowPath);

		initVTCallback();
	};
protected:
	~cTraderApi() {
		if (pApi == NULL) {
			return;
		}

		Release();
	};

private:
	CThostFtdcTraderApi *pApi;
	// Callback virtual table
	// Only used in C wrapper for Other Language
	callbackVirtualTable vtCallback;

	void initVTCallback() { memset(&vtCallback, 0, sizeof(callbackVirtualTable)); }

public:
	///��ȡAPI�İ汾��Ϣ
	///@retrun ��ȡ���İ汾��
	static const char *GetApiVersion();

	int CreateApi(const char *pszFlowPath = "");

	///��ʼ��
	///@param bContinuous Ϊtrue��ʾ�̲߳�����
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	void Init(bool bContinuous = false);

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	void Release();

	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	int Join();

	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	const char *GetTradingDay();

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001����
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	void RegisterFront(char *pszFrontAddress);

	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001����
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterNameServer������RegisterFront
	void RegisterNameServer(char *pszNsAddress);

	///ע�����ַ������û���Ϣ
	///@param pFensUserInfo���û���Ϣ��
	void RegisterFensUserInfo(CThostFtdcFensUserInfoField *pFensUserInfo);

	///����˽������
	///@param nResumeType ˽�����ش���ʽ
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

	///���Ĺ�������
	///@param nResumeType �������ش���ʽ
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

	///�ͻ�����֤����
	int ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID);

	///�û���¼����
	int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///�û����ܵ�¼����
	int ReqUserLoginEncrypt(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///�ǳ�����
	int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID);

	///�û������������
	int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///�ʽ��˻������������
	int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID);

	///����¼������
	int ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID);

	///Ԥ��¼������
	int ReqParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, int nRequestID);

	///Ԥ�񳷵�¼������
	int ReqParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID);

	///������������
	int ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID);

	///��ѯ��󱨵���������
	int ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID);

	///Ͷ���߽�����ȷ��
	int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID);

	///����ɾ��Ԥ��
	int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID);

	///����ɾ��Ԥ�񳷵�
	int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID);

	///ִ������¼������
	int ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///ִ�������������
	int ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID);

	///ѯ��¼������
	int ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID);

	///����¼������
	int ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID);

	///���۲�������
	int ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID);

	///����������������
	int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID);

	///��Ȩ�ԶԳ�¼������
	int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID);

	///��Ȩ�ԶԳ��������
	int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID);

	///������ļ��ʽ�ת��
	int ReqTransFund(CThostFtdcTransFundField *pFtdcTransFund, int nRequestID);

	///�����ѯ����
	int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID);

	///�����ѯ�ɽ�
	int ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID);

	///�����ѯͶ���ֲ߳�
	int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID);

	///�����ѯ�ʽ��˻�
	int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID);

	///�����ѯͶ����
	int ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID);

	///�����ѯ���ױ���
	int ReqQryTradingCode(CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID);

	///�����ѯ��Լ��֤����
	int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID);

	///�����ѯ��Լ��������
	int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID);

	///�����ѯ������
	int ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID);

	///�����ѯ��Ʒ
	int ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID);

	///�����ѯ��Լ
	int ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///�����ѯ����
	int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID);

	///�����ѯ��Ȩ�ԶԳ�
	int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID);

	///�����ѯͶ���߽�����
	int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID);

	///�����ѯ��Լ״̬
	int ReqQryInstrumentStatus(CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///�����ѯת������
	int ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID);

	///�����ѯͶ���ֲ߳���ϸ
	int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID);

	///�����ѯ�ͻ�֪ͨ
	int ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID);

	///�����ѯ������Ϣȷ��
	int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID);

	///�����ѯͶ���ֲ߳���ϸ
	int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID);

	///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
	int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID);

	///�����ѯ�ֵ��۵���Ϣ
	int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID);

	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
	int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID);

	///�����ѯ��������֤����
	int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID);

	///�����ѯ������������֤����
	int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID);

	///�����ѯ����
	int ReqQryExchangeRate(CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);

	///�����ѯ�����������Ա����Ȩ��
	int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID);

	///�����ѯ��Ȩ���׳ɱ�
	int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID);

	///�����ѯ��Ȩ��Լ������
	int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID);

	///�����ѯִ������
	int ReqQryExecOrder(CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///�����ѯѯ��
	int ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID);

	///�����ѯ����
	int ReqQryQuote(CThostFtdcQryQuoteField *pQryQuote, int nRequestID);

	///�����ѯת����ˮ
	int ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID);

	///�����ѯ����ǩԼ��ϵ
	int ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID);

	///�����ѯǩԼ����
	int ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID);

	///�����ѯԤ��
	int ReqQryParkedOrder(CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID);

	///�����ѯԤ�񳷵�
	int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID);

	///�����ѯ����֪ͨ
	int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID);

	///�����ѯ���͹�˾���ײ���
	int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID);

	///�����ѯ���͹�˾�����㷨
	int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID);

	///�ڻ����������ʽ�ת�ڻ�����
	int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///�ڻ������ڻ��ʽ�ת��������
	int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///�ڻ������ѯ�����������
	int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID);

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();
	void SetCallbackOnFrontConnected(CbOnFrontConnected handler) {
		vtCallback.onFrontConnected = handler;
	}

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);
	void SetCallbackOnFrontDisconnected(CbOnFrontDisconnected handler) {
		vtCallback.onFrontDisconnected = handler;
	}

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);
	void SetCallbackOnHeartBeartWarning(CbOnHeartBeatWarning handler) {
		vtCallback.onHeartBeatWarning = handler;
	}

	///�ͻ�����֤��Ӧ
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspAuthenticate(CbOnRspAuthenticate handler) {
		vtCallback.onRspAuthenticate = handler;
	}

	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspUserLogin(CbOnRspUserLogin handler) {
		vtCallback.onRspUserLogin = handler;
	}

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspUserLogout(CbOnRspUserLogout handler) {
		vtCallback.onRspUserLogout = handler;
	}

	///�û��������������Ӧ
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspUserPasswordUpdate(CbOnRspUserPasswordUpdate handler) {
		vtCallback.onRspUserPasswordUpdate = handler;
	}

	///�ʽ��˻��������������Ӧ
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspTradingAccountPasswordUpdate(CbOnRspTradingAccountPasswordUpdate handler) {
		vtCallback.onRspTradingAccountPasswordUpdate = handler;
	}

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOrderInsert(CbOnRspOrderInsert handler) {
		vtCallback.onRspOrderInsert = handler;
	}

	///Ԥ��¼��������Ӧ
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspParkedOrderInsert(CbOnRspParkedOrderInsert handler) {
		vtCallback.onRspParkedOrderInsert = handler;
	}

	///Ԥ�񳷵�¼��������Ӧ
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspParketOrderAction(CbOnRspParkedOrderAction handler) {
		vtCallback.onRspParkedOrderAction = handler;
	}

	///��������������Ӧ
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOrderAction(CbOnRspOrderAction handler) {
		vtCallback.onRspOrderAction = handler;
	}

	///��ѯ��󱨵�������Ӧ
	virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQueryMaxOrderVolume(CbOnRspQueryMaxOrderVolume handler) {
		vtCallback.onRspQueryMaxOrderVolume = handler;
	}

	///Ͷ���߽�����ȷ����Ӧ
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspSettlementInfoConfirm(CbOnRspSettlementInfoConfirm handler) {
		vtCallback.onRspSettlementInfoConfirm = handler;
	}

	///ɾ��Ԥ����Ӧ
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspRemoveParketOrder(CbOnRspRemoveParkedOrder handler) {
		vtCallback.onRspRemoveParkedOrder = handler;
	}

	///ɾ��Ԥ�񳷵���Ӧ
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspRemoveParkedOrderAction(CbOnRspRemoveParkedOrderAction handler) {
		vtCallback.onRspRemoveParkedOrderAction = handler;
	}

	///ִ������¼��������Ӧ
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspExecOrderInsert(CbOnRspExecOrderInsert handler) {
		vtCallback.onRspExecOrderInsert = handler;
	}

	///ִ���������������Ӧ
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspExecOrderAction(CbOnRspExecOrderAction handler) {
		vtCallback.onRspExecOrderAction = handler;
	}

	///ѯ��¼��������Ӧ
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspForQuoteInsert(CbOnRspForQuoteInsert handler) {
		vtCallback.onRspForQuoteInsert = handler;
	}

	///����¼��������Ӧ
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQuoteInsert(CbOnRspQuoteInsert handler) {
		vtCallback.onRspQuoteInsert = handler;
	}

	///���۲���������Ӧ
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQuoteAction(CbOnRspQuoteAction handler) {
		vtCallback.onRspQuoteAction = handler;
	}

	///������������������Ӧ
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspBatchOrderAction(CbOnRspBatchOrderAction handler) {
		vtCallback.onRspBatchOrderAction = handler;
	}

	///��Ȩ�ԶԳ�¼��������Ӧ
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOptionSelfCloseInsert(CbOnRspOptionSelfCloseInsert handler) {
		vtCallback.onRspOptionSelfCloseInsert = handler;
	}

	///��Ȩ�ԶԳ����������Ӧ
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOptioinSelfCloseAction(CbOnRspOptionSelfCloseAction handler) {
		vtCallback.onRspOptionSelfCloseAction = handler;
	}

	///������ļ��ʽ�ת����Ӧ
	virtual void OnRspTransFund(CThostFtdcTransFundField *pTransFund, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspTransFund(CbOnRspTransFund handler) {
		vtCallback.onRspTransFund = handler;
	}

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOrder(CbOnRspQryOrder handler) {
		vtCallback.onRspQryOrder = handler;
	}

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTrade(CbOnRspQryTrade handler) {
		vtCallback.onRspQryTrade = handler;
	}

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorPosition(CbOnRspQryInvestorPosition handler) {
		vtCallback.onRspQryInvestorPosition = handler;
	}

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTradingAccount(CbOnRspQryTradingAccount handler) {
		vtCallback.onRspQryTradingAccount = handler;
	}

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestor(CbOnRspQryInvestor handler) {
		vtCallback.onRspQryInvestor = handler;
	}

	///�����ѯ���ױ�����Ӧ
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTradingCode(CbOnRspQryTradingCode handler) {
		vtCallback.onRspQryTradingCode = handler;
	}

	///�����ѯ��Լ��֤������Ӧ
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrumentMarginRate(CbOnRspQryInstrumentMarginRate handler) {
		vtCallback.onRspQryInstrumentMarginRate = handler;
	}

	///�����ѯ��Լ����������Ӧ
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrumentCommissionRate(CbOnRspQryInstrumentCommissionRate handler) {
		vtCallback.onRspQryInstrumentCommissionRate = handler;
	}

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchange(CbOnRspQryExchange handler) {
		vtCallback.onRspQryExchange = handler;
	}

	///�����ѯ��Ʒ��Ӧ
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryProduct(CbOnRspQryProduct handler) {
		vtCallback.onRspQryProduct = handler;
	}

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrument(CbOnRspQryInstrument handler) {
		vtCallback.onRspQryInstrument = handler;
	}

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryDepthMarketData(CbOnRspQryDepthMarketData handler) {
		vtCallback.onRspQryDepthMarketData = handler;
	}

	///�����ѯͶ���߽�������Ӧ
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQrySettlementInfo(CbOnRspQrySettlementInfo handler) {
		vtCallback.onRspQrySettlementInfo = handler;
	}

	///�����ѯ��Լ״̬��Ӧ
	virtual void OnRspQryInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrumentStatus(CbOnRspQryInstrumentStatus handler) {
		vtCallback.onRspQryInstrumentStatus = handler;
	}

	///�����ѯת��������Ӧ
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTransferBank(CbOnRspQryTransferBank handler) {
		vtCallback.onRspQryTransferBank = handler;
	}

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorPositionDetail(CbOnRspQryInvestorPositionDetail handler) {
		vtCallback.onRspQryInvestorPositionDetail = handler;
	}

	///�����ѯ�ͻ�֪ͨ��Ӧ
	virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryNotice(CbOnRspQryNotice handler) {
		vtCallback.onRspQryNotice = handler;
	}

	///�����ѯ������Ϣȷ����Ӧ
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQrySettlementInfoConfirm(CbOnRspSettlementInfoConfirm handler) {
		vtCallback.onRspQrySettlementInfoConfirm = handler;
	}

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorPositionCombineDetail(CbOnRspQryInvestorPositionCombineDetail handler) {
		vtCallback.onRspQryInvestorPositionCombineDetail = handler;
	}

	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryCFMMCTradingAccountKey(CbOnRspQryCFMMCTradingAccountKey handler) {
		vtCallback.onRspQryCFMMCTradingAccountKey = handler;
	}

	///�����ѯ�ֵ��۵���Ϣ��Ӧ
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryEWarrantOffset(CbOnRspQryEWarrantOffset handler) {
		vtCallback.onRspQryEWarrantOffset = handler;
	}

	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorProductGroupMargin(CbOnRspQryInvestorProductGroupMargin handler) {
		vtCallback.onRspQryInvestorProductGroupMargin = handler;
	}

	///�����ѯ��������֤������Ӧ
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchangeMarginRate(CbOnRspQryExchangeMarginRate handler) {
		vtCallback.onRspQryExchangeMarginRate = handler;
	}

	///�����ѯ������������֤������Ӧ
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchangeMarginRateAdjust(CbOnRspQryExchangeMarginRateAdjust handler) {
		vtCallback.onRspQryExchangeMarginRateAdjust = handler;
	}

	///�����ѯ������Ӧ
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchangeRate(CbOnRspQryExchangeRate handler) {
		vtCallback.onRspQryExchangeRate = handler;
	}

	///�����ѯ�����������Ա����Ȩ����Ӧ
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQrySecAgentACIDMap(CbOnRspQrySecAgentACIDMap handler) {
		vtCallback.onRspQrySecAgentACIDMap = handler;
	}

	///�����ѯ��Ȩ���׳ɱ���Ӧ
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOptionInstrTradeCost(CbOnRspQryOptionInstrTradeCost handler) {
		vtCallback.onRspQryOptionInstrTradeCost = handler;
	}

	///�����ѯ��Ȩ��Լ��������Ӧ
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOptionInstrCommRate(CbOnRspQryOptionInstrCommRate handler) {
		vtCallback.onRspQryOptionInstrCommRate = handler;
	}

	///�����ѯִ��������Ӧ
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExecOrder(CbOnRspQryExecOrder handler) {
		vtCallback.onRspQryExecOrder = handler;
	}

	///�����ѯѯ����Ӧ
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryForQuote(CbOnRspQryForQuote handler) {
		vtCallback.onRspQryForQuote = handler;
	}

	///�����ѯ������Ӧ
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryQuote(CbOnRspQryQuote handler) {
		vtCallback.onRspQryQuote = handler;
	}

	///�����ѯ��Ȩ�ԶԳ���Ӧ
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOptionSelfClose(CbOnRspQryOptionSelfClose handler) {
		vtCallback.onRspQryOptionSelfClose = handler;
	}

	///�����ѯת����ˮ��Ӧ
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTransferSerial(CbOnRspQryTransferSerial handler) {
		vtCallback.onRspQryTransferSerial = handler;
	}

	///�����ѯ����ǩԼ��ϵ��Ӧ
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryAccountregister(CbOnRspQryAccountregister handler) {
		vtCallback.onRspQryAccountregister = handler;
	}

	///����Ӧ��
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspError(CbOnRspError handler) {
		vtCallback.onRspError = handler;
	}

	///����֪ͨ
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
	void SetCallbackOnRtnOrder(CbOnRtnOrder handler) {
		vtCallback.onRtnOrder = handler;
	}

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
	void SetCallbackOnRtnTrade(CbOnRtnTrade handler) {
		vtCallback.onRtnTrade = handler;
	}

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOrderInsert(CbOnErrRtnOrderInsert handler) {
		vtCallback.onErrRtnOrderInsert = handler;
	}

	///������������ر�
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOrderAction(CbOnErrRtnOrderAction handler) {
		vtCallback.onErrRtnOrderAction = handler;
	}

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
	void SetCallbackOnRtnInstrumentStatus(CbOnRtnInstrumentStatus handler) {
		vtCallback.onRtnInstrumentStatus = handler;
	}

	///����֪ͨ
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	void SetCallbackOnRtnTradingNotice(CbOnRtnTradingNotice handler) {
		vtCallback.onRtnTradingNotice = handler;
	}

	///��ʾ������У�����
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	void SetCallbackOnRtnErrorConditionalOrder(CbOnRtnErrorConditionalOrder handler) {
		vtCallback.onRtnErrorConditionalOrder = handler;
	}

	///ִ������֪ͨ
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);
	void SetCallbackOnRtnExecOrder(CbOnRtnExecOrder handler) {
		vtCallback.onRtnExecOrder = handler;
	}

	///ִ������¼�����ر�
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnExecOrderInsert(CbOnErrRtnExecOrderInsert handler) {
		vtCallback.onErrRtnExecOrderInsert = handler;
	}

	///ִ�������������ر�
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnExecOrderAction(CbOnErrRtnExecOrderAction handler) {
		vtCallback.onErrRtnExecOrderAction = handler;
	}

	///ѯ��¼�����ر�
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnForQuoteInsert(CbOnErrRtnForQuoteInsert handler) {
		vtCallback.onErrRtnForQuoteInsert = handler;
	}

	///����֪ͨ
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);
	void SetCallbackOnRtnQuote(CbOnRtnQuote handler) {
		vtCallback.onRtnQuote = handler;
	}

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnQuoteInsert(CbOnErrRtnQuoteInsert handler) {
		vtCallback.onErrRtnQuoteInsert = handler;
	}

	///���۲�������ر�
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnQuoteAction(CbOnErrRtnQuoteAction handler) {
		vtCallback.onErrRtnQuoteAction = handler;
	}

	///ѯ��֪ͨ
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
	void SetCallbackOnRtnForQuoteRsp(CbOnRtnForQuoteRsp handler) {
		vtCallback.onRtnForQuoteRsp = handler;
	}

	///����������������ر�
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnBatchOrderAction(CbOnErrRtnBatchOrderAction handler) {
		vtCallback.onErrRtnBatchOrderAction = handler;
	}

	///��Ȩ�ԶԳ�֪ͨ
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose);
	void SetCallbackOnRtnOptionSelfClose(CbOnRtnOptionSelfClose handler) {
		vtCallback.onRtnOptionSelfClose = handler;
	}

	///��Ȩ�ԶԳ�¼�����ر�
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOptionSelfCloseInsert(CbOnErrRtnOptionSelfCloseInsert handler) {
		vtCallback.onErrRtnOptionSelfCloseInsert = handler;
	}

	///��Ȩ�ԶԳ��������ر�
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOptionSelfCloseAction(CbOnErrRtnOptionSelfCloseAction handler) {
		vtCallback.onErrRtnOptionSelfCloseAction = handler;
	}

	///�����ѯǩԼ������Ӧ
	virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryContractBank(CbOnRspQryContractBank handler) {
		vtCallback.onRspQryContractBank = handler;
	}

	///�����ѯԤ����Ӧ
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryParkedOrder(CbOnRspQryParkedOrder handler) {
		vtCallback.onRspQryParkedOrder = handler;
	}

	///�����ѯԤ�񳷵���Ӧ
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryparketOrderAction(CbOnRspQryParkedOrderAction handler) {
		vtCallback.onRspQryParkedOrderAction = handler;
	}

	///�����ѯ����֪ͨ��Ӧ
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTradingNotice(CbOnRspQryTradingNotice handler) {
		vtCallback.onRspQryTradingNotice = handler;
	}

	///�����ѯ���͹�˾���ײ�����Ӧ
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryBrokerTradingParams(CbOnRspQryBrokerTradingParams handler) {
		vtCallback.onRspQryBrokerTradingParams = handler;
	}

	///�����ѯ���͹�˾�����㷨��Ӧ
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryBrokerTradingAlgos(CbOnRspQryBrokerTradingAlgos handler) {
		vtCallback.onRspQryBrokerTradingAlgos = handler;
	}

	///���з��������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromBankToFutureByBank(CbOnRtnFromBankToFutureByBank handler) {
		vtCallback.onRtnFromBankToFutureByBank = handler;
	}

	///���з����ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromFutureToBankByBank(CbOnRtnFromFutureToBankByBank handler) {
		vtCallback.onRtnFromFutureToBankByBank = handler;
	}

	///���з����������ת�ڻ�֪ͨ
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromBankToFutureByBank(CbOnRtnRepealFromBankToFutureByBank handler) {
		vtCallback.onRtnRepealFromBankToFutureByBank = handler;
	}

	///���з�������ڻ�ת����֪ͨ
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromFutureToBankByBank(CbOnRtnRepealFromFutureToBankByBank handler) {
		vtCallback.onRtnRepealFromFutureToBankByBank = handler;
	}

	///�ڻ����������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromBankToFutureByFuture(CbOnRtnFromBankToFutureByFuture handler) {
		vtCallback.onRtnFromBankToFutureByFuture = handler;
	}

	///�ڻ������ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromFutureToBankByFuture(CbOnRtnFromFutureToBankByFuture handler) {
		vtCallback.onRtnFromFutureToBankByFuture = handler;
	}

	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromBankToFutureByFutureManual(CbOnRtnRepealFromBankToFutureByFutureManual handler) {
		vtCallback.onRtnRepealFromBankToFutureByFutureManual = handler;
	}

	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromFutureToBankByFutureManual(CbOnRtnRepealFromFutureToBankByFutureManual handler) {
		vtCallback.onRtnRepealFromFutureToBankByFutureManual = handler;
	}

	///�ڻ������ѯ�������֪ͨ
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	void SetCallbackOnRtnQueryBankBalanceByFuture(CbOnRtnQueryBankBalanceByFuture handler) {
		vtCallback.onRtnQueryBankBalanceByFuture = handler;
	}

	///�ڻ����������ʽ�ת�ڻ�����ر�
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnBankToFutureByFuture(CbOnErrRtnBankToFutureByFuture handler) {
		vtCallback.onErrRtnBankToFutureByFuture = handler;
	}

	///�ڻ������ڻ��ʽ�ת���д���ر�
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnFutureToBankByFuture(CbOnErrRtnFutureToBankByFuture handler) {
		vtCallback.onErrRtnFutureToBankByFuture = handler;
	}

	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnRepealBankToFutureByFutureManual(CbOnErrRtnRepealBankToFutureByFutureManual handler) {
		vtCallback.onErrRtnRepealBankToFutureByFutureManual = handler;
	}

	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnRepealFutureToBankByFutureManual(CbOnErrRtnRepealFutureToBankByFutureManual handler) {
		vtCallback.onErrRtnRepealFutureToBankByFutureManual = handler;
	}

	///�ڻ������ѯ����������ر�
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnQueryBankBalanceByFuture(CbOnErrRtnQueryBankBalanceByFuture handler) {
		vtCallback.onErrRtnQueryBankBalanceByFuture = handler;
	}

	///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromBankToFutureByFuture(CbOnRtnRepealFromBankToFutureByFuture handler) {
		vtCallback.onRtnRepealFromBankToFutureByFuture = handler;
	}

	///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromFutureToBankByFuture(CbOnRtnRepealFromFutureToBankByFuture handler) {
		vtCallback.onRtnRepealFromFutureToBankByFuture = handler;
	}

	///�ڻ����������ʽ�ת�ڻ�Ӧ��
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspFromBankToFutureByFuture(CbOnRspFromBankToFutureByFuture handler) {
		vtCallback.onRspFromBankToFutureByFuture = handler;
	}

	///�ڻ������ڻ��ʽ�ת����Ӧ��
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspFromFutureToBankByFuture(CbOnRspFromFutureToBankByFuture handler) {
		vtCallback.onRspFromFutureToBankByFuture = handler;
	}

	///�ڻ������ѯ�������Ӧ��
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQueryBankAccountMoneyByFuture(CbOnRspQueryBankAccountMoneyByFuture handler) {
		vtCallback.onRspQueryBankAccountMoneyByFuture = handler;
	}

	///���з������ڿ���֪ͨ
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);
	void SetCallbackOnRtnOpenAccountByBank(CbOnRtnOpenAccountByBank handler) {
		vtCallback.onRtnOpenAccountByBank = handler;
	}

	///���з�����������֪ͨ
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);
	void SetCallbackOnRtnCancelAccountByBank(CbOnRtnCancelAccountByBank handler) {
		vtCallback.onRtnCancelAccountByBank = handler;
	}

	///���з����������˺�֪ͨ
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);
	void SetCallbackOnRtnChangeAccountByBank(CbOnRtnChangeAccountByBank handler) {
		vtCallback.onRtnChangeAccountByBank = handler;
	}

	void SetCallbackVirtualTable(callbackVirtualTable *vt) {
		memcpy(&vtCallback, vt, sizeof(callbackVirtualTable));
	}
};
