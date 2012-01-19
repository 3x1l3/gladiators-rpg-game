/// \file
/// \brief State class header file.
/// \author Jason Racine
/// \date November 6, 2010
/// Header file for the abstract base class State, from which several possible 
/// state classes will be derived. 
#ifndef STATE_H
#define STATE_H

#include "Item.h"
#include "Equipable.h"

class State
{
      public:
             ///Default constructor
             State();
             
             ///destructor
             virtual ~State();
             
             ///Gets the appropriate action(s) to perform when in the
             /// given state and the turn for action passes to the entity
             /// that has this state.
             virtual std::string GetState() = 0;
      
      
};


#endif
