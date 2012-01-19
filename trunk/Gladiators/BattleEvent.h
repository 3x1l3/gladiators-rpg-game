#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include "Unit.h"
#include "Consumable.h"
#include "Menu.h"
#include "EnemyCharacter.h"
#include "Equipable.h"
#include "PlayerParty.h"
#include "EnemyParty.h"
#include "Weapon.h"
#include "Armor.h"
#include "BattleNumber.h"
#include "Money.h"
#include "GameData.h"
#include "BattleMenu.h"

#include "exceptions.h"


#include <vector>
using std::vector;

class BattleEvent{

	///set up for BattleEvent()
	///original coded by jordan peoples november 8th 2010

private:
	///holds possible enemy charcters, obtained from GameData
	std::vector <EnemyCharacter*> enemies;
	///integer to hold the current battle number, obtained from GameData
	unsigned battleNumber;
	///int to hold the current turn within the current battle
	unsigned currentTurn;
	///menu pointer to point to a ,menu.
	BattleMenu* battleMenu;




public:
	///default contrcutor
	BattleEvent()  throw();

	///destructor
	~BattleEvent() throw();

	///\brief print a display of enemy party
	///Outputs a quick referense display, showing the units in the enemy party by name and current hp / max hp
	void PrintEnemyParty() throw();

	void AIRun(const int currentEnemy) throw();

	void PrintAllTargets() throw();

	///will check to see if the players party is all dead
	bool IsPlayerPartyAlive() throw();

	///will check to see if the enemies party has been destoryed
	bool IsEnemyPartyAlive() throw();

	///iterate to the next players turn
	void ProceedToNextTurn() throw();

	///chec the state of the individual characters (dead or alive)
	///@param Unit unit to check the state of
	///@return players state
	void CheckCharacterState(Unit*) throw();

	///makes a new battle menu
	void ConstructBattleMenu() throw();

	///destroys the previoud battle menu if it exists
	void DestroyBattleMenu() throw();

	///creates a enemy part based on players party average level
	void CreateEnemyParty(const int enemyPartySize) throw();

	///Run will execute everythign in the class (make a battle scene)
	void Run() throw();

	///a function to create a random number of enemis based off of the player's party stats
	int EnemyPartySizer() throw();

	void HandleItemSelect() throw(invalid_menu_choice);


};
#endif
