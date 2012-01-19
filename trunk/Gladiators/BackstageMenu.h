/***************************************************
/// \file
///
/// \brief Small header file for the Backstage Screen Menu class
///
/// This is one of the core classes of the game, which
/// defines the Backstage Menu area.
///
/// "Run" will contain a loop that will repeatedly run the
/// core functions and wait for input.
///
/// It should be assumed that any function that creates
/// an object will destroy/cleanup that object before the
/// function finishes.
///
/// 'userOption' denotes a visible menu object that the
/// user can choose.
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/

#ifndef BACKSTAGEMENU_H
#define BACKSTAGEMENU_H

#include "Menu.h"
#include "GameData.h"
#include "BattleEvent.h"
#include "EditCharacterMenu.h"
#include "StoreMenu.h"
#include "StoryEvent.h"

#include <string>
#include <list>
using std::list;

using std::string;

class BackstageMenu : public virtual Menu
{

      public:
             /// \brief Default Constructor for Backstage Menu
  BackstageMenu() throw();

	     /// \brief Default Destructor for Backstage Menu
	     /// Used in case we want to destroy it remotely with special considerations
             ~BackstageMenu() throw();

             //userOption
             /// \brief Function that generates Backstage StoreMenu class object
             /// can be called multiple times to go to the Store
             void GoToStore() throw();

             //userOption
	     /// \brief NextFight function creates the next 'Fight'
             /// prompts the next fight event to occur
             /// this function calls *beventPtr's .RUN() function
             /// all three should cascade back a boolean value (win or loss)
             bool NextFight() throw();

             //userOption

	     /// \brief Creates an Edit Character menu for character trait adjustment
             /// Creates an EditCharacterMenu object and uses its run function
             /// may need to pass additional information in?
             void EditCharacters() throw();

             //userOption
	         /// \brief Sends the user to/creates a Save Menu
             /// creates a SaveGame menu. Allows the user to save their game,
             /// save and quit, etc. and will call destructors or pass destruction
             /// information appropriately.
             void SaveGame() throw();

             //userOption
	         /// \brief Quits to the Main/Start Menu
             /// Allows the user to quit back to the main menu.
             /// Informs them of loss of game progress.
             void QuitToMain() throw();


	         /// \brief Checks if the player won the game
	         /// Checks if the player won the last event he was privy to.
             /// 'Wins' are defined as meeting the objective, which may not
             /// always be 'not dying' (i.e. unwinnable battles)
             void CheckWin() throw();

             /// \brief RUNs the appropriate menu functions
             /// Calls the appropriate functions for the menu to be constructed
             /// and to continue creating events, waiting for user input, etc.
             /// This houses a 'near-infinite' loop which continues until CheckWin
             /// discovers a WIN (of the whole game) or until a BattleMenu finds a
             /// loss and kills to the EndGame menu.
             void Run() throw();

             /// \brief Generic menu functions as defined in the abstract parent Menu Class.
             /// As defined in Menu
             /// Tailored to the BackstageMenu items - simply writes or 'deletes'
             /// menu items to corrospond to the above functions.
          //   void AddMenuItem(string menuItem);
       //      void DeleteMenuItem(string menuItem);
            // void DrawMenu();
	     void HandleInput() throw();
             void HandleInput2(const int userChoice) throw();

      private:

             //a basic string list for the menu contents
             //list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu
             BattleEvent *beventPtr; ///< A Pointer to a corresponding battleEvent/list.
             StoreMenu *store;
             StoryEvent *currentStory;



};

#endif
