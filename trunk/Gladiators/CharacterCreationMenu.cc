#include "CharacterCreationMenu.h"
#include "Archer.h"
#include "Paladin.h"
#include "Wizard.h"
#include <stdlib.h>
//#include "PlayerCharacter.h"



#include <string>
#include <iostream>

using std::cin;
using std::cout;

CharacterCreationMenu::CharacterCreationMenu() throw() : Menu()
{
  this->party = new PlayerParty();
}


CharacterCreationMenu::~CharacterCreationMenu() throw()
{

}


CharacterCreationMenu::CharacterCreationMenu(const int maxChar) throw() : Menu()
{
  this->party = new PlayerParty();
  this->maxCharacters = maxChar;
}

void CharacterCreationMenu::HandleInput() throw()
{

}

void CharacterCreationMenu::HandleInput2(PlayerCharacter* pc, const int& choice, const std::string charactername) throw()
{
      //pc = new PlayerCharacter();
      pc->SetName(charactername);

      GameData::GetInstance()->GetPlayerConsumeInv()->push_back(GameData::GetInstance()->GetAllConsume().at(0));
      GameData::GetInstance()->GetPlayerConsumeInv()->push_back(GameData::GetInstance()->GetAllConsume().at(0));
      GameData::GetInstance()->GetPlayerConsumeInv()->push_back(GameData::GetInstance()->GetAllConsume().at(0));
      GameData::GetInstance()->GetPlayerConsumeInv()->push_back(GameData::GetInstance()->GetAllConsume().at(0));

    switch (choice)
      {
      case 1:
	pc->SetJob(new Archer());

			  //Adjust the player inventory vectors and their associated quantities
			  GameData::GetInstance()->GetPlayerWeaponInv()->push_back(GameData::GetInstance()->GetAllWeapons().at(5));
			  GameData::GetInstance()->GetPlayerWeaponInv()->back()->IncrementQuantity();
			  GameData::GetInstance()->GetPlayerArmorInv()->push_back(GameData::GetInstance()->GetAllArmor().at(4));
			  GameData::GetInstance()->GetPlayerArmorInv()->back()->IncrementQuantity();

			  //Equip the Weapons and Armor to the player
			  pc->GetEquipment()->EquipRightHand(GameData::GetInstance()->GetAllWeapons().at(5));
			  pc->GetEquipment()->UnequipLeftHand();
			  pc->GetEquipment()->EquipChestArmor(GameData::GetInstance()->GetAllArmor().at(4));

			  //std::cerr << pc->GetEquipment()->GetChestArmor()->GetName() << std::endl;
	break;
      case 2:
	pc->SetJob(new Paladin());

			  //Set the items to the player inventory, increment amounts to 1
			  GameData::GetInstance()->GetPlayerWeaponInv()->push_back(GameData::GetInstance()->GetAllWeapons().at(0));
			  GameData::GetInstance()->GetPlayerWeaponInv()->back()->IncrementQuantity();
			  GameData::GetInstance()->GetPlayerWeaponInv()->push_back(GameData::GetInstance()->GetAllWeapons().at(1));
			  GameData::GetInstance()->GetPlayerWeaponInv()->back()->IncrementQuantity();
			  GameData::GetInstance()->GetPlayerArmorInv()->push_back(GameData::GetInstance()->GetAllArmor().at(4));
			  GameData::GetInstance()->GetPlayerArmorInv()->back()->IncrementQuantity();

			  //Equip the Items on the Player Character
			  pc->GetEquipment()->EquipRightHand(GameData::GetInstance()->GetAllWeapons().at(0));
			  pc->GetEquipment()->EquipLeftHand(GameData::GetInstance()->GetAllWeapons().at(1));
			  pc->GetEquipment()->EquipChestArmor(GameData::GetInstance()->GetAllArmor().at(4));
	break;
      case 3:
	pc->SetJob(new Wizard());

			  //Put the items in the inventory and let them know there's only 1...
			  GameData::GetInstance()->GetPlayerWeaponInv()->push_back(GameData::GetInstance()->GetAllWeapons().at(6));
			  GameData::GetInstance()->GetPlayerWeaponInv()->back()->IncrementQuantity();
			  GameData::GetInstance()->GetPlayerArmorInv()->push_back(GameData::GetInstance()->GetAllArmor().at(4));
			  GameData::GetInstance()->GetPlayerArmorInv()->back()->IncrementQuantity();

			  //equip the items to the player characters
			  pc->GetEquipment()->EquipRightHand(GameData::GetInstance()->GetAllWeapons().at(6));
			  pc->GetEquipment()->UnequipLeftHand();
			  pc->GetEquipment()->EquipChestArmor(GameData::GetInstance()->GetAllArmor().at(4));

	break;
      }

}

PlayerParty* CharacterCreationMenu::GetParty() throw()
{
  return party;
}

void CharacterCreationMenu::Run() throw()
{
  std::string charactername, jobChoice;
  int choice;
  PlayerCharacter* pc = new PlayerCharacter();


    Menu::AddMenuItem("Archer");
    Menu::AddMenuItem("Paladin");
    Menu::AddMenuItem("Wizard");



  for(int i=0; i < this->maxCharacters; i++) {
    //std::cerr << i;
    std::cout << "Enter Character Name: " << std::endl;



    getline(std::cin, charactername);

    do {
      Menu::DrawMenu();

      getline(std::cin, jobChoice);
      choice = atoi(jobChoice.c_str());
    }
    while (choice > 3 || choice < 1);

    HandleInput2(pc, choice, charactername);

    pc->LevelUp();
    this->party->AddMember(pc);
    GameData::GetInstance()->GetMoney()->SetMoney(200);
    pc = new PlayerCharacter();
    //cin.clear();



    //Filling the current new units hp



    //
    //
    //
    //
    //
    //
    //
    //

    }
 GameData::GetInstance()->SetPlayerParty(party);
}
