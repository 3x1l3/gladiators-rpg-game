/// \file
/// \brief Item Class header file
/// Defines the base class Items for game. This will be used to derive sub item classes
/// later on. The item class is pure abstract
#ifndef ITEM_H
#define ITEM_H

#include<string>

class Item {

private:
 std::string name; ///<Name of the item
 std::string description; ///<Description of the item
 int price; ///< Price of the item.
 
public:
/// \brief Item Default Constructor
/// Simple initialization of strings and int to default values.
 Item() throw();
 
 
 ~Item() throw();
/// \brief Change Item Name
/// Change the name of the current item.
/// \post Item name will be changed
/// \param [in] name
 void SetName(const std::string&) throw();
/// \brief Change Item Description
/// Change the description of the current item.
/// \post Item description will be changed
/// \param [in] desc
 void SetDescription(const std::string&) throw();
/// \brief Change Price Name
/// Change the price of the current item.
/// \post Item price will be changed
/// \param [in] price
 void SetPrice(const int&) throw();

 /// \brief Get the price of the Item
 int GetPrice() throw();

 /// \brief Get the name of the Item
 std::string GetName() throw();

 /// \brief Get the description of the Item
 std::string GetDescription() throw();

 ///\brief Overloading == operator for Item class
 bool operator==(Item* otherItem) throw();
 
 ///\brief clone method to create a copy of the object passed to it
 Item operator=(Item origItem) throw();

};
#endif
