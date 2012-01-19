#ifndef GAMEDATA_H
#define GAMEDATA_H

///\file Defines the object that holds all of the game's data.

#include "Money.h"
#include "BattleNumber.h"
#include "PlayerParty.h"
#include "EnemyParty.h"
#include "XMLWrapper.h"
#include "ConvertData.h"
#include "CharacterCreationMenu.h"
#include "PotionItem.h"
#include "Weapon.h"
#include <map>
#include <vector>
#include <sstream>
#include <string>

#define MAX_PARTY_SIZE 5
using std::vector;


class GameData
{
    private:
        ///\brief Default constructor
	///Default constructor for GameData object. Private to comply with Singleton Pattern.
	//Will set all Values of GameData object to default values
	GameData() throw();

	///\brief Destructor
	~GameData() throw();
	///Make the Copy Constructor Private
	GameData(const GameData&) throw() {};

	///\brief Overload assignment operator
	/// Make the assignment operator Private as well
	GameData operator=(const GameData& copy) throw() { return copy; };
	//private variables

	//initially not created
	static bool created;

	//instance is a pointer to the GameData object
	static GameData * instance;

    //Wrapper classes
	Money*                     money;  		///<Money for the player
	BattleNumber*              battleNumber;	///<Current battle number
	PlayerParty*               playerParty;		///<Party of player character units
	EnemyParty*                enemyParty; 		///<Party of enemy character units

	//Vectors of information.
	//decided not to do wrapper classes here casue they wouldbe super
	//redundant, with only the vector types changed bwtween them.
	std::vector <Consumable*>       playerConsumableInventory;
	std::vector <Armor*>            playerArmorInventory;
	std::vector <Weapon*>           playerWeaponInventory;
	std::vector <Consumable*>       allConsumable;
	std::vector <Armor*>            allArmor;
	std::vector <Weapon*>           allWeapon;

	std::vector <bool> WeaponEquipStatus;
	std::vector <bool> ArmorEquipStatus;


	//All enemy parties in the game by level they are encountered;
	std::map<int, EnemyParty*> EnemiesByLevel;

    public:
	//public Methods

	//Accessors (getters)
	Money*                     	GetMoney()  throw();
	BattleNumber*               	GetBattleNumber() throw();
	PlayerParty*               	GetPlayerParty() throw();
	EnemyParty*                 	GetEnemyParty() throw();
	std::vector <Consumable*>*  	GetPlayerConsumeInv() throw();
	std::vector <Armor*>*           GetPlayerArmorInv() throw();
	std::vector <Weapon*>*          GetPlayerWeaponInv() throw();
	std::vector <Consumable*>       GetAllConsume() throw();
	std::vector <Armor*>            GetAllArmor() throw();
	std::vector <Weapon*>           GetAllWeapons() throw();


	//Settlers (settlers)
	void SetMoney(Money * money) throw();
	void SetBattleNumber(BattleNumber * number) throw();
	void SetPlayerParty(PlayerParty * playerParty) throw();
	void SetEnemyParty(EnemyParty * enemyParty) throw();
	void SetPlayerConsumeInv(const std::vector<Consumable*> playerConsumInv) throw();
	void SetPlayerArmorInv(const std::vector <Armor * > playerArmorInv) throw();
	void SetPlayerWeaponInv(const std::vector <Weapon *> playerWeaponInv) throw();
	void SetAllConsume(const std::vector <Consumable*> allConsum) throw();
	void SetAllArmor(const std::vector <Armor*> allArmor) throw();
	void SetAllWeapons(const std::vector <Weapon*> alWeapon) throw();


	//GetInstance Method for retrieving an instance of the GameData object: Use of Singleton Pattern
	static GameData* GetInstance() throw();

	// New/Load/Save GameData
	void New() throw();
	void Load() throw();
	void Save() throw();

	//Functions for populating global inventories
	///\brief Populates the list of all possible consumable items in the game
	void DefineConsumables() throw();
	///\brief Populates the list of all possible Armor items in the game
	void DefineArmor() throw();
	///\brief Populates the list of all possible Weapon items in the game
	void DefineWeapons() throw();

    //destroyed the instance; an externally accessable destroyer function
	void DestroyInstance() throw();


	void PrintParty() throw();
};


#endif
