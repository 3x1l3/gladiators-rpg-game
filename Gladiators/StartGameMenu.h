/***************************************************
/// \file
/// \brief Specification for the Start of Game Menu
///
/// This is the first menu that the users see in the game
/// (a splash screen may be prior, but will have no
/// discernable input).
///
/// It allows the users to start a new game, load an old
/// game from a file or quit the game.
///
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/
#ifndef STARTGAMEMENU_H
#define STARTGAMEMENU_H

#include "Menu.h"
#include "Game.h"

#include <string>
#include <list>
using std::list;

using std::string;

class StartGameMenu : public Menu(){

      public:

             /// \brief Basic Constructor for the Start Game Menu
             /// no specialization
             StartGameMenu();

             /// \brief Basic destructor fot the Start Game Menu
             /// No special handling yet defined.
             ~StartGameMenu();

             /// \brief Menu Function for Creating a New Game
             /// Creates a new Game object using the default/'new' game constructor
             void NewGame();

             /// \brief Function for loading an existing game
             /// Absorbs filename from user to load an existing game
             void LoadGame();

             /// \brief Function for exiting the game
             /// Creates an ExitMenu menu object
             void ExitGame();

             /// \brief Function for running the appropriate Menu functions
             /// Loops the option prompts above
             /// (through) Looping menu construction
             void RUN();

             /// \brief Critical Menu Functionality as specified by the Parent
             /// As defined in Menu
             /// Tailored to the StartGameMenu items - simply writes or 'deletes'
             /// menu items to corrospond to the above functions.
             /// In this case, choosing one of the three above options.
             void AddMenuItem(string menuItem);
             void DeleteMenuItem(string menuItem);
             void DrawMenu();
             void HandleInput();

      private:
             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu


};

#endif
