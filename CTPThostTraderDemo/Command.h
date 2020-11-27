#pragma once
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <thread>

#include "TDUserApi.h"

typedef int (*CmdHandler)(void* api, const std::vector<std::string>&);

struct CommandDefine {
	const char* command;
	const char* description;
	const char* usage;
	CmdHandler handler;
};

class Command
{
public:
	Command() { 
		name = "CLI";

		cmdInstance = NULL;
		cmdPreHandler = NULL;
		cmdPostHandler = NULL;
	}
	Command(void* api) {
		new (this)Command();

		cmdInstance = api;
	}
	Command(std::string cmdName, void* api) {
		new (this)Command(api);

		name = cmdName;
	}
private:
	std::string name;
	std::string exitCmdName;
	void* cmdInstance;

	std::map<std::string, CommandDefine*> commandTable;
	std::vector<std::string> commandList;

	CmdHandler cmdPreHandler;
	CmdHandler cmdPostHandler;

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

	void RegisterPreCommand(CmdHandler handler) { cmdPreHandler = handler; };
	void RegisterPostCommand(CmdHandler handler) { cmdPostHandler = handler; };
	
	int RunCommand(std::string commandName, const std::vector<std::string>& args);
	void PrintCommands(std::string cmdName = "");
	
	void Exit();
	void RunForever();
};
