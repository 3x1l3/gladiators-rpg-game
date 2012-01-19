#include "BattleEvent.h"
#include <time.h>

using std::cerr;
using std::endl;
using std::cout;
using std::cin;


	///actual constructor
	BattleEvent::BattleEvent() throw()
	{
	  currentTurn = 0;
	}

	///destructor
	BattleEvent::~BattleEvent() throw()
	{
	  delete battleMenu;
	}

	///\brief will check to see if the players party is all dead
	bool BattleEvent::IsPlayerPartyAlive() throw()
	{
	  bool oneUnitAlive = false;

	  for (unsigned i = 0; i < GameData::GetInstance()->GetPlayerParty()->Size();i++)
	  {
	    if(GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetState() == "NORMAL")
	    {
	      oneUnitAlive = true;
	    }
	  }

	  return oneUnitAlive;
	}

	///\brief will check to see if the enemies party has been destoryed
	bool BattleEvent::IsEnemyPartyAlive() throw()
	{
	  bool oneUnitAlive = false;

	  for (unsigned i = 0; i < enemies.size();i++)
	  {
	    if(enemies[i]->GetState() == "NORMAL")
	    {
	      oneUnitAlive = true;
	    }
	  }

	  return oneUnitAlive;
	}

	///iterate to the next players turn
	void BattleEvent::ProceedToNextTurn() throw()
	{

	}

	///chec the state of the individual characters (dead or alive)
	///@param Unit unit to check the state of
	///@return players state
	void BattleEvent::CheckCharacterState(Unit*) throw()
	{

	}

	///makes a new battle menu
	void BattleEvent::ConstructBattleMenu() throw()
	{
	  this->battleMenu = new BattleMenu();
	  battleMenu->AddMenuItem("Attack!");
	  battleMenu->AddMenuItem("Use Item!");
	  battleMenu->AddMenuItem("Attempt To Flee!");
	}

	///destroys the previoud battle menu if it exists
	void BattleEvent::DestroyBattleMenu() throw()
	{

	}

	///creates a enemy part based on players party average level
	void BattleEvent::CreateEnemyParty(int enemyPartySize) throw()
	{
	  //TODO make random enemies added to the enemy vector
	  if(enemyPartySize == 0)
	  {}
	  else
	  {
	    for(int i = 0; i < enemyPartySize; i++)
	    {
	      enemies.push_back(GameData::GetInstance()->GetEnemyParty()->GetMember(i));
	    }
	  }
	}


	//will print the enemy party
	void BattleEvent::PrintEnemyParty() throw()
	{
	  cerr<<"ENEMY-NAME"<<"\t\t\t"<<"HP"<<endl;
	  cerr<<"-----------------------------------------------------------------------------"<<endl;
	  for (unsigned i = 0; i < enemies.size(); i++)
	  {
	    cout<<enemies[i]->GetName();
	    cout<<"\t\t\t";
	    cout<<enemies[i]->GetCurrentHP();
	    cout<<"/";
	    cout<<enemies[i]->GetMaxHP();
	    cout<<endl;
	  }
	}

    //generates a random number of enemies integer based off of player level
int BattleEvent::EnemyPartySizer() throw()
	{
	    int level = GameData::GetInstance()->GetPlayerParty()->GetMember(0)->GetLevel();
        srand ( time(NULL) );
        int seedLevel;

        if(level == 0)
            seedLevel = 0;
        else if(level >=1 && level <=5)
            seedLevel = 1;
        else if(level > 5 && level <= 15)
            seedLevel = 2;
        else if(level > 15 && level <= 25)
            seedLevel = 3;
        else if(level > 25 && level <= 40)
            seedLevel = 4;
        else if(level > 40 && level <= 55)
            seedLevel = 5;
        else if(level > 55 && level <= 75)
            seedLevel = 6;
        else if(level > 75 && level < 100)
            seedLevel = 7;
        else if(level == 100)
            seedLevel = 8;

	    switch(seedLevel)
	    {
	        case 0:
                return rand() % 3 + 2;
	        case 1:
                return rand() % 3 + 1;//+ 2;
            case 2:
                return rand() % 5 + 1;
            case 3:
                return rand() % 6 + 1;
            case 4:
                return rand() % 6 + 3;
            case 5:
                return rand() % 7 + 2;
            case 6:
                return rand() % 7 + 3;
            case 7:
                return rand() % 9 + 5;
            case 8:
                return 14;
            default:
                return 3;
	    }
	}



	///Run will execute everythign in the class (make a battle scene)
	void BattleEvent::Run() throw()
	{
	  int choice;

	  //both of these are set to ture becasue we will never enter a battle with half dead or dead chracters.
	  //all charcters will be refreshed before the battles, so these booleans hold true for all situations.
	  bool playerPartyAlive = true;
	  bool enemyPartyAlive = true;

	  CreateEnemyParty(EnemyPartySizer());

          ConstructBattleMenu();


	  while (playerPartyAlive && enemyPartyAlive)
	  {
	    for (; this->currentTurn < GameData::GetInstance()->GetPlayerParty()->Size(); currentTurn++)
	    {
	      if(GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetState() == "NORMAL")
	      {
		enemyPartyAlive = IsEnemyPartyAlive();
		if(!enemyPartyAlive)
		  continue;
		
		do
		{
		  system("clear");
		  cout<<"Currently: In a Battle"<<"\n----------------------------"<<endl<<endl;
		  std::cout<<"Your Units:"<<std::endl;
		  GameData::GetInstance()->PrintParty();
		  std::cout<<"Enemy Units:"<<endl;
		  PrintEnemyParty();
		  cout<<"Current Unit's Turn: "<<GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetName()<<endl;
		  std::cout<<endl<<endl<<"What Will You Choose?"<<std::endl<<std::endl;

		  battleMenu->Run();

		  std::string userChoice;
		  getline (std::cin, userChoice);
		  choice = atoi(userChoice.c_str());

		}while(choice > 3 || choice < 1);

		unsigned intChoice;
		string newChoice;

		unsigned intChoice2;
		string newChoice2;


		switch(choice)
		{
		  case 1:
		  do
		    {
		    system("clear");
		    std::cout<<"Your Units:"<<std::endl;
		    GameData::GetInstance()->PrintParty();
		    cout<<"Enemy Units:"<<endl;
		    PrintEnemyParty();
		    cout<<"Select Attack To Use:"<<"\n-----------"<<endl;
		    cout<<"1. Attack"<<endl;
		    cout<<"2. Special"<<endl;   //TODO change to a new battle menu;

		    getline(std::cin, newChoice);

		    intChoice = atoi(newChoice.c_str());
		    }while(intChoice < 1 || intChoice > 2);


		    switch (intChoice)
		    {
		      case 1:
			do
			{
			  system("clear");
			  std::cout<<"Your Units:"<<std::endl;
			  GameData::GetInstance()->PrintParty();
			  cout<<"Enemy Units:"<<endl;
		          PrintEnemyParty();
			  cout<<"Select Unit To Attack! :"<<"\n-----------"<<endl;
			  PrintAllTargets();    //TODO change to a new battle menu;

			  getline(std::cin, newChoice2);

			  intChoice2 = atoi(newChoice2.c_str());
			}while(intChoice2 < 1 || intChoice2 > (enemies.size() + GameData::GetInstance()->GetPlayerParty()->Size()));


			//do the damge to the selected character
			//TODO change to function??
			//if the users choice is withint the range of the players uint.. attack them
			if (intChoice2 <= GameData::GetInstance()->GetPlayerParty()->Size())
			{
			  int damage  = 0;
			  int defense = 0;

			  //getting the attackers base damage
			  damage = GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetAttackVal();
			  //adding in right hand weapon damage
			  damage += GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetEquipment()->GetRightHandWeapon()->GetAttackValue();
			  //adding in left hand weapon damage
			  damage += GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetEquipment()->GetLeftHandWeapon()->GetAttackValue();

			  //getting the targets base defense
			  defense = GameData::GetInstance()->GetPlayerParty()->GetMember(intChoice2-1)->GetDefenseVal();
			  //getting the targets right hand defense
			  defense += GameData::GetInstance()->GetPlayerParty()->GetMember(intChoice2-1)->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
			  //getting the targets left hand defnese
			  defense += GameData::GetInstance()->GetPlayerParty()->GetMember(intChoice2-1)->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
			  //getting the targets armor defense
			  defense = GameData::GetInstance()->GetPlayerParty()->GetMember(intChoice2-1)->GetEquipment()->GetChestArmor()->GetDefenseValue();

			  //calculate the dmagae to give to the target
			  damage = damage - defense;

			  if (damage <= 0)
			    damage = 1;

			  //attacking the charcter with the calculated damage
			  GameData::GetInstance()->GetPlayerParty()->GetMember(intChoice2-1)->TakeDamage(damage);

			  //priting out the turn summary
			  cout<<GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetName()<<
			  " attacked " << GameData::GetInstance()->GetPlayerParty()->GetMember(intChoice2-1)->GetName() <<
			  " for "<< damage<<
			  " damage."<<endl;
			  cin.get();
			}
			//else it should be attacking the enemies.
			else
			{
			  int damage;
			  int defense;

			  //getting the attackers base damage
			  damage = GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetAttackVal();
			  //adding in right hand weapon damage
			  damage += GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetEquipment()->GetRightHandWeapon()->GetAttackValue();
			  //adding in left hand weapon damage
			  damage += GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetEquipment()->GetLeftHandWeapon()->GetAttackValue();

			  //getting the targets base defense
			  defense = enemies[(intChoice2 -1)- (GameData::GetInstance()->GetPlayerParty()->Size())]->GetDefenseVal();
			  //getting the targets right hand defense
			  defense += enemies[(intChoice2 -1)- (GameData::GetInstance()->GetPlayerParty()->Size())]->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
			  //getting the targets left hand defnese
			  defense += enemies[(intChoice2 -1)- (GameData::GetInstance()->GetPlayerParty()->Size())]->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
			  //getting the targets armor defense
			  defense = enemies[(intChoice2 -1)- (GameData::GetInstance()->GetPlayerParty()->Size())]->GetEquipment()->GetChestArmor()->GetDefenseValue();

			  damage = damage - defense;

			  if (damage <= 0)
			    damage = 1;

			   enemies[(intChoice2 -1)- (GameData::GetInstance()->GetPlayerParty()->Size())]
			  ->TakeDamage(damage);

			  cout<<GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetName()<<
			  " attacked " <<  enemies[(intChoice2 -1)- (GameData::GetInstance()->GetPlayerParty()->Size())]->GetName()<<
			  " for " << damage<<
			  " damage."<<endl;
			  cin.get();
			}


		      break;
			//this is when the user selects to use there special attacks..
		      case 2:
			do
			{
			  system("clear");
			  std::cout<<"Your Units:"<<std::endl;
			  GameData::GetInstance()->PrintParty();
			  cout<<"Enemy Units:"<<endl;
		          PrintEnemyParty();
			  cout<<"Select Unit To Use Special Attack On:"<<"\n-----------"<<endl;
			  PrintAllTargets();    //TODO change to a new battle menu;

			  getline(std::cin, newChoice2);

			  intChoice2 = atoi(newChoice2.c_str());
			}while(intChoice2 < 1 || intChoice2 > (enemies.size() + GameData::GetInstance()->GetPlayerParty()->Size()));


			//do the damge to the selected character
			//TODO change to function??
			//if the users choice is withint the range of the players uint.. attack them
			if (intChoice2 <= GameData::GetInstance()->GetPlayerParty()->Size())
			{
			    cout<<"Your target was a friend, - they percieved your attack, and avoided the damage."<<endl;
			    cout<<"Press Enter To Continue"<<endl;
			    cin.get();




			}
			//else it should be attacking the enemies.
			else
			{
			  int damage = 0;

			  damage = GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetAttackVal();
			  damage += GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetEquipment()->GetRightHandWeapon()->GetAttackValue();
			  damage += GameData::GetInstance()->GetPlayerParty()->GetMember(currentTurn)->GetEquipment()->GetLeftHandWeapon()->GetAttackValue();

			  GameData::GetInstance()->
			  GetPlayerParty()->
			  GetMember(currentTurn)->
			  GetJob()->
			  Special(damage, enemies, (intChoice2 -1) - (GameData::GetInstance()->GetPlayerParty()->Size()));
			  cin.get();
			}

			break;

		      default:
			system("clear");
			cout<<"THERE HAS BEEN A AWFUL ERROR\nPLEASE PRESS ENTER"<<endl;
			std::cin.clear();
			std::cin.sync();
			std::cin.get();
			break;
		    }




		    break;
		  case 2:
		    HandleItemSelect();
		    break;
		  case 3:

		    break;

		  default:
		    system("clear");
		    cout<<"THERE HAS BEEN A AWFUL ERROR\nPLEASE PRESS ENTER"<<endl;
		    std::cin.clear();
		    std::cin.sync();
		    std::cin.get();
		    break;
		}
	      }
	    }//end users turn
	    enemyPartyAlive = IsEnemyPartyAlive();
	    if(enemyPartyAlive)
	    {
	      cout<<"Enemy Turn - Press Enter To Continue"<<endl;    
	      std::cin.ignore();
	    }

	    for (; currentTurn < (enemies.size() + GameData::GetInstance()->GetPlayerParty()->Size()); currentTurn++)
	    {
	      if(enemies[( currentTurn - GameData::GetInstance()->GetPlayerParty()->Size() )]->GetState() == "NORMAL")
	      {
		AIRun(currentTurn - GameData::GetInstance()->GetPlayerParty()->Size());
	      }
	    }//end AI enemies turn

	    this->currentTurn = 0;

	    playerPartyAlive = IsPlayerPartyAlive();
	    enemyPartyAlive = IsEnemyPartyAlive();

	    if(!playerPartyAlive)
	    {
	      cout<<"You party has died! How are you reading this, again?"<<endl;
	      std::cin.get();
	      throw lost_game_over("Your entire party has died! Unable to Continue Playing! Game Over!");
	    }

	    if(!enemyPartyAlive)
	    {
	      cout<<"The Enemy Party is Dead!"<<endl;
	      std::cin.get();
	    }

	  }//end while party is not dead thingy


	  DestroyBattleMenu();


      for(unsigned int i=0; i< GameData::GetInstance()->GetEnemyParty()->Size(); i++)
      {
          GameData::GetInstance()->GetEnemyParty()->GetMember(i)->MakeAlive();
          GameData::GetInstance()->GetEnemyParty()->GetMember(i)->SetCurrentHP
            (GameData::GetInstance()->GetEnemyParty()->GetMember(i)->GetMaxHP());
      }

	}

	void BattleEvent::AIRun(int currentEnemy) throw()
	{
	  //TODO make enemies target random players units.
	  int damage = 0;
	  int defense = 0;

	  //indice of who to attack
	  //can be changed later into a random variable or something.
	  unsigned i = 0;
	  
	  do
	  {
	    i = i +1;
	  }while(GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetCurrentHP() <= 0);
	  
	  if(i >= (GameData::GetInstance()->GetPlayerParty()->Size()-1))
	     i = 0;
	    

	  damage = enemies[currentEnemy]->GetAttackVal();
	  damage += enemies[currentEnemy]->GetEquipment()->GetLeftHandWeapon()->GetAttackValue();
	  damage += enemies[currentEnemy]->GetEquipment()->GetRightHandWeapon()->GetAttackValue();

	  defense = GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetDefenseVal();
	  defense += GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetEquipment()->GetRightHandWeapon()->GetDefenseValue();
	  defense += GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetEquipment()->GetLeftHandWeapon()->GetDefenseValue();
	  defense += GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetEquipment()->GetChestArmor()->GetDefenseValue();


	  damage = damage - defense;

	  if (damage <= 0)
	    damage = 1;


	  GameData::GetInstance()->GetPlayerParty()->GetMember(i)->TakeDamage(damage);
	  std::cout<<std::endl<<enemies[currentEnemy]->GetName()<<" attacked "<<
	  GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetName()<<" for "
          <<damage<<" damage."<<std::endl;

	  std::cout<<"Press Enter To Continue"<<std::endl;

	  std::cin.get();
	}


	void BattleEvent::PrintAllTargets() throw()
	{
	  //count to keep track of the units that have been rpinted to the screen.
	  unsigned count = 0;
	  //pringting all the friendly units out.
	  for (; count < GameData::GetInstance()->GetPlayerParty()->Size(); count++ )
	  {
	    cout<<count + 1<<". "<< GameData::GetInstance()->GetPlayerParty()->GetMember(count)->GetName() << " [friend]["<<
	    GameData::GetInstance()->GetPlayerParty()->GetMember(count)->GetState()<<"]"<< endl;
	  }
	  //print all the enemy units out to the screenb.
	  for (; count <(enemies.size() + GameData::GetInstance()->GetPlayerParty()->Size()); count++ )
	  {
	    cout<<count + 1<<". "<< enemies[count - GameData::GetInstance()->GetPlayerParty()->Size()]->GetName() << " [enemy]["<<
	    enemies[count - GameData::GetInstance()->GetPlayerParty()->Size()]->GetState()<<"]"<<endl;
	  }
	}

void BattleEvent::HandleItemSelect() throw(invalid_menu_choice) {
  cout << "Select An Item to Use:" <<"\n--------" << endl;
  vector<Consumable*>::iterator it;

		  vector<Consumable*>* inv = GameData::GetInstance()->GetPlayerConsumeInv();
		  unsigned count = 1;
		  std::string schoice1, schoice2;
		  unsigned ichoice1, ichoice2;
		  bool valid1 = false, valid2 = false;
		  do {
		  try {
		  
		  for (it = inv->begin(); it != inv->end(); ++it) {
		    std::cout << count << "." << (*it)->GetName() << std::endl;
		    count++;
		  }
		  getline(std::cin, schoice1);
		  ichoice1 = atoi(schoice1.c_str());
		  count = 1;
		  if(ichoice1 < 1 || ichoice1 > inv->size())
		    throw invalid_menu_choice();
		  else 
		    valid1 = true;

		  
		  } catch (invalid_menu_choice e) {
		    std::cout << e.what() << std::endl;
		  }

		  } while (valid1 == false);

		  std::cout << "You Selected to use a:  " << inv->at(ichoice1-1)->GetName() << std::endl;
		  do {
		    try {
		    PrintAllTargets();
		    getline(std::cin, schoice2);
		    ichoice2 = atoi(schoice2.c_str());

		    if ( ichoice2 < 1 || ichoice2 > GameData::GetInstance()->GetPlayerParty()->Size() +enemies.size())
		      throw(invalid_menu_choice());
		    else
		      valid2 = true;

		    } catch (invalid_menu_choice e) {
		      std::cout << e.what() << std::endl;
		    }
		  } while (valid2 == false);

		  if (ichoice2 <= GameData::GetInstance()->GetPlayerParty()->Size()) {

		  inv->at(ichoice1-1)->Use(GameData::GetInstance()->GetPlayerParty()->GetMember(ichoice2-1));
		  std::cout << "Selected to use a " << inv->at(ichoice1-1)->GetName() << "on Player " << GameData::GetInstance()->GetPlayerParty()->GetMember(ichoice2-1)->GetName() << std::endl;
		  } else {
		    inv->at(ichoice1-1)->Use(enemies[(ichoice2-1) - GameData::GetInstance()->GetPlayerParty()->Size()]);
		    std::cout << "Selected to use a " << inv->at(ichoice1-1)->GetName() << " on Enemy " << enemies[(ichoice2-1) - GameData::GetInstance()->GetPlayerParty()->Size()]->GetName() << std::endl;
		  }
		  inv->erase(inv->begin()+ichoice1);


}
