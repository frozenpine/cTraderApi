#include "EesTraderApiWrapper.h"

C_API void SetCallbackOnConnection(InstanceID id, CbOnConnection handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnConnection(handler);
}

C_API void SetCallbackOnDisConnection(InstanceID id, CbOnDisConnection handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnDisConnection(handler);
}

C_API void SetCallbackOnUserLogon(InstanceID id, CbOnUserLogon handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnUserLogon(handler);
}

C_API void SetCallbackOnRspChangePassword(InstanceID id, CbOnRspChangePassword handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnChangePassword(handler);
}

C_API void SetCallbackOnQueryUserAccount(InstanceID id, CbOnQueryUserAccount handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryUserAccount(handler);
}

C_API void SetCallbackOnQueryAccountPosition(InstanceID id, CbOnQueryAccountPosition handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountPosition(handler);
}

C_API void SetCallbackOnQueryAccountOptionPosition(InstanceID id, CbOnQueryAccountOptionPosition handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountOptionPosition(handler);
}

C_API void SetCallbackOnQueryAccountBP(InstanceID id, CbOnQueryAccountBP handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountBP(handler);
}

C_API void SetCallbackOnQuerySymbol(InstanceID id, CbOnQuerySymbol handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQuerySymbol(handler);
}

C_API void SetCallbackOnQueryAccountTradeMargin(InstanceID id, CbOnQueryAccountTradeMargin handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountTradeMargin(handler);
}

C_API void SetCallbackOnQueryAccountTradeFee(InstanceID id, CbOnQueryAccountTradeFee handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryAccountTradeFee(handler);
}

C_API void SetCallbackOnOrderAccept(InstanceID id, CbOnOrderAccept handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderAccept(handler);
}

C_API void SetCallbackOnOrderMarketAccept(InstanceID id, CbOnOrderMarketAccept handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderMarketAccept(handler);
}

C_API void SetCallbackOnOrderReject(InstanceID id, CbOnOrderReject handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderReject(handler);
}

C_API void SetCallbackOnOrderMarketReject(InstanceID id, CbOnOrderMarketReject handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderMarketReject(handler);
}

C_API void SetCallbackOnOrderExecution(InstanceID id, CbOnOrderExecution handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderExecution(handler);
}

C_API void SetCallbackOnOrderCxled(InstanceID id, CbOnOrderCxled handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnOrderCxled(handler);
}

C_API void SetCallbackOnCxlOrderReject(InstanceID id, CbOnCxlOrderReject handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnCxlOrderReject(handler);
}

C_API void SetCallbackOnQueryTradeOrder(InstanceID id, CbOnQueryTradeOrder handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryTradeOrder(handler);
}

C_API void SetCallbackOnQueryTradeOrderExec(InstanceID id, CbOnQueryTradeOrderExec handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryTradeOrderExec(handler);
}

C_API void SetCallbackOnPostOrder(InstanceID id, CbOnPostOrder handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnPostOrder(handler);
}

C_API void SetCallbackOnPostOrderExecution(InstanceID id, CbOnPostOrderExecution handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnPostOrderExecution(handler);
}

C_API void SetCallbackOnQueryMarketSession(InstanceID id, CbOnQueryMarketSession handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryMarketSession(handler);
}

C_API void SetCallbackOnMarketSessionStatReport(InstanceID id, CbOnMarketSessionStatReport handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnMarketSessionStatReport(handler);
}

C_API void SetCallbackOnSymbolStatusReport(InstanceID id, CbOnSymbolStatusReport handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnSymbolStatusReport(handler);
}

C_API void SetCallbackOnQuerySymbolStatus(InstanceID id, CbOnQuerySymbolStatus handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQuerySymbolStatus(handler);
}

C_API void SetCallbackOnQueryMarketMBLData(InstanceID id, CbOnQueryMarketMBLData handler)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackOnQueryMarketMBLData(handler);
}

C_API void SetCallbackVirtualTable(InstanceID id, callbackVirtualTable *vt)
{
	if (id == NULL) {
		return;
	}

	((cTraderApi*)id)->SetCallbackVirtualTable(vt);
}
