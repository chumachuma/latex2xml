#pragma once
#ifndef EXECUTABLE_IMPLEMENTATION_FOR_WIN_SYSTEM
#define EXECUTABLE_IMPLEMENTATION_FOR_WIN_SYSTEM

#include <string>

class WinExec {
public:
	WinExec (std::string command, std::string name = "");
	~WinExec ();
	int run (std::string options="");
	void setDefaultOptions (std::string options="");
protected:
	std::string name;
	std::string executableCommand;
	std::string options;
	std::string getCommand ();
	std::string getOptions ();
};

#endif
