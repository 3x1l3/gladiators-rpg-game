#include<iostream>
#include<string>
#include<vector>
#include "pugixml.h"
#include "XMLWrapper.h"




XMLWrapper::XMLWrapper(const std::string& filename) {
  result = doc.load_file(filename.c_str());
}

std::string XMLWrapper::getResult() {
  std::string val = result.description();
  return val;
}

bool XMLWrapper::isValid(std::string type) {
  std::string first_child = doc.first_child().name();
  std::string attribute = doc.first_child().first_attribute().value();
  return (first_child == "GLAD" && attribute==type?true:false);
}

void XMLWrapper::LoadSaveFile() {

  if(!isValid("save")) {
    return;
  }

  pugi::xml_node glad = doc.first_child();
  pugi::xml_node inventory = glad.child("Inventory");
  pugi::xml_node weapons = inventory.child("Weapons");
  pugi::xml_node armor = inventory.child("Armor");
  pugi::xml_node consumeable = inventory.child("Consumeable");
  pugi::xml_node party = glad.child("Party");
  pugi::xml_node character = party.child("Character");
  
  //Get Money Values
  money = atoi(glad.child("Money").child_value());
  
  //Get Battle Number
  battlenumber = atoi(glad.child("BattleNumber").child_value());
  //Iterate through Character nodes to grab all information
  std::vector<std::string> characterVec;
  pugi::xml_node charnode = character;

  for ( ; charnode; charnode = charnode.next_sibling()) {
  
    std::string nameVal = charnode.child("Name").child_value();
    std::string levelVal = charnode.child("Level").child_value();
    std::string attackVal = charnode.child("Attack").child_value();
    std::string defenceVal = charnode.child("Defence").child_value();
    //If more values need to be loaded add them here.
    pugi::xml_node equipment = charnode.child("Equipment");
    std::string lefthandVal = equipment.child("LeftHand").child_value();
    std::string righthandVal = equipment.child("RightHand").child_value();
    std::string chestVal = equipment.child("Chest").child_value();
    std::string hpVal = charnode.child("HP").child_value();
    std::string experienceVal = charnode.child("Experience").child_value();
    std::string jobVal = charnode.child("Job").child_value();
    
    characterVec.push_back(nameVal);
    characterVec.push_back(levelVal);
    characterVec.push_back(hpVal);
    characterVec.push_back(attackVal);
    characterVec.push_back(defenceVal);
    characterVec.push_back(jobVal);
    characterVec.push_back(lefthandVal);
    characterVec.push_back(righthandVal);
    characterVec.push_back(chestVal);
    characterVec.push_back(experienceVal);
    
    characters.push_back(characterVec);
    
    characterVec.clear();
  }

  //Load Inventory
  std::string weaponsVal = weapons.child_value();
  std::string armorVal = armor.child_value();
  std::string consumableVal = consumeable.child_value();

  //Devide Inventory into indecies
  std::vector<int> weaponsVec = explodetoInts(weaponsVal, ",");
  std::vector<int> armorVec = explodetoInts(armorVal, ",");
  std::vector<int> consumableVec = explodetoInts(consumableVal, ",");

  items.push_back(weaponsVec);
  items.push_back(armorVec);
  items.push_back(consumableVec);
  
}


std::vector<int> XMLWrapper::explodetoInts (std::string original, std::string exploder=".") {
	std::string tmp;
	tmp=original;
	int num, loc;
	num=1;
	while (tmp.find(exploder)!=std::string::npos) {
		loc=tmp.find(exploder);
		tmp=tmp.substr(loc+exploder.length());
		num++;
		}
	std::vector<int> result;
	num=0;
	tmp=original;
	while (tmp.find(exploder)!=std::string::npos) {
		loc=tmp.find(exploder);
		std::string tmpsubstr = tmp.substr(0,loc);
		result.push_back(atoi(tmpsubstr.c_str()));
		tmp=tmp.substr(loc+exploder.length());
		num++;
		}
	result.push_back(atoi(tmp.c_str()));
	
	return result;


}

std::vector<std::vector<int> > XMLWrapper::getItemVector() {
  return items;
}

std::vector<std::vector<std::string> > XMLWrapper::getCharacterVector() {
  return characters;
}

int XMLWrapper::getMoney() {
  return money;
}

int XMLWrapper::getBattleNumber() {
  return battlenumber;
}

/*
void XMLWrapper::LoadItemFile() {

}

void XMLWrapper::LoadEnemyFile() {

}*/
