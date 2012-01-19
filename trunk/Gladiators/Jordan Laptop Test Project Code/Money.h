#ifndef MONEY_H
#define MONEY_H

#include "Item.h"
#include "Equipable.h"

class Money
{
      private:
              ///\brief integer to hold the total money
             int money;
              
              
      public:
             ///\brief default contrsutor - setting money to 0
             Money();
             ///\brief destructor
             ~Money();
             ///\brief function that takes in a int and adds it to the money variable
             ///@param increaseValue this is the value to add to the players cash
             void IncreaseMoney(int increaseValue);
             ///\brief function that takes in a int and subratcs it from the money variable
             ///@param decreaseValue ammount to take off the players total money
             void DecreaseMoney(int decreaseValue);
             ///\brief returns the money variable
             ///@return will return the integer value of the players current bank roll
             int GetMoney();
             ///\brief wipes the old total and sets it to the new total.
             ///@param newTotalMoney sets the players bank account to this ammount (will set bank account to 0 first)
             void SetMoney(int newTotalMoney);
            
};

#endif
