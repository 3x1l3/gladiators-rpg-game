/***************************************************
/// \file
/// \brief Header File for the Edit Character Menu Class
///
/// This is a menu that is created from the
/// BackstageScreen area.
///
/// It allows the player to change the equipment attached
/// to player characters and view their stats.
/// \author Adam Shepley, RPG Project
/// \author Jason Racine
/// \date November 1st to 10th, And many other days thereafter.
***************************************************/
#ifndef EDITCHARACTERMENU_H
#define EDITCHARACTERMENU_H

#include "Menu.h"
//#include "Game.h"
//#include "BackstageMenu.h"
//#include "UnitEquipment.h"
#include "Item.h"
//#include "Unit.h"
#include "PlayerParty.h"
#include "GameData.h"
#include "exceptions.h"


#include <string>
#include <list>
#include <ctype.h>
#include <stdlib.h>
using std::list;

using std::string;
using std::cout;
using std::cin;
using std::endl;

class EditCharacterMenu : public Menu{

      public:
             /// \brief Default constructor for the Character Edit menu
             /// Not responsible for anything special, yet
             EditCharacterMenu()  throw();

             /// \brief Default Destructor for the Character Edit Menu
             /// Here for posterity.
             ~EditCharacterMenu() throw();

             /// \brief Character Status Display function
             /// Displays the stats about a particular character
             /// The basic menu construction shows the list of characters.
             /// Choosing a character calls this function.
             void ViewCharacterStatus(PlayerCharacter* pc) throw();


             /// \brief Function for running this Menu
             /// Constructs the menu and loops for input until the user chooses
             /// to exit.
             void Run() throw();

             /// \brief Necessary Menu functions called by RUN()
             /// As defined in Menu
             /// Tailored to the EditCharacterMenu items - simply writes or 'deletes'
             /// menu items to corrospond to the above functions.
             /// In this case, Picking a character, the item to change,
             /// and the item to change it to
             void HandleInput() throw(input_format_error);
	     
	     
	     
      private:

             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu
             
             ///\brief Allows for editing of equipment in Right Hand
             ///\param [in] charIndex index location of character needing equipment change in the player party
	     void EditRightHandWeapon(const unsigned& charIndex)throw();
	     
	     ///\brief Allows for editing of equipment in Left Hand
	     ///\param [in] charIndex index location of character needing equipment change in the player party
	     void EditLeftHandWeapon(const unsigned& charIndex)throw();
	     
	     ///\brief Allows for editing of equipment for Chest Armor
	     ///\param [in] charIndex index location of character needing equipment change in the player party
	     void EditChestArmor(const unsigned& charIndex)throw();
	     
	     /// ^^^I realize the above 3 methods are highly repetitive code, but until we can
	     /// find a better solution these work ^^^
};

#endif
