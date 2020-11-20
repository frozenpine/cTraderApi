#include <iostream>
#include <condition_variable>

#include "Command.h"


bool Command::commandExist(std::string commandName)
{
	return 
		(commandTable.find(commandName) != commandTable.end()) /*&& 
		(subCommands.find(commandName) != subCommands.end())*/;
}

void Command::cmdlineSplit(
	const std::string& input, 
	std::string& cmd, 
	std::vector<std::string>& args, 
	const std::string& delimiters)
{
	std::string::size_type lastPos = input.find_first_not_of(delimiters, 0);
	std::string::size_type pos = input.find_first_of(delimiters, lastPos);
	
	int tokenCount = 0;
	std::string token;
	while (std::string::npos != pos || std::string::npos != lastPos) {
		token = input.substr(lastPos, pos - lastPos);
		
		if (0 == tokenCount++) {
			cmd = token;
		}
		else {
			args.push_back(token);
		}

		lastPos = input.find_first_not_of(delimiters, pos);

		pos = input.find_first_of(delimiters, lastPos);
	}
}

bool Command::AddCommand(CommandDefine* define)
{
	std::string commandName = std::string(define->command);

	if (commandExist(commandName)) {
		std::cerr << "Command " << define->command << " is already exist." << std::endl;
		return false;
	}
	
	commandTable.insert(std::make_pair(commandName, define));
	commandList.push_back(commandName);

	return true;
}

/*
int Command::AddSubCommand(Command* subCommand)
{
	return 0;
}
*/

int Command::RunCommand(std::string commandName, int argCount, ...)
{
	if (!commandExist(commandName)) {
		return unknownCommandCode;
	}

	auto handler = commandTable.at(commandName)->commandHandler;

	va_list args;
	va_start(args, commandName);

	int rtn = (*handler)(cmdInstance, argCount, args);

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

void Command::Start()
{
	running = true;
	PrintCommands();

	std::string inputs;
	std::string cmd;
	std::vector<std::string> args;

	while (running) {
		std::cout << commandName << " > ";
		
		std::getline(std::cin, inputs);

		cmdlineSplit(inputs, cmd, args);

		if ("exit" == cmd) {
			Exit();

			continue;
		}

		// TODO: 需要修复vector到可变长参数的转换
		if (unknownCommandCode == RunCommand(cmd, args.size(), args.data())) {
			std::cout << "Unknown command: " << cmd << std::endl;
		}
	}
}

void Command::Exit()
{
	RunCommand("exit", 0);

	running = false;
}
