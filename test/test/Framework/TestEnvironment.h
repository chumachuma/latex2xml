#ifndef TESTENVIRONMENT_V00_BASE_INTERFACE_FOR_TESTING
#define TESTENVIRONMENT_V00_BASE_INTERFACE_FOR_TESTING
#define TESTENVIRONMENT_VERSION 000

#include "Logger.h"
#include "PreProMacros.h"

namespace test {

class TestingInterface {
public:
	TestingInterface (void) {};
	virtual ~TestingInterface (void) {};
	virtual void preprocessing (void)=0;
	virtual void testprocessing (void)=0;
	virtual void postprocessing (void)=0;
	void run () {
		logI("START PREPROCESSING"); preprocessing(); logI("END PREPROCESSING\r\n" hline); 
		logI("START TESTPROCESSING"); testprocessing(); logI("END TESTPROCESSING\r\n" hline); 
		logI("START POSTPROCESSING"); postprocessing(); logI("END POSTPROCESSING\r\n" hline);
	};
};

}

#endif