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
	return pApi->ConnServer(svrAddr, nPort, pEvent, qrySvrAddr, nQrySvrPort);
}

int cTraderApi::ConnServer(const EES_TradeSvrInfo & param, EESTraderEvent * pEvent)
{
	return pApi->ConnServer(param, pEvent);
}

int cTraderApi::DisConnServer()
{
	return pApi->DisConnServer();
}

int cTraderApi::UserLogon(const char * user_id, const char * user_pwd, const char * prodInfo, const char * macAddr)
{
	return pApi->UserLogon(user_id, user_pwd, prodInfo, macAddr);
}

int cTraderApi::ChangePassword(const char * oldPwd, const char * newPwd)
{
	return pApi->ChangePassword(oldPwd, newPwd);
}

int cTraderApi::QuerySymbolList()
{
	return pApi->QuerySymbolList();
}

int cTraderApi::QueryUserAccount()
{
	return pApi->QueryUserAccount();
}

int cTraderApi::QueryAccountPosition(const char * accountId, int nReqId)
{
	return pApi->QueryAccountPosition(accountId, nReqId);
}

int cTraderApi::QueryAccountBP(const char * accountId, int nReqId)
{
	return pApi->QueryAccountBP(accountId, nReqId);
}

int cTraderApi::QueryAccountTradeMargin(const char * accountId)
{
	return pApi->QueryAccountTradeMargin(accountId);
}

int cTraderApi::QueryAccountTradeFee(const char * accountId)
{
	return pApi->QueryAccountTradeFee(accountId);
}

int cTraderApi::GetMaxToken(OUT EES_ClientToken * orderToken)
{
	return pApi->GetMaxToken(orderToken);
}

int cTraderApi::EnterOrder(EES_EnterOrderField * pOrder)
{
	return pApi->EnterOrder(pOrder);
}

int cTraderApi::CancelOrder(EES_CancelOrder * pCxlOrder)
{
	return pApi->CancelOrder(pCxlOrder);
}

int cTraderApi::QueryAccountOrder(const char * accountId)
{
	return pApi->QueryAccountOrder(accountId);
}

int cTraderApi::QueryAccountOrderExecution(const char * accountId)
{
	return pApi->QueryAccountOrderExecution(accountId);
}

int cTraderApi::QueryMarketSession()
{
	return pApi->QueryMarketSession();
}

int cTraderApi::QuerySymbolStatus()
{
	return pApi->QuerySymbolStatus();
}

int cTraderApi::EnterMultiOrders(EES_EnterOrderField * pArrOrders, int nCount)
{
	return pApi->EnterMultiOrders(pArrOrders, nCount);
}

int cTraderApi::QueryMarketMBLData(int nRequestId, EES_ExchangeID exchangeID, int nSide)
{
	return pApi->QueryMarketMBLData(nRequestId, exchangeID, nSide);
}

int cTraderApi::QueryMarketMBLData(int nRequestId, const char * startSymbol, const char * endSymbol, int nSide)
{
	return pApi->QueryMarketMBLData(nRequestId, startSymbol, endSymbol, nSide);
}

int cTraderApi::ChangeFCParam(unsigned int OrderCount, unsigned int CancelCount)
{
	return pApi->ChangeFCParam(OrderCount, CancelCount);
}
