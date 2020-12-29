#pragma once

#include <map>
#include <vector>
#include <string>

#include "ThostFtdcUserApiStruct.h"

class TDUserApi;

class PositionCache
{
public:
	PositionCache() {};
private:
	std::map<std::string, CThostFtdcInvestorPositionField*> netPosDict;
	std::map<std::string, CThostFtdcInvestorPositionField*> longPosDict;
	std::map<std::string, CThostFtdcInvestorPositionField*> shortPosDict;
public:
	bool InsertOrAssign(CThostFtdcInvestorPositionField* pInvestorPosition);

	std::vector<CThostFtdcInvestorPositionField*> GetPositions(std::string ExchangeID = "", std::string ProductID = "", std::string InstrumentID = "");
};
