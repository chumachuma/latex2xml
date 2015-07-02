#include "stdafx.h"

#include "executable.h"
#include "latex2png.h"

std::string Latex2PNG::LaTeXpath = "";
std::string Latex2PNG::latexCommand = "";
std::string Latex2PNG::dvipngCommand = "";

Latex2PNG::Latex2PNG (std::string latexpath)
{
	texExt = ".tex";
	dviExt = ".dvi";
	setLaTeXpath (latexpath);
	LaTeX2dvi = new WinExec (LaTeXpath + "\\" + "latex.exe", "latex2dvi");
	dvi2png = new WinExec (LaTeXpath + "\\" + "dvipng.exe", "dvi2png");
}

Latex2PNG::~Latex2PNG ()
{
	delete LaTeX2dvi;
	delete dvi2png;
	LaTeX2dvi = 0;
	dvi2png = 0;
}

void Latex2PNG::setLaTeXpath (std::string latexpath)
{
	LaTeXpath = latexpath;
}

void Latex2PNG::setLaTeX2dviCommand (std::string command)
{
	latexCommand = command;
}

void Latex2PNG::setdvi2pngCommand (std::string command)
{
	dvipngCommand = command;
}

std::string Latex2PNG::removeFileExtension (std::string fileName)
{
	int dotIndex = fileName.find_first_of(".");
	if ( dotIndex == std::string::npos )
		return fileName;
	else
		return fileName.substr(0, dotIndex);

}

int Latex2PNG::run(std::string inputFile)//TODO
{
	std::string inputFileName = removeFileExtension(inputFile);
	LaTeX2dvi->run(inputFileName + texExt);
	dvi2png->run(inputFileName + dviExt + " -T tight -D 120 -z 9 -bg Transparent");
	return 0;
}