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

	///连接消息的回调
	///<brief	服务器连接事件
	///@param  errNo                   连接成功能与否的消息
	///@param  pErrStr                 错误信息
	///@return void  
	typedef void (APPWINAPI *CbOnConnection)(ERR_NO errNo, const char* pErrStr);
	void SetCallbackOnConnection(InstanceID id, CbOnConnection handler);

	///连接断开消息的回调
	///<brief	服务器主动断开，会收到这个消息
	///@param  ERR_NO errNo         连接成功能与否的消息
	///@param  const char* pErrStr  错误信息
	///@return void  
	typedef void (APPWINAPI *CbOnDisConnection)(ERR_NO errNo, const char* pErrStr);
	void SetCallbackOnDisConnection(InstanceID id, CbOnDisConnection handler);

	///登录消息的回调
	///@param  pLogon                  登录成功或是失败的结构
	///@return void 
	typedef void (APPWINAPI *CbOnUserLogon)(EES_LogonResponse* pLogon);
	void SetCallbackOnUserLogon(InstanceID id, CbOnUserLogon handler);

	///修改密码响应回调
	///@param  nint                  服务器响应的成功与否返回码
	///@return void 
	typedef void (APPWINAPI *CbOnRspChangePassword)(EES_ChangePasswordResult nint);
	void SetCallbackOnRspChangePassword(InstanceID id, CbOnRspChangePassword handler);

	///查询用户下面帐户的返回事件
	///@param  pAccountInfo	        帐户的信息
	///@param  bFinish	                如果没有传输完成，这个值是 false ，如果完成了，那个这个值为 true 
	///remark 如果碰到 bFinish == true，那么是传输结束，并且 pAccountInfo值无效。
	///@return void 
	typedef void (APPWINAPI *CbOnQueryUserAccount)(EES_AccountInfo * pAccoutnInfo, bool bFinish);
	void SetCallbackOnQueryUserAccount(InstanceID id, CbOnQueryUserAccount handler);

	///查询帐户下面期货仓位信息的返回事件	
	///@param  pAccount	                帐户ID 	
	///@param  pAccoutnPosition	        帐户的仓位信息					   
	///@param  nReqId		                发送请求消息时候的ID号。
	///@param  bFinish	                    如果没有传输完成，这个值是false，如果完成了，那个这个值为 true 
	///remark 如果碰到 bFinish == true，那么是传输结束，并且 pAccountInfo值无效。
	///@return void 	
	typedef void (APPWINAPI *CbOnQueryAccountPosition)(const char* pAccount, EES_AccountPosition* pAccoutnPosition, int nReqId, bool bFinish);
	void SetCallbackOnQueryAccountPosition(InstanceID id, CbOnQueryAccountPosition handler);

	///查询帐户下面期权仓位信息的返回事件, 注意这个回调, 和上一个OnQueryAccountPosition, 会在一次QueryAccountPosition请求后, 分别返回, 先返回期货, 再返回期权, 即使没有期权仓位, 也会返回一条bFinish=true的记录
	///@param  pAccount	                帐户ID 	
	///@param  pAccoutnPosition	        帐户的仓位信息					   
	///@param  nReqId		                发送请求消息时候的ID号。
	///@param  bFinish	                    如果没有传输完成，这个值是false，如果完成了，那个这个值为 true 
	///remark 如果碰到 bFinish == true，那么是传输结束，并且 pAccountInfo值无效。
	///@return void 	
	typedef void (APPWINAPI *CbOnQueryAccountOptionPosition)(const char* pAccount, EES_AccountOptionPosition* pAccoutnOptionPosition, int nReqId, bool bFinish);
	void SetCallbackOnQueryAccountOptionPosition(InstanceID id, CbOnQueryAccountOptionPosition handler);

	///查询帐户下面资金信息的返回事件
	///@param  pAccount	                帐户ID 	
	///@param  pAccoutnPosition	        帐户的仓位信息					   
	///@param  nReqId		                发送请求消息时候的ID号
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountBP)(const char* pAccount, EES_AccountBP* pAccoutnPosition, int nReqId);
	void SetCallbackOnQueryAccountBP(InstanceID id, CbOnQueryAccountBP handler);

	///查询合约列表的返回事件
	///@param  pSymbol	                    合约信息   
	///@param  bFinish	                    如果没有传输完成，这个值是 false，如果完成了，那个这个值为 true   
	///remark 如果碰到 bFinish == true，那么是传输结束，并且 pSymbol 值无效。
	///@return void
	typedef void (APPWINAPI *CbOnQuerySymbol)(EES_SymbolField* pSymbol, bool bFinish);
	void SetCallbackOnQuerySymbol(InstanceID id, CbOnQuerySymbol handler);

	///查询帐户交易保证金的返回事件
	///@param  pAccount                    帐户ID 
	///@param  pSymbolMargin               帐户的保证金信息 
	///@param  bFinish	                    如果没有传输完成，这个值是 false，如果完成，那个这个值为 true 
	///remark 如果碰到 bFinish == true，那么是传输结束，并且 pSymbolMargin 值无效。
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountTradeMargin)(const char* pAccount, EES_AccountMargin* pSymbolMargin, bool bFinish);
	void SetCallbackOnQueryAccountTradeMargin(InstanceID id, CbOnQueryAccountTradeMargin handler);

	///查询帐户交易费用的返回事件
	///@param  pAccount                    帐户ID 
	///@param  pSymbolFee	                帐户的费率信息	 
	///@param  bFinish	                    如果没有传输完成，这个值是 false，如果完成了，那个这个值为 true    
	///remark 如果碰到 bFinish == true ，那么是传输结束，并且 pSymbolFee 值无效。
	///@return void 
	typedef void (APPWINAPI *CbOnQueryAccountTradeFee)(const char* pAccount, EES_AccountFee* pSymbolFee, bool bFinish);
	void SetCallbackOnQueryAccountTradeFee(InstanceID id, CbOnQueryAccountTradeFee handler);

	///下单被柜台系统接受的事件
	///<brief 表示这个订单已经被柜台系统正式的接受
	///@param  pAccept	                    订单被接受以后的消息体
	///@return void 
	typedef void (APPWINAPI *CbOnOrderAccept)(EES_OrderAcceptField* pAccept);
	void SetCallbackOnOrderAccept(InstanceID id, CbOnOrderAccept handler);

	///下单被市场接受的事件
	///<brief 表示这个订单已经被交易所正式的接受
	///@param  pAccept	                    订单被接受以后的消息体，里面包含了市场订单ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderMarketAccept)(EES_OrderMarketAcceptField* pAccept);
	void SetCallbackOnOrderMarketAccept(InstanceID id, CbOnOrderMarketAccept handler);

	///下单被柜台系统拒绝的事件
	///<brief	订单被柜台系统拒绝，可以查看语法检查或是风控检查。 
	///@param  pReject	                    订单被接受以后的消息体
	///@return void 
	typedef void (APPWINAPI *CbOnOrderReject)(EES_OrderRejectField* pReject);
	void SetCallbackOnOrderReject(InstanceID id, CbOnOrderReject handler);

	///下单被市场拒绝的事件
	///<brief	订单被市场拒绝，可以查看语法检查或是风控检查。 
	///@param  pReject	                    订单被接受以后的消息体，里面包含了市场订单ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderMarketReject)(EES_OrderMarketRejectField* pReject);
	void SetCallbackOnOrderMarketReject(InstanceID id, CbOnOrderMarketReject handler);

	///订单成交的消息事件
	///<brief	成交里面包括了订单市场ID，建议用这个ID查询对应的订单
	///@param  pExec	                   订单被接受以后的消息体，里面包含了市场订单ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderExecution)(EES_OrderExecutionField* pExec);
	void SetCallbackOnOrderExecution(InstanceID id, CbOnOrderExecution handler);

	///订单成功撤销事件
	///<brief	成交里面包括了订单市场ID，建议用这个ID查询对应的订单
	///@param  pCxled		               订单被接受以后的消息体，里面包含了市场订单ID
	///@return void 
	typedef void (APPWINAPI *CbOnOrderCxled)(EES_OrderCxled* pCxled);
	void SetCallbackOnOrderCxled(InstanceID id, CbOnOrderCxled handler);

	///撤单被拒绝的消息事件
	///<brief	一般会在发送撤单以后，收到这个消息，表示撤单被拒绝
	///@param  pReject	                   撤单被拒绝消息体
	///@return void 
	typedef void (APPWINAPI *CbOnCxlOrderReject)(EES_CxlOrderRej* pReject);
	void SetCallbackOnCxlOrderReject(InstanceID id, CbOnCxlOrderReject handler);

	///查询订单的返回事件
	///<brief	查询订单信息时候的回调，这里面也可能包含不是当前用户下的订单
	///@param  pAccount                 帐户ID 
	///@param  pQueryOrder	             查询订单的结构
	///@param  bFinish	                 如果没有传输完成，这个值是 false，如果完成了，那个这个值为 true    
	///remark 如果碰到 bFinish == true，那么是传输结束，并且 pQueryOrder值无效。
	///@return void 
	typedef void (APPWINAPI *CbOnQueryTradeOrder)(const char* pAccount, EES_QueryAccountOrder* pQueryOrder, bool bFinish);
	void SetCallbackOnQueryTradeOrder(InstanceID id, CbOnQueryTradeOrder handler);

	///查询订单的返回事件
	///<brief	查询订单信息时候的回调，这里面也可能包含不是当前用户下的订单成交
	///@param  pAccount                        帐户ID 
	///@param  pQueryOrderExec	                查询订单成交的结构
	///@param  bFinish	                        如果没有传输完成，这个值是false，如果完成了，那个这个值为 true    
	///remark 如果碰到 bFinish == true，那么是传输结束，并且pQueryOrderExec值无效。
	///@return void 
	typedef void (APPWINAPI *CbOnQueryTradeOrderExec)(const char* pAccount, EES_QueryOrderExecution* pQueryOrderExec, bool bFinish);
	void SetCallbackOnQueryTradeOrderExec(InstanceID id, CbOnQueryTradeOrderExec handler);

	///接收外部订单的消息
	///<brief	一般会在系统订单出错，进行人工调整的时候用到。
	///@param  pPostOrder	                    查询订单成交的结构
	///@return void 
	typedef void (APPWINAPI *CbOnPostOrder)(EES_PostOrder* pPostOrder);
	void SetCallbackOnPostOrder(InstanceID id, CbOnPostOrder handler);

	///接收外部订单成交的消息
	///<brief	一般会在系统订单出错，进行人工调整的时候用到。
	///@param  pPostOrderExecution	             查询订单成交的结构
	///@return void 
	typedef void (APPWINAPI *CbOnPostOrderExecution)(EES_PostOrderExecution* pPostOrderExecution);
	void SetCallbackOnPostOrderExecution(InstanceID id, CbOnPostOrderExecution handler);

	///查询交易所可用连接的响应
	///<brief	每个当前系统支持的汇报一次，当bFinish= true时，表示所有交易所的响应都已到达，但本条消息本身不包含有用的信息。
	///@param  pPostOrderExecution	             查询订单成交的结构
	///@return void 
	typedef void (APPWINAPI *CbOnQueryMarketSession)(EES_ExchangeMarketSession* pMarketSession, bool bFinish);
	void SetCallbackOnQueryMarketSession(InstanceID id, CbOnQueryMarketSession handler);

	///交易所连接状态变化报告，
	///<brief	当交易所连接发生连接/断开时报告此状态
	///@param  MarketSessionId: 交易所连接代码
	///@param  ConnectionGood: true表示交易所连接正常，false表示交易所连接断开了。
	///@return void 
	typedef void (APPWINAPI *CbOnMarketSessionStatReport)(EES_MarketSessionId MarketSessionId, bool ConnectionGood);
	void SetCallbackOnMarketSessionStatReport(InstanceID id, CbOnMarketSessionStatReport handler);

	///合约状态变化报告
	///<brief	当合约状态发生变化时报告
	///@param  pSymbolStatus: 参见EES_SymbolStatus合约状态结构体定义
	///@return void 
	typedef void (APPWINAPI *CbOnSymbolStatusReport)(EES_SymbolStatus* pSymbolStatus);
	void SetCallbackOnSymbolStatusReport(InstanceID id, CbOnSymbolStatusReport handler);

	///合约状态查询响应
	///<brief  响应合约状态查询请求
	///@param  pSymbolStatus: 参见EES_SymbolStatus合约状态结构体定义
	///@param	bFinish: 当为true时，表示查询所有结果返回。此时pSymbolStatus为空指针NULL
	///@return void 
	typedef void (APPWINAPI *CbOnQuerySymbolStatus)(EES_SymbolStatus* pSymbolStatus, bool bFinish);
	void SetCallbackOnQuerySymbolStatus(InstanceID id, CbOnQuerySymbolStatus handler);

	///深度行情查询响应
	///@param	pMarketMBLData: 参见EES_MarketMBLData深度行情结构体定义
	///@param	bFinish: 当为true时，表示查询所有结果返回。此时pMarketMBLData内容中,仅m_RequestId有效
	///@return void 
	typedef void (APPWINAPI *CbOnQueryMarketMBLData)(EES_MarketMBLData* pMarketMBLData, bool bFinish);
	void SetCallbackOnQueryMarketMBLData(InstanceID id, CbOnQueryMarketMBLData handler);

	typedef struct callbackVirtualTable
	{
		///连接消息的回调
		CbOnConnection onConnection;

		///连接断开消息的回调
		CbOnDisConnection onDisConnection;

		///登录消息的回调
		CbOnUserLogon onUserLogon;

		///修改密码响应回调
		CbOnRspChangePassword onRspChangePassword;

		///查询用户下面帐户的返回事件
		CbOnQueryUserAccount onQueryUserAccount;

		///查询帐户下面期货仓位信息的返回事件
		CbOnQueryAccountPosition onQueryAccountPosition;

		///查询帐户下面期权仓位信息的返回事件
		CbOnQueryAccountOptionPosition onQueryAccountOptionPosition;

		///查询帐户下面资金信息的返回事件
		CbOnQueryAccountBP onQueryAccountBP;

		///查询合约列表的返回事件
		CbOnQuerySymbol onQuerySymbol;

		///查询帐户交易保证金的返回事件
		CbOnQueryAccountTradeMargin onQueryAccountTradeMargin;

		///查询帐户交易费用的返回事件
		CbOnQueryAccountTradeFee onQueryAccountTradeFee;

		///下单被柜台系统接受的事件
		CbOnOrderAccept onOrderAccept;

		///下单被市场接受的事件
		CbOnOrderMarketAccept onOrderMarketAccept;

		///下单被柜台系统拒绝的事件
		CbOnOrderReject onOrderReject;

		///下单被市场拒绝的事件
		CbOnOrderMarketReject onOrderMarketReject;

		///订单成交的消息事件
		CbOnOrderExecution onOrderExecution;

		///订单成功撤销事件
		CbOnOrderCxled onOrderCxled;

		///撤单被拒绝的消息事件
		CbOnCxlOrderReject onCxlOrderReject;

		///查询订单的返回事件
		CbOnQueryTradeOrder onQueryTradeOrder;

		///查询订单的返回事件
		CbOnQueryTradeOrderExec onQueryTradeOrderExec;

		///接收外部订单的消息
		CbOnPostOrder onPostOrder;

		///接收外部订单成交的消息
		CbOnPostOrderExecution onPostOrderExecution;

		///查询交易所可用连接的响应
		CbOnQueryMarketSession onQueryMarketSession;

		///交易所连接状态变化报告
		CbOnMarketSessionStatReport onMarketSessionStatReport;

		///合约状态变化报告
		CbOnSymbolStatusReport onSymbolStatusReport;

		///合约状态查询响应
		CbOnQuerySymbolStatus onQuerySymbolStatus;

		///深度行情查询响应
		CbOnQueryMarketMBLData onQueryMarketMBLData;
	} callbackVirtualTable;
	
	void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt);

#ifdef __cplusplus
}
#endif // __cplusplus
