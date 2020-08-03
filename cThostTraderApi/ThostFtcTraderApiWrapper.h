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
	///获取API的版本信息
	///@retrun 获取到的版本号
	static const char *GetApiVersion();

	int CreateApi(const char *pszFlowPath = "");

	///初始化
	///@param bContinuous 为true表示线程不休眠
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	void Init(bool bContinuous = false);

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	void Release();

	///等待接口线程结束运行
	///@return 线程退出代码
	int Join();

	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	const char *GetTradingDay();

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	void RegisterFront(char *pszFrontAddress);

	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterNameServer优先于RegisterFront
	void RegisterNameServer(char *pszNsAddress);

	///注册名字服务器用户信息
	///@param pFensUserInfo：用户信息。
	void RegisterFensUserInfo(CThostFtdcFensUserInfoField *pFensUserInfo);

	///订阅私有流。
	///@param nResumeType 私有流重传方式
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后私有流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);

	///订阅公共流。
	///@param nResumeType 公共流重传方式
	///        THOST_TERT_RESTART:从本交易日开始重传
	///        THOST_TERT_RESUME:从上次收到的续传
	///        THOST_TERT_QUICK:只传送登录后公共流的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
	void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

	///客户端认证请求
	int ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID);

	///用户登录请求
	int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///用户加密登录请求
	int ReqUserLoginEncrypt(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);

	///登出请求
	int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID);

	///用户口令更新请求
	int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///资金账户口令更新请求
	int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID);

	///报单录入请求
	int ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID);

	///预埋单录入请求
	int ReqParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, int nRequestID);

	///预埋撤单录入请求
	int ReqParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID);

	///报单操作请求
	int ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID);

	///查询最大报单数量请求
	int ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID);

	///投资者结算结果确认
	int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID);

	///请求删除预埋单
	int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID);

	///请求删除预埋撤单
	int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID);

	///执行宣告录入请求
	int ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///执行宣告操作请求
	int ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID);

	///询价录入请求
	int ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID);

	///报价录入请求
	int ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID);

	///报价操作请求
	int ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID);

	///批量报单操作请求
	int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID);

	///期权自对冲录入请求
	int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID);

	///期权自对冲操作请求
	int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID);

	///请求核心间资金转移
	int ReqTransFund(CThostFtdcTransFundField *pFtdcTransFund, int nRequestID);

	///请求查询报单
	int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID);

	///请求查询成交
	int ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID);

	///请求查询投资者持仓
	int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID);

	///请求查询资金账户
	int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID);

	///请求查询投资者
	int ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID);

	///请求查询交易编码
	int ReqQryTradingCode(CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID);

	///请求查询合约保证金率
	int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID);

	///请求查询合约手续费率
	int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID);

	///请求查询交易所
	int ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID);

	///请求查询产品
	int ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID);

	///请求查询合约
	int ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///请求查询行情
	int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID);

	///请求查询期权自对冲
	int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose, int nRequestID);

	///请求查询投资者结算结果
	int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID);

	///请求查询合约状态
	int ReqQryInstrumentStatus(CThostFtdcQryInstrumentStatusField *pQryInstrumentStatus, int nRequestID);

	///请求查询转帐银行
	int ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID);

	///请求查询投资者持仓明细
	int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID);

	///请求查询客户通知
	int ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID);

	///请求查询结算信息确认
	int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID);

	///请求查询投资者持仓明细
	int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID);

	///请求查询保证金监管系统经纪公司资金账户密钥
	int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID);

	///请求查询仓单折抵信息
	int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID);

	///请求查询投资者品种/跨品种保证金
	int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID);

	///请求查询交易所保证金率
	int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID);

	///请求查询交易所调整保证金率
	int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID);

	///请求查询汇率
	int ReqQryExchangeRate(CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID);

	///请求查询二级代理操作员银期权限
	int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID);

	///请求查询期权交易成本
	int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID);

	///请求查询期权合约手续费
	int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID);

	///请求查询执行宣告
	int ReqQryExecOrder(CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID);

	///请求查询询价
	int ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID);

	///请求查询报价
	int ReqQryQuote(CThostFtdcQryQuoteField *pQryQuote, int nRequestID);

	///请求查询转帐流水
	int ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID);

	///请求查询银期签约关系
	int ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID);

	///请求查询签约银行
	int ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID);

	///请求查询预埋单
	int ReqQryParkedOrder(CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID);

	///请求查询预埋撤单
	int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID);

	///请求查询交易通知
	int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID);

	///请求查询经纪公司交易参数
	int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID);

	///请求查询经纪公司交易算法
	int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID);

	///期货发起银行资金转期货请求
	int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///期货发起期货资金转银行请求
	int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID);

	///期货发起查询银行余额请求
	int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID);

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();
	void SetCallbackOnFrontConnected(CbOnFrontConnected handler) {
		vtCallback.onFrontConnected = handler;
	}

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason);
	void SetCallbackOnFrontDisconnected(CbOnFrontDisconnected handler) {
		vtCallback.onFrontDisconnected = handler;
	}

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse);
	void SetCallbackOnHeartBeartWarning(CbOnHeartBeatWarning handler) {
		vtCallback.onHeartBeatWarning = handler;
	}

	///客户端认证响应
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspAuthenticate(CbOnRspAuthenticate handler) {
		vtCallback.onRspAuthenticate = handler;
	}

	///登录请求响应
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspUserLogin(CbOnRspUserLogin handler) {
		vtCallback.onRspUserLogin = handler;
	}

	///登出请求响应
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspUserLogout(CbOnRspUserLogout handler) {
		vtCallback.onRspUserLogout = handler;
	}

	///用户口令更新请求响应
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspUserPasswordUpdate(CbOnRspUserPasswordUpdate handler) {
		vtCallback.onRspUserPasswordUpdate = handler;
	}

	///资金账户口令更新请求响应
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspTradingAccountPasswordUpdate(CbOnRspTradingAccountPasswordUpdate handler) {
		vtCallback.onRspTradingAccountPasswordUpdate = handler;
	}

	///报单录入请求响应
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOrderInsert(CbOnRspOrderInsert handler) {
		vtCallback.onRspOrderInsert = handler;
	}

	///预埋单录入请求响应
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspParkedOrderInsert(CbOnRspParkedOrderInsert handler) {
		vtCallback.onRspParkedOrderInsert = handler;
	}

	///预埋撤单录入请求响应
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspParketOrderAction(CbOnRspParkedOrderAction handler) {
		vtCallback.onRspParkedOrderAction = handler;
	}

	///报单操作请求响应
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOrderAction(CbOnRspOrderAction handler) {
		vtCallback.onRspOrderAction = handler;
	}

	///查询最大报单数量响应
	virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQueryMaxOrderVolume(CbOnRspQueryMaxOrderVolume handler) {
		vtCallback.onRspQueryMaxOrderVolume = handler;
	}

	///投资者结算结果确认响应
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspSettlementInfoConfirm(CbOnRspSettlementInfoConfirm handler) {
		vtCallback.onRspSettlementInfoConfirm = handler;
	}

	///删除预埋单响应
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspRemoveParketOrder(CbOnRspRemoveParkedOrder handler) {
		vtCallback.onRspRemoveParkedOrder = handler;
	}

	///删除预埋撤单响应
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspRemoveParkedOrderAction(CbOnRspRemoveParkedOrderAction handler) {
		vtCallback.onRspRemoveParkedOrderAction = handler;
	}

	///执行宣告录入请求响应
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspExecOrderInsert(CbOnRspExecOrderInsert handler) {
		vtCallback.onRspExecOrderInsert = handler;
	}

	///执行宣告操作请求响应
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspExecOrderAction(CbOnRspExecOrderAction handler) {
		vtCallback.onRspExecOrderAction = handler;
	}

	///询价录入请求响应
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspForQuoteInsert(CbOnRspForQuoteInsert handler) {
		vtCallback.onRspForQuoteInsert = handler;
	}

	///报价录入请求响应
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQuoteInsert(CbOnRspQuoteInsert handler) {
		vtCallback.onRspQuoteInsert = handler;
	}

	///报价操作请求响应
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQuoteAction(CbOnRspQuoteAction handler) {
		vtCallback.onRspQuoteAction = handler;
	}

	///批量报单操作请求响应
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspBatchOrderAction(CbOnRspBatchOrderAction handler) {
		vtCallback.onRspBatchOrderAction = handler;
	}

	///期权自对冲录入请求响应
	virtual void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOptionSelfCloseInsert(CbOnRspOptionSelfCloseInsert handler) {
		vtCallback.onRspOptionSelfCloseInsert = handler;
	}

	///期权自对冲操作请求响应
	virtual void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspOptioinSelfCloseAction(CbOnRspOptionSelfCloseAction handler) {
		vtCallback.onRspOptionSelfCloseAction = handler;
	}

	///请求核心间资金转移响应
	virtual void OnRspTransFund(CThostFtdcTransFundField *pTransFund, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspTransFund(CbOnRspTransFund handler) {
		vtCallback.onRspTransFund = handler;
	}

	///请求查询报单响应
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOrder(CbOnRspQryOrder handler) {
		vtCallback.onRspQryOrder = handler;
	}

	///请求查询成交响应
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTrade(CbOnRspQryTrade handler) {
		vtCallback.onRspQryTrade = handler;
	}

	///请求查询投资者持仓响应
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorPosition(CbOnRspQryInvestorPosition handler) {
		vtCallback.onRspQryInvestorPosition = handler;
	}

	///请求查询资金账户响应
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTradingAccount(CbOnRspQryTradingAccount handler) {
		vtCallback.onRspQryTradingAccount = handler;
	}

	///请求查询投资者响应
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestor(CbOnRspQryInvestor handler) {
		vtCallback.onRspQryInvestor = handler;
	}

	///请求查询交易编码响应
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTradingCode(CbOnRspQryTradingCode handler) {
		vtCallback.onRspQryTradingCode = handler;
	}

	///请求查询合约保证金率响应
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrumentMarginRate(CbOnRspQryInstrumentMarginRate handler) {
		vtCallback.onRspQryInstrumentMarginRate = handler;
	}

	///请求查询合约手续费率响应
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrumentCommissionRate(CbOnRspQryInstrumentCommissionRate handler) {
		vtCallback.onRspQryInstrumentCommissionRate = handler;
	}

	///请求查询交易所响应
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchange(CbOnRspQryExchange handler) {
		vtCallback.onRspQryExchange = handler;
	}

	///请求查询产品响应
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryProduct(CbOnRspQryProduct handler) {
		vtCallback.onRspQryProduct = handler;
	}

	///请求查询合约响应
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrument(CbOnRspQryInstrument handler) {
		vtCallback.onRspQryInstrument = handler;
	}

	///请求查询行情响应
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryDepthMarketData(CbOnRspQryDepthMarketData handler) {
		vtCallback.onRspQryDepthMarketData = handler;
	}

	///请求查询投资者结算结果响应
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQrySettlementInfo(CbOnRspQrySettlementInfo handler) {
		vtCallback.onRspQrySettlementInfo = handler;
	}

	///请求查询合约状态响应
	virtual void OnRspQryInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInstrumentStatus(CbOnRspQryInstrumentStatus handler) {
		vtCallback.onRspQryInstrumentStatus = handler;
	}

	///请求查询转帐银行响应
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTransferBank(CbOnRspQryTransferBank handler) {
		vtCallback.onRspQryTransferBank = handler;
	}

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorPositionDetail(CbOnRspQryInvestorPositionDetail handler) {
		vtCallback.onRspQryInvestorPositionDetail = handler;
	}

	///请求查询客户通知响应
	virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryNotice(CbOnRspQryNotice handler) {
		vtCallback.onRspQryNotice = handler;
	}

	///请求查询结算信息确认响应
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQrySettlementInfoConfirm(CbOnRspSettlementInfoConfirm handler) {
		vtCallback.onRspQrySettlementInfoConfirm = handler;
	}

	///请求查询投资者持仓明细响应
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorPositionCombineDetail(CbOnRspQryInvestorPositionCombineDetail handler) {
		vtCallback.onRspQryInvestorPositionCombineDetail = handler;
	}

	///查询保证金监管系统经纪公司资金账户密钥响应
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryCFMMCTradingAccountKey(CbOnRspQryCFMMCTradingAccountKey handler) {
		vtCallback.onRspQryCFMMCTradingAccountKey = handler;
	}

	///请求查询仓单折抵信息响应
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryEWarrantOffset(CbOnRspQryEWarrantOffset handler) {
		vtCallback.onRspQryEWarrantOffset = handler;
	}

	///请求查询投资者品种/跨品种保证金响应
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryInvestorProductGroupMargin(CbOnRspQryInvestorProductGroupMargin handler) {
		vtCallback.onRspQryInvestorProductGroupMargin = handler;
	}

	///请求查询交易所保证金率响应
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchangeMarginRate(CbOnRspQryExchangeMarginRate handler) {
		vtCallback.onRspQryExchangeMarginRate = handler;
	}

	///请求查询交易所调整保证金率响应
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchangeMarginRateAdjust(CbOnRspQryExchangeMarginRateAdjust handler) {
		vtCallback.onRspQryExchangeMarginRateAdjust = handler;
	}

	///请求查询汇率响应
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExchangeRate(CbOnRspQryExchangeRate handler) {
		vtCallback.onRspQryExchangeRate = handler;
	}

	///请求查询二级代理操作员银期权限响应
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQrySecAgentACIDMap(CbOnRspQrySecAgentACIDMap handler) {
		vtCallback.onRspQrySecAgentACIDMap = handler;
	}

	///请求查询期权交易成本响应
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOptionInstrTradeCost(CbOnRspQryOptionInstrTradeCost handler) {
		vtCallback.onRspQryOptionInstrTradeCost = handler;
	}

	///请求查询期权合约手续费响应
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOptionInstrCommRate(CbOnRspQryOptionInstrCommRate handler) {
		vtCallback.onRspQryOptionInstrCommRate = handler;
	}

	///请求查询执行宣告响应
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryExecOrder(CbOnRspQryExecOrder handler) {
		vtCallback.onRspQryExecOrder = handler;
	}

	///请求查询询价响应
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryForQuote(CbOnRspQryForQuote handler) {
		vtCallback.onRspQryForQuote = handler;
	}

	///请求查询报价响应
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryQuote(CbOnRspQryQuote handler) {
		vtCallback.onRspQryQuote = handler;
	}

	///请求查询期权自对冲响应
	virtual void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryOptionSelfClose(CbOnRspQryOptionSelfClose handler) {
		vtCallback.onRspQryOptionSelfClose = handler;
	}

	///请求查询转帐流水响应
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTransferSerial(CbOnRspQryTransferSerial handler) {
		vtCallback.onRspQryTransferSerial = handler;
	}

	///请求查询银期签约关系响应
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryAccountregister(CbOnRspQryAccountregister handler) {
		vtCallback.onRspQryAccountregister = handler;
	}

	///错误应答
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspError(CbOnRspError handler) {
		vtCallback.onRspError = handler;
	}

	///报单通知
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
	void SetCallbackOnRtnOrder(CbOnRtnOrder handler) {
		vtCallback.onRtnOrder = handler;
	}

	///成交通知
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
	void SetCallbackOnRtnTrade(CbOnRtnTrade handler) {
		vtCallback.onRtnTrade = handler;
	}

	///报单录入错误回报
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOrderInsert(CbOnErrRtnOrderInsert handler) {
		vtCallback.onErrRtnOrderInsert = handler;
	}

	///报单操作错误回报
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOrderAction(CbOnErrRtnOrderAction handler) {
		vtCallback.onErrRtnOrderAction = handler;
	}

	///合约交易状态通知
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
	void SetCallbackOnRtnInstrumentStatus(CbOnRtnInstrumentStatus handler) {
		vtCallback.onRtnInstrumentStatus = handler;
	}

	///交易通知
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	void SetCallbackOnRtnTradingNotice(CbOnRtnTradingNotice handler) {
		vtCallback.onRtnTradingNotice = handler;
	}

	///提示条件单校验错误
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	void SetCallbackOnRtnErrorConditionalOrder(CbOnRtnErrorConditionalOrder handler) {
		vtCallback.onRtnErrorConditionalOrder = handler;
	}

	///执行宣告通知
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);
	void SetCallbackOnRtnExecOrder(CbOnRtnExecOrder handler) {
		vtCallback.onRtnExecOrder = handler;
	}

	///执行宣告录入错误回报
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnExecOrderInsert(CbOnErrRtnExecOrderInsert handler) {
		vtCallback.onErrRtnExecOrderInsert = handler;
	}

	///执行宣告操作错误回报
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnExecOrderAction(CbOnErrRtnExecOrderAction handler) {
		vtCallback.onErrRtnExecOrderAction = handler;
	}

	///询价录入错误回报
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnForQuoteInsert(CbOnErrRtnForQuoteInsert handler) {
		vtCallback.onErrRtnForQuoteInsert = handler;
	}

	///报价通知
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);
	void SetCallbackOnRtnQuote(CbOnRtnQuote handler) {
		vtCallback.onRtnQuote = handler;
	}

	///报价录入错误回报
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnQuoteInsert(CbOnErrRtnQuoteInsert handler) {
		vtCallback.onErrRtnQuoteInsert = handler;
	}

	///报价操作错误回报
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnQuoteAction(CbOnErrRtnQuoteAction handler) {
		vtCallback.onErrRtnQuoteAction = handler;
	}

	///询价通知
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
	void SetCallbackOnRtnForQuoteRsp(CbOnRtnForQuoteRsp handler) {
		vtCallback.onRtnForQuoteRsp = handler;
	}

	///批量报单操作错误回报
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnBatchOrderAction(CbOnErrRtnBatchOrderAction handler) {
		vtCallback.onErrRtnBatchOrderAction = handler;
	}

	///期权自对冲通知
	virtual void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField *pOptionSelfClose);
	void SetCallbackOnRtnOptionSelfClose(CbOnRtnOptionSelfClose handler) {
		vtCallback.onRtnOptionSelfClose = handler;
	}

	///期权自对冲录入错误回报
	virtual void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOptionSelfCloseInsert(CbOnErrRtnOptionSelfCloseInsert handler) {
		vtCallback.onErrRtnOptionSelfCloseInsert = handler;
	}

	///期权自对冲操作错误回报
	virtual void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField *pOptionSelfCloseAction, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnOptionSelfCloseAction(CbOnErrRtnOptionSelfCloseAction handler) {
		vtCallback.onErrRtnOptionSelfCloseAction = handler;
	}

	///请求查询签约银行响应
	virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryContractBank(CbOnRspQryContractBank handler) {
		vtCallback.onRspQryContractBank = handler;
	}

	///请求查询预埋单响应
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryParkedOrder(CbOnRspQryParkedOrder handler) {
		vtCallback.onRspQryParkedOrder = handler;
	}

	///请求查询预埋撤单响应
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryparketOrderAction(CbOnRspQryParkedOrderAction handler) {
		vtCallback.onRspQryParkedOrderAction = handler;
	}

	///请求查询交易通知响应
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryTradingNotice(CbOnRspQryTradingNotice handler) {
		vtCallback.onRspQryTradingNotice = handler;
	}

	///请求查询经纪公司交易参数响应
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryBrokerTradingParams(CbOnRspQryBrokerTradingParams handler) {
		vtCallback.onRspQryBrokerTradingParams = handler;
	}

	///请求查询经纪公司交易算法响应
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQryBrokerTradingAlgos(CbOnRspQryBrokerTradingAlgos handler) {
		vtCallback.onRspQryBrokerTradingAlgos = handler;
	}

	///银行发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromBankToFutureByBank(CbOnRtnFromBankToFutureByBank handler) {
		vtCallback.onRtnFromBankToFutureByBank = handler;
	}

	///银行发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromFutureToBankByBank(CbOnRtnFromFutureToBankByBank handler) {
		vtCallback.onRtnFromFutureToBankByBank = handler;
	}

	///银行发起冲正银行转期货通知
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromBankToFutureByBank(CbOnRtnRepealFromBankToFutureByBank handler) {
		vtCallback.onRtnRepealFromBankToFutureByBank = handler;
	}

	///银行发起冲正期货转银行通知
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromFutureToBankByBank(CbOnRtnRepealFromFutureToBankByBank handler) {
		vtCallback.onRtnRepealFromFutureToBankByBank = handler;
	}

	///期货发起银行资金转期货通知
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromBankToFutureByFuture(CbOnRtnFromBankToFutureByFuture handler) {
		vtCallback.onRtnFromBankToFutureByFuture = handler;
	}

	///期货发起期货资金转银行通知
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void SetCallbackOnRtnFromFutureToBankByFuture(CbOnRtnFromFutureToBankByFuture handler) {
		vtCallback.onRtnFromFutureToBankByFuture = handler;
	}

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromBankToFutureByFutureManual(CbOnRtnRepealFromBankToFutureByFutureManual handler) {
		vtCallback.onRtnRepealFromBankToFutureByFutureManual = handler;
	}

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromFutureToBankByFutureManual(CbOnRtnRepealFromFutureToBankByFutureManual handler) {
		vtCallback.onRtnRepealFromFutureToBankByFutureManual = handler;
	}

	///期货发起查询银行余额通知
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	void SetCallbackOnRtnQueryBankBalanceByFuture(CbOnRtnQueryBankBalanceByFuture handler) {
		vtCallback.onRtnQueryBankBalanceByFuture = handler;
	}

	///期货发起银行资金转期货错误回报
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnBankToFutureByFuture(CbOnErrRtnBankToFutureByFuture handler) {
		vtCallback.onErrRtnBankToFutureByFuture = handler;
	}

	///期货发起期货资金转银行错误回报
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnFutureToBankByFuture(CbOnErrRtnFutureToBankByFuture handler) {
		vtCallback.onErrRtnFutureToBankByFuture = handler;
	}

	///系统运行时期货端手工发起冲正银行转期货错误回报
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnRepealBankToFutureByFutureManual(CbOnErrRtnRepealBankToFutureByFutureManual handler) {
		vtCallback.onErrRtnRepealBankToFutureByFutureManual = handler;
	}

	///系统运行时期货端手工发起冲正期货转银行错误回报
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnRepealFutureToBankByFutureManual(CbOnErrRtnRepealFutureToBankByFutureManual handler) {
		vtCallback.onErrRtnRepealFutureToBankByFutureManual = handler;
	}

	///期货发起查询银行余额错误回报
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	void SetCallbackOnErrRtnQueryBankBalanceByFuture(CbOnErrRtnQueryBankBalanceByFuture handler) {
		vtCallback.onErrRtnQueryBankBalanceByFuture = handler;
	}

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromBankToFutureByFuture(CbOnRtnRepealFromBankToFutureByFuture handler) {
		vtCallback.onRtnRepealFromBankToFutureByFuture = handler;
	}

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void SetCallbackOnRtnRepealFromFutureToBankByFuture(CbOnRtnRepealFromFutureToBankByFuture handler) {
		vtCallback.onRtnRepealFromFutureToBankByFuture = handler;
	}

	///期货发起银行资金转期货应答
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspFromBankToFutureByFuture(CbOnRspFromBankToFutureByFuture handler) {
		vtCallback.onRspFromBankToFutureByFuture = handler;
	}

	///期货发起期货资金转银行应答
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspFromFutureToBankByFuture(CbOnRspFromFutureToBankByFuture handler) {
		vtCallback.onRspFromFutureToBankByFuture = handler;
	}

	///期货发起查询银行余额应答
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void SetCallbackOnRspQueryBankAccountMoneyByFuture(CbOnRspQueryBankAccountMoneyByFuture handler) {
		vtCallback.onRspQueryBankAccountMoneyByFuture = handler;
	}

	///银行发起银期开户通知
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);
	void SetCallbackOnRtnOpenAccountByBank(CbOnRtnOpenAccountByBank handler) {
		vtCallback.onRtnOpenAccountByBank = handler;
	}

	///银行发起银期销户通知
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);
	void SetCallbackOnRtnCancelAccountByBank(CbOnRtnCancelAccountByBank handler) {
		vtCallback.onRtnCancelAccountByBank = handler;
	}

	///银行发起变更银行账号通知
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);
	void SetCallbackOnRtnChangeAccountByBank(CbOnRtnChangeAccountByBank handler) {
		vtCallback.onRtnChangeAccountByBank = handler;
	}

	void SetCallbackVirtualTable(callbackVirtualTable *vt) {
		memcpy(&vtCallback, vt, sizeof(callbackVirtualTable));
	}
};
