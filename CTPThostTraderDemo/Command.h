#pragma once
#include <map>
#include <vector>
#include <iomanip>
#include <string>

#include "TDUserApi.h"

struct CommandDefine {
	const char* command;
	const char* description;
	int (*commandHandler)(void* api, int argCount, va_list args);
};

class Command
{
public:
	Command(void* api) {
		commandName = "CLI";

		cmdInstance = api;
	}
private:
	std::string commandName;
	void* cmdInstance;

	// std::map<std::string, Command*> subCommands;
	std::map<std::string, CommandDefine*> commandTable;
	std::vector<std::string> commandList;

	bool running;

	bool commandExist(std::string commandName);
	const int unknownCommandCode = 255;

	void cmdlineSplit(
		const std::string& input, 
		std::string& cmd, 
		std::vector<std::string>& tokens, 
		const std::string& delimiters = " ");
public:
	bool AddCommand(CommandDefine* define);
	// int AddSubCommand(Command* subCommand);
	int RunCommand(std::string commandName, int argCount, ...);
	void PrintCommands();
	void Start();
	void Exit();
};
