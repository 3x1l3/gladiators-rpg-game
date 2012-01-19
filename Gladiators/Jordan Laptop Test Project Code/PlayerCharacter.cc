/// \file
/// \brief PlayerCharacter class header file.
/// \author Jason Racine
/// \date November 25, 2010
/// Implementation file describing the PlayerCharacter class, which derives from the
/// Unit class and extends the Unit class to add additional functionality needed 
/// specifically for player controlled units.


using namespace std;

//Default constructor
PlayerCharacter::PlayerCharacter() : Unit::Unit()
{
    experience = 0;   
    job = new Commoner();                               
}

///Constructor to set PlayerCharacter attributes according to parameters///////////////////////////////////////////////////////
PlayerCharacter::PlayerCharacter(std::string name, int level, int maxHP, 
    int attack, int defense, std::string jobname, int leftHand, int rightHand, 
    int chest, int exp ) : Unit::Unit( name, level, maxHP, attack, defense, leftHand, rightHand, chest)
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
PlayerCharacter::~PlayerCharacter()
{
    //Nothing                                    
}

//function to getthe current units expierence
int PlayerCharacter::GetExperience()
{
    return experience;                            
}

//function that takes in a integer and adds it to the current units exprience.
//if this value is negative it will set amount to 0 and add 0 to the expierence
void PlayerCharacter::IncreaseExperience(int amount)
{
    if(amount < 0)
        amount = 0;
    
    experience += amount;
}

//function that levels up the current unit
//see inside for more documentation
void PlayerCharacter::LevelUp()
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
}

//function that returns the current units job
Job* PlayerCharacter::GetJob()
{
     return job;
}

//function that takes in a job and sets the current units job to it
void PlayerCharacter::SetJob(Job* j)
{
    if(j != NULL)
        job = j;
    else
        job = new Commoner();
    //TO DO
	//Should probably throw an exception here if the job* passed in is null
}

//function to set the currnet units hp
void PlayerCharacter::SetHP(int hp)
{
     if(hp < 0)
         hp = 0;
         
     Unit::maxHP = hp;
}

//function that gets the current units job name
std::string PlayerCharacter::GetJobName()
{
    return job->GetJobName();
}

