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




///Default constructor for the Wizard class
Wizard::Wizard() throw() : Job::Job()
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
    statArray[2][0] = 40;
    statArray[2][1] = 8;
    statArray[2][2] = 3;
    
    statArray[3][0] = 40;
    statArray[3][1] = 8;
    statArray[3][2] = 3;
    
    statArray[4][0] = 40;
    statArray[4][1] = 8;
    statArray[4][2] = 3;
    
    statArray[5][0] = 40;
    statArray[5][1] = 8;
    statArray[5][2] = 3;
    
    statArray[6][0] = 40;
    statArray[6][1] = 8;
    statArray[6][2] = 3;
    
    statArray[7][0] = 40;
    statArray[7][1] = 8;
    statArray[7][2] = 3;
    
    statArray[8][0] = 40;
    statArray[8][1] = 8;
    statArray[8][2] = 3;
    
    statArray[9][0] = 40;
    statArray[9][1] = 8;
    statArray[9][2] = 3;
    
    statArray[10][0] = 40;
    statArray[10][1] = 8;
    statArray[10][2] = 3;
    
    statArray[11][0] = 40;
    statArray[11][1] = 8;
    statArray[11][2] = 3;
    
    statArray[13][0] = 40;
    statArray[13][1] = 8;
    statArray[13][2] = 3;
    
    statArray[14][0] = 40;
    statArray[14][1] = 8;
    statArray[14][2] = 3;
    
    statArray[15][0] = 40;
    statArray[15][1] = 8;
    statArray[15][2] = 3;

}


///Destructor for Wizard class
Wizard::~Wizard() throw()
{

}

std::string Wizard::GetSpecialAttackName()
{
    return specialAttackName;
}

///\brief Special ability for the Wizard job.
///\param [in] enemyList Vector that contains pointers to the list of enemy units
/// Wizard's special ability allows the Wizard to deal a smaller portion
/// of it's damage to multiple enemies simultaneously
void Wizard::Special( const int attackValue, const std::vector<EnemyCharacter*> enemyList, const unsigned target1) throw()
{
     //checking if enemy list is empty... if so just abort the function.
     if(enemyList.size() == 0)
     {
         std::cout<<"ENEMY LIST SIZE IS 0, ERROR, ERROR.\nIn Paladin.cc, Special().\nNO ENEMIES TO TARGET....\nAborting Damaging Anybody"<<std::endl;;
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
       int defense = 0;
       defense = enemyList[i]->GetDefenseVal();
       defense += enemyList[i]->GetEquipment()->GetRightHandWeapon()->GetDefenseValue(); 
       defense += enemyList[i]->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
       defense += enemyList[i]->GetEquipment()->GetChestArmor()->GetDefenseValue();
       
       defense = defense / enemyList.size();
       
       splashDamage = splashDamage - defense;
       
       if(splashDamage <= 0)
	 splashDamage = 5;
       
         (enemyList[i])->TakeDamage(splashDamage);
	 std::cout<<specialAttackName<<" damages "<<enemyList[i]->GetName()<<" for " <<splashDamage<<" damage."<<std::endl;
     }
}
