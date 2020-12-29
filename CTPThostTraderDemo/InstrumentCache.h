#pragma once

#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

#include "ThostFtdcUserApiStruct.h"

class TDUserApi;

class InstrumentCache
{
public:
	InstrumentCache() {
		marginRateQryIdx = 0;
		commRateQryIdx = 0;
		api = NULL;
	};
	InstrumentCache(TDUserApi* api) {
		new (this)InstrumentCache();

		this->api = api;
	};
protected:
	~InstrumentCache() {
		for (auto& ins : instrumentDict) {
			free(ins.second);
		}

		for (auto& md : marketDataDict) {
			free(md.second);
		}

		for (auto& margin : marginRateDict) {
			free(margin.second);
		}

		for (auto& comm : commRateDict) {
			free(comm.second);
		}
	}
private:
	TDUserApi* api;
	int marginRateQryIdx;
	int commRateQryIdx;
	std::map<std::string, CThostFtdcInstrumentField*> instrumentDict;
	std::map<std::string, CThostFtdcDepthMarketDataField*> marketDataDict;
	std::map<std::string, CThostFtdcInstrumentMarginRateField*> marginRateDict;
	std::map<std::string, CThostFtdcInstrumentCommissionRateField*> commRateDict;
	std::vector<CThostFtdcInstrumentField*> instrumentList;

	CThostFtdcInstrumentField* getNextInstrument(int& idx);
public:
	bool InsertOrAssignInstrument(CThostFtdcInstrumentField* pInstrument);
	bool InsertOrAssignMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData);

	bool InsertOrAssignMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate);
	bool InsertOrAssignCommRate(CThostFtdcInstrumentCommissionRateField* commRate);

	void QueryNextMarginRate();
	void QueryNextCommRate();

	void BuildInstrumentList();

	std::vector<CThostFtdcInstrumentField*> GetInstrumentList(
		std::string ExchangeID = "", std::string ProductID = "", std::string InstrumentID = ""
	);
};
