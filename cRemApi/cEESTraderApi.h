#include <stdint.h>
#include <stdbool.h>

#include "EesTraderDefine.h"
#include "EesTraderErr.h"

#ifdef __GNUC__
#ifdef CTRADERAPI_EXPORTS
#define C_API __attribute__((dllexport))
#else
#define C_API __attribute__((dllimport))
#endif
#else
#ifdef CREMAPI_EXPORTS
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

	///C API instance id
	typedef uintptr_t InstanceID;

	///������Ϣ�Ļص�
	///<brief	�����������¼�
	///@param  errNo                   ���ӳɹ���������Ϣ
	///@param  pErrStr                 ������Ϣ
	///@return void  
	typedef void (APPWINAPI *CbOnConnection)(ERR_NO errNo, const char* pErrStr);
	void SetCallbackOnConnection(InstanceID id, CbOnConnection handler);

	///���ӶϿ���Ϣ�Ļص�
	///<brief	�����������Ͽ������յ������Ϣ
	///@param  ERR_NO errNo         ���ӳɹ���������Ϣ
	///@param  const char* pErrStr  ������Ϣ
	///@return void  
	typedef void (APPWINAPI *CbOnDisConnection)(ERR_NO errNo, const char* pErrStr);
	void SetCallbackOnDisConnection(InstanceID id, CbOnDisConnection handler);

	///��¼��Ϣ�Ļص�
	///@param  pLogon                  ��¼�ɹ�����ʧ�ܵĽṹ
	///@return void 
	typedef void (APPWINAPI *CbOnUserLogon)(EES_LogonResponse* pLogon);
	void SetCallbackOnUserLogon(InstanceID id, CbOnUserLogon handler);

	///�޸�������Ӧ�ص�
	///@param  nint                  ��������Ӧ�ĳɹ���񷵻���
	///@return void 
	typedef void (APPWINAPI *CbOnRspChangePassword)(EES_ChangePasswordResult nint);
	void SetCallbackOnRspChangePassword(InstanceID id, CbOnRspChangePassword handler);

	///��ѯ�û������ʻ��ķ����¼�
	///@param  pAccountInfo	        �ʻ�����Ϣ
	///@param  bFinish	                ���û�д�����ɣ����ֵ�� false ���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryUserAccount)(EES_AccountInfo * pAccoutnInfo, bool bFinish);
	void SetCallbackOnQueryUserAccount(InstanceID id, CbOnQueryUserAccount handler);

	///��ѯ�ʻ������ڻ���λ��Ϣ�ķ����¼�	
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID�š�
	///@param  bFinish	                    ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 	
	typedef void (APPWINAPI *CbOnQueryAccountPosition)(const char* pAccount, EES_AccountPosition* pAccoutnPosition, int nReqId, bool bFinish);
	void SetCallbackOnQueryAccountPosition(InstanceID id, CbOnQueryAccountPosition handler);

	///��ѯ�ʻ�������Ȩ��λ��Ϣ�ķ����¼�, ע������ص�, ����һ��OnQueryAccountPosition, ����һ��QueryAccountPosition�����, �ֱ𷵻�, �ȷ����ڻ�, �ٷ�����Ȩ, ��ʹû����Ȩ��λ, Ҳ�᷵��һ��bFinish=true�ļ�¼
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID�š�
	///@param  bFinish	                    ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 	
	typedef void (APPWINAPI *CbOnQueryAccountOptionPosition)(const char* pAccount, EES_AccountOptionPosition* pAccoutnOptionPosition, int nReqId, bool bFinish);
	void SetCallbackOnQueryAccountOptionPosition(InstanceID id, CbOnQueryAccountOptionPosition handler);

	///��ѯ�ʻ������ʽ���Ϣ�ķ����¼�
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountBP)(const char* pAccount, EES_AccountBP* pAccoutnPosition, int nReqId);
	void SetCallbackOnQueryAccountBP(InstanceID id, CbOnQueryAccountBP handler);

	///��ѯ��Լ�б�ķ����¼�
	///@param  pSymbol	                    ��Լ��Ϣ   
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true   
	///remark ������� bFinish == true����ô�Ǵ������������ pSymbol ֵ��Ч��
	///@return void
	typedef void (APPWINAPI *CbOnQuerySymbol)(EES_SymbolField* pSymbol, bool bFinish);
	void SetCallbackOnQuerySymbol(InstanceID id, CbOnQuerySymbol handler);

	///��ѯ�ʻ����ױ�֤��ķ����¼�
	///@param  pAccount                    �ʻ�ID 
	///@param  pSymbolMargin               �ʻ��ı�֤����Ϣ 
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false�������ɣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pSymbolMargin ֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountTradeMargin)(const char* pAccount, EES_AccountMargin* pSymbolMargin, bool bFinish);
	void SetCallbackOnQueryAccountTradeMargin(InstanceID id, CbOnQueryAccountTradeMargin handler);

	///��ѯ�ʻ����׷��õķ����¼�
	///@param  pAccount                    �ʻ�ID 
	///@param  pSymbolFee	                �ʻ��ķ�����Ϣ	 
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true ����ô�Ǵ������������ pSymbolFee ֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountTradeFee)(const char* pAccount, EES_AccountFee* pSymbolFee, bool bFinish);
	void SetCallbackOnQueryAccountTradeFee(InstanceID id, CbOnQueryAccountTradeFee handler);

	///�µ�����̨ϵͳ���ܵ��¼�
	///<brief ��ʾ��������Ѿ�����̨ϵͳ��ʽ�Ľ���
	///@param  pAccept	                    �����������Ժ����Ϣ��
	///@return void 
	typedef void (APPWINAPI *CbOnOrderAccept)(EES_OrderAcceptField* pAccept);
	void SetCallbackOnOrderAccept(InstanceID id, CbOnOrderAccept handler);

	///�µ����г����ܵ��¼�
	///<brief ��ʾ��������Ѿ�����������ʽ�Ľ���
	///@param  pAccept	                    �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderMarketAccept)(EES_OrderMarketAcceptField* pAccept);
	void SetCallbackOnOrderMarketAccept(InstanceID id, CbOnOrderMarketAccept handler);

	///�µ�����̨ϵͳ�ܾ����¼�
	///<brief	��������̨ϵͳ�ܾ������Բ鿴�﷨�����Ƿ�ؼ�顣 
	///@param  pReject	                    �����������Ժ����Ϣ��
	///@return void 
	typedef void (APPWINAPI *CbOnOrderReject)(EES_OrderRejectField* pReject);
	void SetCallbackOnOrderReject(InstanceID id, CbOnOrderReject handler);

	///�µ����г��ܾ����¼�
	///<brief	�������г��ܾ������Բ鿴�﷨�����Ƿ�ؼ�顣 
	///@param  pReject	                    �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderMarketReject)(EES_OrderMarketRejectField* pReject);
	void SetCallbackOnOrderMarketReject(InstanceID id, CbOnOrderMarketReject handler);

	///�����ɽ�����Ϣ�¼�
	///<brief	�ɽ���������˶����г�ID�����������ID��ѯ��Ӧ�Ķ���
	///@param  pExec	                   �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderExecution)(EES_OrderExecutionField* pExec);
	void SetCallbackOnOrderExecution(InstanceID id, CbOnOrderExecution handler);

	///�����ɹ������¼�
	///<brief	�ɽ���������˶����г�ID�����������ID��ѯ��Ӧ�Ķ���
	///@param  pCxled		               �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderCxled)(EES_OrderCxled* pCxled);
	void SetCallbackOnOrderCxled(InstanceID id, CbOnOrderCxled handler);

	///�������ܾ�����Ϣ�¼�
	///<brief	һ����ڷ��ͳ����Ժ��յ������Ϣ����ʾ�������ܾ�
	///@param  pReject	                   �������ܾ���Ϣ��
	///@return void 
	typedef void (APPWINAPI *CbOnCxlOrderReject)(EES_CxlOrderRej* pReject);
	void SetCallbackOnCxlOrderReject(InstanceID id, CbOnCxlOrderReject handler);

	///��ѯ�����ķ����¼�
	///<brief	��ѯ������Ϣʱ��Ļص���������Ҳ���ܰ������ǵ�ǰ�û��µĶ���
	///@param  pAccount                 �ʻ�ID 
	///@param  pQueryOrder	             ��ѯ�����Ľṹ
	///@param  bFinish	                 ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true����ô�Ǵ������������ pQueryOrderֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryTradeOrder)(const char* pAccount, EES_QueryAccountOrder* pQueryOrder, bool bFinish);
	void SetCallbackOnQueryTradeOrder(InstanceID id, CbOnQueryTradeOrder handler);

	///��ѯ�����ķ����¼�
	///<brief	��ѯ������Ϣʱ��Ļص���������Ҳ���ܰ������ǵ�ǰ�û��µĶ����ɽ�
	///@param  pAccount                        �ʻ�ID 
	///@param  pQueryOrderExec	                ��ѯ�����ɽ��Ľṹ
	///@param  bFinish	                        ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true����ô�Ǵ������������pQueryOrderExecֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryTradeOrderExec)(const char* pAccount, EES_QueryOrderExecution* pQueryOrderExec, bool bFinish);
	void SetCallbackOnQueryTradeOrderExec(InstanceID id, CbOnQueryTradeOrderExec handler);

	///�����ⲿ��������Ϣ
	///<brief	һ�����ϵͳ�������������˹�������ʱ���õ���
	///@param  pPostOrder	                    ��ѯ�����ɽ��Ľṹ
	///@return void 
	typedef void (APPWINAPI *CbOnPostOrder)(EES_PostOrder* pPostOrder);
	void SetCallbackOnPostOrder(InstanceID id, CbOnPostOrder handler);

	///�����ⲿ�����ɽ�����Ϣ
	///<brief	һ�����ϵͳ�������������˹�������ʱ���õ���
	///@param  pPostOrderExecution	             ��ѯ�����ɽ��Ľṹ
	///@return void 
	typedef void (APPWINAPI *CbOnPostOrderExecution)(EES_PostOrderExecution* pPostOrderExecution);
	void SetCallbackOnPostOrderExecution(InstanceID id, CbOnPostOrderExecution handler);

	///��ѯ�������������ӵ���Ӧ
	///<brief	ÿ����ǰϵͳ֧�ֵĻ㱨һ�Σ���bFinish= trueʱ����ʾ���н���������Ӧ���ѵ����������Ϣ�����������õ���Ϣ��
	///@param  pPostOrderExecution	             ��ѯ�����ɽ��Ľṹ
	///@return void 
	typedef void (APPWINAPI *CbOnQueryMarketSession)(EES_ExchangeMarketSession* pMarketSession, bool bFinish);
	void SetCallbackOnQueryMarketSession(InstanceID id, CbOnQueryMarketSession handler);

	///����������״̬�仯���棬
	///<brief	�����������ӷ�������/�Ͽ�ʱ�����״̬
	///@param  MarketSessionId: ���������Ӵ���
	///@param  ConnectionGood: true��ʾ����������������false��ʾ���������ӶϿ��ˡ�
	///@return void 
	typedef void (APPWINAPI *CbOnMarketSessionStatReport)(EES_MarketSessionId MarketSessionId, bool ConnectionGood);
	void SetCallbackOnMarketSessionStatReport(InstanceID id, CbOnMarketSessionStatReport handler);

	///��Լ״̬�仯����
	///<brief	����Լ״̬�����仯ʱ����
	///@param  pSymbolStatus: �μ�EES_SymbolStatus��Լ״̬�ṹ�嶨��
	///@return void 
	typedef void (APPWINAPI *CbOnSymbolStatusReport)(EES_SymbolStatus* pSymbolStatus);
	void SetCallbackOnSymbolStatusReport(InstanceID id, CbOnSymbolStatusReport handler);

	///��Լ״̬��ѯ��Ӧ
	///<brief  ��Ӧ��Լ״̬��ѯ����
	///@param  pSymbolStatus: �μ�EES_SymbolStatus��Լ״̬�ṹ�嶨��
	///@param	bFinish: ��Ϊtrueʱ����ʾ��ѯ���н�����ء���ʱpSymbolStatusΪ��ָ��NULL
	///@return void 
	typedef void (APPWINAPI *CbOnQuerySymbolStatus)(EES_SymbolStatus* pSymbolStatus, bool bFinish);
	void SetCallbackOnQuerySymbolStatus(InstanceID id, CbOnQuerySymbolStatus handler);

	///��������ѯ��Ӧ
	///@param	pMarketMBLData: �μ�EES_MarketMBLData�������ṹ�嶨��
	///@param	bFinish: ��Ϊtrueʱ����ʾ��ѯ���н�����ء���ʱpMarketMBLData������,��m_RequestId��Ч
	///@return void 
	typedef void (APPWINAPI *CbOnQueryMarketMBLData)(EES_MarketMBLData* pMarketMBLData, bool bFinish);
	void SetCallbackOnQueryMarketMBLData(InstanceID id, CbOnQueryMarketMBLData handler);

	typedef struct callbackVirtualTable
	{
		///������Ϣ�Ļص�
		CbOnConnection onConnection;

		///���ӶϿ���Ϣ�Ļص�
		CbOnDisConnection onDisConnection;

		///��¼��Ϣ�Ļص�
		CbOnUserLogon onUserLogon;

		///�޸�������Ӧ�ص�
		CbOnRspChangePassword onRspChangePassword;

		///��ѯ�û������ʻ��ķ����¼�
		CbOnQueryUserAccount onQueryUserAccount;

		///��ѯ�ʻ������ڻ���λ��Ϣ�ķ����¼�
		CbOnQueryAccountPosition onQueryAccountPosition;

		///��ѯ�ʻ�������Ȩ��λ��Ϣ�ķ����¼�
		CbOnQueryAccountOptionPosition onQueryAccountOptionPosition;

		///��ѯ�ʻ������ʽ���Ϣ�ķ����¼�
		CbOnQueryAccountBP onQueryAccountBP;

		///��ѯ��Լ�б�ķ����¼�
		CbOnQuerySymbol onQuerySymbol;

		///��ѯ�ʻ����ױ�֤��ķ����¼�
		CbOnQueryAccountTradeMargin onQueryAccountTradeMargin;

		///��ѯ�ʻ����׷��õķ����¼�
		CbOnQueryAccountTradeFee onQueryAccountTradeFee;

		///�µ�����̨ϵͳ���ܵ��¼�
		CbOnOrderAccept onOrderAccept;

		///�µ����г����ܵ��¼�
		CbOnOrderMarketAccept onOrderMarketAccept;

		///�µ�����̨ϵͳ�ܾ����¼�
		CbOnOrderReject onOrderReject;

		///�µ����г��ܾ����¼�
		CbOnOrderMarketReject onOrderMarketReject;

		///�����ɽ�����Ϣ�¼�
		CbOnOrderExecution onOrderExecution;

		///�����ɹ������¼�
		CbOnOrderCxled onOrderCxled;

		///�������ܾ�����Ϣ�¼�
		CbOnCxlOrderReject onCxlOrderReject;

		///��ѯ�����ķ����¼�
		CbOnQueryTradeOrder onQueryTradeOrder;

		///��ѯ�����ķ����¼�
		CbOnQueryTradeOrderExec onQueryTradeOrderExec;

		///�����ⲿ��������Ϣ
		CbOnPostOrder onPostOrder;

		///�����ⲿ�����ɽ�����Ϣ
		CbOnPostOrderExecution onPostOrderExecution;

		///��ѯ�������������ӵ���Ӧ
		CbOnQueryMarketSession onQueryMarketSession;

		///����������״̬�仯����
		CbOnMarketSessionStatReport onMarketSessionStatReport;

		///��Լ״̬�仯����
		CbOnSymbolStatusReport onSymbolStatusReport;

		///��Լ״̬��ѯ��Ӧ
		CbOnQuerySymbolStatus onQuerySymbolStatus;

		///��������ѯ��Ӧ
		CbOnQueryMarketMBLData onQueryMarketMBLData;
	} callbackVirtualTable;
	
	void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt);

#ifdef __cplusplus
}
#endif // __cplusplus
