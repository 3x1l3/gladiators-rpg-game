#ifndef ENEMYPARTY_H
#define ENEMYPARTY_H

/// \file
///\brief Header file to define the party wrapper/ 

#include <vector>
#include "EnemyCharacter.h"

class EnemyParty {
 private:
  std::vector<EnemyCharacter*> party;
 public:
  /// Default Constructor
  EnemyParty() throw();
  
  /// Default Destructor
  ~EnemyParty() throw();
  
  ///Add a member to the party Vector
  void AddMember(EnemyCharacter*) throw();

  ///Delete a member from the party vector at index
  void DeleteMember(const int&) throw();

  ///Return the vector
  std::vector<EnemyCharacter*>  GetAllMembers() throw();

  ///\brief Get a single member of the enemy party.
  ///\return A single member from the enemy party as Unit
  EnemyCharacter* GetMember(const int&) throw();

  /// Return the size of the party. 
  /// \return size_type
  unsigned Size() throw();
 
};

#endif
