#include "TestEnvironment.h"

class TP_latex2xml: public test::TestingInterface {
public:
	TP_latex2xml ();
	~TP_latex2xml ();
	void preprocessing (void);
	void testprocessing (void);
	void postprocessing (void);
private:
	void testIntro ();
	void testExecutable ();
	void testLatex2png ();
};