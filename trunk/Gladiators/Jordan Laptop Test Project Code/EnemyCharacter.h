/// \file
/// \brief EnemyCharacter class header file.
/// \author Jason Racine
/// \date November 2, 2010
/// Header file for the Enemy Character class, which inherits from the Unit class
/// and extends it to add funcitonality specific to enemy units (non player units).
#ifndef ENEMY_CHARACTER_H
#define ENEMY_CHARACTER_H

class EnemyCharacter : virtual public Unit
{
    private:
        int expGiven; ///<Experience awarded for defeating this unit
        
    public:
        ///\brief Default Constructor
        EnemyCharacter();
        
        ///\brief Destructor
        virtual ~EnemyCharacter(); 
        
        ///\brief Return the value of experience granted by defeating this enemy.
        ///\return Integer representing the experience given by the enemy character.
        int GetExpGiven();
	
	///\brief Set the value of the experience granted by defeating this enemy.
	///\param [in] amount Value to set the amount of experience rewarded to.
	///\post expGiven = amount;
	void SetExpGiven(int amount);
      
};

#endif
