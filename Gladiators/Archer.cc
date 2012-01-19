/// \file
/// \brief Unit class implementation file.
/// \author Jordan Peoples, Jason Racine
/// \date Dec 1, 2010
/// Implementation of the Archer job class. Specialized version of Job base class.

#include "Unit.h"
#include "Job.h"
#include "UnitEquipment.h"
#include "Normal.h"
#include "Dead.h"

#include "Archer.h"
#include <vector>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>

//// .CC INCLUDES
/*
#include "Unit.cc"
#include "Job.cc"
#include "UnitEquipment.cc"
#include "Dead.cc"
#include "Normal.cc"
#include "Weapon.cc"
#include "Armor.cc"
#include "Equipable.cc"
#include "State.cc"
#include "Item.cc"
*/

using namespace std;


///Default constructor for the Archer class
Archer::Archer() throw() : Job::Job()
{
    specialAttackName = "Piercing Fire Arrow";
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
    statArray[2][0] = 33;
    statArray[2][1] = 7;
    statArray[2][2] = 3;
    
    statArray[3][0] = 33;
    statArray[3][1] = 7;
    statArray[3][2] = 3;
    
    statArray[4][0] = 33;
    statArray[4][1] = 7;
    statArray[4][2] = 3;
    
    statArray[5][0] = 33;
    statArray[5][1] = 7;
    statArray[5][2] = 3;
    
    statArray[6][0] = 33;
    statArray[6][1] = 7;
    statArray[6][2] = 3;
    
    statArray[7][0] = 33;
    statArray[7][1] = 7;
    statArray[7][2] = 3;
    
    statArray[8][0] = 33;
    statArray[8][1] = 7;
    statArray[8][2] = 3;
    
    statArray[9][0] = 33;
    statArray[9][1] = 7;
    statArray[9][2] = 3;
    
    statArray[10][0] = 33;
    statArray[10][1] = 7;
    statArray[10][2] = 3;
    
    statArray[11][0] = 33;
    statArray[11][1] = 7;
    statArray[11][2] = 3;
    
    statArray[12][0] = 33;
    statArray[12][1] = 7;
    statArray[12][2] = 3;
    
    statArray[13][0] = 33;
    statArray[13][1] = 7;
    statArray[13][2] = 3;
    
    statArray[14][0] = 33;
    statArray[14][1] = 7;
    statArray[14][2] = 3;
    
    statArray[15][0] = 33;
    statArray[15][1] = 7;
    statArray[15][2] = 3;
    
    
}


///Destructor for archer class
Archer::~Archer() throw()
{

}

///\brief Special ability for the Archer job.
///\param [in] enemyList Vector that contains pointers to the list of enemy units
/// Archer's special ability allows the unit to deal 125%
/// of it's damage to 1 unit.
void Archer::Special( const int attackValue, const std::vector<EnemyCharacter*> enemyList, const unsigned target1 ) throw ()
{
     //checking if enemy list is empty... if so just abort the function.
     if(enemyList.size() == 0)
     {
         cout<<"ENEMY LIST SIZE IS 0, ERROR, ERROR.\nIn Archer.cc, Special().\nNO ENEMIES TO TARGET....\nAborting Damaging Anybody"<<endl;;
         return;
     }
     //check if target is out of bounds, then abort the function
     if(target1 > enemyList.size())
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

     
     //gets the enemy that the user targets and do the damage to them
     //NOTE this is ignoring the targets armor on purpose.
     //the specials purpose it to be a armor piercing shot.
     //so we just send in the attack value strait up, with no mods done with defense value of the target.
     (enemyList[target1])->TakeDamage(attackValue);
     //print out the turn summary
     cout<<specialAttackName<<" damages "<<enemyList[target1]->GetName()<<" for "<<attackValue<<" damage."<<endl;
     
}
