#pragma once
#include <map>
#include <vector>
#include <iomanip>
#include <string>

#include "TDUserApi.h"

struct CommandDefine {
	const char* command;
	const char* description;
	const char* usage;
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

	void cmdlineSplit(
		const std::string& input, 
		std::string& cmd, 
		std::vector<std::string>& tokens, 
		const std::string& delimiters = " ");
public:
	static const int CMDUnknownCommand = 255;
	static const int CMDInvalidArgs = 250;
public:
	bool AddCommand(CommandDefine* define);
	bool AddExitCommand(CommandDefine* define);
	
	int RunCommand(std::string commandName, const std::vector<std::string>& args);
	void PrintCommands(std::string cmdName = "");
	
	void Start();
	void Exit();
};
