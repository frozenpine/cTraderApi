#pragma once
#include <map>
#include <vector>
#include <string>

#include "TDUserApi.h"

struct CommandDefine {
	const char* command;
	const char* description;
	int (*commandHandler)(TDUserApi* api, va_list args);
};

class Command
{
public:
	Command() { tradeAPI = nullptr; commandName = "CLI"; }
	Command(TDUserApi* api) { 
		new (this)Command();
		
		tradeAPI = api; 
	}
private:
	std::string commandName;
	TDUserApi* tradeAPI;

	std::map<std::string, Command*> subCommands;
	std::map<std::string, CommandDefine*> commandTable;
	std::vector<std::string> commandList;

	bool commandExist(std::string commandName);
public:
	int AddCommand(CommandDefine* define);
	int AddSubCommand(Command* subCommand);
	int RunCommand(TDUserApi* api, std::string commandName, ...);
	// void Start();
	void PrintCommands();
};
