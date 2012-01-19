/***************************************************
/// \brief Headerfile for the Character Creation Menu
///
/// This menu is used to create new characters when the
/// player selects "New Game" from the beginning game
/// menu.
///
/// It allows them to specify the name and job of the
/// characters.
///
/// Any future expansions upon character statuses would
/// need to be implimented here.
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/

#ifndef CHARACTERCREATIONMENU_H
#define CHARACTERCREATIONMENU_H

#include "Menu.h"
//#include "Game.h"
#include "PlayerCharacter.h"
#include "Unit.h"
#include "Job.h"
#include "Paladin.h"
#include "Wizard.h"
#include "Archer.h"
#include "PlayerParty.h"
#include "GameData.h"

#include <string>
#include <list>
using std::list;

using std::string;

class CharacterCreationMenu : public virtual Menu
{

      public:
             /// \brief Default Constructor
             ///Constructor that may later set maxCharacters to 4.
             CharacterCreationMenu() throw();

             /// \brief Default Destructor
             /// Here for posterity, may find later uses.
             ~CharacterCreationMenu() throw();

             /// \brief Constructor that sets a limit on player characters
             /// special constructor that can be used to impliment a difficulty
             /// setting by simply restricting the amount ofplayer chars allowed
             CharacterCreationMenu(const int maxChar) throw();

             /// \brief RUN function that calls the appropriate menu functions
             /// loops the character creation menu creation/process
             /// until the max amount of characters has been created
             void Run() throw();
	     /// Method to handle input for the character creation menu
	     /// \param [in] pc
	     /// \param [in] choice
             void HandleInput2(PlayerCharacter*, const int&, const string charactername) throw();
             void HandleInput() throw();
	     /// Get the party that will be constructed in the Run function
	     PlayerParty* GetParty() throw();

      private:
             //the maximum number of characters the player can create
             //defaults to 4 via the default constructor
             int maxCharacters; ///< an integer establishing the upper character limit
	     PlayerParty* party; //<
};

#endif
