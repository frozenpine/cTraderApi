#pragma once
#include <map>
#include <vector>
#include <string>

#include "TDUserApi.h"

struct CommandDefine {
	const char* command;
	const char* description;
	int (*commandHandler)(void* api, va_list args);
};

class Command
{
public:
	Command() { cmdInstance = nullptr; commandName = "CLI"; }
	Command(void* api) { 
		new (this)Command();
		
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

public:
	int AddCommand(CommandDefine* define);
	// int AddSubCommand(Command* subCommand);
	int RunCommand(std::string commandName, ...);
	void PrintCommands();
	void Start();
	void Exit();
};
