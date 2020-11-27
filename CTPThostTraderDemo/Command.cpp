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
	cmd = "";
	args.clear();

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

bool Command::AddExitCommand(CommandDefine* define)
{
	exitCmdName = define->command;
	return AddCommand(define);
}

int Command::RunCommand(std::string commandName, const std::vector<std::string>& args)
{
	if (!commandExist(commandName)) {
		return CMDUnknownCommand;
	}

	auto handler = commandTable.at(commandName)->handler;

	int rtn = (*handler)(cmdInstance, args);

	return rtn;
}

void Command::PrintCommands(std::string cmdName)
{
	if ("" == cmdName) {
		std::cout << std::endl << "Use \"help\" to show this command list again." << std::endl;
	}

	std::cout << std::endl << "Command List:" << std::endl;

	int cmdMaxSize = 0;

	for (std::string cmd : commandList) {
		if (cmd.size() > cmdMaxSize) {
			cmdMaxSize = cmd.size();
		}
	}

	for (int i = 0; i < commandList.size(); i++) {
		if ("" != cmdName && cmdName != commandList[i]) { continue; }

		auto define = commandTable.at(commandList[i]);
		
		std::cout
			<< std::setw(std::streamsize(cmdMaxSize) + 2) << std::setfill(' ') << define->command << "    "
			<< define->description << std::endl;
		if (NULL != define->usage) {
			std::cout
				<< std::setw(std::streamsize(cmdMaxSize) + 2 + 4) << std::setfill(' ') << " "
				<< "Usage: " << define->usage << std::endl;
		}
	}
}

void Command::Start(Command* instance)
{
	instance->PrintCommands();

	std::string inputs;
	std::string cmd;
	std::vector<std::string> args;

	while (instance->IsRunning()) {
		std::cout << instance->GetName() << " > ";
		
		std::getline(std::cin, inputs);

		Command::cmdlineSplit(inputs, cmd, args);

		if ("" == cmd) { 
			continue; 
		}

		if ("help" == cmd) { 
			instance->PrintCommands(); 
			continue; 
		}

		if (NULL != instance->cmdPreHandler) {
			(*instance->cmdPreHandler)(instance->cmdInstance, args);
		}

		if (instance->GetExitName() == cmd) { 
			instance->Exit(); 
		}

		int rtn = instance->RunCommand(cmd, args);

		switch (rtn)
		{
		case CMDSucceeded:
			break;
		case CMDUnknownCommand:
			std::cerr << "Unknown command: " << cmd << std::endl;
			break;
		case CMDInvalidArgs:
			instance->PrintCommands(cmd);
			break;
		default:
			std::cout << "Command return code: " << rtn << std::endl;
			break;
		}

		if (NULL != instance->cmdPostHandler) {
			(*instance->cmdPostHandler)(instance->cmdInstance, args);
		}
	}
}

void Command::Exit()
{
	running = false;
}

void Command::RunForever()
{
	running = true;
	
	std::thread tr = std::thread(Start, this);

	tr.join();
}
