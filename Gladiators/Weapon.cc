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
    Item::SetPrice(100);
    Equipable::SetEquipStatus(false);
    attackValue = 10;
    defenseValue = 10;
}

Weapon::Weapon(const std::string name, const std::string description, const int price, const int attackVal, const int defenseVal)
{
      Item::SetName(name);
      Item::SetDescription(description);
      Item::SetPrice(price);
      Equipable::SetEquipStatus(false);
      attackValue = attackVal;
      defenseValue = defenseVal;
}

Weapon::~Weapon()
{
    
}

void Weapon::ChangeAttackValue(const int & newValue)
{
    attackValue = newValue;

}

void Weapon::ChangeDefenseValue(const int & newValue)
{
    defenseValue = newValue;

}

int& Weapon::GetAttackValue()
{
    return attackValue;
}

int& Weapon::GetDefenseValue()
{
    return defenseValue;
}

bool Weapon::operator==(Weapon* otherWeapon)
{
    return ( this->GetAttackValue() == otherWeapon->GetAttackValue() &&
	     this->GetName() == otherWeapon->GetName() &&
	     this->GetDescription() == otherWeapon->GetDescription() &&
	     this->GetPrice() == otherWeapon->GetPrice() );
}

Weapon Weapon::operator=(Weapon origWeapon)
{
    Weapon wpn;
    wpn.SetName(origWeapon.GetName());
    wpn.SetPrice(origWeapon.GetPrice());
    wpn.SetDescription(origWeapon.GetDescription());
    wpn.attackValue = wpn.attackValue;
    return wpn;
}