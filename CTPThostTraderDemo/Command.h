#pragma once
#include <map>
#include <vector>
#include <iomanip>
#include <string>

#include "TDUserApi.h"

struct CommandDefine {
	const char* command;
	const char* description;
	int (*commandHandler)(void* api, const std::vector<std::string>&);
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
	std::string exitCmdName;
	void* cmdInstance;

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
	bool AddExitCommand(CommandDefine* define);
	
	int RunCommand(std::string commandName, const std::vector<std::string>& args);
	void PrintCommands();
	
	void Start();
	void Exit();
};
