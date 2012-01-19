#include <cppunit/TextTestRunner.h>

#include "WizardTester.h"
#include "UnitEquipmentTester.h"

int main()
{
    CppUnit::TextTestRunner runner;
    runner.addTest(WizardTest::suite());
    runner.addTest(UnitEquipTest::suite());
    runner.run();

    return 0;
}
