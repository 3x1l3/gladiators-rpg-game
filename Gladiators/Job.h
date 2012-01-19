/// \file
/// \brief Job class header file.
/// \author Jason Racine
/// \date November 1, 2010
/// Header file for the abstract base class Job. Various types of specific Job
/// subclasses will derive from this class.
#ifndef JOB_H
#define JOB_H

//maybe move into class?
const int MAX_LEVEL = 100;
const int UNIT_STATS = 3;

#include<string>
#include<vector>
#include "Unit.h"
#include "Item.h"
#include "Equipable.h"
#include "EnemyCharacter.h"

class Job
{
    //enumerator to label the stat associated with an array position.
    enum stats { STATS_FIRST = 0, STATS_MAXHP = 0, STATS_ATK = 1, STATS_DEF = 2, STATS_LAST = 2 };

    private:


        ///\brief representative name to specify the type of job
        std::string jobName;


    protected:
        ///\brief Array representing stat boosts.
        /// The first dimention of the array is the level, the second dimension
        /// refers to the stat that the int in that position gives an increase to.
        int statArray[MAX_LEVEL][UNIT_STATS];

    public:
        ///Default constructor
        Job()  throw();

        ///Virtual Destructor
        virtual ~Job()  throw();

        ///\brief Returns the name identifying the type of job
        ///\return String representing the name of the job
        std::string GetJobName() throw();

        void SetJobName(const std::string name) throw();

        virtual void Special(const int attackVal, const std::vector <EnemyCharacter*> enemyList, const unsigned target1 ) = 0;

        int* GetStatArray() throw();
	
	std::string GetSpecialAttackName();

};


#endif
