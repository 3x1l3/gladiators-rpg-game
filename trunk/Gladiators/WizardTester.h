//****************************************************************************//
///\file
/// \brief Header file defining Test Fixture to run tests on the Wizard class
///
/// \author Jason Racine
/// \date Dec 2, 2010
///
/// Developed for 2720 Gladiators game project
//****************************************************************************//
#ifndef WIZARD_TESTER_H
#define WIZARD_TESTER_H
///\file
///\brief This file contains the test class dericed from TestFixture

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Wizard.h"
#include "PlayerCharacter.h"
#include "GameData.h"

///Test Fixture to run tests on the Wizard class
class WizardTest : public CppUnit::TestFixture
{

    ///macros to create the test suite
    CPPUNIT_TEST_SUITE(WizardTest);
	
    //Add individual CPPUNIT_TEST() tests here
    CPPUNIT_TEST(testWizardConstructor);
    CPPUNIT_TEST(testPlayerConstructor);
    CPPUNIT_TEST(testAssigningJob);
    CPPUNIT_TEST(testIncreaseExperience);
    CPPUNIT_TEST(testHP);
    CPPUNIT_TEST(testLevelUp);
    
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();		///<Create variables to be used in testing
        void tearDown();	///<Clean up any allocated variables
        void testWizardConstructor();	///<Test the Wizard constructor methods.
	void testPlayerConstructor(); 	///<Test PlayerCharacter constructor.
	void testAssigningJob();	///<Test Setting the job to an already created Player Character
	void testIncreaseExperience(); ///<Test that Increase Experience works properly
	void testHP();
	void testLevelUp();
	
    private:
	Wizard* wiz1;		
	PlayerCharacter* pc;
	PlayerCharacter* pc2;
	
};

#endif
