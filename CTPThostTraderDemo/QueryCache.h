#pragma once

#include <vector>
#include <atomic>
#include <mutex>
#include <map>

class TDUserApi;

enum class QueryFlag {
	QryFinished = 0,
	QrySettlementInfo,
	QrySettlementConfirm,
	QryAccount,
	QryOrder,
	QryPosition,
	QryExecution,
	QryInstrument,
	QryMarginRate,
	QryCommissionRate,
	QryMarketData,
};

struct Query {
	enum class QueryFlag flag;
	void* qry;
};

class QueryCache
{
public:
	QueryCache() {
		lastQryTS = 0;
		qryFreq = 3;
		qryCount = 0;

		flag = QueryFlag::QryFinished;

		api = NULL;
	};
	QueryCache(TDUserApi* api) {
		new (this)QueryCache();

		this->api = api;
	};
	QueryCache(TDUserApi* api, int qryFreq) {
		new (this)QueryCache(api);

		this->qryFreq = qryFreq;
	}
protected:
	~QueryCache() {
		for (auto& qry : qryCache) {
			free(qry.second->qry);
		}
	}
private:
	long long lastQryTS;
	std::atomic<int> qryFreq;
	std::atomic<int> qryCount;

	std::mutex g_lock;
	std::condition_variable g_cond;

	TDUserApi* api;

	QueryFlag flag;

	std::map<int, Query*> qryCache;

	bool chkStatus(long long& timeout);
public:
	void SetQueryFreq(int freq) { qryFreq = freq; }

	int StartQuery(QueryFlag flag, void* qry, bool copyQry = true);
	void RedoQuery(int requestID);
	void FinishQuery(int requestID);

	void CheckAndWait();
};

