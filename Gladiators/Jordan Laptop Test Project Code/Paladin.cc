/// \file
/// \brief Unit class implementation file.
/// \author Jordan Peoples
/// \date November 24rg, 2010
/// Implementation of the Paladin job class. Specialized version of Job base class.

#include "Paladin.h"
#include <vector>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>



///Constructor taking pointer to the unit that has this Job
Paladin::Paladin() : Job::Job()
{
    specialAttackName = "Jousting Impalement";
    Job::SetJobName("Paladin");
    
    ///   ***   STAT ARRAY FOR PALADIN JOB   ***   ///
    
    //level 1
    statArray[0][0] = 51;      //MaxHP increase
    statArray[0][1] = 6;       //Attack increase
    statArray[0][2] = 5;       //Defense increase
    //level 2
    statArray[1][0] = 50;      //MaxHP increase
    statArray[1][1] = 4;      //Attack increase
    statArray[1][2] = 5;      //Defense increase
    //level 3
    statArray[2][0] = 9000;
    statArray[2][1] = 9001;
    statArray[2][2] = 9002;
}


///Destructor for paldin class
Paladin::~Paladin()
{
    
} 

///\brief Special ability for the Paladin job.
///\param [in] enemyList Vector that contains pointers to the list of enemy units
/// Paladin's special ability allows the unit to deal 50% 
/// of it's damage to 2 enemies simultaneously
void Paladin::Special( int attackValue, std::vector<Unit*> enemyList, unsigned target1 )
{
     //checking if enemy list is empty... if so just abort the function.
     if(enemyList.size() == 0)
     {
         cout<<"ENEMY LIST SIZE IS 0, ERROR, ERROR.\nIn Paladin.cc, Special().\nNO ENEMIES TO TARGET....\nAborting Damaging Anybody"<<endl;;
         return;
     }

     //check if target is out of bounds, then abort the function
     //minus one off the enemy list size casue it counts 123, where the target will be 012
     if(target1 > (enemyList.size()-1))
     {
         cout<<"Aborting Special Attack Function, Selected User Is Out Of Bounds"<<endl;
         cout<<"In Paladin.cc, Special()"<<endl;
         return;
     }

     //check if target is out of bouncs, then abort the function
     if(target1 < 0)
     {
         cout<<"Aborting Special Attack Function, Selected User Is Out Of Bounds"<<endl;
         cout<<"In Paladin.cc, Special()"<<endl;
         return;
     }

     //assigning the damage vale to half of the units total attack
     int damageValue = attackValue / 2;

     //gets the enemy that the user targets and do the damage to them
     (enemyList[target1])->TakeDamage(damageValue);
     
     //finding the next target to do damage to.
     //only one target exists, so do the rest of the damage to it.
     if(enemyList.size() == 1)
     {
         (enemyList[target1])->TakeDamage(damageValue);
     }
     
     //checking if the target above the selected one is out of bounds to atatck...
     else if( (target1 - 1) < 0 )
     {
          ///...if so, attack the target below the current target.
         (enemyList[ (target1 + 1) ])->TakeDamage(damageValue);
     }
     
     //else attack the unit abovethe currently selected one.
     else
     {
          //...if so attackj the target above the current target.
         (enemyList[ ( target1 - 1 ) ])->TakeDamage(damageValue);
     }
         
}
