#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H
/// \file
/// XMLWrapper, this file wraps pugiXML external library to utilize loading
/// and saving to files. 

#include <iostream>
#include <string>
#include <vector>
#include "pugixml.h"


/// Wrapper class to utilize pugiXML the way we want for the game
class XMLWrapper {
private:
  /// Initial Document to load into for pugixml
  pugi::xml_document doc;

  /// Resultant data when pugi loads xml files
  pugi::xml_parse_result result;
  
  /// Multidimentional vector of items. Used for passing later
  std::vector<std::vector<int> > items; 

  /// Multidimentional vector for characters. Used for passing later
  std::vector<std::vector<std::string> > characters; 
  
  /// Store Money for return 
  int money;

  /// store battle number for return
  int battlenumber;
public:
  /// \briefDefault Constructor
  /// Default constructor takes in a file name to read from an XML file.
  /// \param [in] filename
  XMLWrapper(const std::string&);
  
  /// \brief Check if File is GLAD
  /// This function checks the first node to be GLAD and the type is of \a type
  /// \param [in] type
  /// \return bool
  bool isValid(std::string);
  
  /// \brief Load Save File
  /// Method goes through the XML file and extracts information from a properly
  /// constructed XML save File. 
  void LoadSaveFile();

  /// \brief Get Result
  /// Returns the status of the file being loaded. Indecates if error has occured while trying
  /// to load the file.
  std::string getResult();
  
  /// \brief Split String
  /// Method will split a string on a delimiter into a vector of ints.
  /// \param [in] original
  /// \param [in] exploder
  std::vector<int> explodetoInts (std::string, std::string);

  /// \brief Return Item Vector
  /// Item vector is built from Load Save file method. Used to transfer information to
  /// the factory method that will create the objects on runtime.
  /// \return items
  std::vector<std::vector<int> > getItemVector();

  /// \brief Return Character Vector
  /// Character vector is built from load save file method. Used to transfer information into the factory
  /// method. 
  /// \return characters
  std::vector<std::vector<std::string> > getCharacterVector();

  /// \brief Get Money
  /// Return the money that was loaded from the file
  /// \return money
  int getMoney();

  /// \brief Get Battle Number
  /// Return the battle number that was loaded from the file
  /// \return battlenumber
  int getBattleNumber();
    
  };

#endif
