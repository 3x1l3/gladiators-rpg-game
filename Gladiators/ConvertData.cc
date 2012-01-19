#include "ConvertData.h"

ConvertData::ConvertData(const std::vector<std::vector<int> > initems, const std::vector<std::vector<std::string> > incharacters) throw() {
  items = initems;
  characters = incharacters;
}
ConvertData::~ConvertData() throw ()
{
  //delete party;
}
void ConvertData::BuildParty() throw() {

  party = new PlayerParty();
  PlayerCharacter* pc = NULL;
  for(unsigned int i=0; i<characters.size(); i++) {
    pc = new PlayerCharacter(characters[i][0], atoi(characters[i][1].c_str()), atoi(characters[i][2].c_str()), atoi(characters[i][3].c_str()), atoi(characters[i][4].c_str()), characters[i][5], atoi(characters[i][6].c_str()), atoi(characters[i][7].c_str()), atoi(characters[i][8].c_str()), atoi(characters[i][9].c_str()));

    party->AddMember(pc);
  }

}

std::vector<Weapon* > ConvertData::BuildWeapons(const std::vector<Weapon* > allWeapons) throw() {

  for(unsigned int i=0; i<items[0].size(); i++) {
    this->weapons.push_back(allWeapons.at(items[0][i]));

    weapons.at(i)->IncrementQuantity();
  }

  return this->weapons;

}

std::vector<Armor* > ConvertData::BuildArmor(const std::vector<Armor* > allArmor) throw() {
  for(unsigned int i=0; i<items[1].size(); i++) {
    this->armor.push_back(allArmor.at(items[1][i]));
    armor.at(i)->IncrementQuantity();
  }

  return this->armor;
}

std::vector<Consumable*> ConvertData::BuildConsumables(const std::vector<Consumable*> allConsumables) throw() {
  for(unsigned int i=0; i<items[2].size(); i++) {
    this->consumable.push_back(allConsumables.at(items[2][i]));
  }

  return this->consumable;
}

PlayerParty* ConvertData::getParty() throw() {
  return party;
}
std::vector<Weapon*> ConvertData::getWeapons() throw() {
  return weapons;
}
std::vector<Armor*> ConvertData::getArmor() throw() {
  return armor;
}
std::vector<Consumable*> ConvertData::getConsumable() throw() {
  return consumable;
}
