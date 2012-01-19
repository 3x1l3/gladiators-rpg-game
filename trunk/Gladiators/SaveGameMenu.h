/***************************************************
/// \file
/// \brief Specification file for the Save Game Menu
///
/// This menu is responsible for carrying out the
/// "savegame" functions, which is basically opening
/// the savegame file (or creating one if there is not
/// one currently) and writing the information to it.
///
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/
#ifndef SAVEGAMEMENU_H
#define SAVEGAMEMENU_H

#include <string>
#include <fstream>
#include "Menu.h"
#include "Game.h"
#include <list>
using std::list;

using std::string;
using std::fstream;

class SaveGameMenu : public Menu(){

      public:
             /// \brief Constructor for the SaveGameMenu
             /// No specializations currently.
             SaveGameMenu();

             /// \brief Destructor for the SaveGameMenu
             /// Here for Posterity.
             ~SaveGameMenu();

             /// \brief Special SaveGameMenu constructor for an existing Fstream
             /// special constructor
             /// used if there's an existing filestream ready to be utilized
             SaveGameMenu(fstream existingFile);

             /// \brief Second Special Constructor for SaveGameMenu
             /// special constuctor
             /// used if there's no stream, but the Filename is known
             /// Prevents needless prompts for a filename
             SaveGameMenu(const string existingFileName);

             /// \brief SaveGame function
             /// Prompts the user for the save file name if there isn't one set
             /// opens the appropriate file, or creates it if it isn't there
             /// They then save the data, if possible, or inform the user
             /// of a failure to do so.
             void SaveGame();

             /// \brief Second SaveGame Function for Existing Stream
             /// Called with a filestream ready
             /// Called from either the Menu or from one of the other functions
             /// Writes gamedata to a file.
             void SaveGame(ofstream outFile);

             /// \brief Savegame function for when the Filename is known
             /// If the filename is stored in a variable but the filestream is
             /// not open, this function is called.
             /// Opens a corresponding filestream with the given filename var
             void SaveGame(const string existingFileName);

             /// \brief Function for Exiting the menu
             /// Exits the save menu class/breaks out of the RUN loop
             void Exit();

             /// \brief Function for running/looping the menu functions
             /// Loops for user input and menu creation.
             void RUN();

             /// \brief Menu functionality as specified in the Menu Abstract Super
             /// As defined in Menu
             /// Tailored to the SaveGameMenu items - writes or 'deletes'
             /// menu items to corrospond to the above functions.
             /// In this case, the options to Save or quit
             void AddMenuItem(const string menuItem);
             void DeleteMenuItem(const string menuItem);
             void DrawMenu();
             void HandleInput();

      private:
              string filename;  ///< String used to store the savefile's name
              ofstream inFile;  ///< Outbound filestream for the Savegame data

              //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu
};

#endif
