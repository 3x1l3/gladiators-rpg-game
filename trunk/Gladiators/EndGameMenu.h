/***************************************************
/// \file
/// \brief Specification file for the 'End Game' Menu
///
/// This menu appears at the end of a game, regardless of
/// whether the user won or not.
/// It is the "end of the chain."
///
/// It presents the user with the option of quitting the
/// game, quitting back to the main menu or
/// loading a gamefile.
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/

#ifndef ENDGAMEMENU_H
#define ENDGAMEMENU_H

#include "Menu.h"
#include "Game.h"

#include <string>
#include <list>
using std::list;

using std::string;

class EndGameMenu : public Menu(){

      public:
             /// \brief Default constructor for the menu
             /// Needs to handle game Object as one will already be existing...
             EndGameMenu();

             /// \brief Default Destructor
             /// Here for Posterity
             ~EndGameMenu();

             /// \brief Function for Loading the Game
             /// an option that will create a LoadGameMenu object and call its run().
             void LoadGame();

             /// \brief A menu choice function for "Quitting" the game
             /// This function will create an ExitMenu object and call its run().
             void Exit();

             /// \brief A function for returning to the main/startofgame menu
             /// "Dials up" the menu chain until we get back to the original game
             /// menu. Alternatively, kills the old game object which sends us
             /// back to the Main file's created menu.
             void ReturnToMenu();

             /// \brief A function to RUN the menu through a loop
             /// Loops the construction of the menu items.
             /// Loops until broken out of by the higher menus or elsewhise
             void RUN();

             /// \brief Critical functions specified by the Menu Abstract
             /// As defined in Menu
             /// Tailored to the EndGameMenu items - simply writes or 'deletes'
             /// menu items to corrospond to the above functions.
             /// In this case, of special note is that "GAME OVER" must be printed
             /// and centered. Bolded, even.
             void AddMenuItem(string menuItem);
             void DeleteMenuItem(string menuItem);
             void DrawMenu();
             void HandleInput();

      private:
             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu
};

#endif
