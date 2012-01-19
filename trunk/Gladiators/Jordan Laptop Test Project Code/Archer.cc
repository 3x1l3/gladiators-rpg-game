/// \file
/// \brief Unit class implementation file.
/// \author Jordan Peoples
/// \date November 24rg, 2010
/// Implementation of the Archer job class. Specialized version of Job base class.

#include "Archer.h"
#include <vector>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>



///Constructor taking pointer to the unit that has this Job
Archer::Archer() : Job::Job()
{
    specialAttackName = "Fire Arrow";
    Job::SetJobName("Archer");
    
        ///   ***   STAT ARRAY FOR ARCHER JOB   ***   ///
    
    //level 1
    statArray[0][0] = 43;      //MaxHP increase
    statArray[0][1] = 6;       //Attack increase
    statArray[0][2] = 4;       //Defense increase
    //level 2
    statArray[1][0] = 33;      //MaxHP increase
    statArray[1][1] = 7;      //Attack increase
    statArray[1][2] = 3;      //Defense increase
    //level 3
    statArray[2][0] = 9000;
    statArray[2][1] = 9001;
    statArray[2][2] = 9002;
}


///Destructor for archer class
Archer::~Archer()
{
    
} 

///\brief Special ability for the Archer job.
///\param [in] enemyList Vector that contains pointers to the list of enemy units
/// Archer's special ability allows the unit to deal 125% 
/// of it's damage to 1 unit.
void Archer::Special( int attackValue, std::vector<Unit*> enemyList, unsigned target1 )
{
     //checking if enemy list is empty... if so just abort the function.
     if(enemyList.size() == 0)
     {
         cout<<"ENEMY LIST SIZE IS 0, ERROR, ERROR.\nIn Archer.cc, Special().\nNO ENEMIES TO TARGET....\nAborting Damaging Anybody"<<endl;;
         return;
     }
     //check if target is out of bounds, then abort the function
     if(target1 > ( enemyList.size() - 1 ) )
     {
         cout<<"Aborting Special Attack Function, Selected User Is Out Of Bounds"<<endl;
         cout<<"In Archer.cc, Special()"<<endl;
         return;
     }
     //check if target is out of bouncs, then abort the function
     if(target1 < 0)
     {
         cout<<"Aborting Special Attack Function, Selected User Is Out Of Bounds"<<endl;
         cout<<"In Archer.cc, Special()"<<endl;
         return;
     }
     
     std::vector<Unit*>::iterator it;   //iterator to traverse vector

     //assigning the damage vale to one quarter of the total attackj Value of the unit
     int damageValue = attackValue / 4;
     //then add on the attack value which should be 125% damage.
     damageValue += attackValue;
     //gets the enemy that the user targets and do the damage to them
     (enemyList[target1])->TakeDamage(damageValue);
}
