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

UnitEquipment::UnitEquipment() throw()
{
    fist = new Weapon("Fist", "Your Fist", 0, 0, 0);
    skin = new Armor("Skin", "Your Skin", 0, 0);

    rightHand = fist;
    leftHand = fist;
    chest = skin;
}

UnitEquipment::~UnitEquipment() throw()
{
    delete rightHand;
    delete leftHand;
    delete chest;
    delete fist;
    delete skin;
}

void UnitEquipment::UnequipRightHand() throw()
{
    if(rightHand != NULL)
    {
        rightHand->DecrementEquipedQuantity();
        rightHand->SetEquipStatus(false);
        rightHand = fist;
    }
}

void UnitEquipment::EquipRightHand(Weapon* weaponAddress) throw(unable_to_equip)
{
	if(weaponAddress->Usable())
	{
	    UnequipRightHand();
            rightHand = weaponAddress;//////////////////////////////////////////////////////////
            rightHand->IncrementEquipedQuantity();
	    rightHand->SetEquipStatus(true);
	}
	else
	{
	    throw unable_to_equip("Item is already equiped");
	}
}

void UnitEquipment::UnequipLeftHand() throw()
{
    if(leftHand != NULL)
    {
        leftHand->SetEquipStatus(false);
	leftHand->DecrementEquipedQuantity();
        leftHand = fist;

    }
}

void UnitEquipment::EquipLeftHand(Weapon* weaponAddress) throw(unable_to_equip)
{
    if(weaponAddress->Usable())
    {
	UnequipLeftHand();
	leftHand = weaponAddress;////////////////////////////////////////////////////////////////////////
	leftHand->IncrementEquipedQuantity();
	leftHand->SetEquipStatus(true);
    }
    else
    {
        throw unable_to_equip("Item is already equiped");
    }
}

void UnitEquipment::UnequipChestArmor() throw()
{
    if(chest != NULL)
    {
        chest->SetEquipStatus(false);
	chest->DecrementEquipedQuantity();
        chest = skin;
    }

}

void UnitEquipment::EquipChestArmor(Armor* armorAddress) throw (unable_to_equip)
{
    if(armorAddress->Usable())
    {   
        UnequipChestArmor();
        chest = armorAddress;
	chest->IncrementEquipedQuantity();
        chest->SetEquipStatus(true);
    }
    else
    {
        throw unable_to_equip("Item is already equiped");
    }
}

//Not Yet Implemented
void UnitEquipment::AddEquipableWeaponPoint(const string& weaponBodyPoint) throw()
{
}
//Not Yet Implemented
void UnitEquipment::AddEquipableArmorPoint(const string& armorBodyPoint) throw()
{
}

Weapon* UnitEquipment::GetRightHandWeapon() throw()
{
    return rightHand;        
}

Weapon* UnitEquipment::GetLeftHandWeapon() throw()
{
    return leftHand;
}

Armor* UnitEquipment::GetChestArmor() throw()
{
    return chest;
}
