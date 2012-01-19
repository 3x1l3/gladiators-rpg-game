#include "BattleNumber.h"

BattleNumber::BattleNumber() throw(){
    battleNumber = 0;
}

BattleNumber::BattleNumber(const int& number) throw(){
  battleNumber = number;
}

BattleNumber::~BattleNumber() throw()
{
  
}

void BattleNumber::increment() throw(){
  battleNumber+= 1;
}

int BattleNumber::get() throw(){
  return battleNumber;
}
