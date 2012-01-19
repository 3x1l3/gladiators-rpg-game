/***************************************************
/// \file
/// \brief Specification file for the 'Exit Game?' Menu
///
/// This is a menu that appears whenever the user decides
/// to quit the game.
/// It presents the user with the option of confirming
/// their request, or returning to their previous menu.
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/
#ifndef EXITMENU_H
#define EXITMENU_H

#include "Menu.h"
#include "Game.h"
#include <string>
#include <list>
using std::list;
using std::string;

class ExitMenu : public Menu(){

      public:

             /// \brief Default constructor for the menu
             /// No expanded/special functionality
             ExitMenu();

             /// \brief Default Destructor
             /// No special functionality, here for posterity.
             ~ExitMenu();

             /// \brief Exit the Program function. Exits the program.
             /// Asks the user if they really want to quit, and closes the program
             /// gracefully if they accept, otherwise it returns/breaks out of RUN.
             ExitProgram()

             /// \brief Function for looping the operations/construction of the menu
             /// Loops menu construction until a correct input is found.
             RUN();

             /// \brief Critical functions as required by the Menu Abstract Parent
             /// As defined in Menu
             /// Tailored to the SaveGameMenu items - writes or 'deletes'
             /// menu items to corrospond to the above functions.
             /// In this case, the options Yes or No
             void AddMenuItem(string menuItem);
             void DeleteMenuItem(string menuItem);
             void DrawMenu();
             void HandleInput();

      private:
             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu
};

#endif
