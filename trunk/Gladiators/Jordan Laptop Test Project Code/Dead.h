/// \file
/// \brief Dead state class header file.
/// \author Jason Racine
/// \date November 6, 2010
/// Header file for the Dead sate class, which is a specialized subclass of
/// the abstract base class State.  
#ifndef DEAD_H
#define DEAD_H

#include "State.h"
#include "Item.h"
#include "Equipable.h"

class Dead : virtual public State
{
      public:
             ///Default constructor
             Dead();
             
             ///destructor
             virtual ~Dead();
             
             ///Gets the appropriate action(s) to perform when in the
             /// Dead state and the turn for action passes to the entity
             /// that has this state.
             virtual std::string GetState();
      
      
};


#endif
