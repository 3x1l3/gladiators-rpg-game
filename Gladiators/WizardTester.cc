//****************************************************************************//
///\file
/// \brief Implementation of Test Fixture to run tests on the Wizard class
///
/// \author Jason Racine
/// \date Dec 2, 2010
///
/// Developed for 2720  Gladiators Game project
//****************************************************************************//

#include <cppunit/extensions/HelperMacros.h>
#include "Wizard.h"
#include "Unit.h"
#include "WizardTester.h"
#include "PlayerCharacter.h"
#include <sstream>

#include <iostream>

///\brief Create variables to be used in testing
///\pre Variables declared in header file are uninitialized
///\post Variavles are initialized
void WizardTest::setUp()
{
    wiz1 = new Wizard();
    pc = new PlayerCharacter();
    pc2 = new PlayerCharacter("George", 5, 50, 10, 10, "Paladin", 1, 2, 1, 1000);
}

///\brief Cleans up memory allocated to variables of the class
///\pre The variables of the class are initialized to some values
///\post The variables are deleted and the memory cleaned up
void WizardTest::tearDown()
{
    delete wiz1;
    delete pc;
    delete pc2;
}

///\brief Tests the constructors of the Wizard class
///Tests the constructor of the Wizard class and verifies that the
/// values of the attributes are as expected after the object is created.
void WizardTest::testWizardConstructor()
{
    std::string specialName("Arcane Blast");
    //If custPtr is null as it should be, this is what is printed from custPtr->write()
    std::string jobName("Wizard");
    
    CPPUNIT_ASSERT( jobName == wiz1->GetJobName() );

    CPPUNIT_ASSERT( specialName == wiz1->GetSpecialAttackName() );    
}

void WizardTest::testPlayerConstructor()
{
    CPPUNIT_ASSERT( "Nobody :'(" == pc->GetName() );
    CPPUNIT_ASSERT( 10 == pc->GetMaxHP() );
    CPPUNIT_ASSERT( 10 == pc->GetCurrentHP() );
    CPPUNIT_ASSERT( 10 == pc->GetAttackVal() );
    CPPUNIT_ASSERT( 10 == pc->GetDefenseVal() );
    CPPUNIT_ASSERT( 0 == pc->GetLevel() );
    CPPUNIT_ASSERT( "NORMAL" == pc->GetState() );
    
    //Right hand item
    CPPUNIT_ASSERT( "Fist" == pc->GetEquipment()->GetRightHandWeapon()->GetName() );
    CPPUNIT_ASSERT( "Your Fist" == pc->GetEquipment()->GetRightHandWeapon()->GetDescription() );
    CPPUNIT_ASSERT( 0 == pc->GetEquipment()->GetRightHandWeapon()->GetAttackValue() );
    CPPUNIT_ASSERT( 0 == pc->GetEquipment()->GetRightHandWeapon()->GetPrice() );
    
    
    //left hand item
    CPPUNIT_ASSERT( "Fist" == pc->GetEquipment()->GetLeftHandWeapon()->GetName() );
    CPPUNIT_ASSERT( "Your Fist" == pc->GetEquipment()->GetLeftHandWeapon()->GetDescription() );
    CPPUNIT_ASSERT( 0 == pc->GetEquipment()->GetLeftHandWeapon()->GetAttackValue() );
    CPPUNIT_ASSERT( 0 == pc->GetEquipment()->GetLeftHandWeapon()->GetPrice() );
    
    //chest item
    CPPUNIT_ASSERT( "Skin" == pc->GetEquipment()->GetChestArmor()->GetName() );
    CPPUNIT_ASSERT( "Your Skin" == pc->GetEquipment()->GetChestArmor()->GetDescription() );
    CPPUNIT_ASSERT( 0 == pc->GetEquipment()->GetChestArmor()->GetDefenseValue() );
    CPPUNIT_ASSERT( 0 == pc->GetEquipment()->GetChestArmor()->GetPrice() );
    
    CPPUNIT_ASSERT( pc->GetExperience() == 0);
    CPPUNIT_ASSERT( pc->GetJobName() == "Commoner");
    
    //Player 2, constructed by Constructor with Parameters
    
    CPPUNIT_ASSERT( "George" == pc2->GetName() );
    CPPUNIT_ASSERT( 50 == pc2->GetMaxHP() );
    CPPUNIT_ASSERT( 50 == pc2->GetCurrentHP() );
    CPPUNIT_ASSERT( 10 == pc2->GetAttackVal() );
    CPPUNIT_ASSERT( 10 == pc2->GetDefenseVal() );
    CPPUNIT_ASSERT( 5 == pc2->GetLevel() );
    CPPUNIT_ASSERT( "NORMAL" == pc2->GetState() );
    CPPUNIT_ASSERT( pc2->GetExperience() == 1000);
    CPPUNIT_ASSERT( pc2->GetJobName() == "Paladin");
    
    //Right hand item
    CPPUNIT_ASSERT( "Fist" == pc2->GetEquipment()->GetRightHandWeapon()->GetName() );
    CPPUNIT_ASSERT( "Your Fist" == pc2->GetEquipment()->GetRightHandWeapon()->GetDescription() );
    CPPUNIT_ASSERT( 0 == pc2->GetEquipment()->GetRightHandWeapon()->GetAttackValue() );
    CPPUNIT_ASSERT( 0 == pc2->GetEquipment()->GetRightHandWeapon()->GetPrice() );
    
}

void WizardTest::testAssigningJob()
{
    pc->SetJob( new Wizard() );
    CPPUNIT_ASSERT( pc->GetJobName() == "Wizard");
    
    pc->SetJob(wiz1);
    CPPUNIT_ASSERT( pc->GetJobName() == "Wizard");
}


void WizardTest::testIncreaseExperience()
{
    int xp = pc->GetExperience();
    pc->IncreaseExperience( 100 );
    CPPUNIT_ASSERT( pc->GetExperience() == xp + 100);
    pc->IncreaseExperience( -3 );
    CPPUNIT_ASSERT( pc->GetExperience() == xp + 100);
}

void WizardTest::testHP()
{
    int maxHP = pc->GetMaxHP();
    pc->SetMaxHP(maxHP + 100);
    CPPUNIT_ASSERT(pc->GetMaxHP() == maxHP + 100);
    
    pc->SetCurrentHP(200);
    CPPUNIT_ASSERT(pc->GetCurrentHP() == 200);
    
    pc->TakeDamage(100);
    CPPUNIT_ASSERT(pc->GetCurrentHP() == 100);
    
    pc->SetMaxHP(500);
    CPPUNIT_ASSERT(pc->GetMaxHP() == 500);
    pc->SetCurrentHP(100);
    pc->RecieveHealing(150, pc->GetState());
    CPPUNIT_ASSERT(pc->GetCurrentHP() == 250);
    
    pc->RecieveHealing(50000000, pc->GetState());
    CPPUNIT_ASSERT(pc->GetCurrentHP() == 500);
    
    pc->TakeDamage(9000 + 1);
    CPPUNIT_ASSERT(pc->GetCurrentHP() == 0);
    CPPUNIT_ASSERT(pc->GetState() == "DEAD");
    
    pc->MakeAlive();
    CPPUNIT_ASSERT(pc->GetState() == "NORMAL");
    
}

void WizardTest::testLevelUp()
{
    pc->SetLevel(1);
    int hp = pc->GetMaxHP();
    int atk = pc->GetAttackVal();
    int def = pc->GetDefenseVal();
    
    pc->SetJob(new Wizard());
    pc->LevelUp();
    
    CPPUNIT_ASSERT(pc->GetLevel() == 2);
    CPPUNIT_ASSERT(pc->GetMaxHP() == hp + 40);
    CPPUNIT_ASSERT(pc->GetAttackVal() == atk + 8);
    CPPUNIT_ASSERT(pc->GetDefenseVal() == def + 3);
    CPPUNIT_ASSERT(pc->GetCurrentHP() == hp + 40);
    CPPUNIT_ASSERT(pc->GetCurrentHP() == pc->GetCurrentHP() );
}
