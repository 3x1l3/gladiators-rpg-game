/// \file
/// \brief Unit class header file.
/// \author Jason Racine
/// \date November 1, 2010
/// Header file for the abstract base class Unit. Defines all the basic properties
/// that any unit in the game must have. Subclasses derived from this will implement
/// more specific types of units that will be used in different ways.
#ifndef UNIT_H
#define UNIT_H

#include <string>
#include "UnitEquipment.h" //Needed for the unit's equipment attribute
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
        Unit() throw();

	Unit(const std::string name, const int level, const int maxHP, const int attack, const int defense, const int leftHand, const int rightHand, const int chest) throw();

        ///\brief Default destructor
        ///Destroys a unit object and cleans up memory allocated for data members
        virtual ~Unit() throw();

                        //*******Accessor Methods*******//

        ///\brief Returns unit's max health
        ///\return integer representing unit's maximum health value
        int GetMaxHP() throw();

        ///\brief Returns unit's current health
        ///\return integer representing unit's current health
        int GetCurrentHP() throw();

        ///\brief Returns the unit's attack value
        ///\return integer representing unit's attack value
        int GetAttackVal() throw();

        ///\brief Returns unit's defense value
        ///\return integer representing unit's defense value
        int GetDefenseVal() throw();

        ///\brief Get Equipment function that returns an equipment pointer for the unit
        /// \pre requires the player to havepre-defined (even default) equipment
        /// \post Returns a pointer to the player unit's equipment
        ///
        UnitEquipment* GetEquipment() throw()
        {
            return equipment;
        }


        std::string GetState() throw();

        ///\brief Returns the unit's level
        ///\return integer representing unit's level
        int GetLevel() throw();

        ///\brief gets the name of the current unit
        ///\return string representing the unit's name
        std::string GetName() throw();

        ///\brief increases the level of the character by 1.
        void LevelUp() throw();

        void SetName(std::string name) throw();

        void SetMaxHP(const int newHP) throw();

        void SetAttackValue(const int newAttack) throw();

        void SetDefenseValue(const int newDefense) throw();

        void SetLevel(const int newLevel) throw();

        void SetState(State* newState) throw();

        void MakeAlive() throw();

        void IncreaseMaxHP(const int amount) throw();

        void IncreaseAttack(const int amount) throw();

        void IncreaseDefense(const int ammount) throw();

        void SetCurrentHP(const int newCurrentHP) throw();



                        //*******Mutator Methods*******//

        ///\brief Deals damage to the unit
        ///\param [in] amount The amount of damage to be dealt to the unit.
        ///\post The unit's health is reduced by \b amount.
        void TakeDamage(const int amount) throw();

        ///\brief Heals the unit of damage done
        ///\param [in] amount The amount of damage to heal from the unit.
        ///\post The unit's health is increaded by \b amount up to it's max HP.
        void RecieveHealing(const int amount, const std::string state) throw();



};


#endif
