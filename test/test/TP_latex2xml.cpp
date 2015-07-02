#include "stdafx.h"
#include <direct.h>

#include "TP_latex2xml.h"
#include "Logger.h"
#include "executable.h"
#include "latex2png.h"

TP_latex2xml::TP_latex2xml ()
{
}

TP_latex2xml::~TP_latex2xml ()
{
}

void TP_latex2xml::preprocessing (void)
{
	testIntro ();
}

void TP_latex2xml::testIntro (void)
{
	log0("TITLE", "latex2xml");
	log0("DESC", "Transform latex code to a xml file with png images. \r\n The conversion is done in a two steps process \r\n And a post processing to create the xml file.");
	log0("STEP 01", "Use existing latex tools");
	/*
	Configurables:
		latexpath
		latex.exe command
		dvipng.exe command
	*/
}

void TP_latex2xml::testprocessing ()
{
	log0("STEP 01", "BEGIN");
		testExecutable ();
		testLatex2png ();
	log0("STEP 01", "END");
}

void TP_latex2xml::testExecutable ()
{
	logI("Creating dummy program <echo> with default options <Hello World!>");
		WinExec winEcho = WinExec ("echo", "windows echo");
		winEcho.setDefaultOptions ("Hello World!");
	logD("Running echo with default parameter");
	logD("TERMINAL output 'Hello World!' below this sentence:");
		winEcho.run();
	logD("Running echo with 'Goodbye World!' as an option");
	logD("TERMINAL output 'Goodbye World!' below this sentence:");
		winEcho.run("Goodbye World!");

	std::string hardcodedLatexPath = "D:\\PROGRA~1\\LATEX\\miktex-portable-2.9.4757\\miktex\\bin\\latex.exe";
	logI("Create latex program in:\r\n" + hardcodedLatexPath);
		WinExec winLatex = WinExec (hardcodedLatexPath, "latex");
	logD("Run latex with:\r\nNewtonBinomial.tex");
		winLatex.run("NewtonBinomial.tex");	
	logD("Manual check for dvi file");
}

void testDirectories ()
{
	WinExec winEcho = WinExec ("echo", "windows echo");
	winEcho.setDefaultOptions ("Hello World!");
}

void TP_latex2xml::testLatex2png ()
{
	std::string hardcodedLatexPath = "D:\\PROGRA~1\\LATEX\\miktex-portable-2.9.4757\\miktex\\bin";
	std::string texfile01 = "NewtonBinomial";

	logI("The current path of LaTeX executables is found in:\r\n" + 
		hardcodedLatexPath);
	logW("This is really hardcoded");
		//Latex2PNG* winLatex2PNG = new Latex2PNG (hardcodedLatexPath);
		Latex2PNG winLatex2PNG(hardcodedLatexPath);

	logI("Test latex2png on:\r\n" + texfile01);
	logD("Simple run of the program");
	logW("Beware of the input and output path of the file");
		winLatex2PNG.run(texfile01);
	logD("Manual check for dvi and png files");

	logI("Verify that program runs given the correct file extension");
	winLatex2PNG.run(texfile01);

	logI("Verify that program does not execute if file does not exists");

	logW("Need testing: , file extension, paths, existing files, configuration, input/outputs, options, problems with spaces");

}

void TP_latex2xml::postprocessing ()
{
	std::cout << "postprocessing" << std::endl;
}