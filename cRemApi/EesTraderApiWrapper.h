#pragma once

#include "EesTraderApi.h"
#include "cEESTraderApi.h"

class cTraderApi : public EESTraderEvent
{
public:
	cTraderApi() {
		pApi = CreateEESTraderApi();
	};

	~cTraderApi() {
		DestroyEESTraderApi(pApi);
	};
private:
	EESTraderApi *pApi;
	callbackVirtualTable vtCallback;
public:
	///������Ϣ�Ļص�
	///<brief	�����������¼�
	///@param  errNo                   ���ӳɹ���������Ϣ
	///@param  pErrStr                 ������Ϣ
	///@return void  
	virtual void OnConnection(ERR_NO errNo, const char* pErrStr);
	void SetCallbackOnConnection(CbOnConnection handler) {
		vtCallback.onConnection = handler;
	};

	///���ӶϿ���Ϣ�Ļص�
	///<brief	�����������Ͽ������յ������Ϣ
	///@param  ERR_NO errNo         ���ӳɹ���������Ϣ
	///@param  const char* pErrStr  ������Ϣ
	///@return void  
	virtual void OnDisConnection(ERR_NO errNo, const char* pErrStr);
	void SetCallbackOnDisConnection(CbOnDisConnection handler) {
		vtCallback.onDisConnection = handler;
	}

	///��¼��Ϣ�Ļص�
	///@param  pLogon                  ��¼�ɹ�����ʧ�ܵĽṹ
	///@return void 
	virtual void OnUserLogon(EES_LogonResponse* pLogon);
	void SetCallbackOnUserLogon(CbOnUserLogon handler) {
		vtCallback.onUserLogon = handler;
	}

	///�޸�������Ӧ�ص�
	///@param  nint                  ��������Ӧ�ĳɹ���񷵻���
	///@return void 
	virtual void OnRspChangePassword(EES_ChangePasswordResult nint);
	void SetCallbackOnChangePassword(CbOnRspChangePassword handler) {
		vtCallback.onRspChangePassword = handler;
	}

	///��ѯ�û������ʻ��ķ����¼�
	///@param  pAccountInfo	        �ʻ�����Ϣ
	///@param  bFinish	                ���û�д�����ɣ����ֵ�� false ���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 
	virtual void OnQueryUserAccount(EES_AccountInfo * pAccoutnInfo, bool bFinish);
	void SetCallbackOnQueryUserAccount(CbOnQueryUserAccount handler) {
		vtCallback.onQueryUserAccount = handler;
	}

	///��ѯ�ʻ������ڻ���λ��Ϣ�ķ����¼�	
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID�š�
	///@param  bFinish	                    ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 	
	virtual void OnQueryAccountPosition(const char* pAccount, EES_AccountPosition* pAccoutnPosition, int nReqId, bool bFinish);
	void SetCallbackOnQueryAccountPosition(CbOnQueryAccountPosition handler) {
		vtCallback.onQueryAccountPosition = handler;
	}

	///��ѯ�ʻ�������Ȩ��λ��Ϣ�ķ����¼�, ע������ص�, ����һ��OnQueryAccountPosition, ����һ��QueryAccountPosition�����, �ֱ𷵻�, �ȷ����ڻ�, �ٷ�����Ȩ, ��ʹû����Ȩ��λ, Ҳ�᷵��һ��bFinish=true�ļ�¼
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID�š�
	///@param  bFinish	                    ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 	
	virtual void OnQueryAccountOptionPosition(const char* pAccount, EES_AccountOptionPosition* pAccoutnOptionPosition, int nReqId, bool bFinish);
	void SetCallbackOnQueryAccountOptionPosition(CbOnQueryAccountOptionPosition handler) {
		vtCallback.onQueryAccountOptionPosition = handler;
	}

	///��ѯ�ʻ������ʽ���Ϣ�ķ����¼�
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID��
	///@return void 
	virtual void OnQueryAccountBP(const char* pAccount, EES_AccountBP* pAccoutnPosition, int nReqId);
	void SetCallbackOnQueryAccountBP(CbOnQueryAccountBP handler) {
		vtCallback.onQueryAccountBP = handler;
	}

	///��ѯ��Լ�б�ķ����¼�
	///@param  pSymbol	                    ��Լ��Ϣ   
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true   
	///remark ������� bFinish == true����ô�Ǵ������������ pSymbol ֵ��Ч��
	///@return void 
	virtual void OnQuerySymbol(EES_SymbolField* pSymbol, bool bFinish);
	void SetCallbackOnQuerySymbol(CbOnQuerySymbol handler) {
		vtCallback.onQuerySymbol = handler;
	}

	///��ѯ�ʻ����ױ�֤��ķ����¼�
	///@param  pAccount                    �ʻ�ID 
	///@param  pSymbolMargin               �ʻ��ı�֤����Ϣ 
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false�������ɣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pSymbolMargin ֵ��Ч��
	///@return void 
	virtual void OnQueryAccountTradeMargin(const char* pAccount, EES_AccountMargin* pSymbolMargin, bool bFinish);
	void SetCallbackOnQueryAccountTradeMargin(CbOnQueryAccountTradeMargin handler) {
		vtCallback.onQueryAccountTradeMargin = handler;
	}

	///��ѯ�ʻ����׷��õķ����¼�
	///@param  pAccount                    �ʻ�ID 
	///@param  pSymbolFee	                �ʻ��ķ�����Ϣ	 
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true ����ô�Ǵ������������ pSymbolFee ֵ��Ч��
	///@return void 
	virtual void OnQueryAccountTradeFee(const char* pAccount, EES_AccountFee* pSymbolFee, bool bFinish);
	void SetCallbackOnQueryAccountTradeFee(CbOnQueryAccountTradeFee handler) {
		vtCallback.onQueryAccountTradeFee = handler;
	}

	///�µ�����̨ϵͳ���ܵ��¼�
	///<brief ��ʾ��������Ѿ�����̨ϵͳ��ʽ�Ľ���
	///@param  pAccept	                    �����������Ժ����Ϣ��
	///@return void 
	virtual void OnOrderAccept(EES_OrderAcceptField* pAccept);
	void SetCallbackOnOrderAccept(CbOnOrderAccept handler) {
		vtCallback.onOrderAccept = handler;
	}

	///�µ����г����ܵ��¼�
	///<brief ��ʾ��������Ѿ�����������ʽ�Ľ���
	///@param  pAccept	                    �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	virtual void OnOrderMarketAccept(EES_OrderMarketAcceptField* pAccept);
	void SetCallbackOnOrderMarketAccept(CbOnOrderMarketAccept handler) {
		vtCallback.onOrderMarketAccept = handler;
	}

	///	�µ�����̨ϵͳ�ܾ����¼�
	///<brief	��������̨ϵͳ�ܾ������Բ鿴�﷨�����Ƿ�ؼ�顣 
	///@param  pReject	                    �����������Ժ����Ϣ��
	///@return void 
	virtual void OnOrderReject(EES_OrderRejectField* pReject);
	void SetCallbackOnOrderReject(CbOnOrderReject handler) {
		vtCallback.onOrderReject = handler;
	}

	///	�µ����г��ܾ����¼�
	///<brief	�������г��ܾ������Բ鿴�﷨�����Ƿ�ؼ�顣 
	///@param  pReject	                    �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	virtual void OnOrderMarketReject(EES_OrderMarketRejectField* pReject);
	void SetCallbackOnOrderMarketReject(CbOnOrderMarketReject handler) {
		vtCallback.onOrderMarketReject = handler;
	}

	///	�����ɽ�����Ϣ�¼�
	///<brief	�ɽ���������˶����г�ID�����������ID��ѯ��Ӧ�Ķ���
	///@param  pExec	                   �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	virtual void OnOrderExecution(EES_OrderExecutionField* pExec);
	void SetCallbackOnOrderExecution(CbOnOrderExecution handler) {
		vtCallback.onOrderExecution = handler;
	}

	///	�����ɹ������¼�
	///<brief	�ɽ���������˶����г�ID�����������ID��ѯ��Ӧ�Ķ���
	///@param  pCxled		               �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	virtual void OnOrderCxled(EES_OrderCxled* pCxled);
	void SetCallbackOnOrderCxled(CbOnOrderCxled handler) {
		vtCallback.onOrderCxled = handler;
	}

	///	�������ܾ�����Ϣ�¼�
	///<brief	һ����ڷ��ͳ����Ժ��յ������Ϣ����ʾ�������ܾ�
	///@param  pReject	                   �������ܾ���Ϣ��
	///@return void 
	virtual void OnCxlOrderReject(EES_CxlOrderRej* pReject);
	void SetCallbackOnCxlOrderReject(CbOnCxlOrderReject handler) {
		vtCallback.onCxlOrderReject = handler;
	}

	///	��ѯ�����ķ����¼�
	///<brief	��ѯ������Ϣʱ��Ļص���������Ҳ���ܰ������ǵ�ǰ�û��µĶ���
	///@param  pAccount                 �ʻ�ID 
	///@param  pQueryOrder	             ��ѯ�����Ľṹ
	///@param  bFinish	                 ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true����ô�Ǵ������������ pQueryOrderֵ��Ч��
	///@return void 
	virtual void OnQueryTradeOrder(const char* pAccount, EES_QueryAccountOrder* pQueryOrder, bool bFinish);
	void SetCallbackOnQueryTradeOrder(CbOnQueryTradeOrder handler) {
		vtCallback.onQueryTradeOrder = handler;
	}

	///	��ѯ�����ķ����¼�
	///<brief	��ѯ������Ϣʱ��Ļص���������Ҳ���ܰ������ǵ�ǰ�û��µĶ����ɽ�
	///@param  pAccount                        �ʻ�ID 
	///@param  pQueryOrderExec	                ��ѯ�����ɽ��Ľṹ
	///@param  bFinish	                        ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true����ô�Ǵ������������pQueryOrderExecֵ��Ч��
	///@return void 
	virtual void OnQueryTradeOrderExec(const char* pAccount, EES_QueryOrderExecution* pQueryOrderExec, bool bFinish);
	void SetCallbackOnQueryTradeOrderExec(CbOnQueryTradeOrderExec handler) {
		vtCallback.onQueryTradeOrderExec = handler;
	}

	///	�����ⲿ��������Ϣ
	///<brief	һ�����ϵͳ�������������˹�������ʱ���õ���
	///@param  pPostOrder	                    ��ѯ�����ɽ��Ľṹ
	///@return void 
	virtual void OnPostOrder(EES_PostOrder* pPostOrder);
	void SetCallbackOnPostOrder(CbOnPostOrder handler) {
		vtCallback.onPostOrder = handler;
	}

	///	�����ⲿ�����ɽ�����Ϣ
	///<brief	һ�����ϵͳ�������������˹�������ʱ���õ���
	///@param  pPostOrderExecution	             ��ѯ�����ɽ��Ľṹ
	///@return void 
	virtual void OnPostOrderExecution(EES_PostOrderExecution* pPostOrderExecution);
	void SetCallbackOnPostOrderExecution(CbOnPostOrderExecution handler) {
		vtCallback.onPostOrderExecution = handler;
	}

	///	��ѯ�������������ӵ���Ӧ
	///<brief	ÿ����ǰϵͳ֧�ֵĻ㱨һ�Σ���bFinish= trueʱ����ʾ���н���������Ӧ���ѵ����������Ϣ�����������õ���Ϣ��
	///@param  pPostOrderExecution	             ��ѯ�����ɽ��Ľṹ
	///@return void 
	virtual void OnQueryMarketSession(EES_ExchangeMarketSession* pMarketSession, bool bFinish);
	void SetCallbackOnQueryMarketSession(CbOnQueryMarketSession handler) {
		vtCallback.onQueryMarketSession = handler;
	}

	///	����������״̬�仯���棬
	///<brief	�����������ӷ�������/�Ͽ�ʱ�����״̬
	///@param  MarketSessionId: ���������Ӵ���
	///@param  ConnectionGood: true��ʾ����������������false��ʾ���������ӶϿ��ˡ�
	///@return void 
	virtual void OnMarketSessionStatReport(EES_MarketSessionId MarketSessionId, bool ConnectionGood);
	void SetCallbackOnMarketSessionStatReport(CbOnMarketSessionStatReport handler) {
		vtCallback.onMarketSessionStatReport = handler;
	}

	///	��Լ״̬�仯����
	///<brief	����Լ״̬�����仯ʱ����
	///@param  pSymbolStatus: �μ�EES_SymbolStatus��Լ״̬�ṹ�嶨��
	///@return void 
	virtual void OnSymbolStatusReport(EES_SymbolStatus* pSymbolStatus);
	void SetCallbackOnSymbolStatusReport(CbOnSymbolStatusReport handler) {
		vtCallback.onSymbolStatusReport = handler;
	}

	///	��Լ״̬��ѯ��Ӧ

	///<brief  ��Ӧ��Լ״̬��ѯ����
	///@param  pSymbolStatus: �μ�EES_SymbolStatus��Լ״̬�ṹ�嶨��
	///@param	bFinish: ��Ϊtrueʱ����ʾ��ѯ���н�����ء���ʱpSymbolStatusΪ��ָ��NULL
	///@return void 
	virtual void OnQuerySymbolStatus(EES_SymbolStatus* pSymbolStatus, bool bFinish);
	void SetCallbackOnQuerySymbolStatus(CbOnQuerySymbolStatus handler) {
		vtCallback.onQuerySymbolStatus = handler;
	}

	///��������ѯ��Ӧ
	///@param	pMarketMBLData: �μ�EES_MarketMBLData�������ṹ�嶨��
	///@param	bFinish: ��Ϊtrueʱ����ʾ��ѯ���н�����ء���ʱpMarketMBLData������,��m_RequestId��Ч
	///@return void 
	virtual void OnQueryMarketMBLData(EES_MarketMBLData* pMarketMBLData, bool bFinish);
	void SetCallbackOnQueryMarketMBLData(CbOnQueryMarketMBLData handler) {
		vtCallback.onQueryMarketMBLData = handler;
	}

	
	///���ӷ�����
	///�ṩ2�ֽӿڣ���������ʽ�����ݼ��°�Ľӿڣ���һ�ֽӿڼ�ʹ��TCPģʽ
	int ConnServer(const char* svrAddr, int nPort, EESTraderEvent* pEvent, const char* qrySvrAddr, int nQrySvrPort);
	int ConnServer(const EES_TradeSvrInfo& param, EESTraderEvent* pEvent);

	///�Ͽ�������
	///@return int						�ο� EesTraderErr.h�ļ�
	int DisConnServer();

	///�û���¼
	///<brief	��������Ĳ����ʻ��������û���
	///@param  const char* userId			�û���
	///@param  const char* userPwd		    �û���¼����
	///@return int			����ֵ���ο� EesTraderErr.h�ļ�
	int UserLogon(const char* user_id, const char* user_pwd, const char* prodInfo, const char* macAddr);

	///�û������޸�
	///<brief	��¼�ɹ������ʹ��
	///@param  const char* oldPwd			������
	///@param  const char* newPwd		    ������
	///@return int			����ֵ���ο� EesTraderErr.h�ļ�
	int ChangePassword(const char* oldPwd, const char* newPwd);

	///��ѯ��Լ�б�
	///<brief	ֻ�᷵�ص�����Ч�ĺ�Լ
	///@return int			����ֵ���ο� EesTraderErr.h�ļ�
	int QuerySymbolList();


	///��ѯ�û��������ʻ�
	///@return int			����ֵ���ο� EesTraderErr.h�ļ�
	int QueryUserAccount();

	///��ѯ�ʻ���λ
	///<brief	
	///@param  const char* accountId		�ʻ�ID
	///@param  int   nReqId			    �����ѯ��ID��
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int QueryAccountPosition(const char* accountId, int nReqId);

	///��ѯ�ʻ�BP
	///<brief	
	///@param  const char* accountId		�ʻ�ID
	///@param  int   nReqId				�����ѯ��ID��
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int QueryAccountBP(const char* accountId, int nReqId);

	///��ѯ�ʻ���֤����
	///@param  const char* accountId		�ʻ�ID
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int QueryAccountTradeMargin(const char* accountId);

	///��ѯ�ʻ�������
	///<brief	���ڣ�ÿһ���ʻ��ķ��ʲ�һ�������ÿһ���ʻ�����ѯһ�¡�
	///@param  const char* accountId		�ʻ�ID
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int QueryAccountTradeFee(const char* accountId);


	///��ȡ���� ���  token ֵ
	///<brief	��ȡ���� ���  token ֵ
	///@param  EES_ClientToken * orderToken	Ҫ�����ֵ
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int GetMaxToken(OUT EES_ClientToken* orderToken);


	///�µ�
	///@param  EES_EnterOrderField* pOrder	��֯�õĶ����ṹ��
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int EnterOrder(EES_EnterOrderField* pOrder);

	///��������ָ��
	///@param  EES_CancelOrder* pCxlOrder		�����ṹ��
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int CancelOrder(EES_CancelOrder* pCxlOrder);

	///��ѯ�ʻ�������Ϣ 
	///@param  const char* accountId		     �ʻ�ID
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int QueryAccountOrder(const char* accountId);

	///��ѯ�ʻ��ɽ���Ϣ
	///@param  const char* accountId		     �ʻ�ID
	///@return int			����ֵ���ο�EesTraderErr.h�ļ�
	int QueryAccountOrderExecution(const char* accountId);

	///���Ͳ�ѯ����������ϯλ����	
	///@return û�з���ֵ����Ӧ��EESTraderEvent::OnQueryMarketSession�з���
	int QueryMarketSession();

	///ʱ���ת�����������ڽ�API�����е�EES_Nanosecond���ͣ�ת����C���Ա�׼��struct tm�ṹ�壬�Լ����ʱ����һ���ڵ�������
	///@param  EES_Nanosecond timeStamp		API����ṹ���е�ʱ���ֵ
	///@param  tm& tmint					���ڽ��ս����struct tm�ṹ��
	///@param  unsigned int& nanoSsec 			���ڽ��ս����������
	///@return û�з���ֵ
	virtual void ConvertFromTimestamp(EES_Nanosecond timeStamp, tm& tmint, unsigned int& nanoSsec) = 0;



	///������־���أ�Ĭ��Ϊ�ء�
	///@param  bool bOn		true: �򿪱�����־; false: �رձ�����־
	///@return û�з���ֵ
	virtual void SetLoggerSwitch(bool bOn) = 0;

	///���Ͳ�ѯ��Լ״̬����
	///@return û�з���ֵ����Ӧ��EESTraderEvent::OnQuerySymbolStatus�з���
	int QuerySymbolStatus();

	///�������������־��Ϣд���ļ�
	///@return û�з���ֵ
	virtual void LoggerFlush() = 0;

	///���ͻ�������Ϊ�첽��������ģʽ��������ConnectServer֮ǰʹ�ã���һ��ʹ�ã��������л�����
	///���ӿ�ֻ��ͼ�λ��ֹ��µ�����ʹ�ã����򻯽���ƽ̨ʹ�øýӿڻ���ɽ��ն��ӳٱ��
	///@return û�з���ֵ
	virtual void SetAsyncReceiveMode() = 0;

	///�����µ������һ����8��������ֻ����TCPģʽ��ʹ��
	///ע��ÿ�������ĵ�OrderToken���뱣֤���ⲿ�����úò��ظ���
	///@param   pArrOrders: EES_EnterOrderField�ṹ�����飬���4����nCount���� >=1���� <=8
	///@return: �ɹ�����0������һ�������д��򷵻ط�0ֵ�������б��������ᱻ����
	int EnterMultiOrders(EES_EnterOrderField* pArrOrders, int nCount);

	///���ս���������������ѯ����ע�⣺��̨ϵͳ��������֧��������飬�ù��ܲŻṤ��	
	///nRequestId: �ͻ����б�ţ���Ӧ�ķ����¼�OnQueryMarketMBLData�У��᷵�����RequestId���ͻ�������ƥ���Լ��Ĳ�ѯ����
	///exchangeID: ��Ҫ����EES_ExchangeID_shfe��ʵ�ʽ���������	
	///nSide: 0-˫�ߣ� 1-����Bid�� 2-������Ask
	///@return: �ɹ�����0��������OnQueryMarketMBLData�з���
	int QueryMarketMBLData(int nRequestId, EES_ExchangeID exchangeID, int nSide);

	///ָ����Լ��Χ����������ѯ����ע�⣺��̨ϵͳ��������֧��������飬�ù��ܲŻṤ��	
	///nRequestId: �ͻ����б�ţ���Ӧ�ķ����¼�OnQueryMarketMBLData�У��᷵�����RequestId���ͻ�������ƥ���Լ��Ĳ�ѯ����	
	///startSymbol , endSymbol: ��ʼ��ѯ��Լ����ֹ��ѯ��Լ����������Ϸ��ĺ�Լ
	///nSide: 0-˫�ߣ� 1-����Bid�� 2-������Ask
	///@return: �ɹ�����0��������OnQueryMarketMBLData�з���
	int QueryMarketMBLData(int nRequestId, const char* startSymbol, const char* endSymbol, int nSide);

	///�����ͻ������ز���
	///��¼�ɹ��󣬿ɴӵ�¼������Ϣ�ṹEES_LogonResponse�У���ȡ����ǰ��¼�����ز�������λ��ÿ���ٺ��룬���ٴ��µ�/������
	///���ڷ���˶����µ��Ŀ����Ǹ����˺ţ�������ϵͳ����һ���˺Ŷ���¼ͬʱ�µ������ʵ�����ؿ��ܻ�Ȼ�õĲ��������ϸ�
	///����ṩ�ýӿڣ��ͻ����Ը����Լ��Ƿ���Ҫ����¼�µ��������ز������и����ϸ�ĵ�������ֹ�����˷����������شӶ����������۶ϵ�¼
	///���ӿ�ֻ��������µ���������ֻ�ܵ��ø��٣��Ҳ��ܽ���������0
	///OrderCount�������µ���������
	///CancelCount�����³�����������
	///�ӿڲ��᷵����ȷ���Ǵ�����������˴���Ĳ�������ԭ��������仯
	int ChangeFCParam(unsigned int OrderCount, unsigned int CancelCount);
};
