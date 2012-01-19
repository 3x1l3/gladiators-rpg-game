#include "EnemyParty.h"


///Default Constructor
EnemyParty::EnemyParty()  throw()
{
  

}
/// Default Destructor. Make sure to destroy all units inside the vector first. 
EnemyParty::~EnemyParty() throw() {
  std::vector<EnemyCharacter*>::iterator it;
  /*
  for(it = party.begin(); it < party.end(); ++it) {
    delete (*it);
  }*/
  for (unsigned int i = 0; i < party.size(); i ++)
    delete party[i];

}

/// Simply Just push back the Unit into the party vector.
/// \param [in] member
void EnemyParty::AddMember(EnemyCharacter* member) throw() {
  party.push_back(member);
}

///Simply just look up the index and delete from vector.
/// \param [in] index
void EnemyParty::DeleteMember(const int& index) throw() {
  party.erase(party.begin()+index);
}

///Return the party pointer
/// \return party
std::vector<EnemyCharacter*> EnemyParty::GetAllMembers() throw() {
  return party;
} 

///Return a unit at the index
/// \param [in] index
/// \return member
EnemyCharacter* EnemyParty::GetMember(const int& index) throw() {
  return party.at(index);
}

unsigned EnemyParty::Size() throw() {
  return party.size();
}
