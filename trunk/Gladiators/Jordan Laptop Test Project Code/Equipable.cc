/******************************************************
/// \file
/// \brief Implimentation file for the Equipable Abstract Class
///
/// The implimentation for the lone Setter and Getter in Equipable.h
///
/// A class that defines the Equipable items parent class.
/// Sub of Item.h
///
/// \author Adam Shepley
/// \date November 24th, 2010
*******************************************************/

#include "Equipable.h"

void Equipable::SetEquipStatus(bool newStatus)
{
    isEquipped = newStatus;
}

bool Equipable::ShowEquipStatus()
{
    return isEquipped;
}

Equipable::Equipable()
{
                          
}

Equipable::~Equipable()
{
     
}
