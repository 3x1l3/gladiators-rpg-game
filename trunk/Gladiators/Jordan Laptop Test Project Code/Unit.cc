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
Unit::Unit()
{

    name = "Nobody :'(";
    maxHP = -1;
    currentHP = -1;
    attackVal = -1;
    defenseVal = -1;
    equipment = new UnitEquipment(); //How to set Equipment struct to a default? Make this a pointer an use new Equipment() ?            
    level = 1;
    state = new Normal();

}

Unit::Unit( std::string name, int level, int maxHP, int attack, int defense, int leftHand, int rightHand, int chest)
{
    this->name = name;
    this->maxHP = maxHP;
    this->attackVal = attack;
    this->defenseVal = defense;
    this->level = level;
    
    //TODO Fix this to set to the equipment passed as parameters
    equipment = new UnitEquipment();

  
}

///Constructor that initializes unit variables to


///\brief Default destructor
///Destroys a unit object and cleans up memory allocated for data members
Unit::~Unit()
{
    //if(equipment != NULL)
        //delete equipment;
        
    if(state != NULL)
        delete state;
}

                /****    Accessor methods    ****/

///Accessor method to return value of the Unit's maxHP attribute
///\return integer value representing unit's maximum health
int Unit::GetMaxHP()
{
    return maxHP;
}

///Accessor method to return value of the unit's currentHP attribute
///\return integer value representing unit's current health
int Unit::GetCurrentHP()
{
    return currentHP;
}

///Accessor method to return the value of the unit's attackVal attribute
///\return integer representing unit's attack value
int Unit::GetAttackVal()
{
    return attackVal;
}

///Accessor method to return the value of the unit's defenseVal attribute
///\return integer representing the unit's defense value
int Unit::GetDefenseVal()
{
    return defenseVal;
}

///Accessor method to return the value of the unit's level attribute
///\return integer representing the unit's level.
int Unit::GetLevel()
{
    return level;
}

//function that returns the name of the current character
std::string Unit::GetName()
{
    return name;
}

void Unit::SetName(std::string name)
{
     this->name = name;
}
 
void Unit::SetMaxHP(int newHP)
{
     this->maxHP = newHP;
}

void Unit::SetAttackValue(int newAttack)
{
     this->attackVal = newAttack;
}

void Unit::SetDefenseValue(int newDefense)
{
     this->defenseVal = newDefense;
}

void Unit::SetLevel(int newLevel)
{
     this->level = newLevel;
}

void Unit::SetState(State* newState)
{
     this->state = newState;
}

std::string Unit::GetState()
{
     return this->state->GetState();
}

void Unit::IncreaseMaxHP(int amount)
{
     this->maxHP += amount;
}

void Unit::IncreaseAttack(int amount)
{
     this->attackVal += amount;
}

void Unit::IncreaseDefense(int amount)
{
     this->defenseVal += amount;
}

void Unit::SetCurrentHP(int newCurrentHP)
{
    this->currentHP = newCurrentHP;
}



///\brief Deals damage to the unit
///\param [in] amount The amount of damage to be dealt to the unit.
///\post The unit's health is reduced by \b amount.
void Unit::TakeDamage(int amount)
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
/// this function also takes in the units state so the user is able to use potions on
//... dead charcters if they choose to.  
void Unit::RecieveHealing(int amount, std::string currentState)
{
     if (currentState == "NORMAL")
     {
         if(currentHP + amount >= maxHP)    //Don't heal unit more than maxHP
             currentHP = maxHP;
         else
             currentHP += amount;             
     }
     else
     {}
}
