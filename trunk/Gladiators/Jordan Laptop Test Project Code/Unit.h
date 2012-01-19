/// \file
/// \brief Unit class header file.
/// \author Jason Racine
/// \date November 1, 2010
/// Header file for the abstract base class Unit. Defines all the basic properties
/// that any unit in the game must have. Subclasses derived from this will implement
/// more specific types of units that will be used in different ways.
#ifndef UNIT_H
#define UNIT_H

#include <string.h>
#include "UnitEquipment.h" //Needed for the unit's equipment attribute
#include "Job.h"           //Needed for the unit's job attribute.
#include "Normal.h"
#include "Dead.h"
#include "Item.h"
#include "Equipable.h"

class Unit
{
    protected:
        std::string name;              ///<unit's name   
        int maxHP;                     ///<Maximum Health for the unit
        int currentHP;                 ///<Unit's current health value
        int attackVal;                 ///<Unit's attack value
        int defenseVal;                ///<Unit's defense value
        UnitEquipment* equipment;       ///<Unit's equipped items
        int level;                     ///<Unit's level
        State* state;                  ///<Pointer to unit's state
        
    public:
        ///\brief Default constructor
        ///Initializes all attributes of unit to default values
        Unit();
	
	Unit( std::string name, int level, int maxHP, int attack, int defense, int leftHand, int rightHand, int chest);
        
        ///\brief Default destructor
        ///Destroys a unit object and cleans up memory allocated for data members
        virtual ~Unit();
        
                        //*******Accessor Methods*******//
        
        ///\brief Returns unit's max health
        ///\return integer representing unit's maximum health value
        int GetMaxHP();
        
        ///\brief Returns unit's current health
        ///\return integer representing unit's current health
        int GetCurrentHP();
        
        ///\brief Returns the unit's attack value
        ///\return integer representing unit's attack value
        int GetAttackVal();
        
        ///\brief Returns unit's defense value
        ///\return integer representing unit's defense value
        int GetDefenseVal();
        
        UnitEquipment* GetEquipment()
        {
            return equipment;
        }
        
        ///\brief Returns the unit's level
        ///\return integer representing unit's level
        int GetLevel();
        
        ///\brief gets the name of the current unit
        ///\return string representing the unit's name
        std::string GetName();
        
        ///\brief increases the level of the character by 1.
        void LevelUp();
        
        void SetName(std::string name);
 
        void SetMaxHP(int newHP);
        
        void SetAttackValue(int newAttack);
        
        void SetDefenseValue(int newDefense);
        
        void SetLevel(int newLevel);
        
        void SetState(State* newState);
        
        std::string GetState();
        
        void IncreaseMaxHP(int amount);
        
        void IncreaseAttack(int amount);
        
        void IncreaseDefense(int ammount);
        
        void SetCurrentHP(int newCurrentHP);

        

                        //*******Mutator Methods*******//
                        
        ///\brief Deals damage to the unit
        ///\param [in] amount The amount of damage to be dealt to the unit.
        ///\post The unit's health is reduced by \b amount.
        void TakeDamage(int amount);
        
        ///\brief Heals the unit of damage done
        ///\param [in] amount The amount of damage to heal from the unit.
        ///\post The unit's health is increaded by \b amount up to it's max HP.
        ///@param state is the state of the unit so the use can use potions on dead characters if they want.
        void RecieveHealing(int amount, std::string currentState);
        
        
        
};


#endif
