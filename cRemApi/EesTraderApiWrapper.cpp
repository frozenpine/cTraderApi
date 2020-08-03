#include "EesTraderApiWrapper.h"

void cTraderApi::OnConnection(ERR_NO errNo, const char * pErrStr)
{
	if (vtCallback.onConnection == NULL) {
		return;
	}

	vtCallback.onConnection((InstanceID)this, errNo, pErrStr);
}

void cTraderApi::OnDisConnection(ERR_NO errNo, const char * pErrStr)
{
	if (vtCallback.onDisConnection == NULL) {
		return;
	}

	vtCallback.onDisConnection((InstanceID)this, errNo, pErrStr);
}

void cTraderApi::OnUserLogon(EES_LogonResponse * pLogon)
{
	if (vtCallback.onUserLogon == NULL) {
		return;
	}

	vtCallback.onUserLogon((InstanceID)this, pLogon);
}

void cTraderApi::OnRspChangePassword(EES_ChangePasswordResult nResult)
{
	if (vtCallback.onRspChangePassword == NULL) {
		return;
	}

	vtCallback.onRspChangePassword((InstanceID)this, nResult);
}

void cTraderApi::OnQueryUserAccount(EES_AccountInfo * pAccoutnInfo, bool bFinish)
{
	if (vtCallback.onQueryUserAccount == NULL) {
		return;
	}

	vtCallback.onQueryUserAccount((InstanceID)this, pAccoutnInfo, bFinish);
}

void cTraderApi::OnQueryAccountPosition(const char * pAccount, EES_AccountPosition * pAccoutnPosition, int nReqId, bool bFinish)
{
	if (vtCallback.onQueryAccountPosition == NULL) {
		return;
	}

	vtCallback.onQueryAccountPosition((InstanceID)this, pAccount, pAccoutnPosition, nReqId, bFinish);
}

void cTraderApi::OnQueryAccountOptionPosition(const char * pAccount, EES_AccountOptionPosition * pAccountOptionPosition, int nReqId, bool bFinish)
{
	if (vtCallback.onQueryAccountOptionPosition == NULL) {
		return;
	}

	vtCallback.onQueryAccountOptionPosition((InstanceID)this, pAccount, pAccountOptionPosition, nReqId, bFinish);
}

void cTraderApi::OnQueryAccountBP(const char * pAccount, EES_AccountBP * pAccoutnPosition, int nReqId)
{
	if (vtCallback.onQueryAccountBP == NULL) {
		return;
	}

	vtCallback.onQueryAccountBP((InstanceID)this, pAccount, pAccoutnPosition, nReqId);
}

void cTraderApi::OnQuerySymbol(EES_SymbolField * pSymbol, bool bFinish)
{
	if (vtCallback.onQuerySymbol == NULL) {
		return;
	}

	vtCallback.onQuerySymbol((InstanceID)this, pSymbol, bFinish);
}

void cTraderApi::OnQueryAccountTradeMargin(const char * pAccount, EES_AccountMargin * pSymbolMargin, bool bFinish)
{
	if (vtCallback.onQueryAccountTradeMargin == NULL) {
		return;
	}

	vtCallback.onQueryAccountTradeMargin((InstanceID)this, pAccount, pSymbolMargin, bFinish);
}

void cTraderApi::OnQueryAccountTradeFee(const char * pAccount, EES_AccountFee * pSymbolFee, bool bFinish)
{
	if (vtCallback.onQueryAccountTradeFee == NULL) {
		return;
	}

	vtCallback.onQueryAccountTradeFee((InstanceID)this, pAccount, pSymbolFee, bFinish);
}

void cTraderApi::OnOrderAccept(EES_OrderAcceptField * pAccept)
{
	if (vtCallback.onOrderAccept == NULL) {
		return;
	}

	vtCallback.onOrderAccept((InstanceID)this, pAccept);
}

void cTraderApi::OnOrderMarketAccept(EES_OrderMarketAcceptField * pAccept)
{
	if (vtCallback.onOrderMarketAccept == NULL) {
		return;
	}

	vtCallback.onOrderMarketAccept((InstanceID)this, pAccept);
}

void cTraderApi::OnOrderReject(EES_OrderRejectField * pReject)
{
	if (vtCallback.onOrderReject == NULL) {
		return;
	}

	vtCallback.onOrderReject((InstanceID)this, pReject);
}

void cTraderApi::OnOrderMarketReject(EES_OrderMarketRejectField * pReject)
{
	if (vtCallback.onOrderMarketReject == NULL) {
		return;
	}

	vtCallback.onOrderMarketReject((InstanceID)this, pReject);
}

void cTraderApi::OnOrderExecution(EES_OrderExecutionField * pExec)
{
	if (vtCallback.onOrderExecution == NULL) {
		return;
	}

	vtCallback.onOrderExecution((InstanceID)this, pExec);
}

void cTraderApi::OnOrderCxled(EES_OrderCxled * pCxled)
{
	if (vtCallback.onOrderCxled == NULL) {
		return;
	}

	vtCallback.onOrderCxled((InstanceID)this, pCxled);
}

void cTraderApi::OnCxlOrderReject(EES_CxlOrderRej * pReject)
{
	if (vtCallback.onCxlOrderReject == NULL) {
		return;
	}

	vtCallback.onCxlOrderReject((InstanceID)this, pReject);
}

void cTraderApi::OnQueryTradeOrder(const char * pAccount, EES_QueryAccountOrder * pQueryOrder, bool bFinish)
{
	if (vtCallback.onQueryTradeOrder == NULL) {
		return;
	}

	vtCallback.onQueryTradeOrder((InstanceID)this, pAccount, pQueryOrder, bFinish);
}

void cTraderApi::OnQueryTradeOrderExec(const char * pAccount, EES_QueryOrderExecution * pQueryOrderExec, bool bFinish)
{
	if (vtCallback.onQueryTradeOrderExec == NULL) {
		return;
	}

	vtCallback.onQueryTradeOrderExec((InstanceID)this, pAccount, pQueryOrderExec, bFinish);
}

void cTraderApi::OnPostOrder(EES_PostOrder * pPostOrder)
{
	if (vtCallback.onPostOrder == NULL) {
		return;
	}

	vtCallback.onPostOrder((InstanceID)this, pPostOrder);
}

void cTraderApi::OnPostOrderExecution(EES_PostOrderExecution * pPostOrderExecution)
{
	if (vtCallback.onPostOrderExecution == NULL) {
		return;
	}

	vtCallback.onPostOrderExecution((InstanceID)this, pPostOrderExecution);
}

void cTraderApi::OnQueryMarketSession(EES_ExchangeMarketSession * pMarketSession, bool bFinish)
{
	if (vtCallback.onQueryMarketSession == NULL) {
		return;
	}

	vtCallback.onQueryMarketSession((InstanceID)this, pMarketSession, bFinish);
}

void cTraderApi::OnMarketSessionStatReport(EES_MarketSessionId MarketSessionId, bool ConnectionGood)
{
	if (vtCallback.onMarketSessionStatReport == NULL) {
		return;
	}

	vtCallback.onMarketSessionStatReport((InstanceID)this, MarketSessionId, ConnectionGood);
}

void cTraderApi::OnSymbolStatusReport(EES_SymbolStatus * pSymbolStatus)
{
	if (vtCallback.onSymbolStatusReport == NULL) {
		return;
	}

	vtCallback.onSymbolStatusReport((InstanceID)this, pSymbolStatus);
}

void cTraderApi::OnQuerySymbolStatus(EES_SymbolStatus * pSymbolStatus, bool bFinish)
{
	if (vtCallback.onQuerySymbolStatus == NULL) {
		return;
	}

	vtCallback.onQuerySymbolStatus((InstanceID)this, pSymbolStatus, bFinish);
}

void cTraderApi::OnQueryMarketMBLData(EES_MarketMBLData * pMarketMBLData, bool bFinish)
{
	if (vtCallback.onQueryMarketMBLData == NULL) {
		return;
	}

	vtCallback.onQueryMarketMBLData((InstanceID)this, pMarketMBLData, bFinish);
}

void cTraderApi::CreateApi()
{
	if (pApi != NULL) {
		return;
	}

	pApi = CreateEESTraderApi();
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
