
#include "Money.h"

    //--------------------------------------------------------------------------    
    //default contrcutor    
    Money::Money() throw()
    {
           money = 0;
    }
    
    Money::Money(int amount) throw()
    {
	   money = amount;
    }
    
    //--------------------------------------------------------------------------
    //default destructor
    Money::~Money() throw()
    {
                   
    }
    //--------------------------------------------------------------------------
    //this function takes a value and adds it to the total.
    //this is used as a deposit function if were talking about a bank
    //Notice!! if the value is negative, we change the value to positive and then add it.
    void Money::IncreaseMoney(int increaseValue) throw()
    {
           if(increaseValue <0)
               increaseValue = -increaseValue;
               
           money += increaseValue;
    }
    //--------------------------------------------------------------------------
    //this function takes a value and subtracts it from the total.
    //this is used as a withdrawl function if were talking about a bank
    //Notice!! if the value is negative, we change the value to positive and then subtract it.
    void Money::DecreaseMoney( int decreaseValue) throw()
    {
         if(decreaseValue < 0)
             decreaseValue = -decreaseValue;
             
         money -= decreaseValue; 
    }
    //--------------------------------------------------------------------------
    //this function will return the total bank of the current object.
    //this is used as a "Get Balance" function in regards to a bank
    int Money::GetMoney() throw()
    {
        return money;
    }
    //--------------------------------------------------------------------------
    //this function resets the bank ammount with the integer paramter.
    //will set the bank to 0,and then reset it with the paramter we passed in.
    //this can be used to reset the bank account say for a story item?
    //IE if you get kidnapped and they take all your money, we can send in a 0 to this function.
    void Money::SetMoney(int newTotalMoney) throw()
    {
         if(newTotalMoney < 0)
             newTotalMoney = -newTotalMoney;
             
         money = 0;
         money = newTotalMoney;
    }
    //--------------------------------------------------------------------------
    
