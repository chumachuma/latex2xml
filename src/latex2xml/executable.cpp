#include "stdafx.h"

#include "executable.h"

WinExec::WinExec (std::string command, std::string name): executableCommand(command), name(name)
{
}

WinExec::~WinExec ()
{
}

int WinExec::run (std::string options)
{
	std::string fullCommand = getCommand() + " ";
	if (options.empty())
		fullCommand += getOptions();
	else
		fullCommand += options;
	system (fullCommand.c_str());
	return 0;
}

void WinExec::setDefaultOptions (std::string options)
{
	this->options = options;
}

std::string WinExec::getCommand ()
{
	return executableCommand;
}
std::string WinExec::getOptions ()
{
	return options;
}
