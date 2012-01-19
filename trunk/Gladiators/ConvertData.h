///\file
///\brief Converts data loaded from XML save file.
/// Converts data loaded from an external XML save file to be stored
/// in internal data structures.

#ifndef CONVERT_DATA_H
#define CONVERT_DATA_H

#include<vector>
#include<string>
#include "PlayerCharacter.h"
#include "PlayerParty.h"
#include "Unit.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"
#include<stdio.h>
#include<stdlib.h>

class ConvertData {

 private:
  std::vector<std::vector<int> > items;
  std::vector<std::vector<std::string> > characters;
  PlayerParty* party;
  std::vector<Weapon* > weapons;
  std::vector<Armor* > armor;
  std::vector<Consumable* > consumable;

 public:
  ConvertData(const std::vector<std::vector<int> >, const std::vector<std::vector<std::string> >)  throw();
  ~ConvertData() throw();
  void Run() throw();
  ///\brief Construct player party from save file data
  void BuildParty() throw();
  ///\brief Builds the player's Weapon inventory from save data
  std::vector<Weapon* > BuildWeapons(const std::vector<Weapon*>) throw();
  ///\brief Builds the player's Armor inventory from save data
  std::vector<Armor* > BuildArmor(const std::vector<Armor *>) throw();
  ///\brief Builds the player's Consumable inventory from save data
  std::vector<Consumable* > BuildConsumables(const std::vector<Consumable*>) throw();
  
  //Accessors
  ///\brief Accessor for the PlayerParty object created by the data conversion
  PlayerParty* getParty() throw();
  ///\brief Accessor for the Weapon inventory created by the data conversion
  std::vector<Weapon*> getWeapons() throw();
  ///\brief Accessor for the Armor inventory created by the data conversion
  std::vector<Armor*> getArmor() throw();
  ///\brief Accessor for the Consumable inventory created by the data conversion
  std::vector<Consumable*> getConsumable() throw();


};
#endif
