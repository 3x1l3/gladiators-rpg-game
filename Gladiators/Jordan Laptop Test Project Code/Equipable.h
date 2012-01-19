/// \file
/// \brief Equipable Item Class header file
/// Defines the derived class Equippable items from base class item.
/// This class is pure abstract
/// \Author Chad Klassen, Altered by Adam Shepley
/// \date Further altered on November 24th.

#ifndef EQUIPABLE_H
#define EQUIPABLE_H

#include "Item.h"
#include "Item.h"
#include "Equipable.h"

class Equipable : public virtual Item {

private:
bool isEquipped; ///< Weather an item is equipped already.

public:
/// \brief Equipable Default Constructor
/// Initialize isEquipped to false
Equipable();

~Equipable();

/// \brief Sets the item as Equipped or Unequipped
/// Takes a true or fals and sets isEquipped to it.
void SetEquipStatus(bool newStatus);

/// \brief Lets the user know if an item is equipped.
/// Returns the boolean status of the item's equip status
bool ShowEquipStatus();

};

#endif
