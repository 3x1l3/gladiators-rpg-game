/***************************************************
/// \file
/// \brief header file for the Menu used when fighting a Battle
/// This is the BattleMenu class used when fighting a
/// battle.
/// It needs information from Game.h and BattleEvent.h,
/// and is a subclass/child of the Menu.h object.
/// \date November 1st to 10th
/// \author Adam Shepley, RPG Project
***************************************************/

#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "Menu.h"


#include <string>
#include <list>
#include "stdlib.h"
#include "GameData.h"
using std::list;


using std::string;

class BattleMenu : public Menu{

      public:
             /// \brief Default Constructor
             /// Constructs the menu, may later set currentUnitTurn to 0;
             BattleMenu() throw();

             /// \brief Secondary Constructor to set current turn
	     ///\param [in] curTurn Current turn of the battle
             /// sets currentUnitTurn to curTurn (grabbed from BattleEvent/caller class)
             /// make sure to use GetTurn() from BattleEvent.h
             /// make sure that said function exists!
             BattleMenu(const int curTurn) throw();

             /// \brief Default constructor for posterity.
             ~BattleMenu() throw();



             /// \brief Run function to Run all the menu operations
             /// this calls the appropriate construction and battle functions,
             /// then terminates the object suicidally.
             void Run() throw();

             /// \brief Generic menu functions as defined in the abstract parent Menu Class.
             /// As defined in Menu
             /// Tailored to the BattleMenu items - simply writes or 'deletes'
             /// menu items to corrospond to the above functions.
             //void AddMenuItem(string menuItem);
             //void DeleteMenuItem(string menuItem);
             //void DrawMenu();
             void HandleInput() throw();

      private:
             //...is this supposed to be a player pointer?
             //defaulting to INT for now. Must be same type as curTurn
             //in the constructor.
             int currentUnitTurn; ///< An integer variable to keep track/determine the current player turn

             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu

};

#endif
