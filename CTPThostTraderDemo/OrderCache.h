#pragma once

#include <stdlib.h>
#include <map>
#include <vector>
#include <string>

#include "ThostFtdcUserApiStruct.h"

class TDUserApi;

class OrderCache
{
public:
	OrderCache() { api = NULL; };
	OrderCache(TDUserApi* api) {
		this->api = api;
	}
private:
	TDUserApi* api;

	std::map<std::string, CThostFtdcOrderField*> orderDictByRef;
	std::map<std::string, CThostFtdcOrderField*> orderDictBySysID;
	std::vector<CThostFtdcOrderField*> orderList;
public:
	void InsertOrAssignOrder(CThostFtdcOrderField* pOrder);

	std::vector<CThostFtdcOrderField*> GetOrders(std::string orderRef = "", std::string orderSysID = "");
};
