#include "EditCharacterMenu.h"

EditCharacterMenu::EditCharacterMenu() throw() {

}

EditCharacterMenu::~EditCharacterMenu()  throw()
{
  //delete choiceList;

}

void EditCharacterMenu::Run() throw() {
	PlayerParty* party = GameData::GetInstance()->GetPlayerParty();
	bool successful = false;


	//populate menu list with names of party members
	for (unsigned i=0; i < party->Size(); i++)
	{
		Menu::AddMenuItem(party->GetMember(i)->GetName());
	}

	do
	{
	    try
	    {
	        std::cout << "Choose A Character to Edit" << std::endl;
		DrawMenu(); //Uses base menu class Draw() to print out the menu list.
		HandleInput();

		successful = true;
	    }
	    catch(input_format_error& e) //catch if user inputs an invalid selection
	    {
	        std::cerr << e.what() << std::endl;
	    }

	}while(!successful);
	Menu::Clear();

}

void EditCharacterMenu::HandleInput() throw(input_format_error)
{
;
 std::cin.sync();
 //std::cin.get();
 //std::cin.ignore();

 string buffer = "";
 unsigned charIndex = 0;

  std::cin >> buffer;

  std::cin.ignore();

  charIndex = atoi(buffer.c_str());

  charIndex -= 1; //To convert from human representation to machine representation starting with 0-index

  if(0 > charIndex || charIndex >= (GameData::GetInstance())->GetPlayerParty()->GetAllMembers().size() )
      throw input_format_error("Invalid choice of party member to edit. Please try again!");

  std::cerr << "" << std::endl;
  PlayerCharacter* pc = GameData::GetInstance()->GetPlayerParty()->GetMember(charIndex);

  unsigned choice = 0; //menu variable in loop
  do
  {

      ViewCharacterStatus(pc);
      //prompt for an action to take

      std::cout << "What would you like to do? " << std::endl << std:: endl
		<< "1. Change Right Hand Weapon" << std::endl
		<< "2. Change Left Hand Weapon" << std::endl
		<< "3. Change Body Armor" << std::endl
		<< "4. Go Back " << std::endl << std::endl;

      std::cin.sync();
      //std::cin.get();
      std::cin >> buffer;
      choice = atoi(buffer.c_str());

      switch(choice)
      {
	  case 1:
	    EditRightHandWeapon(charIndex);
	    break;
	  case 2:
	    EditLeftHandWeapon(charIndex);
	    break;
	  case 3:
	    EditChestArmor(charIndex);
	  default:
	    break;

      }//end switch

  }while(choice != 4);


}

void EditCharacterMenu::EditRightHandWeapon(const unsigned& charIndex) throw()
{
    PlayerCharacter* pc = GameData::GetInstance()->GetPlayerParty()->GetMember(charIndex);
    string inputBuffer = "";
    unsigned choice = -1;
    std::vector<Weapon*> weaps =  *(GameData::GetInstance()->GetPlayerWeaponInv()); //TODO Needs player inventory only

    do
    {
        std::cout << "Currently equipped: " << pc->GetEquipment()->GetRightHandWeapon()->GetName() << std::endl << std::endl;

	std::cout << "What would you like to do?" << endl << endl
		  << "1. Equip Right Hand." << endl
		  << "2. Unequip Right Hand." << endl
		  << "3. Go Back." << endl << endl;

	cin.sync();
	cin.get();

	cin >> inputBuffer;
	choice = atoi(inputBuffer.c_str());

	bool validSelect = false; //bool for testing menu selection for weapon to equip
	switch(choice)
	{
	  case 1:

	    do
	    {
	        cout << "Choose weapon to equip..." << endl;

	        for(unsigned i = 0; i < weaps.size(); i++)
	        {
		    cout << (i+1) << ". " <<  weaps.at(i)->GetName();
		    if(! weaps.at(i)->Usable() )
		        cout << " (E)";
		    cout << endl;
	        }
	        cin.sync();
	        cin.get();
	        try
	        {

		    unsigned index;
		    cin >> inputBuffer;
		    index = atoi(inputBuffer.c_str());

		    index -= 1; //converting human logic to machine logic.

		    if(index < 0 || index >= weaps.size())
		    {
			throw input_format_error("Invalid selection");
		    }
		    try
		    {
		        pc->GetEquipment()->EquipRightHand(weaps[index]);
		        cout << pc->GetEquipment()->GetRightHandWeapon()->GetName() << " equipped to Right Hand" << endl << endl;
		    }
		    catch(unable_to_equip& e)
		    {
		        cout << "------------------------------------" << endl;
			cout << e.what() << endl;
			cout << "------------------------------------" << endl;
		    }
		    validSelect = true;
		}
		catch(input_format_error& e)
		{
		    cout << "------------------------------------" << endl;
		    cout << e.what() << endl;
		    cout << "------------------------------------" << endl;
		}

	    }while(!validSelect);
	    break;
	  case 2:
	    pc->GetEquipment()->UnequipRightHand();
	    break;
	  case 3:
	    //Do nothing, allow control to fall through and exit loop
	    break;
	  default:
	    break;
	}



    }while(choice != 3);

}


void EditCharacterMenu::EditLeftHandWeapon(const unsigned& charIndex) throw()
{
    PlayerCharacter* pc = GameData::GetInstance()->GetPlayerParty()->GetMember(charIndex);
    string inputBuffer = "";
    unsigned choice = -1;
    std::vector<Weapon*> weaps = *(GameData::GetInstance()->GetPlayerWeaponInv()); //TODO Needs player inventory only


    do
    {
        std::cout << "Currently equipped: " << pc->GetEquipment()->GetLeftHandWeapon()->GetName() << std::endl << std::endl;

	std::cout << "What would you like to do?" << endl << endl
		  << "1. Equip Left Hand." << endl
		  << "2. Unequip Left Hand." << endl
		  << "3. Go Back." << endl << endl;

	cin.sync();
	cin.get();

	cin >> inputBuffer;
	choice = atoi(inputBuffer.c_str());
	bool validSelect = false; //bool for testing menu selection for weapon to equip
	switch(choice)
	{
	  case 1:
	    do
	    {
	        try
	        {
		    cout << "Choose weapon to equip..." << endl;

		    for(unsigned i = 0; i < weaps.size(); i++)
		    {
			cout << (i+1) << ". " <<  weaps.at(i)->GetName();
			if(! weaps.at(i)->Usable() )
		        cout << " (E)";
			cout << endl;
		    }
		    cin.sync();
		    cin.get();
		    unsigned index;
		    cin >> inputBuffer;
		    index = atoi(inputBuffer.c_str());

		    index -= 1; //converting human logic to machine logic.

		    if(index < 0 || index >= weaps.size()) //if selection is out of range of indices of inventory
		    {
			throw input_format_error("Invalid selection");
		    }
		    try
		    {

		        pc->GetEquipment()->EquipLeftHand(weaps[index]);
		        cout << pc->GetEquipment()->GetLeftHandWeapon()->GetName() << " equipped to Left Hand" << endl << endl;
		    }
		    catch(unable_to_equip& e) //thrown if weapon cannot be equiped, i.e. is already equipped to self or another unit.
		    {
		        cout << "------------------------------------" << endl;
		        cout << e.what() << endl;
			cout << "------------------------------------" << endl;
		    }
		    validSelect = true;
		}
		catch(input_format_error& e)
		{
		    cout << "------------------------------------" << endl;
		    cout << e.what() << endl;
		    cout << "------------------------------------" << endl;
		}
	    }while(!validSelect);

	    break;
	  case 2:
	    pc->GetEquipment()->UnequipLeftHand();
	    break;
	  case 3:
	    //Do nothing, allow control to fall through and exit loop
	    break;
	  default:
	    break;
	}



    }while(choice != 3);

}

void EditCharacterMenu::EditChestArmor(const unsigned& charIndex) throw()
{
    PlayerCharacter* pc = GameData::GetInstance()->GetPlayerParty()->GetMember(charIndex);
    cout<<"pc name = "<<pc->GetName()<<endl;
    cout<<"member = " <<GameData::GetInstance()->GetPlayerParty()->GetMember(charIndex)->GetName()<<endl;
    string inputBuffer = "";
    unsigned choice = -1;
    std::vector<Armor*> arms = *(GameData::GetInstance()->GetPlayerArmorInv()); //TODO Needs player inventory only


    do
    {
        std::cout << "Currently equipped: " << pc->GetEquipment()->GetChestArmor()->GetName() << std::endl << std::endl;

	std::cout << "What would you like to do?" << endl << endl
		  << "1. Equip Chest." << endl
		  << "2. Unequip Chest." << endl
		  << "3. Go Back." << endl << endl;

	cin.sync();
	cin.get();

	cin >> inputBuffer;
	choice = atoi(inputBuffer.c_str());
	bool validSelect = false; //bool for testing menu selection for weapon to equip
	switch(choice)
	{
	  case 1:

	    do
	    {
	        try
	        {

		    cout << "Choose armor to equip..." << endl;

		    for(unsigned i = 0; i < arms.size(); i++)
		    {
			cout << (i+1) << ". " <<  arms.at(i)->GetName();
			if(! arms.at(i)->Usable() )
		        cout << " (E)";
			cout << endl;
		    }
		    cin.sync();
		    cin.get();
		    unsigned index;
		    cin >> inputBuffer;
		    index = atoi(inputBuffer.c_str());

		    index -= 1; //converting human logic to machine logic.

		    if(index < 0 || index >= arms.size())
		    {
			throw input_format_error("Invalid selection");
		    }

		    try
		    {
			pc->GetEquipment()->EquipChestArmor(arms[index]);
			cout << pc->GetEquipment()->GetChestArmor()->GetName() << " equipped to Chest" << endl << endl;
		    }
		    catch(unable_to_equip& e)
		    {
		        cout << "------------------------------------" << endl;
		        cout << e.what() << endl;
			cout << "------------------------------------" << endl;
		    }

		    validSelect = true;
		}
		catch(input_format_error& e)
		{
		    cout << "------------------------------------" << endl;
		    cout << e.what() << endl;
		    cout << "------------------------------------" << endl;
		}
	    }while(!validSelect);
	    break;
	  case 2:
	    pc->GetEquipment()->UnequipChestArmor();
	    break;
	  case 3:
	    //Do nothing, allow control to fall through and exit loop
	    break;
	  default:
	    break;
	}



    }while(choice != 3);

}

//Displays the player character's current status, including attributes, status and equipment.
void EditCharacterMenu::ViewCharacterStatus(PlayerCharacter* pc)  throw()
{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Name: " << pc->GetName() << std::endl
              << "Level " << pc->GetLevel() << " " << pc->GetJob()->GetJobName() << std::endl
	      << "HP: " << pc->GetMaxHP() << "/" << pc->GetCurrentHP() << std::endl
	      << "Attack: " << pc->GetAttackVal() << std::endl
	      << "Defense: " << pc->GetDefenseVal() << std::endl
	      << "Status: " << pc->GetState() << std::endl //TODO This line segfaults. FIX
	      << "Right Hand: " << pc->GetEquipment()->GetRightHandWeapon()->GetName() << std::endl
	      << "Left Hand: " << pc->GetEquipment()->GetLeftHandWeapon()->GetName() << std::endl
	      << "Body: " << pc->GetEquipment()->GetChestArmor()->GetName() << std::endl;
    std::cout << "------------------------------" << std::endl << std::endl;


}
