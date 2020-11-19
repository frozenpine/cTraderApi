#include <iostream>
#include <iomanip>

#include "Command.h"

bool Command::commandExist(std::string commandName)
{
	return 
		(commandTable.find(commandName) != commandTable.end()) && 
		(subCommands.find(commandName) != subCommands.end());
}

int Command::AddCommand(CommandDefine* define)
{
	std::string commandName = std::string(define->command);

	if (commandExist(commandName)) {
		std::cerr << "Command " << define->command << " is already exist." << std::endl;
		return 1;
	}
	
	commandTable.insert(std::make_pair(commandName, define));
	commandList.push_back(commandName);

	return 0;
}

int Command::AddSubCommand(Command* subCommand)
{
	return 0;
}

int Command::RunCommand(TDUserApi* api, std::string commandName, ...)
{
	if (!commandExist(commandName)) {
		return 255;
	}

	auto handler = commandTable.at(commandName)->commandHandler;

	va_list args;
	va_start(args, commandName);

	int rtn = (*handler)(api, args);

	va_end(args);

	return rtn;
}

void Command::PrintCommands()
{
	std::cout << "Command List:" << std::endl;

	for (int i = 0; i < commandList.size(); i++) {
		auto define = commandTable.at(commandList[i]);
		
		std::cout
			<< std::setw(2) << std::setfill('0') << i+1 << ". "
			<< define->command << ": "
			<< define->description << std::endl;
	}
}
