#ifndef TESTENVIRONMENT_V00_BASE_INTERFACE_FOR_TESTING
#define TESTENVIRONMENT_V00_BASE_INTERFACE_FOR_TESTING
#define TESTENVIRONMENT_VERSION 000

class TestingInterface {
public:
	TestingInterface (void) {};
	virtual ~TestingInterface (void) {};
	virtual void preprocessing (void)=0;
	virtual void testprocessing (void)=0;
	virtual void postprocessing (void)=0;
	void run () {preprocessing(); testprocessing(); postprocessing();};
};

#endif