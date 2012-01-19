#ifndef MONEY_H
#define MONEY_H

class Money
{
      private:
              ///\brief integer to hold the total money
             int money;
              
              
      public:
             ///\brief default contrsutor - setting money to 0
             Money() throw();
             ///\brief destructor
             ~Money() throw();
	     ///\brief Constructor accepting integer parameter
	     ///\param [in] amount value to set money to
	     ///\post value of money is set to the amount passed in parameter when object is created
	     Money(int amount) throw();
             ///\brief function that takes in a int and adds it to the money variable
             ///@param increaseValue this is the value to add to the players cash
             void IncreaseMoney(int increaseValue) throw();
             ///\brief function that takes in a int and subratcs it from the money variable
             ///@param decreaseValue ammount to take off the players total money
             void DecreaseMoney(int decreaseValue) throw();
             ///\brief returns the money variable
             ///@return will return the integer value of the players current bank roll
             int GetMoney() throw();
             ///\brief wipes the old total and sets it to the new total.
             ///@param newTotalMoney sets the players bank account to this ammount (will set bank account to 0 first)
             void SetMoney(int newTotalMoney) throw();
            
};

#endif
