#include "Item.h"

Item::Item()  throw()
{
}

Item::~Item() throw()
{
             
}

void Item::SetName(const std::string& name) throw() {
  this->name = name; 
}

void Item::SetDescription(const std::string& description) throw() {
  this->description = description;
}

void Item::SetPrice(const int& price) throw() {
  this->price = price;
}

std::string Item::GetName() throw() {
  return this->name;
}

std::string Item::GetDescription() throw() {
  return this->description;
}

int Item::GetPrice() throw() {
  return this->price;
}

bool Item::operator==(Item* otherItem) throw()
{
    return ( this->GetName() == otherItem->GetName() &&
	     this->GetDescription() == otherItem->GetDescription() &&
	     this->GetPrice() == otherItem->GetPrice() );
}

Item Item::operator=(Item origItem) throw()
{
    Item itm;
    itm.name = origItem.name;
    itm.price = origItem.price;
    itm.description = origItem.description;
    return itm;
}
