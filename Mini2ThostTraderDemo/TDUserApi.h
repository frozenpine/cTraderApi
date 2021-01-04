#pragma once

#include "stdlib.h"

#include "ThostFtdcTraderApi.h"

class TDUserApi : CThostFtdcTraderSpi
{
public:
	TDUserApi() { pApi = NULL; };
private:
	CThostFtdcTraderApi* pApi;
};

