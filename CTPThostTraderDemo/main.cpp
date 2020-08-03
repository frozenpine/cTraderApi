#include <stdio.h>

#include "TDUserApi.h"

const char flowPath[] = "flow/";

char tdFront[] = "tcp://180.166.6.242:41205";
char brokerID[] = "0121";
char appID[] = "client_VIIB_V1.0";
char authCode[] = "E4785GL0IKCR8HGH";
char userID[] = "000645";
char password[] = "147258";
char userProdInfo[] = "CPP TEST API";

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
	memcpy(auth.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	memcpy(auth.UserID, userID, sizeof(TThostFtdcUserIDType) - 1);
	memcpy(auth.AppID, appID, sizeof(TThostFtdcAppIDType) - 1);
	memcpy(auth.AuthCode, authCode, sizeof(TThostFtdcAuthCodeType) - 1);
	memcpy(auth.UserProductInfo, userProdInfo, sizeof(TThostFtdcProductInfoType) - 1);
	api->ReqAuthenticate(&auth);
	printf("Send authentication: %s, %s, %s\n", brokerID, userID, appID);

	CThostFtdcReqUserLoginField login;
	memset(&login, 0, sizeof(login));
	memcpy(login.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	memcpy(login.UserID, userID, sizeof(TThostFtdcUserIDType) - 1);
	memcpy(login.Password, password, sizeof(TThostFtdcPasswordType) - 1);
	api->ReqUserLogin(&login);
	printf("Send login: %s, %s\n", brokerID, userID);

	api->Join();
}