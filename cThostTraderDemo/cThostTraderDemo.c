#include <stdio.h>
#include <string.h>

#include "cThostTraderApi.h"

#ifdef _WIN32
#include <direct.h>
#include <windows.h>
#define MKDIR(path) _mkdir((path))
#define SLEEP(time) Sleep(time)
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define MKDIR(path) mkdir((path), S_IRUSR|S_IWUSR|S_IRGRP)
#define SLEEP(time) sleep(time)
#endif

const char* flowPath = "flow/";
const char* tdFront = "tcp://180.166.6.246:65086";
const char* mdFront = "tcp://180.166.6.246:65090";
const char* brokerID = "0121";
const char* appID = "Rohon_RHProTrade_1.4";
const char* authCode = "A0L3ZW5IUQT7PS90";
const char* userID = "000603";
const char* password = "147258";

bool running = true;

void onFrontConnected(InstanceID id)
{
	printf("Front connected: %s\n", tdFront);

	CThostFtdcReqAuthenticateField auth;
	memset(&auth, 0, sizeof(auth));
	strncpy(&(auth.BrokerID), brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	strncpy(&(auth.AppID), appID, sizeof(TThostFtdcClientAppIDType) - 1);
	strncpy(&(auth.AuthCode), authCode, sizeof(TThostFtdcAuthCodeType) - 1);

	printf("Try to authenticate with AppID[%s].\n", appID);

	ReqAuthenticate(id, &auth, 0);
}

void onRspAuthenticatioin(InstanceID id, CThostFtdcRspAuthenticateField* pRspAuthenticateField,
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo->ErrorID != 0)
	{
		printf("Authentication failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		running = false;
		return;
	}

	printf("Authenticated with AppID[%s].\n", appID);

	CThostFtdcReqUserLoginField login;
	memset(&login, 0, sizeof(login));
	strncpy(&(login.BrokerID), brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	strncpy(&(login.UserID), userID, sizeof(TThostFtdcUserIDType) - 1);
	strncpy(&(login.Password), password, sizeof(TThostFtdcPasswordType) - 1);

	printf("Try to login with UserID[%s]\n", userID);

	ReqUserLogin(id, &login, ++nRequestID);
}

void onRspUserLogin(InstanceID id, CThostFtdcRspUserLoginField* pRspUserLogin,
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo->ErrorID != 0)
	{
		printf("Login failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		running = false;
		return;
	}

	printf("User[%s] logged in.\n", userID);

	CThostFtdcQryExchangeField qry;
	memset(&qry, 0, sizeof(CThostFtdcQryExchangeField));
	printf("Try to query available Exchanges.\n");
	ReqQryExchange(id, &qry, ++nRequestID);
}

void onRspQryExchange(InstanceID id, CThostFtdcExchangeField* pExchange,
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo->ErrorID != 0)
	{
		printf("Query exchange failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		running = false;
		return;
	}

	if (pExchange != NULL)
	{
		printf("Exchange[%s]: %s\n", pExchange->ExchangeID, pExchange->ExchangeName);
	}
	else if (bIsLast)
	{
		CThostFtdcQryInstrumentField qry;
		memset(&qry, 0, sizeof(qry));
		printf("Try to query all instruments.\n");
		ReqQryInstrument(id, &qry, ++nRequestID);
	}
}

void onRspQryInstrument(InstanceID id, CThostFtdcInstrumentField* pInstrument,
	CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pRspInfo->ErrorID != 0)
	{
		printf("Query instruments failed[%d]: %s\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
		running = false;
		return;
	}

	if (pInstrument != NULL)
	{
		printf("Instrument[%s.%s]: %s\n", pInstrument->ExchangeID, pInstrument->InstrumentID, pInstrument->InstrumentName);
	}
	else if (bIsLast)
	{
		running = false;
	}
}


int main() {
	printf("API Version: %s", GetApiVersion());

	MKDIR(flowPath);

	InstanceID id = CreateThostTraderApi(flowPath);

	SetCallbackOnFrontConnected(id, onFrontConnected);
	SetCallbackOnRspAuthenticate(id, onRspAuthenticatioin);
	SetCallbackOnRspUserLogin(id, onRspUserLogin);
	SetCallbackOnRspQryExchange(id, onRspQryExchange);
	SetCallbackOnRspQryInstrument(id, onRspQryInstrument);

	RegisterFront(id, tdFront);

	SubscribePrivateTopic(id, THOST_TERT_QUICK);
	SubscribePublicTopic(id, THOST_TERT_QUICK);

	Init(id, false);
	running = true;

	while (running) { SLEEP(1); }

	Release(id);

	printf("Exit.");

	return 0;
}