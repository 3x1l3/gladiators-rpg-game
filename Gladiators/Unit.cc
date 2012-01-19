/// \file
/// \brief Unit class implementation file.
/// \author Jason Racine
/// \date November 14, 2010
/// Specifies implementation for the abstract base class Unit.
/// Subclasses derived from this will implement
/// more specific types of units that will be used in different ways.

#include "Unit.h"
#include <string.h>
#include "UnitEquipment.h" //Needed for the unit's equipment attribute
#include "Job.h"           //Needed for the unit's job attribute.
#include "Normal.h"
#include "Dead.h"

///\brief Default constructor
///Initializes Unit attribues to default values.
Unit::Unit() throw()
{

    name = "Nobody :'(";
    maxHP = 10;
    currentHP = 10;
    attackVal = 10;
    defenseVal = 10;
    equipment = new UnitEquipment(); //How to set Equipment struct to a default? Make this a pointer an use new Equipment() ?
    level = 0;
    state = new Normal();

}

Unit::Unit(const std::string name, const int level, const int maxHP, const int attack, const int defense, const int leftHand,  const int rightHand, const int chest) throw()
{
    this->name = name;
    this->maxHP = maxHP;
    this->currentHP = maxHP;
    this->attackVal = attack;
    this->defenseVal = defense;
    this->level = level;

    //TODO Fix this to set to the equipment passed as parameters
    equipment = new UnitEquipment();

    /* Havent got this working, however the fix is to just pass pointers from the GameData load
       so its not a huge deal. It can be done but doesnt have to be. 

    equipment->EquipRightHand(GameData::GetInstance()->GetAllWeapons().at(rightHand));
    equipment->EquipLeftHand(GameData::GetInstance()->GetAllWeapons().at(leftHand));
    equipment->EquipChestArmor(GameData::GetInstance()->GetAllWeapons().at(chest));
    */
    state = new Normal();
}

///Constructor that initializes unit variables to


///\brief Default destructor
///Destroys a unit object and cleans up memory allocated for data members
Unit::~Unit() throw()
{
    //if(equipment != NULL)
        //delete equipment;

    if(state != NULL)
        delete state;
    
    delete equipment;
}

                /****    Accessor methods    ****/

///Accessor method to return value of the Unit's maxHP attribute
///\return integer value representing unit's maximum health
int Unit::GetMaxHP() throw()
{
    return maxHP;
}

///Accessor method to return value of the unit's currentHP attribute
///\return integer value representing unit's current health
int Unit::GetCurrentHP() throw()
{
    return currentHP;
}

///Accessor method to return the value of the unit's attackVal attribute
///\return integer representing unit's attack value
int Unit::GetAttackVal() throw()
{
    return attackVal;
}

///Accessor method to return the value of the unit's defenseVal attribute
///\return integer representing the unit's defense value
int Unit::GetDefenseVal() throw()
{
    return defenseVal;
}

///Accessor method to return the value of the unit's level attribute
///\return integer representing the unit's level.
int Unit::GetLevel() throw()
{
    return level;
}

//function that returns the name of the current character
std::string Unit::GetName() throw()
{
    return name;
}

void Unit::SetName(const std::string name) throw()
{
     this->name = name;
}

void Unit::SetMaxHP(const int newHP) throw()
{
     this->maxHP = newHP;
}

void Unit::SetAttackValue(const int newAttack) throw()
{
     this->attackVal = newAttack;
}

void Unit::SetDefenseValue(const int newDefense) throw()
{
     this->defenseVal = newDefense;
}

void Unit::SetLevel(const int newLevel) throw()
{
     this->level = newLevel;
}

void Unit::SetState(State* newState) throw()
{
     this->state = newState;
}

std::string Unit::GetState() throw()
{
     return this->state->GetState();
}

void Unit::IncreaseMaxHP(const int amount) throw()
{
     this->maxHP += amount;
}

void Unit::IncreaseAttack(const int amount) throw()
{
     this->attackVal += amount;
}

void Unit::IncreaseDefense(const int amount) throw()
{
     this->defenseVal += amount;
}

void Unit::SetCurrentHP(const int newCurrentHP) throw()
{
    this->currentHP = newCurrentHP;
}



///\brief Deals damage to the unit
///\param [in] amount The amount of damage to be dealt to the unit.
///\post The unit's health is reduced by \b amount.
void Unit::TakeDamage(const int amount) throw()
{
     if(currentHP - amount <= 0)  //Taken enough damage to kill the unit?
     {
         currentHP = 0;           //prevent HP from going negative: -1 used as a default initialization for an incomplete unit.
         delete state;            //clean data currently in state pointer
         state = new Dead();      //set state pointer to Dead state
     }
     else                         //Unit still alive
         currentHP -= amount;     //just take the damage amount.
}

///\brief Heals the unit of damage done
///\param [in] amount The amount of damage to heal from the unit.
///\post The unit's health is increaded by \b amount up to it's max HP.
void Unit::RecieveHealing(const int amount, const std::string state) throw()
{
     //TODO Check state, don't allow healing to a dead character
     {
	if(currentHP + amount >= maxHP)    //Don't heal unit more than maxHP
	    currentHP = maxHP;
	else
	    currentHP += amount;
     }

}

void Unit::MakeAlive() throw()
{
    if(state == NULL)
        state = new Normal();
    if(state->GetState() == "DEAD")
    {
        delete state;
        state = new Normal();
    }
}
