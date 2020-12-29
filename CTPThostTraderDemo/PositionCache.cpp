#include <assert.h>

#include "tools.h"
#include "PositionCache.h"

bool PositionCache::InsertOrAssign(CThostFtdcInvestorPositionField* pInvestorPosition)
{
	if (NULL == pInvestorPosition || pInvestorPosition->Position <= 0) {
		return false;
	}

	CThostFtdcInvestorPositionField* pos = NULL;

	switch (pInvestorPosition->PosiDirection)
	{
	case THOST_FTDC_PD_Net:
		if (netPosDict.find(pInvestorPosition->InstrumentID) == netPosDict.end()) {
			pos = new(CThostFtdcInvestorPositionField);

			netPosDict.insert_or_assign(pInvestorPosition->InstrumentID, pos);
		}
		else {
			pos = netPosDict.at(pInvestorPosition->InstrumentID);
		}
		break;
	case THOST_FTDC_PD_Long:
		if (longPosDict.find(pInvestorPosition->InstrumentID) == longPosDict.end()) {
			pos = new(CThostFtdcInvestorPositionField);

			longPosDict.insert_or_assign(pInvestorPosition->InstrumentID, pos);
		}
		else {
			pos = longPosDict.at(pInvestorPosition->InstrumentID);
		}
		break;
	case THOST_FTDC_PD_Short:
		if (shortPosDict.find(pInvestorPosition->InstrumentID) == shortPosDict.end()) {
			pos = new(CThostFtdcInvestorPositionField);

			shortPosDict.insert_or_assign(pInvestorPosition->InstrumentID, pos);
		}
		else {
			pos = shortPosDict.at(pInvestorPosition->InstrumentID);
		}
		break;
	default:
		fprintf(stderr, "Invalid position direction: %c\n", pInvestorPosition->PosiDirection);
		return false;
	}

	assert(pos != NULL);
	memcpy(pos, pInvestorPosition, sizeof(CThostFtdcInvestorPositionField));

	return true;
}

std::vector<CThostFtdcInvestorPositionField*> PositionCache::GetPositions(std::string ExchangeID, std::string ProductID, std::string InstrumentID)
{
	std::vector<CThostFtdcInvestorPositionField*> result;

	// TODO: ExchangeID & ProductID filter

	if (InstrumentID != "") {
		int count = 0;
		char** insList = split(InstrumentID.c_str(), count);

		for (int i = 0; i < count; i++) {
			if (netPosDict.find(insList[i]) != netPosDict.end()) {
				result.push_back(netPosDict.at(insList[i]));
			}

			if (longPosDict.find(insList[i]) != longPosDict.end()) {
				result.push_back(longPosDict.at(insList[i]));
			}

			if (shortPosDict.find(insList[i]) != shortPosDict.end()) {
				result.push_back(shortPosDict.at(insList[i]));
			}
		}

		return result;
	}

	for (auto& pos : netPosDict) {
		result.push_back(pos.second);
	}

	for (auto& pos : longPosDict) {
		result.push_back(pos.second);
	}

	for (auto& pos : shortPosDict) {
		result.push_back(pos.second);
	}

	return result;
}
