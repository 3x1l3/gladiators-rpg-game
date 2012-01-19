/**************************************************************
/// \file
/// \brief Specification for the base/super Menu Abstract Class
///
/// Base Menu Class used to define the constructory
/// attributes of the other menus.
///
/// There is a problem in that if it's pure/virtual,
/// it should not have a defined data member (in this
/// case, the list of menu contents).
///
/// Game.h is included because of its importance to
/// the sub menus.
///
/// I'm not too sure of if it is needed here, but
/// for posterity, I put it here.
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
**************************************************************/

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <iostream>



class Menu
{

      public:

             /// \brief Default constructor for the abstract menu
             /// no given specialized constructions defined at this level
	     Menu() throw();

             /// \brief Virtual Destructor for the Menu Class
             /// virtual destructor to ensure properly ordered child destruction
             virtual ~Menu() throw();

             //under the assumptions that no confirmation is passed back,
             //and that confirmation is the default outcome,
             //with exceptions being handled within these functions.

             /// \brief Function for 'adding' a menu item to display
             /// adds a menu item to the display list that will later be drawn
             /// Increases the number of items in the Menulist
             /// Different for EACH subclass.
             void AddMenuItem(const std::string&) throw();

             /// \brief Function for 'deleting' (removing) a menu item from display
             /// defines an item NOT to be rendered by DrawMenu
             /// Removes values held in the Menulist
             /// Different for EACH subclass
	     void DeleteMenuItem(const int& menuItem) throw();

             /// \brief Function for Drawing the menu itself
             /// Using the MenuList, it draws the appropriate menu options to the screen
             /// May call "HandleInput" on its own in special cases;
             /// Will usually defer to the RUN function for further functionality
             /// Specialized for each child menu.
             void DrawMenu() throw();

	     /// Clear all menu items from the list.
	     void Clear() throw();

             /// \brief Function for handling the input for a menu class
             /// Waits for the appropriate/corresponding input for a menu
             /// Calls the appropriate Menu's member routines for a given input.
             virtual void HandleInput() = 0;

	     /// \brief Function for running the menu, looping between Drawing the menu
	     /// \brief and Handling the input
	     /// Runs the Menu, displaying the menu and waiting for user input until the appropriate exit condition
	     virtual void Run() = 0;

      private:
	     std::vector<std::string> menuitems;

};

#endif
