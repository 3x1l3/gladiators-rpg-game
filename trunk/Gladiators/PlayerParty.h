#ifndef PLAYERPARTY_H
#define PLAYERPARTY_H

/// \file
/// Header file to define the party wrapper/ 

#include "PlayerCharacter.h"
#include <vector>


class PlayerParty {
 private:
  std::vector<PlayerCharacter*> party;
 public:
  /// Default Constructor
  PlayerParty() throw();
  
  /// Default Destructor
  ~PlayerParty() throw();
  
  ///Add a member to the party Vector
  void AddMember(PlayerCharacter*) throw();

  ///Delete a member from the party vector at index
  void DeleteMember(const int&) throw();

  ///Return the vector
  std::vector<PlayerCharacter*>  GetAllMembers() throw();

  ///Return a single member as Unit
  PlayerCharacter* GetMember(const unsigned&) throw();

  /// Return the size of the party. 
  /// \return size_type
  unsigned Size() throw();
 
};

#endif
