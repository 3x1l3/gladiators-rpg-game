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
             Dead() throw();
             
             ///destructor
             virtual ~Dead() throw();
             
             ///Returns a string indicating the current state of the unit.
             virtual std::string GetState() throw();
  
	     //State has kind of been altered and performs quite differently now than originally conceived.
      
};


#endif
