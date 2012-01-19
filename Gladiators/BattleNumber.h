#ifndef BATTLENUMBER_H
#define BATTLENUMBER_H

/// Wrapper class for the battle number. 
class BattleNumber {

 private:
  /// Stored Battle number, this is under private for protection
  int battleNumber;
 public:
 
  ///Default constructor
  BattleNumber() throw();

  ///Second Default Constructor
  ///\param [in] number Integer value to set the BattleNumber to.
  BattleNumber(const int&) throw();
  
  ///Default destructor
  ~BattleNumber() throw();

  ///Increment the battle number by one. and only by one
  void increment() throw();

  /// Get the battle number for external use if needed.
  int get() throw();
  
};


#endif
