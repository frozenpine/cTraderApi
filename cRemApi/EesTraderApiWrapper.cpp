#include "EesTraderApiWrapper.h"

void cTraderApi::OnConnection(ERR_NO errNo, const char * pErrStr)
{
}

void cTraderApi::OnDisConnection(ERR_NO errNo, const char * pErrStr)
{
}

void cTraderApi::OnUserLogon(EES_LogonResponse * pLogon)
{
}

void cTraderApi::OnRspChangePassword(EES_ChangePasswordResult nResult)
{
}

void cTraderApi::OnQueryUserAccount(EES_AccountInfo * pAccoutnInfo, bool bFinish)
{
}

void cTraderApi::OnQueryAccountPosition(const char * pAccount, EES_AccountPosition * pAccoutnPosition, int nReqId, bool bFinish)
{
}

void cTraderApi::OnQueryAccountOptionPosition(const char * pAccount, EES_AccountOptionPosition * pAccoutnOptionPosition, int nReqId, bool bFinish)
{
}

void cTraderApi::OnQueryAccountBP(const char * pAccount, EES_AccountBP * pAccoutnPosition, int nReqId)
{
}

void cTraderApi::OnQuerySymbol(EES_SymbolField * pSymbol, bool bFinish)
{
}

void cTraderApi::OnQueryAccountTradeMargin(const char * pAccount, EES_AccountMargin * pSymbolMargin, bool bFinish)
{
}

void cTraderApi::OnQueryAccountTradeFee(const char * pAccount, EES_AccountFee * pSymbolFee, bool bFinish)
{
}

void cTraderApi::OnOrderAccept(EES_OrderAcceptField * pAccept)
{
}

void cTraderApi::OnOrderMarketAccept(EES_OrderMarketAcceptField * pAccept)
{
}

void cTraderApi::OnOrderReject(EES_OrderRejectField * pReject)
{
}

void cTraderApi::OnOrderMarketReject(EES_OrderMarketRejectField * pReject)
{
}

void cTraderApi::OnOrderExecution(EES_OrderExecutionField * pExec)
{
}

void cTraderApi::OnOrderCxled(EES_OrderCxled * pCxled)
{
}

void cTraderApi::OnCxlOrderReject(EES_CxlOrderRej * pReject)
{
}

void cTraderApi::OnQueryTradeOrder(const char * pAccount, EES_QueryAccountOrder * pQueryOrder, bool bFinish)
{
}

void cTraderApi::OnQueryTradeOrderExec(const char * pAccount, EES_QueryOrderExecution * pQueryOrderExec, bool bFinish)
{
}

void cTraderApi::OnPostOrder(EES_PostOrder * pPostOrder)
{
}

void cTraderApi::OnPostOrderExecution(EES_PostOrderExecution * pPostOrderExecution)
{
}

void cTraderApi::OnQueryMarketSession(EES_ExchangeMarketSession * pMarketSession, bool bFinish)
{
}

void cTraderApi::OnMarketSessionStatReport(EES_MarketSessionId MarketSessionId, bool ConnectionGood)
{
}

void cTraderApi::OnSymbolStatusReport(EES_SymbolStatus * pSymbolStatus)
{
}

void cTraderApi::OnQuerySymbolStatus(EES_SymbolStatus * pSymbolStatus, bool bFinish)
{
}

void cTraderApi::OnQueryMarketMBLData(EES_MarketMBLData * pMarketMBLData, bool bFinish)
{
}

int cTraderApi::ConnServer(const char * svrAddr, int nPort, EESTraderEvent * pEvent, const char * qrySvrAddr, int nQrySvrPort)
{
	return 0;
}

int cTraderApi::ConnServer(const EES_TradeSvrInfo & param, EESTraderEvent * pEvent)
{
	return 0;
}

int cTraderApi::DisConnServer()
{
	return 0;
}

int cTraderApi::UserLogon(const char * user_id, const char * user_pwd, const char * prodInfo, const char * macAddr)
{
	return 0;
}

int cTraderApi::ChangePassword(const char * oldPwd, const char * newPwd)
{
	return 0;
}

int cTraderApi::QuerySymbolList()
{
	return 0;
}

int cTraderApi::QueryUserAccount()
{
	return 0;
}

int cTraderApi::QueryAccountPosition(const char * accountId, int nReqId)
{
	return 0;
}

int cTraderApi::QueryAccountBP(const char * accountId, int nReqId)
{
	return 0;
}

int cTraderApi::QueryAccountTradeMargin(const char * accountId)
{
	return 0;
}

int cTraderApi::QueryAccountTradeFee(const char * accountId)
{
	return 0;
}

int cTraderApi::GetMaxToken(OUT EES_ClientToken * orderToken)
{
	return 0;
}

int cTraderApi::EnterOrder(EES_EnterOrderField * pOrder)
{
	return 0;
}

int cTraderApi::CancelOrder(EES_CancelOrder * pCxlOrder)
{
	return 0;
}

int cTraderApi::QueryAccountOrder(const char * accountId)
{
	return 0;
}

int cTraderApi::QueryAccountOrderExecution(const char * accountId)
{
	return 0;
}

int cTraderApi::QueryMarketSession()
{
	return 0;
}

int cTraderApi::QuerySymbolStatus()
{
	return 0;
}

int cTraderApi::EnterMultiOrders(EES_EnterOrderField * pArrOrders, int nCount)
{
	return 0;
}

int cTraderApi::QueryMarketMBLData(int nRequestId, EES_ExchangeID exchangeID, int nSide)
{
	return 0;
}

int cTraderApi::QueryMarketMBLData(int nRequestId, const char * startSymbol, const char * endSymbol, int nSide)
{
	return 0;
}

int cTraderApi::ChangeFCParam(unsigned int OrderCount, unsigned int CancelCount)
{
	return 0;
}
