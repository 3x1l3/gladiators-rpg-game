#include "Menu.h"

Menu::Menu() throw() {
	
}

Menu::~Menu() throw() {
	
}

void Menu::AddMenuItem(const std::string& menuItem) throw() {
  this->menuitems.push_back(menuItem);
}

void Menu::DeleteMenuItem(const int& index) throw() {
  this->menuitems.erase( menuitems.begin() + index); //Quick fix... kekeke
}

void Menu::Clear() throw() {
  this->menuitems.clear();
}

void Menu::DrawMenu() throw() {
  
  std::vector<std::string>::iterator it;
  int counter = 1;
  for(it = this->menuitems.begin(); it != this->menuitems.end(); ++it) {
    std::cout << counter << ". " <<  (*it) << std::endl;
      counter++;
  }

}
