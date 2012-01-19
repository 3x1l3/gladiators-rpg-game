/*********************************************************
/// \file
/// \brief Implimentation file for the Weapon Class
///
/// The implimentation for the functions defined in Weapon.h
///
/// A class that defines a weapon.
/// Currently, weapons differentiate by attackvalue only.
/// Inside the parent, Item, their other attributes are set.
///
/// \author Adam Shepley
/// \date November 24th, 2010
*******************************************************/

#include "Weapon.h"

Weapon::Weapon()
{
    Item::SetName("Default Weapon");
    Item::SetDescription("This is a Weapon");
    Item::SetPrice(99999);
    Equipable::SetEquipStatus(false);
    attackValue = 999999999;
}

Weapon::Weapon(const string name, const string description, const int price, const int attackVal)
{
      Item::SetName(name);
      Item::SetDescription(description);
      Item::SetPrice(price);
      Equipable::SetEquipStatus(false);
      attackValue = attackVal;
}

Weapon::~Weapon()
{
    
}

void Weapon::ChangeAttackValue(const int & newValue)
{
    attackValue = newValue;

}

int& Weapon::GetAttackValue()
{
    return attackValue;
}
