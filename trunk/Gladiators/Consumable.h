/// \file
/// \brief Defines the Consumable header file
/// The counter part to the Equipable header file. This class defines items that
/// can be consumed by units. Derived from the item class. Pure virtual abstract
/// class.

#ifndef CONSUMABLE_H
#define CONSUMABLE_H


#include "Item.h"

#include "Unit.h"


//#include "State.h"

class Unit;

class Consumable : public virtual Item {

 protected:
  int effectValue;
 public:
/// \brief Consumeable Default Constructor
/// Do nothing for default construction.
 Consumable() throw();

 virtual ~Consumable() throw();
/// \brief Pure Use Method
/// In derived classes this method should be overridden for use. Simply
/// just to use the item.
/// We send in the state sothe user can use items on dead characters if they want too
/// @param unit The unit we want to use the item on
 virtual void Use(Unit * unit) = 0;

 /// Get the effect value
 /// \return Integer representing effect value
 int GetEffectValue() throw();

 /// Set the effect value
 /// \param [in] effectvalue
 void SetEffectValue(const int& effectvalue) throw();

};

#endif
