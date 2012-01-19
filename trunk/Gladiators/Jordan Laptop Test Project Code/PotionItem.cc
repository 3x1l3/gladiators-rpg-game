#include "Consumable.h"


PotionItem::PotionItem(std::string name, std::string description, int value, int healValue)
{
   Item::SetName(name);
   Item::SetDescription(description);
   Item::SetPrice(value);
   Consumable::SetEffectValue(healValue);

}
//------------------------------------------------------------------------------
//this function takes in a pointer to the unit to apply the items effects to...
//...and a state pointer that is the current state of the unit
//this in turns calls the recieve healing function of the unit casue we are a potion ...
//...and send in the current potions heal value and the state of the unit.
//we send state in so users can use a potion on a dead character with no effect if they want
void PotionItem::Use(Unit* unit) 
{
    //see above comments
    unit->RecieveHealing(Consumable::effectValue, unit->GetState());
}
