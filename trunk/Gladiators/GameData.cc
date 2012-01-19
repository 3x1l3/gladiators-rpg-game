///\file Implementation of GameData object.

#include "GameData.h"
#include <fstream>

using std::vector;
using std::cerr;
using std::cout;
using std::endl;

//Need to #include in .cc file too? Or is it enough to be included in the .h?


//GameData::instance = NULL;

///Default constructor for GameData object
GameData::GameData() throw()
{

    money = new Money();
    battleNumber = new BattleNumber();
    playerParty = new PlayerParty();
    enemyParty = new EnemyParty();

    DefineArmor();
    DefineWeapons();
    DefineConsumables();

    ///This needs some hard coding of Parties for enemies, but how?
    //EnemiesByLevel[1] = new EnemyParty();
    //EnemiesByLevel[2] = new EnemyParty();
    //EnemiesByLevel[3] = new EnemyParty();

    EnemyCharacter * enemy;

    for (int i = 0; i<100; i++)
    {
       enemy = new EnemyCharacter();
       //TODO fix the name of the enemy so there always different.

       std::ostringstream ss;
       ss << i + 1;

       enemy->SetName("Enemy" + ss.str());
       enemy->SetMaxHP(i+10);
       enemy->SetCurrentHP(enemy->GetMaxHP());
       enemy->SetAttackValue(i+10);
       enemy->SetDefenseValue(i+10);
       enemyParty->AddMember(enemy);
    }
}

///Destructor for GameData
GameData::~GameData() throw()
{
    delete money;
    delete battleNumber;
    delete playerParty;
    delete enemyParty;

    for (unsigned i = 0; i < playerConsumableInventory.size(); i ++)
      delete playerConsumableInventory[i];

    for (unsigned i = 0; i < playerArmorInventory.size(); i ++)
      delete playerArmorInventory[i];

    for (unsigned i = 0; i < playerWeaponInventory.size(); i++)
      delete playerWeaponInventory[i];

    for (unsigned i = 0; i< allConsumable.size(); i++)
      delete allConsumable[i];

    for (unsigned i = 0; i < allArmor.size(); i++)
      delete allArmor[i];

    for (unsigned i = 0; i < allWeapon.size(); i ++)
      delete allWeapon[i];

    playerConsumableInventory.clear();
    playerArmorInventory.clear();
    playerWeaponInventory.clear();
    allConsumable.clear();
    allArmor.clear();
    allWeapon.clear();

    created = false;
    delete  instance;
}

void GameData::DestroyInstance() throw()
{
  std::cin.get();
    if(instance != NULL)
        delete instance;
    else
        return;
}

		///   ***   Accessor methods   ***   ///


///\brief Get an instance of the GameData object
GameData* GameData::GetInstance() throw()
{
    if(!created)
    {
	instance = new GameData();
	created = true;
    }
    return instance;
}

///\brief Accessor for Money object
Money* GameData::GetMoney() throw()
{
    return money;
}

BattleNumber* GameData::GetBattleNumber() throw()
{
    return battleNumber;
}

PlayerParty* GameData::GetPlayerParty() throw()
{
    return playerParty;
}

EnemyParty* GameData::GetEnemyParty() throw()
{
    return enemyParty;
}

vector <Consumable*>* GameData::GetPlayerConsumeInv() throw()
{
    return &playerConsumableInventory;
}

vector <Armor*>* GameData::GetPlayerArmorInv() throw()
{
    return &playerArmorInventory;
}

vector <Weapon*>* GameData::GetPlayerWeaponInv() throw()
{
    return &playerWeaponInventory;
}

vector <Consumable*> GameData::GetAllConsume() throw()
{
    return allConsumable;
}

vector <Armor*> GameData::GetAllArmor() throw()
{
    return allArmor;
}

vector <Weapon*> GameData::GetAllWeapons() throw()
{
    return allWeapon;
}

//Settlers (settlers)
void GameData::SetMoney(Money * money) throw()
{
  this->money = money;
}
void GameData::SetBattleNumber(BattleNumber * number) throw()
{
  this->battleNumber = number;
}
void GameData::SetPlayerParty(PlayerParty * playerParty) throw()
{
  this->playerParty = playerParty;
}
void GameData::SetEnemyParty(EnemyParty * enemyParty) throw()
{
  this->enemyParty = enemyParty;
}
void GameData::SetPlayerConsumeInv(std::vector<Consumable*> playerConsumInv) throw()
{
  this->playerConsumableInventory = playerConsumInv;
}
void GameData::SetPlayerArmorInv(std::vector <Armor * > playerArmorInv) throw()
{
  this->playerArmorInventory = playerArmorInv;
}
void GameData::SetPlayerWeaponInv(std::vector <Weapon *> playerWeaponInv) throw()
{
  this->playerWeaponInventory = playerWeaponInv;
}
void GameData::SetAllConsume(std::vector <Consumable*> allConsum) throw()
{
  this->allConsumable = allConsum;
}
void GameData::SetAllArmor(std::vector <Armor*> allArmor) throw()
{
  this->allArmor = allArmor;
}
void GameData::SetAllWeapons(std::vector <Weapon*> allWeapon) throw()
{
  this->allWeapon = allWeapon;
}




void GameData::PrintParty() throw()
{
    cerr<<"NAME"<<"\t\t\t"<<"JOB"<<"\t\t\t"<<"HP"<<endl;
    cerr<<"-----------------------------------------------------------------------------"<<endl;
    for (unsigned i = 0; i < (GameData::GetInstance()->GetPlayerParty()->Size());i++)
    {
      cout<<GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetName();
      cout<<"\t\t\t";
      cout<<GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetJob()->GetJobName();
      cout<<"\t\t\t";
      cout<<GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetCurrentHP();
      cout<<"/";
      cout<<GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetMaxHP();
      cout<<endl;
    }
}

	/// New, Save, and Load Game. Needs XML parser! //

void GameData::New() throw()
{
  CharacterCreationMenu* createMenu = new CharacterCreationMenu(MAX_PARTY_SIZE);

  createMenu->Run();
  playerParty = createMenu->GetParty();



  delete createMenu;
}


//saves the game to a file
void GameData::Save() throw()
{
    std::string fileName;
    std::cout << "\nPlease enter the name of the file you want to save to: ";
    std::cin >> fileName;

    std::ofstream myFile;
    if(!myFile)
        throw invalid_file("Invalid file error!");
    myFile.open(fileName.c_str());
    myFile << "<?xml version=\"1.0\" ?>\n";
    myFile << "<GLAD type=\"save\">\n";
    myFile << "  <Money>" << GetMoney()->GetMoney() << "</Money>\n";
    myFile << "  <BattleNumber>" << GetBattleNumber()->get()+1 << "</BattleNumber>\n\n";
    myFile << "  <Inventory>\n    <Weapons>";

    //write the weapons to the file by indice compared to all weapons vector
    for(unsigned int i = 0; i < GetPlayerWeaponInv()->size(); i++)
    {
        for(unsigned int x = 0; x < GetAllWeapons().size(); x++)
        {
            if(GetPlayerWeaponInv()->at(i)->GetName() == GetAllWeapons().at(x)->GetName())
            {
                myFile << x;
                if((i != GetPlayerWeaponInv()->size()-1))
                {
                    myFile << ",";
                }

            }
        }
    }
    myFile << "</Weapons>\n";
    myFile << "    <Armor>";

    for(unsigned int i = 0; i < GetPlayerArmorInv()->size(); i++)
    {
        for(unsigned int x = 0; x < GetAllArmor().size(); x++)
        {
            if(GetPlayerArmorInv()->at(i)->GetName() == GetAllArmor().at(x)->GetName())
            {
                myFile << x;
                if((i != GetPlayerArmorInv()->size()-1))
                {
                    myFile << ",";
                }

            }
        }
    }

    myFile << "</Armor>\n";
    myFile << "    <Consumeable>";

    for(unsigned int i = 0; i < GetPlayerConsumeInv()->size(); i++)
    {
        for(unsigned int x = 0; x < GetAllConsume().size(); x++)
        {
            if(GetPlayerConsumeInv()->at(i)->GetName() == GetAllConsume().at(x)->GetName())
            {
                myFile << x;
                if((i != GetPlayerConsumeInv()->size()-1))
                {
                    myFile << ",";
                }

            }
        }
    }
    myFile << "</Consumeable>\n";
    myFile << "  </Inventory>\n";

    myFile << "  <Party>\n";

    for(unsigned int i = 0; i < GetPlayerParty()->Size(); i++)
    {
        myFile << "    <Character>\n";
        myFile << "      <Name>" << GetPlayerParty()->GetMember(i)->GetName() << "</Name>\n";
        myFile << "      <Level>" << GetPlayerParty()->GetMember(i)->GetLevel() << "</Level>\n";
        myFile << "      <Equipment>\n    <LeftHand>";

        for(unsigned int x = 0; x < GetAllWeapons().size(); x++)
        {
            if(GetPlayerParty()->GetMember(i)->GetEquipment()->GetLeftHandWeapon()->GetName()
                == GetAllWeapons().at(x)->GetName())
            {
                myFile << x;
                break;
            }
        }
        myFile << "</LeftHand>\n";
        myFile << "    <RightHand>";
        for(unsigned int x = 0; x < GetAllWeapons().size(); x++)
        {
            if(GetPlayerParty()->GetMember(i)->GetEquipment()->GetRightHandWeapon()->GetName()
                == GetAllWeapons().at(x)->GetName())
            {
                myFile << x;
                break;
            }
        }
        myFile << "</RightHand>\n";

        myFile << "    <Chest>";
        for(unsigned int x = 0; x < GetAllArmor().size(); x++)
        {
            if(GetPlayerParty()->GetMember(i)->GetEquipment()->GetChestArmor()->GetName()
                == GetAllArmor().at(x)->GetName())
            {
                myFile << x;
                break;
            }
        }
        myFile << "</Chest>\n";
        myFile << "      </Equipment>\n";

        myFile << "      <Attack>" << GetPlayerParty()->GetMember(i)->GetAttackVal() << "</Attack>\n";
        myFile << "      <Defence>" << GetPlayerParty()->GetMember(i)->GetDefenseVal() << "</Defence>\n";
        myFile << "      <Job>" << GetPlayerParty()->GetMember(i)->GetJob()->GetJobName() << "</Job>\n";
        myFile << "      <HP>" << GetPlayerParty()->GetMember(i)->GetMaxHP() << "</HP>\n";
        myFile << "      <Experience>" << GetPlayerParty()->GetMember(i)->GetExperience() << "</Experience>\n";

        myFile << "    </Character>\n";
    }
    myFile << "\n  </Party>\n";
    myFile << "\n</GLAD>\n";

    myFile.close();

    cout << "\nSavefile " << fileName << " successfuly saved!" << endl;
    cout << "Press Enter to continue." << endl;
    std::cin.ignore();
    std::cin.get();

}

void GameData::Load() throw()
{

  std::string filename;
  std::cout << "Please enter the file name you wish to load: ";
  std::cin.sync();
  getline(std::cin, filename);
  std::cout << "\nLoading File. Press ENTER to continue." << endl;
  std::cin.ignore();
          std::cerr << filename << std::endl;
  XMLWrapper* XML = new XMLWrapper(filename);
  try
  {
    XML->LoadSaveFile();
  }
  catch(invalid_file e)
  {
      std::cout << "Invalid file? Message reads:\n" << e.what() << std::endl;throw;
      return;
  }
  money = new Money(XML->getMoney());
  ConvertData* data = new ConvertData(XML->getItemVector(), XML->getCharacterVector());
  data->BuildParty();
  playerParty = data->getParty();
  playerWeaponInventory = data->BuildWeapons(GetAllWeapons());
  playerArmorInventory = data->BuildArmor(GetAllArmor());
  playerConsumableInventory = data->BuildConsumables(GetAllConsume());
  delete data; delete XML;


  //Testing

  std::cout << "\nFile Loaded Successfully!\nPress ENTER to continue." << endl;
  //std::cerr << "after for loop" << std::endl;
  std::cin.sync();
  std::cin.get();

}

void GameData::DefineConsumables() throw()
{
  allConsumable.push_back(new PotionItem("Potion", "+30 HP", 50, 30));
  allConsumable.push_back(new PotionItem("Super Potion", "+60 HP", 100, 60));
  allConsumable.push_back(new PotionItem("Hyper Potion", "+150 HP", 200, 150));
  allConsumable.push_back(new PotionItem("Massive Potion", "+500 HP", 400, 500));
  allConsumable.push_back(new PotionItem("Swift Potion", "+800 HP", 650, 800));
  allConsumable.push_back(new PotionItem("Mega Potion", "+1250 HP", 875, 1250));
  allConsumable.push_back(new PotionItem("Full Life", "+999999 HP", 2500, 999999));
}

void GameData::DefineArmor() throw()
{
  allArmor.push_back(new Armor("Chain Mail", "Chain mail that protects from most attacks", 200, 5));
  allArmor.push_back(new Armor("Dragon Armor", "Armor made from dragon haide", 300, 10));
  allArmor.push_back(new Armor("Hoodie", "What? Hoodie? Whats that gonna do?", 1000, 3));
  allArmor.push_back(new Armor("Mythril Suit", "Suit made of Mythril, strong", 1000, 20));
	allArmor.push_back(new Armor("Tunic", "Kakori Green Tunic FTW!", 10, 5));
}

void GameData::DefineWeapons() throw()
{
  allWeapon.push_back(new Weapon("Wooden Sword", "Sword that is absolutely useless", 10, 0, 0));
  allWeapon.push_back(new Weapon("Wooden Shield", "Shield that is useless against attack", 10, 0, 4));
  allWeapon.push_back(new Weapon("Kakori Sword", "Sword that was made in the distant land of Hyrule",50, 5, 0));
  allWeapon.push_back(new Weapon("Hylian Shield", "Steal shield from the distant land of Hyrule", 50, 10, 14));
  allWeapon.push_back(new Weapon("Keyblade","Its a key! Wtf?", 300, 20, 5));
  allWeapon.push_back(new Weapon("Bow","Regular bow.", 250, 15, 0));
  allWeapon.push_back(new Weapon("Wand", "Just a wand", 120, 1, 2));
}

bool GameData::created = false;
GameData* GameData::instance;
