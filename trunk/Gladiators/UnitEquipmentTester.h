//****************************************************************************//
///\file
/// \brief Header file defining Test Fixture to run tests on the UnitEquipment class
///
/// \author Jason Racine
/// \date Dec 2, 2010
///
/// Developed for 2720 Gladiators game project
//****************************************************************************//
#ifndef UNIT_EQUIPMENT_TESTER_H
#define UNIT_EQUIPMENT_TESTER_H
///\file
///\brief This file contains the test class dericed from TestFixture

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "UnitEquipment.h"
#include "PlayerCharacter.h"
#include "GameData.h"

///Test Fixture to run tests on the Wizard class
class UnitEquipTest : public CppUnit::TestFixture
{

    ///macros to create the test suite
    CPPUNIT_TEST_SUITE(UnitEquipTest);
	
    //Add individual CPPUNIT_TEST() tests here
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testEquipUnequip);
    
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();		///<Create variables to be used in testing
        void tearDown();	///<Clean up any allocated variables
	void testConstructor(); ///<Test class constructor
	void testEquipUnequip();
	
    private:
	UnitEquipment* equip;
	
	
};

#endif