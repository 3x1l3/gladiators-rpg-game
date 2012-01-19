#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdlib.h>


#include "Money.h"
#include "Money.cc"
#include "Job.h"
#include "Job.cc"
#include "Unit.h"
#include "Unit.cc"
#include "PlayerCharacter.h"
#include "PlayerCharacter.cc"
#include "Wizard.h"
#include "Wizard.cc"
#include "Archer.h"
#include "Archer.cc"
#include "Paladin.h"
#include "Paladin.cc"
#include "State.h"
#include "State.cc"
#include "Dead.h"
#include "Dead.cc"
#include "Normal.h"
#include "Normal.cc"
#include "UnitEquipment.h"
#include "UnitEquipment.cc"
#include "Weapon.h"
#include "Weapon.cc"
#include "Equipable.h"
#include "Equipable.cc"
#include "Item.h"
#include "Item.cc"
#include "Armor.h"
#include "Armor.cc"
#include "EnemyCharacter.h"
#include "EnemyCharacter.cc"
#include "Commoner.h"
#include "Commoner.cc"


using std::cout;
using std::cin;
using std::endl;
using std::string;


int main (void)
{
    //TESTING THE MONEY OBJECTS/////////////////////////////////////////////////
    cout<<"TESTING MONEY"<<endl;
    Money *money = new Money();
    
    money->IncreaseMoney(123);
    cout<<"123 = "<<money->GetMoney()<<endl;
    
    money->DecreaseMoney(-123);
    cout<<"0 = "<<money->GetMoney()<<endl;
    
    money->SetMoney(-300);
    cout<<"300 = "<<money->GetMoney()<<endl;
    
    int fresh;
    
    fresh = money->GetMoney();
    cout<<"300 = "<<fresh<<endl;
    
    money->IncreaseMoney(300);
    cout<<"600 = "<<money->GetMoney()<<endl;
    
    money->DecreaseMoney(200);
    cout<<"400 = "<<money->GetMoney()<<endl;
    
    fresh = money->GetMoney();
    cout<<"400 = "<<fresh<<endl;
    
    cout<<"END TESTING MONEY"<<endl;
    //END TESTING MONEY/////////////////////////////////////////////////////////
    
    //TESTING DECIMAL ROUNDING//////////////////////////////////////////////////
    cout<<endl;
    cout<<"TESTING DECIMAL ROUNDING START"<<endl;
    int frank = 33;
    
    int frank2 = frank / 32;
    
    cout<<frank2<<endl;
    cout<<frank2 /2 <<endl;
    cout<<frank2 /4 <<endl;
    cout<<"TESTING DECIMAL ROUNDING END"<<endl;
    //END TESTING DECIMAL ROUNDINGS/////////////////////////////////////////////
    
    //TESTING JOB///////////////////////////////////////////////////////////////
    cout<<endl;
    cout<<"TESTING JOB START"<<endl;
    
    PlayerCharacter* pc = new  PlayerCharacter( "Nograd", 5, 500, 64, 
              40, "Archer", 1, 1, 1, 10000 );
    

    
    cout<< pc->GetJobName()<<endl
        <<"Name: " << pc->GetName() << endl
        <<"Level: "  << pc->GetLevel() << endl
        <<"Max HP: " << pc->GetMaxHP() << endl
        <<"Attack: " << pc->GetAttackVal() << endl
	<<"Defense: " << pc->GetDefenseVal() << endl
	<<"EXP: " << pc->GetExperience() << endl;
    
    pc->LevelUp();
    cout<<"Leveled Up!"<<endl; 
    
    pc->SetJob(NULL);
    
    
    cout << pc->GetLevel() << endl
         << pc->GetMaxHP() << endl
         << pc->GetAttackVal() << endl
         << pc->GetDefenseVal() << endl;
    
    cout << pc->GetJob()->GetJobName() << endl;

    Wizard *frank1 = new Wizard();
    
    PlayerCharacter * OvidThePerv = new PlayerCharacter();
    PlayerCharacter * JoanOfArc = new PlayerCharacter();
    
    OvidThePerv->SetJob(new Paladin);
    JoanOfArc->SetJob(new Archer);
    cout<<"///////////////////////////"<<endl;
    cout<<OvidThePerv->GetState()<<endl;
    OvidThePerv->SetMaxHP(2342);
    OvidThePerv->SetCurrentHP(OvidThePerv->GetMaxHP());
    cout<<"HP = " <<OvidThePerv->GetMaxHP()<<endl;
    OvidThePerv->TakeDamage(1500);
    cout<<"Attack 1500 - now HP = " <<OvidThePerv->GetCurrentHP()<<endl;
    OvidThePerv->TakeDamage(3000);
    cout<<"Attack 3000 - hp = " <<OvidThePerv->GetCurrentHP()<<endl;
    cout<<OvidThePerv->GetState()<<endl;
    cout<<"///////////////////////////"<<endl;

    cout<<"END TESTING JOB"<<endl;
    //END TESTING JOBS//////////////////////////////////////////////////////////
    
    //Test ITEMS on PLAYERCHARACTERS///////////////////////////////////////////
    cout << JoanOfArc->GetMaxHP() << endl;
    cout << "Joan of Arc Left Weapon Name: " << JoanOfArc->GetEquipment()->GetLeftHandWeapon()->GetName() << endl;
    cout << "Joan of Arc Left Weapon Attack: " << JoanOfArc->GetEquipment()->GetLeftHandWeapon()->GetAttackValue() << endl;
    cout << "Joan of Arc Right Weapon Attack: " << JoanOfArc->GetEquipment()->GetRightHandWeapon()->GetAttackValue() << endl;
    cout << "Joan of Arc Armor Name: " << JoanOfArc->GetEquipment()->GetChestArmor()->GetName() << endl;
    cout << "Joan of Arc Armor Defense Value: " << JoanOfArc->GetEquipment()->GetChestArmor()->GetDefenseValue() << endl;
    cout << "Joan of Arc Armor Description: " << JoanOfArc->GetEquipment()->GetChestArmor()->GetDescription() << endl;
    
    JoanOfArc->GetEquipment()->UnequipLeftHand();
    JoanOfArc->GetEquipment()->EquipLeftHand( (new Weapon("New Weapon", "This is new", 100, 10000)) );
    
    cout << "New Joan of Arc Weapon" << endl;
    cout << JoanOfArc->GetEquipment()->GetLeftHandWeapon()->GetName() << endl;
    cout << JoanOfArc->GetEquipment()->GetLeftHandWeapon()->GetDescription() << endl;
    
    JoanOfArc->GetEquipment()->UnequipRightHand();
    cout << JoanOfArc->GetEquipment()->GetRightHandWeapon()->GetName() << endl;
    
    
    
    //END TEST ITEMS ON PLAYER CHARS///////////////////////////////////////////
    
    
    
    //TESTING VECTORS///////////////////////////////////////////////////////////
    cout<<endl;
    cout<<"TESTING VECTORS START"<<endl;
    
    vector <int> AllWeapons;
    vector <int*> PlayerOwnedWeapons;
    int* rightHand;
    
    AllWeapons.push_back(5);
    
    cout << &AllWeapons[0] << endl;
    
    PlayerOwnedWeapons.push_back( &AllWeapons[0] );
    
    cout << *PlayerOwnedWeapons[0] << endl;
    
    rightHand = PlayerOwnedWeapons[0];
    
    cout << *rightHand << endl;
    
    *rightHand = 9;
    
    cout << *rightHand << endl << *PlayerOwnedWeapons[0] << endl << AllWeapons[0];
    
    cout<<"TESTING VECTORS END"<<endl;
    //END TESTING VECTORS///////////////////////////////////////////////////////
    
    //Testing enemy character/////////////////////////////////////////////////
    EnemyCharacter* BobTheVile = new EnemyCharacter();
    cout << BobTheVile->GetName() << endl
         << BobTheVile->GetMaxHP() << endl;
	
    BobTheVile->SetName("Bob the Vile");
    
    cout << BobTheVile->GetName() << endl
         << BobTheVile->GetAttackVal() << endl
         << BobTheVile->GetEquipment()->GetLeftHandWeapon()->GetName() << endl
         << BobTheVile->GetEquipment()->GetLeftHandWeapon()->GetAttackValue() << endl;
	 
	 BobTheVile->SetExpGiven(9001);
	 
    cout << "Bob the Vile has been slain!" << endl << endl
         << "Exp awarded: " << BobTheVile->GetExpGiven() << endl;
	 
    //DONE Testing ENEMY CHARACTERS ///////////////////////////////////////////
    
    cin.get();
    cin.sync();
    return 0;
}
