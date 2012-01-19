#include "PlayerParty.h"


///Default Constructor
PlayerParty::PlayerParty()  throw()
{
  

}
/// Default Destructor. Make sure to destroy all units inside the vector first. 
PlayerParty::~PlayerParty() throw() {
  std::vector<PlayerCharacter*>::iterator it;
  
  for(it = party.begin(); it < party.end(); ++it) {
    delete (*it);
  }
  party.clear();

}

/// Simply Just push back the Unit into the party vector.
/// \param [in] member
void PlayerParty::AddMember(PlayerCharacter* member) throw() {
  party.push_back(member);
}

///Simply just look up the index and delete from vector.
/// \param [in] index
void PlayerParty::DeleteMember(const int& index) throw() {
  party.erase(party.begin()+index);
}

///Return the party pointer
/// \return party
std::vector<PlayerCharacter*> PlayerParty::GetAllMembers() throw() {
  return party;
} 

///Return a unit at the index
/// \param [in] index
/// \return member
PlayerCharacter* PlayerParty::GetMember(const unsigned& index) throw() {
  return party.at(index);
}

unsigned PlayerParty::Size() throw() {
  return party.size();
}
