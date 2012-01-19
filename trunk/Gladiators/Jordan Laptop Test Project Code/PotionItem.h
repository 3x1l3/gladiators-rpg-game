#ifndef POTIONITEM_H
#define POTIONITEM_H

#include "Consumable.h"
#include "State.h"

/// \file 
/// \brief Defines the potion item header file
/// Derives from the consumable class. Items from this class are considered healing items.
/// Therefore it is appropriate to say that potions have a heal value. Units consume these
/// items in order to regain health.

class PotionItem : public virtual Consumable {

private:

public:
/// \brief Potion Item Default Constructor
/// Sets the healValue to a default. Inorder for it to be used.
PotionItem(std::string name, std::string description, int value, int healValue);
/// \brief Use Potion Item
/// Use the current potion item on a unit. This will heal them. Will this also 
/// destroy the item from memory?
/// We send in the state of the unit so the user can select and use items on...
/// ...a dead unit if they choose too.
/// \pre Item must be in the inventory of unit
/// \post Item must remove itself from the inventory
/// \param [in] unit to heal
/// \param [in] state of the current unit
void Use(Unit* unit);


};

#endif
