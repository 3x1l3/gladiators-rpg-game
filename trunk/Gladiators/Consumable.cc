
#include "Consumable.h"


Consumable::Consumable() throw()
{

}

Consumable::~Consumable() throw()
{
}
int Consumable::GetEffectValue() throw()
{
  return this->effectValue;
}

void Consumable::SetEffectValue(const int& effectvalue) throw()
{
  this->effectValue = effectvalue;
}
