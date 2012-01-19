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
//#include "Item.h"

//#include "Item.cc"

void Equipable::SetEquipStatus(const bool newStatus) throw()
{
    isEquipped = newStatus;
}

bool Equipable::GetEquipStatus() throw()
{
    return isEquipped;
}

Equipable::Equipable() throw()
{
    quantity = 0;
    equipedQuantity = 0;
}

Equipable::~Equipable() throw()
{

}

void Equipable::SetEquipedQuantity(const unsigned val) throw()
{
    equipedQuantity = val;
}

unsigned Equipable::GetEquipedQuantity() throw()
{
    return equipedQuantity;
}

bool Equipable::Usable() throw()
{
    return (quantity > equipedQuantity);
}

void Equipable::SetQuantity(const unsigned val) throw()
{
    quantity = val;
}

unsigned Equipable::GetQuantity() throw()
{
    return quantity;
}

void Equipable::DecrementQuantity() throw()
{
    if(this->Usable())
        quantity--;
}

void Equipable::IncrementQuantity() throw()
{    
    quantity++;
}

void Equipable::DecrementEquipedQuantity() throw()
{
    equipedQuantity--;
}

void Equipable::IncrementEquipedQuantity() throw()
{
    if(this->Usable())
        equipedQuantity++;
}
