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

using std::cout;
using std::endl;


///Default constructor for the Paladin class
Paladin::Paladin() throw() : Job::Job()
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
    statArray[2][0] = 50;
    statArray[2][1] = 4;
    statArray[2][2] = 5;
    
    statArray[3][0] = 50;
    statArray[3][1] = 4;
    statArray[3][2] = 5;
    
    statArray[4][0] = 50;
    statArray[4][1] = 4;
    statArray[4][2] = 5;
    
    statArray[5][0] = 50;
    statArray[5][1] = 4;
    statArray[5][2] = 5;
    
    statArray[6][0] = 50;
    statArray[6][1] = 4;
    statArray[6][2] = 5;
    
    statArray[7][0] = 50;
    statArray[7][1] = 4;
    statArray[7][2] = 5;
    
    statArray[8][0] = 50;
    statArray[8][1] = 4;
    statArray[8][2] = 5;
    
    statArray[9][0] = 50;
    statArray[9][1] = 4;
    statArray[9][2] = 5;
    
    statArray[10][0] = 50;
    statArray[10][1] = 4;
    statArray[10][2] = 5;
    
    statArray[11][0] = 50;
    statArray[11][1] = 4;
    statArray[11][2] = 5;
    
    statArray[12][0] = 50;
    statArray[12][1] = 4;
    statArray[12][2] = 5;
    
    statArray[13][0] = 50;
    statArray[13][1] = 4;
    statArray[13][2] = 5;
    
    statArray[14][0] = 50;
    statArray[14][1] = 4;
    statArray[14][2] = 5;
    
    statArray[15][0] = 50;
    statArray[15][1] = 4;
    statArray[15][2] = 5;
}


///Destructor for paldin class
Paladin::~Paladin() throw()
{

}

///\brief Special ability for the Paladin job.
///\param [in] enemyList Vector that contains pointers to the list of enemy units
/// Paladin's special ability allows the unit to deal 50%
/// of it's damage to 2 enemies simultaneously
void Paladin::Special(const  int attackValue, const std::vector<EnemyCharacter*> enemyList, const unsigned target1 ) throw()
{
     //checking if enemy list is empty... if so just abort the function.
     if(enemyList.size() == 0)
     {
         std::cout<<"ENEMY LIST SIZE IS 0, ERROR, ERROR.\nIn Paladin.cc, Special().\nNO ENEMIES TO TARGET....\nAborting Damaging Anybody"<<std::endl;;
         return;
     }
     //check if target is out of bounds, then abort the function
     if(target1 > enemyList.size())
     {
         std::cout<<"Aborting Special Attack Function, Selected User Is Out Of Bounds"<<std::endl;
         std::cout<<"In Paladin.cc, Special()"<<std::endl;
         return;
     }
     //check if target is out of bouncs, then abort the function
     if(target1 < 0)
     {
         std::cout<<"Aborting Special Attack Function, Selected User Is Out Of Bounds"<<std::endl;
         std::cout<<"In Paladin.cc, Special()"<<std::endl;
         return;
     }

     std::vector<Unit*>::iterator it;   //iterator to traverse vector

     //assigning the damage vale to half of the units total attack
     int damageValue = attackValue / 2;
     
     if(damageValue <= 0)
       damageValue = 1;
     
     //find the defense value of the target first....
     int defense = 0;
     defense = enemyList[target1]->GetDefenseVal();
     defense += enemyList[target1]->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
     defense += enemyList[target1]->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
     defense += enemyList[target1]->GetEquipment()->GetChestArmor()->GetDefenseValue();
     
     //splitting the defense in 2 casue we do half damage
     defense = defense / 2;
     
     //checking if defense is below 0, then set to 0
     if(defense < 0)
       defense = 0;
     
     //set damage value to be itself minus defense
     damageValue = damageValue - defense;
     
     //if the new damage value is below 7, default to 7 damage
     if(damageValue <= 0)
       damageValue = 7;
     
     //gets the enemy that the user targets and do the damage to them
     (enemyList[target1])->TakeDamage(damageValue);
     
     //print out the first attack summary
     cout<<specialAttackName<<" right hand damages "<<enemyList[target1]->GetName()<<" for "<<damageValue<<" damage."<<endl;

     //finding the next target to do damage to.
     //only one target exists, so do the rest of the damage to it.
     if(enemyList.size() == 1)
     {
       //get defense of the target
       defense = enemyList[target1]->GetDefenseVal();
       defense += enemyList[target1]->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
       defense += enemyList[target1]->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
       defense += enemyList[target1]->GetEquipment()->GetChestArmor()->GetDefenseValue();
       //split the densfence in half casue we split the attack
       defense = defense / 2;
      //if defense is less than 0, change to 0-
       if(defense < 0)
	 defense = 0;
      //get the new damage value
       damageValue = damageValue - defense;
      //if new damage value is less that 0, default to 7
       if(damageValue <= 0)
	 damageValue = 7;	
	//do tha damage to the target
       enemyList[target1]->TakeDamage(damageValue);
       //cout the turn summary
       cout<<specialAttackName<<" left hand damages "<<enemyList[target1]->GetName()<<" for "<<damageValue<<" damage."<<endl;
     }
     //checking if the target above the selected one is out of bounds to atatck...
     else if(target1+ 1 > enemyList.size()-1)
     {
       //for documnetaiont see the about if block
       defense = enemyList[target1]->GetDefenseVal();
       defense += enemyList[target1]->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
       defense += enemyList[target1]->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
       defense += enemyList[target1]->GetEquipment()->GetChestArmor()->GetDefenseValue();
       
       defense = defense / 2;
      
       if(defense < 0)
	 defense = 0;
      
       damageValue = damageValue - defense;
      
       if(damageValue <= 0)
	 damageValue = 7;
       
       //...if so, attack the target below the current target.
       enemyList[target1-1]->TakeDamage(damageValue);
       cout<<specialAttackName<<" left hand damages "<<enemyList[target1-1]->GetName()<<" for "<<damageValue<<" damage."<<endl;
     }
     //else attack the unit abovethe currently selected one.
     else
     {
       //for documnetaiton, see the above if block
       defense = enemyList[target1]->GetDefenseVal();
       defense += enemyList[target1]->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
       defense += enemyList[target1]->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
       defense += enemyList[target1]->GetEquipment()->GetChestArmor()->GetDefenseValue();
       
       defense = defense / 2;
      
       if(defense < 0)
	 defense = 0;
      
       damageValue = damageValue - defense;
      
       if(damageValue <= 0)
	 damageValue = 7;
       
       //...if so attackj the target above the current target.
       (enemyList[target1+1])->TakeDamage(damageValue);
       cout<<specialAttackName<<" left hand damages "<<enemyList[target1+1]->GetName()<<" for "<<damageValue<<" damage."<<endl;
     }

}
