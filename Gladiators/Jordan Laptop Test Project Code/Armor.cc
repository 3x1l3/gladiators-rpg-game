/******************************************************
/// \file
/// \brief Implimentation file for the Armor Item Class
///
/// The implimentation for the functions defined in Armor.h
///
/// A class that defines an equippable armor.
/// Currently, armor differentiate by defensevalue only.
/// Inside the parent, Item, their other attributes are set.
///
/// \author Adam Shepley
/// \date November 24th, 2010
*******************************************************/

#include "Armor.h"
#include "Equipable.h"
#include "Item.h"
#include <string>

using std::string;

Armor::Armor()
{
    Item::SetName("Default Armor");
    Item::SetDescription("The Ultimate Default Weapon! A Codpiece.");
    Item::SetPrice(99999);
    Equipable::SetEquipStatus(false);
    defenseValue = 9999999;
}

Armor::Armor(string name, string description, int price, int defVal)
{
      Item::SetName(name);
      Item::SetDescription(description);
      Item::SetPrice(price);
      Equipable::SetEquipStatus(false);
      defenseValue = defVal;
}

Armor::~Armor()
{
                  
}

void Armor::ChangeDefenseValue(const int& newDefense)
{
    defenseValue = newDefense;
}

int& Armor::GetDefenseValue()
{
    return defenseValue;
}
