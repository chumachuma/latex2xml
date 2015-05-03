#include "stdafx.h"

#include "TP_latex2xml.h"
#include "Logger.h"
#include "executable.h"

TP_latex2xml::TP_latex2xml () {
}

TP_latex2xml::~TP_latex2xml () {
}

void TP_latex2xml::testIntro (void)
{
	log0("TITLE", "latex2xml");
	log0("DESC", "Transform latex code to a xml file with png images. \r\n The conversion is done in a two steps process \r\n And a post processing to create the xml file.");
	log0("STEP 01", "Use existing latex tools");
}

void TP_latex2xml::preprocessing (void)
{
	testIntro ();
}

void TP_latex2xml::testprocessing (){
	logI("Creating dummy program <echo> with default options <Hello World!>");
		WinExec winEcho = WinExec ("echo", "windows echo");
		winEcho.setDefaultOptions ("Hello World!");
	logD("Running echo with default parameter");
	logD("TERMINAL output 'Hello World!' below this sentence:");
		winEcho.run();
	logD("Running echo with 'Goodbye World!' as an option");
	logD("TERMINAL output 'Goodbye World!' below this sentence:");
		winEcho.run("Goodbye World!");
}

void TP_latex2xml::postprocessing (){
	std::cout << "postprocessing" << std::endl;
}