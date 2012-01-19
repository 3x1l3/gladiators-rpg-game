#include "ConvertData.h"

ConvertData::ConvertData(std::vector<std::vector<int> > initems, std::vector<std::vector<std::string> > incharacters) {
  items = initems;
  characters = incharacters;
}

void ConvertData::BuildParty() {

  party = new Party();
  PlayerCharacter* pc = NULL;
  for(int i=0; i<characters.size(); i++) {
    unit = new PlayerCharacter(characters[i][0], characters[i][1], characters[i][2], characters[i][3], characters[i][4], characters[i][5], characters[i][6], characters[i][7], characters[i][8], characters[i][9]);

    party->addMember(unit);
  }
  
}

Inventory* ConvertData::BuildWeapons(const Inventory* allWeapons) {
  Inventory* weapons = new Inventory();
  int index = 0;
  for(int i=0; i<items[0].size(); i++) {
    index = atoi(items[0][i]);
    weapons.AddItem(&allWeapons.at(index)); 
  }

  return weapons;

}

Inventory* ConvertData::BuildArmor(const Inventory* allArmor) {
  Inventory* armor = new Inventory();
  int index = 0;
  for(int i=0; i<items[0].size(); i++) {
    index = atoi(items[0][i]);
    armor.AddItem(&allWeapons.at(index)); 
  }

  return armor;
}

Inventory* ConvertData::BuildConsumables(const Inventory* allConsumables) {
  Inventory* consumables = new Inventory();
  int index = 0;
  for(int i=0; i<items[0].size(); i++) {
    index = atoi(items[0][i]);
    consumables.AddItem(&allWeapons.at(index)); 
  }

  return consumables;
}

Party* ConvertData::getParty() {
  return party;
}
Inventory* ConvertData::getWeapons() {
  return weapons;
}
Inventory* ConvertData::getArmor() {
  return armor;
}
Inventory* ConvertData::getConsumable() {
  return consumable;
}
