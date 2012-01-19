/// \file
/// \brief Normal state class header file.
/// \author Jason Racine
/// \date November 6, 2010
/// Header file for the Normal sate class, which is a specialized subclass of
/// the abstract base class State.  
#ifndef NORMAL_H
#define NORMAL_H

#include "State.h"
#include "Item.h"
#include "Equipable.h"

class Normal : virtual public State
{
      public:
             ///Default constructor
             Normal();
             
             ///destructor
             virtual ~Normal();
             
             ///Gets the appropriate action(s) to perform when in the
             /// Normal state and the turn for action passes to the entity
             /// that has this state.
             virtual std::string GetState();
      
      
};


#endif
