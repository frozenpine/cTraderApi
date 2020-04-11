#ifndef C_EES_TRADER_API_H
#define C_EES_TRADER_API_H
#include <stdint.h>
#include <stdbool.h>

#include "EesTraderDefine.h"
#include "EesTraderErr.h"

#ifdef __GNUC__
#ifdef CREMAPI_EXPORTS
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
#define NULL ((C_API void *)0)
#endif

	///C API instance id
	typedef uintptr_t InstanceID;

	///������Ϣ�Ļص�
	///<brief	�����������¼�
	///@param  errNo                   ���ӳɹ���������Ϣ
	///@param  pErrStr                 ������Ϣ
	///@return void  
	typedef void (APPWINAPI *CbOnConnection)(InstanceID id, ERR_NO errNo, const char* pErrStr);
	C_API void SetCallbackOnConnection(InstanceID id, CbOnConnection handler);

	///���ӶϿ���Ϣ�Ļص�
	///<brief	�����������Ͽ������յ������Ϣ
	///@param  ERR_NO errNo         ���ӳɹ���������Ϣ
	///@param  const char* pErrStr  ������Ϣ
	///@return void  
	typedef void (APPWINAPI *CbOnDisConnection)(InstanceID id, ERR_NO errNo, const char* pErrStr);
	C_API void SetCallbackOnDisConnection(InstanceID id, CbOnDisConnection handler);

	///��¼��Ϣ�Ļص�
	///@param  pLogon                  ��¼�ɹ�����ʧ�ܵĽṹ
	///@return void 
	typedef void (APPWINAPI *CbOnUserLogon)(InstanceID id, EES_LogonResponse* pLogon);
	C_API void SetCallbackOnUserLogon(InstanceID id, CbOnUserLogon handler);

	///�޸�������Ӧ�ص�
	///@param  nint                  ��������Ӧ�ĳɹ���񷵻���
	///@return void 
	typedef void (APPWINAPI *CbOnRspChangePassword)(InstanceID id, EES_ChangePasswordResult nint);
	C_API void SetCallbackOnRspChangePassword(InstanceID id, CbOnRspChangePassword handler);

	///��ѯ�û������ʻ��ķ����¼�
	///@param  pAccountInfo	        �ʻ�����Ϣ
	///@param  bFinish	                ���û�д�����ɣ����ֵ�� false ���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryUserAccount)(InstanceID id, EES_AccountInfo * pAccoutnInfo, bool bFinish);
	C_API void SetCallbackOnQueryUserAccount(InstanceID id, CbOnQueryUserAccount handler);

	///��ѯ�ʻ������ڻ���λ��Ϣ�ķ����¼�	
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID�š�
	///@param  bFinish	                    ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 	
	typedef void (APPWINAPI *CbOnQueryAccountPosition)(InstanceID id, const char* pAccount, EES_AccountPosition* pAccoutnPosition, int nReqId, bool bFinish);
	C_API void SetCallbackOnQueryAccountPosition(InstanceID id, CbOnQueryAccountPosition handler);

	///��ѯ�ʻ�������Ȩ��λ��Ϣ�ķ����¼�, ע������ص�, ����һ��OnQueryAccountPosition, ����һ��QueryAccountPosition�����, �ֱ𷵻�, �ȷ����ڻ�, �ٷ�����Ȩ, ��ʹû����Ȩ��λ, Ҳ�᷵��һ��bFinish=true�ļ�¼
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID�š�
	///@param  bFinish	                    ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pAccountInfoֵ��Ч��
	///@return void 	
	typedef void (APPWINAPI *CbOnQueryAccountOptionPosition)(InstanceID id, const char* pAccount, EES_AccountOptionPosition* pAccoutnOptionPosition, int nReqId, bool bFinish);
	C_API void SetCallbackOnQueryAccountOptionPosition(InstanceID id, CbOnQueryAccountOptionPosition handler);

	///��ѯ�ʻ������ʽ���Ϣ�ķ����¼�
	///@param  pAccount	                �ʻ�ID 	
	///@param  pAccoutnPosition	        �ʻ��Ĳ�λ��Ϣ					   
	///@param  nReqId		                ����������Ϣʱ���ID��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountBP)(InstanceID id, const char* pAccount, EES_AccountBP* pAccoutnPosition, int nReqId);
	C_API void SetCallbackOnQueryAccountBP(InstanceID id, CbOnQueryAccountBP handler);

	///��ѯ��Լ�б�ķ����¼�
	///@param  pSymbol	                    ��Լ��Ϣ   
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true   
	///remark ������� bFinish == true����ô�Ǵ������������ pSymbol ֵ��Ч��
	///@return void
	typedef void (APPWINAPI *CbOnQuerySymbol)(InstanceID id, EES_SymbolField* pSymbol, bool bFinish);
	C_API void SetCallbackOnQuerySymbol(InstanceID id, CbOnQuerySymbol handler);

	///��ѯ�ʻ����ױ�֤��ķ����¼�
	///@param  pAccount                    �ʻ�ID 
	///@param  pSymbolMargin               �ʻ��ı�֤����Ϣ 
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false�������ɣ��Ǹ����ֵΪ true 
	///remark ������� bFinish == true����ô�Ǵ������������ pSymbolMargin ֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountTradeMargin)(InstanceID id, const char* pAccount, EES_AccountMargin* pSymbolMargin, bool bFinish);
	C_API void SetCallbackOnQueryAccountTradeMargin(InstanceID id, CbOnQueryAccountTradeMargin handler);

	///��ѯ�ʻ����׷��õķ����¼�
	///@param  pAccount                    �ʻ�ID 
	///@param  pSymbolFee	                �ʻ��ķ�����Ϣ	 
	///@param  bFinish	                    ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true ����ô�Ǵ������������ pSymbolFee ֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountTradeFee)(InstanceID id, const char* pAccount, EES_AccountFee* pSymbolFee, bool bFinish);
	C_API void SetCallbackOnQueryAccountTradeFee(InstanceID id, CbOnQueryAccountTradeFee handler);

	///�µ�����̨ϵͳ���ܵ��¼�
	///<brief ��ʾ��������Ѿ�����̨ϵͳ��ʽ�Ľ���
	///@param  pAccept	                    �����������Ժ����Ϣ��
	///@return void 
	typedef void (APPWINAPI *CbOnOrderAccept)(InstanceID id, EES_OrderAcceptField* pAccept);
	C_API void SetCallbackOnOrderAccept(InstanceID id, CbOnOrderAccept handler);

	///�µ����г����ܵ��¼�
	///<brief ��ʾ��������Ѿ�����������ʽ�Ľ���
	///@param  pAccept	                    �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderMarketAccept)(InstanceID id, EES_OrderMarketAcceptField* pAccept);
	C_API void SetCallbackOnOrderMarketAccept(InstanceID id, CbOnOrderMarketAccept handler);

	///�µ�����̨ϵͳ�ܾ����¼�
	///<brief	��������̨ϵͳ�ܾ������Բ鿴�﷨�����Ƿ�ؼ�顣 
	///@param  pReject	                    �����������Ժ����Ϣ��
	///@return void 
	typedef void (APPWINAPI *CbOnOrderReject)(InstanceID id, EES_OrderRejectField* pReject);
	C_API void SetCallbackOnOrderReject(InstanceID id, CbOnOrderReject handler);

	///�µ����г��ܾ����¼�
	///<brief	�������г��ܾ������Բ鿴�﷨�����Ƿ�ؼ�顣 
	///@param  pReject	                    �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderMarketReject)(InstanceID id, EES_OrderMarketRejectField* pReject);
	C_API void SetCallbackOnOrderMarketReject(InstanceID id, CbOnOrderMarketReject handler);

	///�����ɽ�����Ϣ�¼�
	///<brief	�ɽ���������˶����г�ID�����������ID��ѯ��Ӧ�Ķ���
	///@param  pExec	                   �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderExecution)(InstanceID id, EES_OrderExecutionField* pExec);
	C_API void SetCallbackOnOrderExecution(InstanceID id, CbOnOrderExecution handler);

	///�����ɹ������¼�
	///<brief	�ɽ���������˶����г�ID�����������ID��ѯ��Ӧ�Ķ���
	///@param  pCxled		               �����������Ժ����Ϣ�壬����������г�����ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderCxled)(InstanceID id, EES_OrderCxled* pCxled);
	C_API void SetCallbackOnOrderCxled(InstanceID id, CbOnOrderCxled handler);

	///�������ܾ�����Ϣ�¼�
	///<brief	һ����ڷ��ͳ����Ժ��յ������Ϣ����ʾ�������ܾ�
	///@param  pReject	                   �������ܾ���Ϣ��
	///@return void 
	typedef void (APPWINAPI *CbOnCxlOrderReject)(InstanceID id, EES_CxlOrderRej* pReject);
	C_API void SetCallbackOnCxlOrderReject(InstanceID id, CbOnCxlOrderReject handler);

	///��ѯ�����ķ����¼�
	///<brief	��ѯ������Ϣʱ��Ļص���������Ҳ���ܰ������ǵ�ǰ�û��µĶ���
	///@param  pAccount                 �ʻ�ID 
	///@param  pQueryOrder	             ��ѯ�����Ľṹ
	///@param  bFinish	                 ���û�д�����ɣ����ֵ�� false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true����ô�Ǵ������������ pQueryOrderֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryTradeOrder)(InstanceID id, const char* pAccount, EES_QueryAccountOrder* pQueryOrder, bool bFinish);
	C_API void SetCallbackOnQueryTradeOrder(InstanceID id, CbOnQueryTradeOrder handler);

	///��ѯ�����ķ����¼�
	///<brief	��ѯ������Ϣʱ��Ļص���������Ҳ���ܰ������ǵ�ǰ�û��µĶ����ɽ�
	///@param  pAccount                        �ʻ�ID 
	///@param  pQueryOrderExec	                ��ѯ�����ɽ��Ľṹ
	///@param  bFinish	                        ���û�д�����ɣ����ֵ��false���������ˣ��Ǹ����ֵΪ true    
	///remark ������� bFinish == true����ô�Ǵ������������pQueryOrderExecֵ��Ч��
	///@return void 
	typedef void (APPWINAPI *CbOnQueryTradeOrderExec)(InstanceID id, const char* pAccount, EES_QueryOrderExecution* pQueryOrderExec, bool bFinish);
	C_API void SetCallbackOnQueryTradeOrderExec(InstanceID id, CbOnQueryTradeOrderExec handler);

	///�����ⲿ��������Ϣ
	///<brief	һ�����ϵͳ�������������˹�������ʱ���õ���
	///@param  pPostOrder	                    ��ѯ�����ɽ��Ľṹ
	///@return void 
	typedef void (APPWINAPI *CbOnPostOrder)(InstanceID id, EES_PostOrder* pPostOrder);
	C_API void SetCallbackOnPostOrder(InstanceID id, CbOnPostOrder handler);

	///�����ⲿ�����ɽ�����Ϣ
	///<brief	һ�����ϵͳ�������������˹�������ʱ���õ���
	///@param  pPostOrderExecution	             ��ѯ�����ɽ��Ľṹ
	///@return void 
	typedef void (APPWINAPI *CbOnPostOrderExecution)(InstanceID id, EES_PostOrderExecution* pPostOrderExecution);
	C_API void SetCallbackOnPostOrderExecution(InstanceID id, CbOnPostOrderExecution handler);

	///��ѯ�������������ӵ���Ӧ
	///<brief	ÿ����ǰϵͳ֧�ֵĻ㱨һ�Σ���bFinish= trueʱ����ʾ���н���������Ӧ���ѵ����������Ϣ�����������õ���Ϣ��
	///@param  pPostOrderExecution	             ��ѯ�����ɽ��Ľṹ
	///@return void 
	typedef void (APPWINAPI *CbOnQueryMarketSession)(InstanceID id, EES_ExchangeMarketSession* pMarketSession, bool bFinish);
	C_API void SetCallbackOnQueryMarketSession(InstanceID id, CbOnQueryMarketSession handler);

	///����������״̬�仯���棬
	///<brief	�����������ӷ�������/�Ͽ�ʱ�����״̬
	///@param  MarketSessionId: ���������Ӵ���
	///@param  ConnectionGood: true��ʾ����������������false��ʾ���������ӶϿ��ˡ�
	///@return void 
	typedef void (APPWINAPI *CbOnMarketSessionStatReport)(InstanceID id, EES_MarketSessionId MarketSessionId, bool ConnectionGood);
	C_API void SetCallbackOnMarketSessionStatReport(InstanceID id, CbOnMarketSessionStatReport handler);

	///��Լ״̬�仯����
	///<brief	����Լ״̬�����仯ʱ����
	///@param  pSymbolStatus: �μ�EES_SymbolStatus��Լ״̬�ṹ�嶨��
	///@return void 
	typedef void (APPWINAPI *CbOnSymbolStatusReport)(InstanceID id, EES_SymbolStatus* pSymbolStatus);
	C_API void SetCallbackOnSymbolStatusReport(InstanceID id, CbOnSymbolStatusReport handler);

	///��Լ״̬��ѯ��Ӧ
	///<brief  ��Ӧ��Լ״̬��ѯ����
	///@param  pSymbolStatus: �μ�EES_SymbolStatus��Լ״̬�ṹ�嶨��
	///@param  bFinish: ��Ϊtrueʱ����ʾ��ѯ���н�����ء���ʱpSymbolStatusΪ��ָ��NULL
	///@return void 
	typedef void (APPWINAPI *CbOnQuerySymbolStatus)(InstanceID id, EES_SymbolStatus* pSymbolStatus, bool bFinish);
	C_API void SetCallbackOnQuerySymbolStatus(InstanceID id, CbOnQuerySymbolStatus handler);

	///��������ѯ��Ӧ
	///@param	pMarketMBLData: �μ�EES_MarketMBLData�������ṹ�嶨��
	///@param	bFinish: ��Ϊtrueʱ����ʾ��ѯ���н�����ء���ʱpMarketMBLData������,��m_RequestId��Ч
	///@return void 
	typedef void (APPWINAPI *CbOnQueryMarketMBLData)(InstanceID id, EES_MarketMBLData* pMarketMBLData, bool bFinish);
	C_API void SetCallbackOnQueryMarketMBLData(InstanceID id, CbOnQueryMarketMBLData handler);

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
	
	C_API void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif
