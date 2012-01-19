/// \file EnemyCharacter class implementation file
/// \brief EnemyCharacter class implementation file.
/// \author Jason Racine
/// \date November 25, 2010
/// Implementation file for the Enemy Character class, which inherits from the Unit class
/// and extends it to add funcitonality specific to enemy units (non player units).

#include "EnemyCharacter.h"

EnemyCharacter::EnemyCharacter() throw() : Unit()
{
    expGiven = 0;
}

EnemyCharacter::~EnemyCharacter() throw()
{

}

int EnemyCharacter::GetExpGiven() throw()
{
    return expGiven;
}


void EnemyCharacter::SetExpGiven(int amount) throw()
{
    //prevent negative amount of exp award
    if(amount < 0)
        amount = 0;

    expGiven = amount;
}
