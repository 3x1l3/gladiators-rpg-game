/// \file
/// \brief Equipable Item Class header file
/// Defines the derived class Equippable items from base class item.
/// This class is pure abstract
/// \Author Chad Klassen, Altered by Adam Shepley
/// \date Further altered on November 24th.

#ifndef EQUIPABLE_H
#define EQUIPABLE_H

#include "Item.h"

class Equipable : public virtual Item {

private:
bool isEquipped; ///< Weather an item is equipped already.
unsigned equipedQuantity;
unsigned quantity;

public:
/// \brief Equipable Default Constructor
/// Initialize isEquipped to false
Equipable() throw();

~Equipable() throw();

/// \brief Sets the item as Equipped or Unequipped
/// Takes a true or fals and sets isEquipped to it.
void SetEquipStatus(const bool newStatus) throw();

/// \brief Lets the user know if an item is equipped.
/// Returns the boolean status of the item's equip status
bool GetEquipStatus() throw();

///\brief Returns how many of the items remain that can be equipped
unsigned GetEquipedQuantity() throw();

///\brief Changes how many of quantities of the item can be equipped
void SetEquipedQuantity(const unsigned val) throw();
///\brief Decreases how many items are considered equiped
void DecrementEquipedQuantity() throw();
///\brief Increases how many items are equiped if there are free items
void IncrementEquipedQuantity() throw();

///\brief Decreases quantity of item owned if there are some not equipped
void DecrementQuantity() throw();
///\brief Increases quantity of item owned
void IncrementQuantity() throw();
///\brief accessor telling the quantity of the item owned
unsigned GetQuantity() throw();
 
///\brief set the total quantity of the item owned
void SetQuantity(const unsigned val) throw();

///\brief Returns true if there remain items owned that are not equipped, false otherwise.
bool Usable() throw();

};

#endif
