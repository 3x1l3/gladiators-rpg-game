/// \file
/// \brief PlayerCharacter class header file.
/// \author Jason Racine
/// \date November 1, 2010
/// Header file describing the PlayerCharacter class, which derives from the
/// Unit class and extends the Unit class to add additional functionality needed 
/// specifically for player controlled units.

#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "Unit.h"
#include "Job.h"
#include "Item.h"
#include "Equipable.h"
#include "PlayerCharacter.h"
#include "Wizard.h"
#include "Paladin.h"
#include "Archer.h"
#include "Commoner.h"

#include <string>

using std::string;

class PlayerCharacter : virtual public Unit
{
    private:
        int experience;                ///<Unit's accumulated experience total
        Job* job;
        
        
    public:
        ///\brief Defualt Constructor
        PlayerCharacter();
        
        PlayerCharacter(std::string name, int level, int maxHP, int attack, 
              int defense, std::string job, int leftHand, int rightHand, 
              int chest, int expierence );
        
        ///\brief Destructor
        virtual ~PlayerCharacter();

                        //*******Accessor Methods*******//
                                   
        ///\brief Returns the unit's experience total
        ///\return integer representing unit's experience total
        int GetExperience();
        
                        //*******Mutator Methods*******//

        
        ///\brief Adds \b amount experience to the character's experience total
        ///\param [in] amount Integer amount by which to increase the character's experience total
        ///\post Character's experience total 
        void IncreaseExperience(int amount);
	
	void LevelUp();
        
        ///\brief gets the job ofthe current unit
        ///\return job pointer representing the units job
        Job* GetJob();
        
        ///\brief Function to set the units job
        ///\param job pointer to set the units job to
        void SetJob(Job*);
        
        ///\brief function that resets the units HP to the integer sent in
        ///\param hp ammount to reset the units HP to
        void SetHP(int hp);
        
        ///function the gets the job name for the current unit.
        ///this function calls the Job class GetJobName() function.
        ///\return string with the units job name in it.
        std::string GetJobName();
        
};

#endif
