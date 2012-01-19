/// \file
/// \brief EnemyCharacter class header file.
/// \author Jason Racine
/// \date November 2, 2010
/// Header file for the Enemy Character class, which inherits from the Unit class
/// and extends it to add funcitonality specific to enemy units (non player units).
#ifndef ENEMYCHARACTER_H
#define ENEMYCHARACTER_H

#include "Unit.h"
class Unit;

class EnemyCharacter : virtual public Unit
{
    private:
        int expGiven; ///<Experience awarded for defeating this unit

    public:
        ///\brief Default Constructor
        EnemyCharacter() throw();

        ///\brief Destructor
        virtual ~EnemyCharacter() throw();

        ///\brief Return the value of experience granted by defeating this enemy.
        ///\return Integer representing the experience given by the enemy character.
        int GetExpGiven() throw();

	///\brief Set the value of the experience granted by defeating this enemy.
	///\param [in] amount Value to set the amount of experience rewarded to.
	///\post expGiven = amount;
	void SetExpGiven(int amount) throw();

};

#endif
