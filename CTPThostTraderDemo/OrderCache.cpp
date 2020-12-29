#include <assert.h>

#include "tools.h"
#include "OrderCache.h"
#include "TDUserApi.h"

#define JOIN_REF(session, front, ref) (session) + "." + (front) + "." + (ref)

std::vector<CThostFtdcOrderField*> OrderCache::GetOrders(std::string orderRef, std::string orderSysID)
{
	std::vector<CThostFtdcOrderField*> result;

	if (orderSysID != "") {
		int count = 0;
		char** idList = split(orderSysID.c_str(), count);

		for (int i = 0; i < count; i++) {
			if (orderDictBySysID.find(idList[i]) == orderDictBySysID.end()) {
				continue;
			}

			result.push_back(orderDictBySysID.at(idList[i]));
		}

		return result;
	}

	if (orderRef != "") {
		int count = 0;
		char** refList = split(orderRef.c_str(), count);

		for (int i = 0; i < count; i++) {
			std::string sessionID = std::to_string(api->User.SessionID);
			std::string frontID = std::to_string(api->User.FrontID);
			std::string ref = JOIN_REF(sessionID, frontID, refList[i]);

			if (orderDictByRef.find(ref) == orderDictByRef.end()) {
				continue;
			}

			result.push_back(orderDictByRef.at(ref));
		}

		return result;
	}

	result = orderList;

	return result;
}

void OrderCache::InsertOrAssignOrder(CThostFtdcOrderField* pOrder)
{
	if (NULL == pOrder) {
		return;
	}

	std::string sysID = ltrim(pOrder->OrderSysID);
	std::string orderRef = ltrim(pOrder->OrderRef);
	std::string sessionID = std::to_string(pOrder->SessionID);
	std::string frontID = std::to_string(pOrder->FrontID);

	CThostFtdcOrderField* ord = NULL;

	if (sysID != "") {
		if (orderDictBySysID.find(sysID) == orderDictBySysID.end()) {
			ord = new(CThostFtdcOrderField);

			orderDictBySysID.insert_or_assign(sysID, ord);

			if (orderRef != "") {
				orderDictByRef.insert_or_assign(JOIN_REF(sessionID, frontID, orderRef), ord);
			}

			orderList.push_back(ord);
		}
		else {
			ord = orderDictBySysID.at(sysID);
		}
	}
	else if (orderRef != "") {
		std::string ref = JOIN_REF(sessionID, frontID, orderRef);
		if (orderDictByRef.find(ref) == orderDictByRef.end()) {
			ord = new(CThostFtdcOrderField);

			orderDictByRef.insert_or_assign(ref, ord);

			if (ord->OrderStatus != THOST_FTDC_OST_Unknown) {
				orderList.push_back(ord);
			}
		}
		else {
			ord = orderDictByRef.at(ref);
		}
	}
	else {
		return;
	}

	assert(NULL != ord);
	memcpy(ord, pOrder, sizeof(CThostFtdcOrderField));
}
