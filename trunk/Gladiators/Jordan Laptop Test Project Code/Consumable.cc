#include "Consumable.h"


Consumable::Consumable()
{
     
}

Consumable::~Consumable()
{
}
int Consumable::GetEffectValue() {
  return this->effectValue;
}
 
void Consumable::SetEffectValue(const int& effectvalue) {
  this->effectValue = effectvalue;
}
