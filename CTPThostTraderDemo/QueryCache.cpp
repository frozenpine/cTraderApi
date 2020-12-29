#include <assert.h>

#include "tools.h"
#include "QueryCache.h"
#include "TDUserApi.h"

void QueryCache::RedoQuery(int requestID)
{
	if (qryCache.find(requestID) == qryCache.end()) {
		fprintf(stderr, "Request[%d] not in query cache.\n", requestID);
		return;
	}

	flag = QueryFlag::QryFinished;
	auto qry = qryCache.at(requestID);
	qryCount -= int(qryCache.erase(requestID));
	if (qryCount < 0) {
		qryCount = 0;
	}
	g_cond.notify_one();

	StartQuery(qry->flag, qry->qry, false);
	delete qry;
}

int QueryCache::StartQuery(QueryFlag flag, void* qry, bool copyQry)
{
	assert(api != NULL);

	CheckAndWait();

	lastQryTS = get_ms_ts();
	this->flag = flag;
	int requestID = ++api->nRequestID;

	int rtn = 0;
	Query* query = new(Query);
	query->flag = flag;

	while (true) {
		switch (flag)
		{
		case QueryFlag::QryFinished:
			FinishQuery(requestID);
			return 0;
		case QueryFlag::QrySettlementInfo:
			rtn = api->pApi->ReqQrySettlementInfo((CThostFtdcQrySettlementInfoField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQrySettlementInfoField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQrySettlementInfoField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QrySettlementConfirm:
			rtn = api->pApi->ReqQrySettlementInfoConfirm((CThostFtdcQrySettlementInfoConfirmField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQrySettlementInfoConfirmField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQrySettlementInfoConfirmField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryAccount:
			rtn = api->pApi->ReqQryTradingAccount((CThostFtdcQryTradingAccountField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryTradingAccountField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryTradingAccountField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryOrder:
			rtn = api->pApi->ReqQryOrder((CThostFtdcQryOrderField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryOrderField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryOrderField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryPosition:
			rtn = api->pApi->ReqQryInvestorPosition((CThostFtdcQryInvestorPositionField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInvestorPositionField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInvestorPositionField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryExecution:
			break;
		case QueryFlag::QryInstrument:
			rtn = api->pApi->ReqQryInstrument((CThostFtdcQryInstrumentField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentField));
			}
			else {
				query->qry = qry;
			}

			break;
		case QueryFlag::QryMarginRate:
		{
			auto pQryInstrumentMarginRate = (CThostFtdcQryInstrumentMarginRateField*)qry;
			printf("Quering instrument[%s] margin rate.\n", pQryInstrumentMarginRate->InstrumentID);
			rtn = api->pApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentMarginRateField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentMarginRateField));
			}
			else {
				query->qry = qry;
			}

			break;
		}
		case QueryFlag::QryCommissionRate:
		{
			auto pQryInstrumentCommissionRate = (CThostFtdcQryInstrumentCommissionRateField*)qry;
			printf("Quering instrument[%s] comm rate.\n", pQryInstrumentCommissionRate->InstrumentID);
			rtn = api->pApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryInstrumentCommissionRateField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryInstrumentCommissionRateField));
			}
			else {
				query->qry = qry;
			}

			break;
		}
		case QueryFlag::QryMarketData:
			rtn = api->pApi->ReqQryDepthMarketData((CThostFtdcQryDepthMarketDataField*)qry, requestID);

			if (copyQry) {
				query->qry = malloc(sizeof(CThostFtdcQryDepthMarketDataField));
				assert(query->qry != NULL);
				memcpy(query->qry, qry, sizeof(CThostFtdcQryDepthMarketDataField));
			}
			else {
				query->qry = qry;
			}

			break;
		default:
			fprintf(stderr, "Invalid query flag: %x\n", flag);
			return 255;
		}

		if (0 == rtn) {
			break;
		}

		if (-2 == rtn) {
			fprintf(stderr, "Inflight request exceeded.\n");
		}
		else if (-3 == rtn) {
			fprintf(stderr, "Flow control exceeded.\n");
		}
		else {
			fprintf(stderr, "Unknown request rtn code: %d\n", rtn);
			return rtn;
		}

		SLEEP(500);
	}

	qryCache.insert_or_assign(requestID, query);
	qryCount++;

	return rtn;
}

void QueryCache::FinishQuery(int requestID) {
	if (qryCache.find(requestID) == qryCache.end()) {
		return;
	}

	auto qry = qryCache.at(requestID);
	free(qry->qry);
	delete qry;

	qryCount -= int(qryCache.erase(requestID));
	if (qryCount < 0) {
		qryCount = 0;
	}

	flag = QueryFlag::QryFinished;
	g_cond.notify_one();
}

bool QueryCache::chkStatus(long long& timeout)
{
	if (flag != QueryFlag::QryFinished) {
		// fprintf(stderr, "Last query not finished.\n");
		timeout = 0;
		return false;
	}

	timeout = get_ms_ts() - lastQryTS;
	if (timeout < 1000 && qryCount >= qryFreq) {
		// fprintf(stderr, "Query frequence exceeded.\n");
		return false;
	}

	timeout = 0;
	return true;
}

void QueryCache::CheckAndWait() {
	std::unique_lock<std::mutex> locker(g_lock);

	long long timeout;

	while (!chkStatus(timeout)) {
		if (timeout > 0) {
			g_cond.wait_for(locker, std::chrono::milliseconds(timeout));
		}
		else {
			g_cond.wait(locker);
		}
	}
}
