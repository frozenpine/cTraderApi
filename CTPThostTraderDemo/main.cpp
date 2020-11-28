#include <stdio.h>
#include <ctype.h>
#include <csignal>
#include <iostream>
#include <regex>

#include "TDUserApi.h"
#include "ini.h"
#include "Command.h"

const char flowPath[] = "flow/";
const std::regex floatPattern("\\d*\\.?\\d+");
const std::regex intPattern("\\d+");

int cmdVersion(void* api, const std::vector<std::string>& args) {
	printf("Current API version is: %s\n", ((TDUserApi*)api)->GetApiVersion());

	return 0;
}

int cmdExit(void* api, const std::vector<std::string>& args) {
	printf("Exit called.\n");

	((TDUserApi*)api)->Release();

	return 0;
}

int cmdPostWait(void* api, const std::vector<std::string>& args) {
	auto apiIns = ((TDUserApi*)api);

	apiIns->WaitResponse(100);

	return 0;
}

int cmdOrderNew(void* api, const std::vector<std::string>& args) {
	if (args.size() < 4) {
		fprintf(stderr, "lack of args: instrumentid direction price volume\n");
		return Command::CMDInvalidArgs;
	}

	TThostFtdcDirectionType direction;
	if (args[1] == "0" || args[1] == "buy") {
		direction = THOST_FTDC_D_Buy;
	}
	else if (args[1] == "1" || args[1]=="sell") {
		direction = THOST_FTDC_D_Sell;
	}
	else {
		fprintf(stderr, "invalid direction input: %s\n", args[1].c_str());
		return Command::CMDInvalidArgs;
	}

	if (!std::regex_match(args[2], floatPattern)) {
		fprintf(stderr, "price must be a float number.\n");
		return Command::CMDInvalidArgs;
	}
	double price = atof(args[2].c_str());

	if (!std::regex_match(args[3], intPattern)) {
		fprintf(stderr, "volume must be a int number.\n");
		return Command::CMDInvalidArgs;
	}
	int volume = atoi(args[3].c_str());

	CThostFtdcInputOrderField ord = { 0 };

	auto apiIns = ((TDUserApi*)api);
	
	/* mandatory fields for a new order */
	strcpy_s(ord.BrokerID, apiIns->User.BrokerID);
	strcpy_s(ord.UserID, apiIns->User.UserID);
	strcpy_s(ord.InstrumentID, args[0].c_str());
	strcpy_s(ord.InvestorID, apiIns->User.UserID);
	
	ord.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	ord.Direction = direction;
	ord.LimitPrice = price;
	ord.VolumeTotalOriginal = volume;
	
	ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
	ord.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;	
	ord.StopPrice = 0;
	ord.TimeCondition = THOST_FTDC_TC_GFD;
	ord.VolumeCondition = THOST_FTDC_VC_AV;
	ord.ContingentCondition = THOST_FTDC_CC_Immediately;
	ord.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;

	return apiIns->ReqOrderInsert(&ord);
}

int cmdOrderModify(void* api, const std::vector<std::string>& args) {
	CThostFtdcInputOrderActionField ord = { 0 };

	auto apiIns = ((TDUserApi*)api);

	// TODO: 填写改单参数

	return apiIns->ReqOrderAction(&ord);
}

int cmdOrderCancel(void* api, const std::vector<std::string>& args) {
	CThostFtdcInputOrderActionField ord = { 0 };

	auto apiIns = ((TDUserApi*)api);

	// TODO: 填写撤单参数

	return apiIns->ReqOrderAction(&ord);
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

	TDUserApi *api = new(TDUserApi);

	Command cli = Command("CTP", api);

	CommandDefine versionCommand = { "version", "Print API's version info.", NULL, cmdVersion };
	CommandDefine exitCommand = { "exit", "Release API & EXIT.", NULL, cmdExit };
	CommandDefine orderNewCommand = { 
		"new", "Make a limited price order.", 
		"new {instrumentid} {direction} {price} {volume}", cmdOrderNew };
	CommandDefine orderModifyCommand = { 
		"modify", "Modify an exist order.", 
		"", cmdOrderModify };
	CommandDefine orderCancelCommand = { 
		"cancel", "Cancel an exist order.", 
		"", cmdOrderCancel };

	cli.AddCommand(&versionCommand);
	cli.AddExitCommand(&exitCommand);
	cli.AddCommand(&orderNewCommand);
	cli.AddCommand(&orderModifyCommand);
	cli.AddCommand(&orderCancelCommand);

	cli.RegisterPostCommand(cmdPostWait);

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
	printf("Quering invesot's orders.\n");

	api->WaitInitialData();

	cli.RunForever();
}