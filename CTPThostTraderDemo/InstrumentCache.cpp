#include <assert.h>

#include "InstrumentCache.h"
#include "TDUserApi.h"

bool InstrumentCache::InsertOrAssignInstrument(CThostFtdcInstrumentField* pInstrument)
{
	if (NULL == pInstrument) { return false; }

	CThostFtdcInstrumentField* ins = NULL;

	if (instrumentDict.find(pInstrument->InstrumentID) == instrumentDict.end()) {
		ins = new(CThostFtdcInstrumentField);
		instrumentDict.insert_or_assign(pInstrument->InstrumentID, ins);
	}
	else {
		ins = instrumentDict.at(pInstrument->InstrumentID);
	}

	assert(ins != NULL);
	memcpy(ins, pInstrument, sizeof(CThostFtdcInstrumentField));

	return true;
}

bool InstrumentCache::InsertOrAssignMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
	if (NULL == pDepthMarketData) {
		return false;
	}

	CThostFtdcDepthMarketDataField* md = NULL;

	if (marketDataDict.find(pDepthMarketData->InstrumentID) == marketDataDict.end()) {
		md = new(CThostFtdcDepthMarketDataField);
		marketDataDict.insert_or_assign(pDepthMarketData->InstrumentID, md);
	}
	else {
		md = marketDataDict.at(pDepthMarketData->InstrumentID);
	}

	assert(md != NULL);
	memcpy(md, pDepthMarketData, sizeof(CThostFtdcDepthMarketDataField));
	return true;
}

CThostFtdcInstrumentField* InstrumentCache::getNextInstrument(int& idx)
{
	if (idx >= instrumentList.size()) {
		return NULL;
	}

	return instrumentList[idx++];
}

bool InstrumentCache::InsertOrAssignMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate)
{
	if (NULL == pInstrumentMarginRate) {
		return false;
	}

	CThostFtdcInstrumentMarginRateField* marginRate = NULL;

	if (marginRateDict.find(pInstrumentMarginRate->InstrumentID) == marginRateDict.end()) {
		marginRate = new(CThostFtdcInstrumentMarginRateField);
		marginRateDict.insert_or_assign(pInstrumentMarginRate->InstrumentID, marginRate);
	}
	else {
		marginRate = marginRateDict.at(pInstrumentMarginRate->InstrumentID);
	}

	assert(marginRate != NULL);
	memcpy(marginRate, pInstrumentMarginRate, sizeof(CThostFtdcInstrumentMarginRateField));
	return true;
}

bool InstrumentCache::InsertOrAssignCommRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate)
{
	if (NULL == pInstrumentCommissionRate) {
		return false;
	}

	CThostFtdcInstrumentCommissionRateField* commRate = NULL;

	if (commRateDict.find(pInstrumentCommissionRate->InstrumentID) == commRateDict.end()) {
		commRate = new(CThostFtdcInstrumentCommissionRateField);
		commRateDict.insert_or_assign(pInstrumentCommissionRate->InstrumentID, commRate);
	}
	else {
		commRate = commRateDict.at(pInstrumentCommissionRate->InstrumentID);
	}

	assert(commRate != NULL);
	memcpy(commRate, pInstrumentCommissionRate, sizeof(CThostFtdcInstrumentCommissionRateField));
	return true;
}

void InstrumentCache::QueryNextMarginRate()
{
	assert(api != NULL);

	CThostFtdcInstrumentField* ins = getNextInstrument(marginRateQryIdx);

	while (NULL != ins) {
		// 目前仅支持期货合约的保证金查询
		// TODO： 支持其他类型的合约保证金查询
		if (marginRateDict.find(ins->InstrumentID) == marginRateDict.end() &&
			THOST_FTDC_APC_FutureSingle == ins->ProductClass) {

			CThostFtdcQryInstrumentMarginRateField qryMargin = { 0 };
			strncpy(qryMargin.BrokerID, api->User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
			strncpy(qryMargin.InvestorID, api->User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);
			strncpy(qryMargin.InstrumentID, ins->InstrumentID, sizeof(TThostFtdcInstrumentIDType) - 1);
			qryMargin.HedgeFlag = THOST_FTDC_HF_Speculation;

			api->ReqQryInstrumentMarginRate(&qryMargin);

			return;
		}

		ins = getNextInstrument(marginRateQryIdx);
	}

	api->queryAllMarginRate = false;
	marginRateQryIdx = 0;

	printf("Quering instrument margin rate finisehd.\n");
}

void InstrumentCache::QueryNextCommRate()
{
	assert(api != NULL);

	CThostFtdcInstrumentField* ins = getNextInstrument(commRateQryIdx);

	while (NULL != ins) {
		// 目前仅支持期货合约的手续费查询
		// TODO： 支持其他类型的合约手续费查询
		if (commRateDict.find(ins->InstrumentID) == commRateDict.end() &&
			THOST_FTDC_APC_FutureSingle == ins->ProductClass) {

			CThostFtdcQryInstrumentCommissionRateField qryComm = { 0 };
			strncpy(qryComm.BrokerID, api->User.BrokerID, sizeof(TThostFtdcBrokerIDType) - 1);
			strncpy(qryComm.InvestorID, api->User.UserID, sizeof(TThostFtdcInvestorIDType) - 1);
			strncpy(qryComm.InstrumentID, ins->InstrumentID, sizeof(TThostFtdcInstrumentIDType) - 1);

			api->ReqQryInstrumentCommissionRate(&qryComm);

			return;
		}

		ins = getNextInstrument(commRateQryIdx);
	}

	api->queryAllCommRate = false;
	commRateQryIdx = 0;

	printf("Quering instrument comm rate finished.\n");
}

void InstrumentCache::BuildInstrumentList()
{
	if (instrumentList.size() > 0) {
		instrumentList.clear();
	}

	for (auto& iter : instrumentDict) {
		instrumentList.push_back(iter.second);
	}
}

std::vector<CThostFtdcInstrumentField*> InstrumentCache::GetInstrumentList(std::string ExchangeID, std::string ProductID, std::string InstrumentID)
{
	std::vector<CThostFtdcInstrumentField*> result;

	if (InstrumentID != "") {
		auto ins = instrumentDict.at(InstrumentID);
		result.push_back(ins);

		return result;
	}

	for (auto ins : instrumentList) {
		if ((ExchangeID != "" && ins->ExchangeID != ExchangeID) ||
			(ProductID != "" && ins->ProductID != ProductID)) {
			continue;
		}

		result.push_back(ins);
	}

	return result;
}
