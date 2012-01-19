//Functions for the backstage menu class
//Original author : Jordan Peoples
//Data November 28th 2010

#include "BackstageMenu.h"

#include <sstream>
#include <iostream>
#include <string>

using std::cerr;
using std::endl;
using std::cin;

//Default Constructor
BackstageMenu::BackstageMenu() throw()
{
    store = new StoreMenu();
    currentStory = new StoryEvent();
}
//Default destructor
BackstageMenu::~BackstageMenu() throw()
{
    delete store;
    delete currentStory;
    delete beventPtr;

}
//function to take the player to teh store to buy teh items! teh!
void BackstageMenu::GoToStore() throw()
{
    store->Run();
}
//function that takes the user to the next fight in line
bool BackstageMenu::NextFight() throw()
{
  return true;

}
//function that takes the user to the edit charcters screen
void BackstageMenu::EditCharacters() throw()
{
    EditCharacterMenu* edMenu;
    edMenu = new EditCharacterMenu();
    edMenu->Run();
    delete edMenu;
}
//functio to save the game
void BackstageMenu::SaveGame() throw()
{

}
//function to quit to main
void BackstageMenu::QuitToMain() throw()
{
  //clean up data
  return;
}
//function to check if the user has won the game
void BackstageMenu::CheckWin() throw()
{
  //DO SOMETHING!!
}
//functoin to run the backstage menu.
void BackstageMenu::Run() throw()
{
  currentStory->PrintStory(0);
  //int to hold the user choice after string conversion
  int choice = -1;
  //adding the menu objects to the menu se we can print them later
  Menu::AddMenuItem("Go To Next Fight!");
  Menu::AddMenuItem("Go To The Store");
  Menu::AddMenuItem("Edit Your Characters");
  Menu::AddMenuItem("Save Your Game");
  Menu::AddMenuItem("Exit Game");

  //do this loop while the users choice is not bwetween 1 and 5
  do
  {

    //make sure all of the characters are alive
    //and level them up!
    for(unsigned i = 0; i<GameData::GetInstance()->GetPlayerParty()->Size(); i++)
    {
        GameData::GetInstance()->GetPlayerParty()->GetMember(i)->MakeAlive();
        GameData::GetInstance()->GetPlayerParty()->GetMember(i)->SetCurrentHP(
            GameData::GetInstance()->GetPlayerParty()->GetMember(i)->GetMaxHP()
        );
    }
    //print the banner
    system("clear");
    cerr<<"-------------------------------------------------------------"<<endl;
  //  cerr<<"You Are Out Of The Coluseum..."<<std::endl;
  //  cerr<<"You see a bustling dusty street, with people and animals alike blasted by the smoltering sun."<<std::endl;
    cerr<<endl<<endl;

    //draw the menu
    Menu::DrawMenu();
    //sting to grab the users input
    string userInput;
    //grabbing the user input
    cin>>userInput;
    //converting the users choice to a int
    choice = atoi(userInput.c_str());


    HandleInput2(choice);

  }while(choice != 5);
  //while (choice > 5 || choice < 1);






}
//function to handlk he intiial user input in the backstagemenu.run()
void BackstageMenu::HandleInput2(const int userChoice) throw()
{
  //make new battle event
  BattleEvent * currentBattle;



  switch (userChoice)
      {
      case 1:
	//next fight

	currentBattle = new BattleEvent();
	currentBattle->Run();
	GameData::GetInstance()->GetBattleNumber()->increment();
    currentStory->PrintStory(GameData::GetInstance()->GetBattleNumber()->get());

    for(unsigned i = 0; i<GameData::GetInstance()->GetPlayerParty()->Size(); i++)
    {
        GameData::GetInstance()->GetPlayerParty()->GetMember(i)->LevelUp();
    }
    delete currentBattle;






	//GetPlayerConsumInv
	//GetPlayerConsumInv
	break;
      case 2:
            GoToStore();
	//go to the store
	//store menu
	break;
      case 3:
	    EditCharacters();
	break;
      case 4:
	GameData::GetInstance()->Save();
	break;
      case 5:
	//exit the game
	//prompt and then exit! or not............. :O:O:O:O:O:O:O:O:O:O
	break;
      }
}

void BackstageMenu::HandleInput() throw()
{}

