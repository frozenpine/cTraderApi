#include <stdio.h>
#include <csignal>
#include <iostream>
#include <regex>
#include <assert.h>
#include <direct.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "tools.h"
#include "ini.h"
#include "TDUserApi.h"
#include "Command.h"
// #include "toml.h"

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

const char flowPath[] = "flow/";
const std::regex floatPattern("\\d*\\.?\\d+");
const std::regex intPattern("\\d+");

static inline TThostFtdcOrderPriceTypeType parse_price_type(char* value, int& rtn) {
	switch (hash_(value)) {
	case hash_compile_time("AnyPrice"):
		return THOST_FTDC_OPT_AnyPrice;
	case hash_compile_time("LimitPrice"):
		return THOST_FTDC_OPT_LimitPrice;
	case hash_compile_time("BestPrice"):
		return THOST_FTDC_OPT_BestPrice;
	case hash_compile_time("LastPrice"):
		return THOST_FTDC_OPT_LastPrice;
	case hash_compile_time("LastPricePlusOneTicks"):
		return THOST_FTDC_OPT_LastPricePlusOneTicks;
	case hash_compile_time("LastPricePlusTwoTicks"):
		return THOST_FTDC_OPT_LastPricePlusTwoTicks;
	case hash_compile_time("LastPricePlusThreeTicks"):
		return THOST_FTDC_OPT_LastPricePlusThreeTicks;
	case hash_compile_time("AskPrice1"):
		return THOST_FTDC_OPT_AskPrice1;
	case hash_compile_time("AskPrice1PlusOneTicks"):
		return THOST_FTDC_OPT_AskPrice1PlusOneTicks;
	case hash_compile_time("AskPrice1PlusTwoTicks"):
		return THOST_FTDC_OPT_AskPrice1PlusTwoTicks;
	case hash_compile_time("AskPrice1PlusThreeTicks"):
		return THOST_FTDC_OPT_AskPrice1PlusThreeTicks;
	case hash_compile_time("BidPrice1"):
		return THOST_FTDC_OPT_BidPrice1;
	case hash_compile_time("BidPrice1PlusOneTicks"):
		return THOST_FTDC_OPT_BidPrice1PlusOneTicks;
	case hash_compile_time("BidPrice1PlusTwoTicks"):
		return THOST_FTDC_OPT_BidPrice1PlusTwoTicks;
	case hash_compile_time("BidPrice1PlusThreeTicks"):
		return THOST_FTDC_OPT_BidPrice1PlusThreeTicks;
	case hash_compile_time("FiveLevelPrice"):
		return THOST_FTDC_OPT_FiveLevelPrice;
	default:
		rtn = Command::CMDInvalidArgs;
		return 0;
	}
}

static inline TThostFtdcDirectionType parse_direction(char* value, int& rtn) {
	switch (hash_(value)) {
	case hash_compile_time("Buy"):
	case hash_compile_time("buy"):
		return THOST_FTDC_D_Buy;
	case hash_compile_time("Sell"):
	case hash_compile_time("sell"):
		return THOST_FTDC_D_Sell;
	default:
		rtn = Command::CMDInvalidArgs;
		return 0;
	}
}

static inline char parse_offset_flag(char* value, int& rtn) {
	switch (hash_(value)) {
	case hash_compile_time("Open"):
	case hash_compile_time("open"):
		return THOST_FTDC_OF_Open;
	case hash_compile_time("Close"):
	case hash_compile_time("close"):
		return THOST_FTDC_OF_Close;
	case hash_compile_time("ForceClose"):
		return THOST_FTDC_OF_ForceClose;
	case hash_compile_time("CloseToday"):
		return THOST_FTDC_OF_CloseToday;
	case hash_compile_time("CloseYesterday"):
		return THOST_FTDC_OF_CloseYesterday;
	case hash_compile_time("ForceOff"):
		return THOST_FTDC_OF_ForceOff;
	case hash_compile_time("LocalForceClose"):
		return THOST_FTDC_OF_LocalForceClose;
	default:
		rtn = Command::CMDInvalidArgs;
		return 0;
	}
}

static inline char parse_hedge_flag(char* value, int& rtn) {
	switch (hash_(value)) {
	case hash_compile_time("Speculation"):
	case hash_compile_time("speculation"):
	case hash_compile_time("spec"):
		return THOST_FTDC_CIDT_Speculation;
	case hash_compile_time("Arbitrage"):
	case hash_compile_time("arbitrage"):
	case hash_compile_time("arbit"):
		return THOST_FTDC_CIDT_Arbitrage;
	case hash_compile_time("Hedge"):
	case hash_compile_time("hedge"):
		return THOST_FTDC_CIDT_Hedge;
	case hash_compile_time("MarketMaker"):
		return THOST_FTDC_CIDT_MarketMaker;
	default:
		fprintf(stderr, "Hedege flag value invalid[%s], use default: THOST_FTDC_CIDT_Speculation\n", value);
		return THOST_FTDC_CIDT_Speculation;
	}
}

int fill_order(CThostFtdcInputOrderField& ord, const char *input) {
	int count = 0;
	char** arg = split(input, count, '=');

	if (count != 2) {
		fprintf(stderr, "invalid arg input: %s", input);
		return Command::CMDInvalidArgs;
	}

	char* cmd = trim(arg[0]);
	char* value = trim(arg[1]);
	int rtn = Command::CMDSucceeded;

	switch (hash_(cmd)) {
	case hash_compile_time("OrderPriceType"):
		ord.OrderPriceType = parse_price_type(value, rtn);
		break;
	case hash_compile_time("Direction"):
		ord.Direction = parse_direction(value, rtn);
		break;
	case hash_compile_time("OffsetFlag"):
		ord.CombOffsetFlag[0] = parse_offset_flag(value, rtn);
		break;
	case hash_compile_time("HedgeFlag"):
		ord.CombHedgeFlag[0] = parse_hedge_flag(value, rtn);
		break;
	case hash_compile_time("LimitPrice"):
		if (!std::regex_match(value, floatPattern)) {
			fprintf(stderr, "price must be a float number.\n");
			rtn = Command::CMDInvalidArgs;
		}
		else {
			ord.LimitPrice = atof(value);
		}
		break;
	case hash_compile_time("VolumeTotalOriginal"):
		if (!std::regex_match(value, intPattern)) {
			fprintf(stderr, "volume must be a int number.\n");
			rtn = Command::CMDInvalidArgs;
		}
		else {
			ord.VolumeTotalOriginal = atoi(value);
		}
		break;
	case hash_compile_time("TimeCondition"):
		break;
	case hash_compile_time("VolumeCondition"):
		break;
	case hash_compile_time("MinVolume"):
		break;
	case hash_compile_time("InvestUnitID"):
		break;
	}

	return rtn;
}

int cmdVersion(void* api, const std::vector<std::string>& args) {
	printf("Current API version is: %s\n", ((TDUserApi*)api)->GetApiVersion());

	return 0;
}

int cmdExit(void* api, const std::vector<std::string>& args) {
	printf("Exit called.\n");

	((TDUserApi*)api)->Release();

	return 0;
}

int cmdShow(void* api, const std::vector<std::string>& args) {
	if (args.size() < 1) {
		fprintf(stderr, "lack of args: {instrument|order|position} [args]\n");
		return Command::CMDInvalidArgs;
	}

	std::string obj = args[0];
	auto apiIns = ((TDUserApi*)api);

	if (obj == "instrument") {
		std::string ExchangeID = "";
		std::string ProductID = "";
		std::string InstrumentID = "";

		for (int i = 1; i < args.size(); i++) {
			int count = 0;
			char** results = split(args[i].c_str(), count, '=');

			if (count != 2) {
				fprintf(stderr, "Invalid args: %s\n", args[i].c_str());
				return Command::CMDInvalidArgs;
			}

			if (strcmp(trim(results[0]), "ExchangeID") == 0) {
				ExchangeID = trim(results[1]);
				continue;
			}

			if (strcmp(trim(results[0]), "ProductID") == 0) {
				ProductID = trim(results[1]);
				continue;
			}

			if (strcmp(trim(results[0]), "InstrumentID") == 0) {
				InstrumentID = trim(results[1]);
				continue;
			}

			fprintf(stderr, "Invalid arg key word: %s\n", results[0]);
			return Command::CMDInvalidArgs;
		}

		printf("ExchangeID, ProductID, InstrumentID, PriceTick, VolumeMultiple, UnderlyingIns, StrikePrice\n");

		for (auto ins : apiIns->GetInstruments(ExchangeID, ProductID, InstrumentID)) {
			printf("%s, %s, %s, %.2lf, %d, %s, %.2lf\n",
				ins->ExchangeID, ins->ProductID, ins->InstrumentID,
				ins->PriceTick, ins->VolumeMultiple,
				ins->UnderlyingInstrID, NORMAL_PRICE(ins->StrikePrice));
		}
	}
	else if (obj == "order") {
		std::string sysID = "";
		std::string orderRef = "";

		// TODO: parse orderRef & sysID in args

		printf("Status, SysID, OrderRef, ExchangeID, InstrumentID, Direction, LimitPrice, "
			"VolumeTotalOrigin, VolumeTraded, InsertDate, InsertTime, StatusMsg\n");

		for (auto ord : apiIns->GetOrders(orderRef, sysID)) {
			printf("%c, %s, %s, %s, %s, %c, %.2lf, %d, %d, %s, %s, %s\n",
				ord->OrderStatus, ord->OrderSysID, ord->OrderRef, 
				ord->ExchangeID, ord->InstrumentID, 
				ord->Direction, ord->LimitPrice, 
				ord->VolumeTotalOriginal, ord->VolumeTraded, 
				ord->InsertDate, ord->InsertTime, ord->StatusMsg);
		}
	}
	else if (obj == "position") {
		std::string ExchangeID = "";
		std::string ProductID = "";
		std::string InstrumentID = "";

		// TODO: parse args

		printf("ExchangeID, InstrumentID, Direction, YdPos, TdPos\n");

		for (auto pos : apiIns->GetPositions(ExchangeID, ProductID, InstrumentID)) {
			printf("%s, %s, %c, %d, %d\n",
				pos->ExchangeID, pos->InstrumentID, pos->PosiDirection,
				pos->YdPosition, pos->Position
			);
		}
	}
	else {
		fprintf(stderr, "invalid show instance: %s", obj.c_str());
		return Command::CMDInvalidArgs;
	}

	return 0;
}

int cmdPostWait(void* api, const std::vector<std::string>& args) {
	auto apiIns = ((TDUserApi*)api);

	apiIns->WaitResponse(100);

	return 0;
}

int cmdOrderNew(void* api, const std::vector<std::string>& args) {
	auto apiIns = ((TDUserApi*)api);
	auto instrument_id = args[0].c_str();
	CThostFtdcInputOrderField ord = { 0 };

	for (int idx = 1; idx < args.size(); idx++) {
		auto rtn = fill_order(ord, args[idx].c_str());
		
		if (rtn != Command::CMDSucceeded) {
			return rtn;
		}
	}

	// 自动判断平今、平昨
	if (ord.CombOffsetFlag[0] == THOST_FTDC_OF_Close) {
		auto insList = apiIns->GetInstruments("", "", instrument_id);

		if (insList.size() == 1 && (
				strcmp(insList[0]->ExchangeID, "SHFE") == 0 || 
				strcmp(insList[0]->ExchangeID, "INE") == 0))
		{
			auto posList = apiIns->GetPositions("", "", args[0]);
			
			if (posList.size() == 1 && posList[0]->Position > 0) {
				ord.CombOffsetFlag[0] = THOST_FTDC_OF_CloseToday;
			}
		}
	}

	/* mandatory fields for a new order below */
	strcpy_s(ord.BrokerID, apiIns->User.BrokerID);
	strcpy_s(ord.UserID, apiIns->User.UserID);
	strcpy_s(ord.InstrumentID, args[0].c_str());
	strcpy_s(ord.InvestorID, apiIns->User.UserID);
	// default value handle
	if (ord.OrderPriceType == 0) ord.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
	if (ord.CombOffsetFlag[0] == 0) ord.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
	if (ord.CombHedgeFlag[0] == 0) ord.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
	if (ord.TimeCondition == 0) ord.TimeCondition = THOST_FTDC_TC_GFD;
	if (ord.VolumeCondition == 0) ord.VolumeCondition = THOST_FTDC_VC_AV;
	if (ord.ContingentCondition == 0) ord.ContingentCondition = THOST_FTDC_CC_Immediately;
	if (ord.ForceCloseReason == 0) ord.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;

	return apiIns->ReqOrderInsert(&ord);
}

int cmdOrderModify(void* api, const std::vector<std::string>& args) {
	fprintf(stderr, "Not supported by CTP.\n");
	return Command::CMDInvalidArgs;
}

int cmdOrderCancel(void* api, const std::vector<std::string>& args) {
	std::string sysIDs = "";
	std::string orderRefs = "";

	for (int i = 0; i < args.size(); i++) {
		int count = 0;
		char** results = split(args[i].c_str(), count, '=');

		if (count != 2) {
			fprintf(stderr, "Invalid args: %s", args[i].c_str());
			return Command::CMDInvalidArgs;
		}

		if (strcmp(trim(results[0]), "SysID") == 0) {
			sysIDs = results[1];
			continue;
		}

		if (strcmp(trim(results[0]), "OrderRef") == 0) {
			orderRefs = results[1];
			continue;
		}

		fprintf(stderr, "Invalid arg key word: %s\n", results[0]);
		return Command::CMDInvalidArgs;
	}

	auto apiIns = ((TDUserApi*)api);

	auto orderList = apiIns->GetOrders(orderRefs, sysIDs);
	if (orderList.size() < 1) {
		fprintf(stderr, "No order found.\n");

		return Command::CMDInvalidArgs;
	}

	for (auto ord : orderList) {
		CThostFtdcInputOrderActionField ordAction = { 0 };
		strcpy_s(ordAction.BrokerID, ord->BrokerID);
		strcpy_s(ordAction.InvestorID, ord->InvestorID);
		strcpy_s(ordAction.UserID, ord->UserID);
		strcpy_s(ordAction.OrderSysID, ord->OrderSysID);
		strcpy_s(ordAction.ExchangeID, ord->ExchangeID);
		strcpy_s(ordAction.InstrumentID, ord->InstrumentID);
		ordAction.ActionFlag = THOST_FTDC_AF_Delete;

		apiIns->ReqOrderAction(&ordAction);
	}

	return 0;
}

bool getValueBool(std::string value) {
	size_t len = value.length();

	if (len < 1) {
		return false;
	}

	// mINI::INIStringUtil::toLower(value);

	if (len == 1) {
		return value.compare("y") == 0 || value.compare("t") == 0;
	}

	if (len == 3) {
		return value.compare("yes") == 0;
	}

	if (len == 4) {
		return value.compare("true") == 0;
	}

	return false;
}

int main(int argc, char* argv[]) {
	printf("CTP API Version: %s impl by CPP.\n", TDUserApi::GetApiVersion());
	printf("Working directory: %s\n", _getcwd(NULL, 0));

	char* confFile = (char *)"setting.ini";

	if (argc > 1) {
		size_t argLen = strlen(argv[1]);
		if (argLen > strlen(confFile)) {
			confFile = (char*)malloc(argLen + 1);
		}
		
		confFile[argLen] = 0;
		strncpy(confFile, argv[1], strlen(argv[1]));
	}

	FILE* fp;
	char errbuf[200] = {0};

	// 1. Read and parse toml file
	// fp = fopen(confFile, "r");
	// if (!fp) {
	// 	printf("cannot open %s: %s\n", confFile, strerror(errno));
	// 	exit(1);
	// }
	// 
	// toml_table_t* conf = toml_parse_file(fp, errbuf, sizeof(errbuf));
	// fclose(fp);
	// 
	// if (!conf) {
	// 	printf("cannot parse: %s\n", errbuf);
	// 	exit(2);
	// }
	// 
	// toml_table_t* front_info = toml_table_in(conf, "front_info");
	// if (!front_info) {
	// 	printf("no [front_info] section");
	// 	exit(3);
	// }
	// 
	// toml_datum_t address = toml_string_in(front_info, "Address");
	// toml_datum_t port = toml_int_in(front_info, "Port");


	// 加载配置文件
	// initial config file path.
	mINI::INIFile setting_file(confFile);

	// 创建ini结构体
	// 
	mINI::INIStructure ini;

	// 配置文件载入结构体解析
	// load ini config file & parse configuration
	setting_file.read(ini);

	const char* frontAddr = ini["front_info"]["Address"].c_str();
	const char* frontPort = ini["front_info"]["Port"].c_str();
	const bool isFens = getValueBool(ini["front_info"]["IsFens"]);

	// 连接字符串格式：tcp://IP:PORT 的最大长度为 6+15+1+5+1
	// conn string format: tcp://IP:PORT, max length 6+15+1+5+1.
	char conn[28] = {0};
	sprintf(conn, "tcp://%s:%s", frontAddr, frontPort);
	// sprintf(conn, "tcp://%s:%s", address.u.s, port.u.s);

	const char* brokerID = ini["login_info"]["BrokerID"].c_str();
	const char* userID = ini["login_info"]["UserID"].c_str();
	const char* userPass = ini["login_info"]["Password"].c_str();
	const char* appID = ini["login_info"]["AppID"].c_str();
	const char* authCode = ini["login_info"]["AuthCode"].c_str();
	const char* initPassword = ini["login_info"]["InitPassword"].c_str();

	TDUserApi *api = new(TDUserApi);

	Command cli = Command("CTP", api);

	CommandDefine versionCommand = { "version", "Print API's version info.", NULL, cmdVersion };
	CommandDefine exitCommand = { "exit", "Release API & EXIT.", NULL, cmdExit };
	CommandDefine showCommand = {
		"show", "Show query info.",
		"show {instrument|order|position} [args]", cmdShow };
	CommandDefine orderNewCommand = { 
		"new", "Make a limited price order.", 
		"new {instrumentid} {direction} {price} {volume} [close]", cmdOrderNew };
	CommandDefine orderModifyCommand = { 
		"modify", "Modify an exist order.", 
		"not supported by CTP system", cmdOrderModify };
	CommandDefine orderCancelCommand = { 
		"cancel", "Cancel an exist order.", 
		"cancel [SysID={id list}] [OrderRef={ref list}]", cmdOrderCancel };

	cli.AddCommand(&versionCommand);
	cli.AddExitCommand(&exitCommand);
	cli.AddCommand(&showCommand);
	cli.AddCommand(&orderNewCommand);
	cli.AddCommand(&orderModifyCommand);
	cli.AddCommand(&orderCancelCommand);

	// cli.RegisterPostCommand(cmdPostWait);

	api->CreateFtdcTraderApi(flowPath);
	api->SubscribePrivateTopic(THOST_TERT_QUICK);
	api->SubscribePublicTopic(THOST_TERT_QUICK);
	if (isFens) {
		CThostFtdcFensUserInfoField fens = { 0 };
		strncpy(fens.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
		strncpy(fens.UserID, userID, sizeof(TThostFtdcUserIDType) - 1);
		fens.LoginMode = THOST_FTDC_LM_Trade;

		api->RegisterFensUserInfo(&fens);
		api->RegisterNameServer(conn);
	}
	else {
		api->RegisterFront(conn);
	}
	api->Init();

	CThostFtdcReqAuthenticateField auth = { 0 };
	strncpy(auth.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType)-1);
	strncpy(auth.UserID, userID, sizeof(TThostFtdcUserIDType)-1);
	strncpy(auth.AppID, appID, sizeof(TThostFtdcAppIDType)-1);
	strncpy(auth.AuthCode, authCode, sizeof(TThostFtdcAuthCodeType)-1);
	api->ReqAuthenticate(&auth);
	printf("Send authentication: %s, %s, %s\n", brokerID, userID, appID);

	CThostFtdcReqUserLoginField login = { 0 };
	strncpy(login.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType)-1);
	strncpy(login.UserID, userID, sizeof(TThostFtdcUserIDType)-1);

	if (strlen(initPassword) != 0) {
		strncpy(login.Password, initPassword, sizeof(TThostFtdcPasswordType) - 1);
	}
	else {
		strncpy(login.Password, userPass, sizeof(TThostFtdcPasswordType) - 1);
	}
	api->ReqUserLogin(&login);
	printf("Send login: %s, %s\n", brokerID, userID);

	if (strlen(initPassword) != 0) {
		CThostFtdcUserPasswordUpdateField updPass = { 0 };
		
		strncpy(updPass.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
		strncpy(updPass.UserID, userID, sizeof(TThostFtdcUserIDType) - 1);
		strncpy(updPass.OldPassword, initPassword, sizeof(TThostFtdcPasswordType) - 1);
		strncpy(updPass.NewPassword, userPass, sizeof(TThostFtdcPasswordType) - 1);
		
		api->ReqUserPasswordUpdate(&updPass);
	}

	CThostFtdcQryInvestorPositionField qryPos = { 0 };
	/* not mandatory */
	// strncpy(qryPos.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	// strncpy(qryPos.InvestorID, userID, sizeof(TThostFtdcInvestorIDType) - 1);
	api->ReqQryInvestorPosition(&qryPos);
	printf("Quering investor's position.\n");

	CThostFtdcQryOrderField qryOdr = { 0 };
	/* not mandatory */
	// strncpy(qryOdr.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	// strncpy(qryOdr.InvestorID, userID, sizeof(TThostFtdcInvestorIDType) - 1);
	api->ReqQryOrder(&qryOdr);
	printf("Quering investor's orders.\n");

	CThostFtdcQryInstrumentField qryIns = { 0 };
	api->ReqQryInstrument(&qryIns);
	printf("Quering instrument info.\n");

	api->QueryMarginRateAll();
	// api->QueryCommRateAll();

	CThostFtdcQrySettlementInfoConfirmField settleConfirm = { 0 };
	memcpy(settleConfirm.BrokerID, brokerID, sizeof(TThostFtdcBrokerIDType) - 1);
	memcpy(settleConfirm.InvestorID, userID, sizeof(TThostFtdcInvestorIDType) - 1);
	api->ReqQrySettlementInfoConfirm(&settleConfirm);
	
	api->WaitSettlementConfirmed();

	cli.RunForever();
}