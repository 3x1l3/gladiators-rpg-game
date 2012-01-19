/// \file
/// \brief Unit class implementation file.
/// \author Jason Racine
/// \date November 14, 2010
/// Implementation of the Wizard job class. Specialized version of Job base class.

#include "Wizard.h"
#include <vector>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>



///Constructor taking pointer to the unit that has this Job
Wizard::Wizard() : Job::Job()
{
    specialAttackName = "Arcane Blast";
    Job::SetJobName("Wizard");
    
        ///   ***   STAT ARRAY FOR WIZARD JOB   ***   ///
    
    //level 1
    statArray[0][0] = 36;      //MaxHP increase
    statArray[0][1] = 8;       //Attack increase
    statArray[0][2] = 3;       //Defense increase
    //level 2
    statArray[1][0] = 40;      //MaxHP increase
    statArray[1][1] = 8;       //Attack increase
    statArray[1][2] = 3;       //Defense increase
    //level 3
    statArray[2][0] = 9000;
    statArray[2][1] = 9001;
    statArray[2][2] = 9002;

}


///Destructor for Wizard class
Wizard::~Wizard()
{
    
} 

///\brief Special ability for the Wizard job.
///\param [in] enemyList Vector that contains pointers to the list of enemy units
/// Wizard's special ability allows the Wizard to deal a smaller portion
/// of it's damage to multiple enemies simultaneously
void Wizard::Special( int attackValue, std::vector<Unit*> enemyList, unsigned target1)
{
     //checking if enemy list is empty... if so just abort the function.
     if(enemyList.size() == 0)
     {
         cout<<"ENEMY LIST SIZE IS 0, ERROR, ERROR.\nIn Paladin.cc, Special().\nNO ENEMIES TO TARGET....\nAborting Damaging Anybody"<<endl;;
         return;
     }
     
     //TO DO
     //Change Damage allocation to doing Full damage to one character and then
     //...fractional damage to other characters.
     //at the moment, all characters recieve a portion of damage relating to the
     //...number of enemy chracters divided by the total atatck of the unit.
     
     
     std::vector<Unit*>::iterator it;   //iterator to traverse vector

     //variable to hold the damage to be done to all enemies
     int splashDamage;
     
     //Doing damage that equals attack divided by # of enemy characters
         if(attackValue / enemyList.size() == 0)
             splashDamage = 1;
         else if (attackValue / enemyList.size() < 0)
             splashDamage = 1;
         else
             splashDamage = (attackValue / enemyList.size());
     
     //for(it = enemyList.begin(); it < enemyList.end(); ++it)
     for(unsigned i = 0; i<enemyList.size(); i++)
     {
         (enemyList[i])->TakeDamage(splashDamage);
     }
}
