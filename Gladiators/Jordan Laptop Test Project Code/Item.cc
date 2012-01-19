#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
             
}

void Item::SetName(const std::string& name) {
  this->name = name; 
}

void Item::SetDescription(const std::string& description) {
  this->description = description;
}

void Item::SetPrice(const int& price) {
  this->price = price;
}

std::string Item::GetName() {
  return this->name;
}

std::string Item::GetDescription() {
  return this->description;
}

int Item::GetPrice() {
  return this->price;
}
