#include <stdio.h>

#include "TDUserApi.h"

const char flowPath[] = "flow/";

//// CTP´ÎÏ¯
//char tdFront[] = "tcp://180.166.6.245:51205";
//char brokerID[] = "5100";
//char appID[] = "client_wfa_1.0.0";
//char authCode[] = "VZ7N55JRMQL98ODU";
//char userID[] = "000006";
//char password[] = "123456";

// CTP·ÂÕæ
char tdFront[] = "tcp://180.166.6.242:41205";
char brokerID[] = "0121";
char appID[] = "client_wfa_1.0.0";
char authCode[] = "VZ7N55JRMQL98ODU";
char userID[] = "300000";
char password[] = "147258";

int main(int argc, char* argv) {
	printf("CTP API Version: %s impl by CPP.\n", TDUserApi::GetApiVersion());

	TDUserApi *api = new(TDUserApi);

	api->CreateFtdcTraderApi(flowPath);
	api->SubscribePrivateTopic(THOST_TERT_QUICK);
	api->SubscribePublicTopic(THOST_TERT_QUICK);
	api->RegisterFront(tdFront);
	api->Init();

	CThostFtdcReqAuthenticateField auth;
	memset(&auth, 0, sizeof(auth));
	strncpy(auth.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType));
	strncpy(auth.UserID, userID, sizeof(TThostFtdcUserIDType));
	strncpy(auth.AppID, appID, sizeof(TThostFtdcAppIDType));
	strncpy(auth.AuthCode, authCode, sizeof(TThostFtdcAuthCodeType));
	api->ReqAuthenticate(&auth);
	printf("Send authentication: %s, %s, %s\n", brokerID, userID, appID);

	CThostFtdcReqUserLoginField login;
	memset(&login, 0, sizeof(login));
	strncpy(login.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType));
	strncpy(login.UserID, userID, sizeof(TThostFtdcUserIDType));
	strncpy(login.Password, password, sizeof(TThostFtdcPasswordType));
	api->ReqUserLogin(&login);
	printf("Send login: %s, %s\n", brokerID, userID);

	CThostFtdcQryInstrumentField qry;
	memset(&qry, 0, sizeof(qry));
	api->ReqQryInstrument(&qry);
	printf("Quering instrument info.\n");

	api->Join();
}