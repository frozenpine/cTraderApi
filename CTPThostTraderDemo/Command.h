#pragma once
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <thread>

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
		name = "CLI";

		cmdInstance = api;
	}
private:
	std::string name;
	std::string exitCmdName;
	void* cmdInstance;

	std::map<std::string, CommandDefine*> commandTable;
	std::vector<std::string> commandList;

	bool running;

	bool commandExist(std::string commandName);
public:
	static const int CMDSucceeded = 0;
	static const int CMDUnknownCommand = 255;
	static const int CMDInvalidArgs = 250;
	static void Start(Command* instance);
	static void cmdlineSplit(
		const std::string& input,
		std::string& cmd,
		std::vector<std::string>& tokens,
		const std::string& delimiters = " ");
public:
	std::string GetName() { return name; }
	bool IsRunning() { return running; }
	std::string GetExitName() { return exitCmdName; }
	
	bool AddCommand(CommandDefine* define);
	bool AddExitCommand(CommandDefine* define);
	
	int RunCommand(std::string commandName, const std::vector<std::string>& args);
	void PrintCommands(std::string cmdName = "");
	
	void Exit();
	void RunForever();
};
