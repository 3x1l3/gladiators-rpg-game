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
//#include "Item.h"
#include <string>


using std::string;

Armor::Armor() throw()
{
    Item::SetName("Default Armor");
    Item::SetDescription("The Ultimate Default Armor! A Codpiece.");
    Item::SetPrice(99999);
    Equipable::SetEquipStatus(false);
    defenseValue = 9999999;
}

Armor::Armor(const string name, const string description, const int price, const int defVal) throw()
{
      Item::SetName(name);
      Item::SetDescription(description);
      Item::SetPrice(price);
      Equipable::SetEquipStatus(false);
      defenseValue = defVal;
}

Armor::~Armor() throw()
{

}

void Armor::ChangeDefenseValue(const int& newDefense) throw()
{
    defenseValue = newDefense;
}

int& Armor::GetDefenseValue() throw()
{
    return defenseValue;
}
