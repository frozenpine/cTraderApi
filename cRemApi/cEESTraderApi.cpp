#include "EesTraderApiWrapper.h"

void SetCallbackOnConnection(InstanceID id, CbOnConnection handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnConnection(handler);
}

void SetCallbackOnDisConnection(InstanceID id, CbOnDisConnection handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnDisConnection(handler);
}

void SetCallbackOnUserLogon(InstanceID id, CbOnUserLogon handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnUserLogon(handler);
}

void SetCallbackOnRspChangePassword(InstanceID id, CbOnRspChangePassword handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnChangePassword(handler);
}

void SetCallbackOnQueryUserAccount(InstanceID id, CbOnQueryUserAccount handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryUserAccount(handler);
}

void SetCallbackOnQueryAccountPosition(InstanceID id, CbOnQueryAccountPosition handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountPosition(handler);
}

void SetCallbackOnQueryAccountOptionPosition(InstanceID id, CbOnQueryAccountOptionPosition handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountOptionPosition(handler);
}

void SetCallbackOnQueryAccountBP(InstanceID id, CbOnQueryAccountBP handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountBP(handler);
}

void SetCallbackOnQuerySymbol(InstanceID id, CbOnQuerySymbol handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQuerySymbol(handler);
}

void SetCallbackOnQueryAccountTradeMargin(InstanceID id, CbOnQueryAccountTradeMargin handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountTradeMargin(handler);
}

void SetCallbackOnQueryAccountTradeFee(InstanceID id, CbOnQueryAccountTradeFee handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountTradeFee(handler);
}

void SetCallbackOnOrderAccept(InstanceID id, CbOnOrderAccept handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderAccept(handler);
}

void SetCallbackOnOrderMarketAccept(InstanceID id, CbOnOrderMarketAccept handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderMarketAccept(handler);
}

void SetCallbackOnOrderReject(InstanceID id, CbOnOrderReject handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderReject(handler);
}

void SetCallbackOnOrderMarketReject(InstanceID id, CbOnOrderMarketReject handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderMarketReject(handler);
}

void SetCallbackOnOrderExecution(InstanceID id, CbOnOrderExecution handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderExecution(handler);
}

void SetCallbackOnOrderCxled(InstanceID id, CbOnOrderCxled handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderCxled(handler);
}

void SetCallbackOnCxlOrderReject(InstanceID id, CbOnCxlOrderReject handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnCxlOrderReject(handler);
}

void SetCallbackOnQueryTradeOrder(InstanceID id, CbOnQueryTradeOrder handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryTradeOrder(handler);
}

void SetCallbackOnQueryTradeOrderExec(InstanceID id, CbOnQueryTradeOrderExec handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryTradeOrderExec(handler);
}

void SetCallbackOnPostOrder(InstanceID id, CbOnPostOrder handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnPostOrder(handler);
}

void SetCallbackOnPostOrderExecution(InstanceID id, CbOnPostOrderExecution handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnPostOrderExecution(handler);
}

void SetCallbackOnQueryMarketSession(InstanceID id, CbOnQueryMarketSession handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryMarketSession(handler);
}

void SetCallbackOnMarketSessionStatReport(InstanceID id, CbOnMarketSessionStatReport handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnMarketSessionStatReport(handler);
}

void SetCallbackOnSymbolStatusReport(InstanceID id, CbOnSymbolStatusReport handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnSymbolStatusReport(handler);
}

void SetCallbackOnQuerySymbolStatus(InstanceID id, CbOnQuerySymbolStatus handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQuerySymbolStatus(handler);
}

void SetCallbackOnQueryMarketMBLData(InstanceID id, CbOnQueryMarketMBLData handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryMarketMBLData(handler);
}
