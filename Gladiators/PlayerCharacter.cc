/// \file
/// \brief PlayerCharacter class header file.
/// \author Jason Racine
/// \date November 25, 2010
/// Implementation file describing the PlayerCharacter class, which derives from the
/// Unit class and extends the Unit class to add additional functionality needed 
/// specifically for player controlled units.

#include "PlayerCharacter.h"

using namespace std;

//Default constructor
PlayerCharacter::PlayerCharacter() throw() : Unit::Unit()
{
    experience = 0;   
    job = new Commoner();                               
}


///Constructor to set PlayerCharacter attributes according to parameters///////////////////////////////////////////////////////
PlayerCharacter::PlayerCharacter(const std::string name, const int level, const int maxHP, 
    const int attack, const int defense, const std::string jobname, const int leftHand, const int rightHand, 
    const int chest, const int exp )  throw(): Unit::Unit( name, level, maxHP, attack, defense, leftHand, rightHand, chest)  
{
    experience = exp;
    
    //Assign job based on string sent as parameter
    if( strcmp(jobname.c_str(), "Paladin") == 0)
    {
        job = new Paladin();
    }
    else if( strcmp(jobname.c_str(), "Archer") == 0)
    {
        job = new Archer();
    }
    else if( strcmp(jobname.c_str(), "Wizard") == 0)
    {
        job = new Wizard();
    }
    else
    {
        job = new Commoner(); 
	//TO DO
	//Should probably make this throw an exception if cannot match the
	//string passed in to an appropriate job type.
    }
    
    
    //accesing the Weapon wep = AllWeaponVectors.at(leftHand);
    //assigning into Unit::equipment.setLefthand(wep).
    //TO DO
}

//Default destructor
PlayerCharacter::~PlayerCharacter() throw()
{
    delete job;                                    
}

//function to getthe current units expierence
int PlayerCharacter::GetExperience() throw()
{
    return experience;                            
}

//function that takes in a integer and adds it to the current units exprience.
//if this value is negative it will set amount to 0 and add 0 to the expierence
void PlayerCharacter::IncreaseExperience(int amount) throw()
{
    if(amount < 0)
        amount = 0;
    
    experience += amount;
}

//function that levels up the current unit
//see inside for more documentation
void PlayerCharacter::LevelUp() throw()
{   
    level++;
    //gets the stats array from the units job
    int* stats = job->GetStatArray();
    //gets the current level of the character
    int lvl = Unit::GetLevel();   
    //increases the units stats corresponding to the stats array
    Unit::maxHP += stats[ 0 + ( ( lvl -1) * 3 ) ];
    Unit::attackVal += stats[ 1 + ( (lvl -1) * 3) ];
    Unit::defenseVal += stats[ 2 + ( (lvl -1) * 3) ];
    
    //increasing the current hp back up to full.
    Unit::currentHP = Unit::maxHP;
}

//function that returns the current units job
Job* PlayerCharacter::GetJob() throw()
{
     return job;
}

//function that takes in a job and sets the current units job to it
void PlayerCharacter::SetJob(Job* j) throw()
{
    if(j != NULL)
        job = j;
    else
        job = new Commoner();
    //TO DO
	//Should probably throw an exception here if the job* passed in is null
}

//function that gets the current units job name
std::string PlayerCharacter::GetJobName() throw()
{
    return job->GetJobName();
}

