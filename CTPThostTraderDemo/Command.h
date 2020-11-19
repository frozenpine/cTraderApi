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
	Command() {};
private:
	std::map<std::string, CommandDefine*> commandTable;
	std::vector<std::string> commandList;

	bool commandExist(std::string commandName);
public:
	void AddCommand(CommandDefine* define);
	int RunCommand(TDUserApi* api, std::string commandName, ...);
	// void Start();
	void PrintCommands();
};
