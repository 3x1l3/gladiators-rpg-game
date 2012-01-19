/*********************************************************
/// \file
/// \brief Implimentation file for the UnitEquipment class
///
/// This class houses the equipment held by a Unit
/// (player character or enemy)
/// And allows the user to remove or add equipment to said
/// character.
///
/// There are also extendable options included, but these
/// functions are not utilized in the current version of
/// the game and as such they are commented out.
///
/// \author Adam Shepley
/// \date November 23rd, 2010
*******************************************************/
#include <string>

#include "UnitEquipment.h"
#include "Armor.h"
#include "Weapon.h"
#include "Unit.h"

using std::string;

UnitEquipment::UnitEquipment()
{
    rightHand = new Weapon();
    leftHand = new Weapon("fuck", "ass", 9001, 1456);
    chest = new Armor();
    
    fist = new Weapon("Fist", "Your Fist", 0, 0);
    skin = new Armor("Skin", "Your Skin", 0, 0);

}

UnitEquipment::~UnitEquipment()
{
    delete rightHand;
    delete leftHand;
    delete chest;
    delete fist;
    delete skin;
}

void UnitEquipment::UnequipRightHand()
{
    if(rightHand != NULL)
    {
        rightHand->SetEquipStatus(false);
        rightHand = fist;
    }
}

void UnitEquipment::EquipRightHand(Weapon* weaponAddress)
{
    UnequipRightHand();
    rightHand = weaponAddress;//////////////////////////////////////////////////////////
    rightHand->SetEquipStatus(true);
}

void UnitEquipment::UnequipLeftHand()
{
    if(leftHand != NULL)
    {
        leftHand->SetEquipStatus(false);

        leftHand = fist;

    }
}

void UnitEquipment::EquipLeftHand(Weapon* weaponAddress)
{
    UnequipLeftHand();
    leftHand = weaponAddress;////////////////////////////////////////////////////////////////////////
    leftHand->SetEquipStatus(true);
}

void UnitEquipment::UnequipArmor()
{
    if(chest != NULL)
    {
        chest->SetEquipStatus(false);
        chest = skin;
    }

}

void UnitEquipment::EquipArmor(Armor* armorAddress)
{
    UnequipArmor();
    chest = armorAddress;
    chest->SetEquipStatus(true);
}

void UnitEquipment::AddEquipableWeaponPoint(const string& weaponBodyPoint)
{
}

void UnitEquipment::AddEquipableArmorPoint(const string& armorBodyPoint)
{
}

Weapon* UnitEquipment::GetRightHandWeapon()
{
    return rightHand;        
}

Weapon* UnitEquipment::GetLeftHandWeapon()
{
    return leftHand;
}

Armor* UnitEquipment::GetChestArmor()
{
    return chest;
}
