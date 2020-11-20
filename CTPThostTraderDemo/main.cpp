#include <stdio.h>
#include <ctype.h>

#include "TDUserApi.h"
#include "ini.h"
#include "Command.h"

const char flowPath[] = "flow/";

int cmdVersion(void* api, va_list args) {
	printf("Current API version is: %s\n", ((TDUserApi*)api)->GetApiVersion());

	return 0;
}

int main(int argc, char* argv[]) {
	printf("CTP API Version: %s impl by CPP.\n", TDUserApi::GetApiVersion());

	char confFile[] = "setting.ini";

	if (argc > 1) {
		memcpy(confFile, argv[1], strlen(argv[1]) + 1);
	}

	// 加载配置文件
	mINI::INIFile setting_file(confFile);

	// 创建ini结构体
	mINI::INIStructure ini;

	// 配置文件载入结构体解析
	setting_file.read(ini);

	const char* frontAddr = ini["front_info"]["Address"].c_str();
	const char* frontPort = ini["front_info"]["Port"].c_str();

	// 连接字符串格式：tcp://IP:PORT 的最大长度为 6+15+1+5+1
	char conn[28] = {0};
	sprintf(conn, "tcp://%s:%s", frontAddr, frontPort);

	const char* brokerID = ini["login_info"]["BrokerID"].c_str();
	const char* userID = ini["login_info"]["UserID"].c_str();
	const char* userPass = ini["login_info"]["Password"].c_str();
	const char* appID = ini["login_info"]["AppID"].c_str();
	const char* authCode = ini["login_info"]["AuthCode"].c_str();

	Command cli;

	CommandDefine versionCommand = {"version", "Print API's version info.", cmdVersion};

	cli.AddCommand(&versionCommand);

	TDUserApi *api = new(TDUserApi);

	api->CreateFtdcTraderApi(flowPath);
	api->SubscribePrivateTopic(THOST_TERT_QUICK);
	api->SubscribePublicTopic(THOST_TERT_QUICK);
	api->RegisterFront(conn);
	api->Init();

	CThostFtdcReqAuthenticateField auth;
	memset(&auth, 0, sizeof(auth));
	strncpy(auth.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType)-1);
	strncpy(auth.UserID, userID, sizeof(TThostFtdcUserIDType)-1);
	strncpy(auth.AppID, appID, sizeof(TThostFtdcAppIDType)-1);
	strncpy(auth.AuthCode, authCode, sizeof(TThostFtdcAuthCodeType)-1);
	api->ReqAuthenticate(&auth);
	printf("Send authentication: %s, %s, %s\n", brokerID, userID, appID);

	CThostFtdcReqUserLoginField login;
	memset(&login, 0, sizeof(login));
	strncpy(login.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType)-1);
	strncpy(login.UserID, userID, sizeof(TThostFtdcUserIDType)-1);
	strncpy(login.Password, userPass, sizeof(TThostFtdcPasswordType)-1);
	api->ReqUserLogin(&login);
	printf("Send login: %s, %s\n", brokerID, userID);

	CThostFtdcQryInstrumentField qryIns;
	memset(&qryIns, 0, sizeof(qryIns));
	api->ReqQryInstrument(&qryIns);
	printf("Quering instrument info.\n");

	CThostFtdcQryInvestorPositionField qryPos;
	memset(&qryPos, 0, sizeof(qryPos));
	/* not mandatory */
	// strncpy(qryPos.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	// strncpy(qryPos.InvestorID, userID, sizeof(TThostFtdcInvestorIDType) - 1);
	api->ReqQryInvestorPosition(&qryPos);
	printf("Quering investor's position.\n");

	CThostFtdcQryOrderField qryOdr;
	memset(&qryOdr, 0, sizeof(qryOdr));
	/* not mandatory */
	// strncpy(qryOdr.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	// strncpy(qryOdr.InvestorID, userID, sizeof(TThostFtdcInvestorIDType) - 1);
	api->ReqQryOrder(&qryOdr);
	printf("Qruering invesot's orders.\n");

	api->WaitInitialData();

	cli.PrintCommands();

	cli.RunCommand(api, "version");

	api->Join();
}