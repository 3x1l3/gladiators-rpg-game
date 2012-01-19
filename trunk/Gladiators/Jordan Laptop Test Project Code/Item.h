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
 Item();
 
 
 ~Item();
/// \brief Change Item Name
/// Change the name of the current item.
/// \post Item name will be changed
/// \param [in] name
 void SetName(const std::string&);
/// \brief Change Item Description
/// Change the description of the current item.
/// \post Item description will be changed
/// \param [in] desc
 void SetDescription(const std::string&);
/// \brief Change Price Name
/// Change the price of the current item.
/// \post Item price will be changed
/// \param [in] price
 void SetPrice(const int&);

 /// \brief Get the price of the Item
 int GetPrice();

 /// \brief Get the name of the Item
 std::string GetName();

 /// \brief Get the description of the Item
 std::string GetDescription();



};
#endif
