//****************************************************************************//
///\file
/// \brief Implementation of Test Fixture to run tests on the UnitEquipment class
///
/// \author Jason Racine
/// \date Dec 2, 2010
///
/// Developed for 2720  Gladiators Game project
//****************************************************************************//

#include <cppunit/extensions/HelperMacros.h>
#include "UnitEquipmentTester.h"
#include <sstream>

#include <iostream>

///\brief Create variables to be used in testing
///\pre Variables declared in header file are uninitialized
///\post Variavles are initialized
void UnitEquipTest::setUp()
{
    equip = new UnitEquipment();
}

///\brief Cleans up memory allocated to variables of the class
///\pre The variables of the class are initialized to some values
///\post The variables are deleted and the memory cleaned up
void UnitEquipTest::tearDown()
{
    
}

void UnitEquipTest::testConstructor()
{
   //right hand weapon
   CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetName() == "Fist");
   CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDescription() == "Your Fist");
   CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetAttackValue() == 0 );
   CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDefenseValue() == 0 );
   CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetPrice() == 0 );
   
   //left hand weapon
   CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetName() == "Fist");
   CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDescription() == "Your Fist");
   CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetAttackValue() == 0 );
   CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDefenseValue() == 0 );
   CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetPrice() == 0 );
   
   //chest armor
   CPPUNIT_ASSERT(equip->GetChestArmor()->GetName() == "Skin" );
   CPPUNIT_ASSERT(equip->GetChestArmor()->GetDescription() == "Your Skin" );
   CPPUNIT_ASSERT(equip->GetChestArmor()->GetDefenseValue() == 0 );
   CPPUNIT_ASSERT(equip->GetChestArmor()->GetPrice() == 0 );
   
   
}

void UnitEquipTest::testEquipUnequip()
{
    //** RIGHT HAND **//
  
    //unequip and check that values are properly default
    equip->UnequipRightHand();
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetName() == "Fist");
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDescription() == "Your Fist");
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetAttackValue() == 0 );
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetPrice() == 0 );
    
    //Create a weapon and equip to right hand
    Weapon* mywep = new Weapon("Warglaive", "Illidari blade", 0, 0, 0);
    mywep->IncrementQuantity(); //needed so does not throw exception due to insufficient quantity
    equip->EquipRightHand(mywep);
    //assert that values are as expected
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetName() == "Warglaive");
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDescription() == "Illidari blade");
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetAttackValue() == 0 );
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetPrice() == 0 );
    //unequip and check that values are again default
    equip->UnequipRightHand();
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetName() == "Fist");
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDescription() == "Your Fist");
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetAttackValue() == 0 );
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetRightHandWeapon()->GetPrice() == 0 );
    
    //** LEFT HAND **//
    
        //unequip and check that values are properly default
    equip->UnequipRightHand();
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetName() == "Fist");
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDescription() == "Your Fist");
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetAttackValue() == 0 );
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetPrice() == 0 );
    
    //Create a weapon and equip to right hand
    Weapon* mywep2 = new Weapon("Warglaive", "Illidari blade", 0, 0, 0);
    mywep2->IncrementQuantity(); //needed so does not throw exception due to insufficient quantity
    equip->EquipLeftHand(mywep2);
    //assert that values are as expected
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetName() == "Warglaive");
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDescription() == "Illidari blade");
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetAttackValue() == 0 );
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetPrice() == 0 );
    //unequip and check that values are again default
    equip->UnequipLeftHand();
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetName() == "Fist");
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDescription() == "Your Fist");
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetAttackValue() == 0 );
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetLeftHandWeapon()->GetPrice() == 0 );
    
    
    //** CHEST ARMOR **//
    equip->UnequipChestArmor();
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetName() == "Skin" );
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetDescription() == "Your Skin" );
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetPrice() == 0 );
    
    Armor* myArm = new Armor("Armoire of Invincibility", "It's kind of heavy...", 0, 1000);
    myArm->IncrementQuantity();
    equip->EquipChestArmor(myArm);
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetName() == "Armoire of Invincibility");
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetDescription() == "It's kind of heavy...");
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetDefenseValue() == 1000);
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetPrice() == 0 );
    
    equip->UnequipChestArmor();
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetName() == "Skin" );
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetDescription() == "Your Skin" );
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetDefenseValue() == 0 );
    CPPUNIT_ASSERT(equip->GetChestArmor()->GetPrice() == 0 );
    
    delete mywep;
    delete mywep2;
}