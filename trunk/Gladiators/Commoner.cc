/// \file
/// \brief Unit class implementation file.
/// \author Jason Racine
/// \date November 25, 2010
/// Implementation of Commoner job class. Specialized version of Job base class
/// which serves as the default job assigned to units in place of a null pointer
/// when the job is otherwise unknown.

#include "Commoner.h"
#include <vector>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include "Job.h"

//// .CC FILES START
//#include "Job.cc"




///Constructor for the Commoner class
Commoner::Commoner() throw() : Job::Job()
{
    specialAttackName = "Blank Stare";
    Job::SetJobName("Commoner");

        ///   ***   STAT ARRAY FOR COMMONER JOB   ***   ///

    /// 0 for everything at all levels 1-100 for commoners
    for(int i = 0; i < 100; i++)
    {
        statArray[i][0] = 0;
	statArray[i][1] = 0;
	statArray[i][2] = 0;
    }
}


///Destructor for commoner class
Commoner::~Commoner() throw()
{

}

///\brief Special ability for the Commoner job.
///\param [in] attackValue attack value to apply to the special
///\param [in] enemyList list of enemy characters as potential targets
///\param [in] target1 Index for the primary target selected.
void Commoner::Special(const int attackValue, const std::vector<EnemyCharacter*> enemyList, const unsigned target1 ) throw()
{
    std::cerr << " wants more DeNiro just to stay at home, well my friend, you gotta say..." << std::endl
				 << "I won't pay, I won't pay ya, no wa-a-a-ayyy. Na na why don't you get a JOB?" << std::endl;
}
