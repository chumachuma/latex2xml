#pragma once
#ifndef LATEX2PNG_IMPLEMENTATION_GIBEN_WORKING_PATH
#define LATEX2PNG_IMPLEMENTATION_GIBEN_WORKING_PATH

#include "executable.h"

class Latex2PNG
{
public:
	Latex2PNG (std::string latexpath);
	~Latex2PNG ();
	static void setLaTeXpath (std::string latexpath);
	/*
		Setter for the existing latex program
		Must be configured before instantiating the class
	*/
	static void setLaTeX2dviCommand (std::string command="latex.exe");
	/*
		Setter needed if the program used is different
		Must be configured before instantiating the class
	*/
	static void setdvi2pngCommand (std::string command="dvipng.exe");
	/*
		Setter needed if the program used is different
		Must be configured before instantiating the class
	*/
	int run(std::string inputFile);
private:
	std::string texExt;
	std::string dviExt;
	WinExec* LaTeX2dvi;
	WinExec* dvi2png;
	static std::string LaTeXpath;
	static std::string latexCommand;
	static std::string dvipngCommand;

	std::string removeFileExtension (std::string);
};

#endif