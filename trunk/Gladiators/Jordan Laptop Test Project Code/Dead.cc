// \file
// \brief Dead State class cc file.
// \author Jordan Peoples
// \date November 23, 2010
 



#include "State.h"
#include "Dead.h"
    
    //default contrcutor
    Dead::Dead() : State::State()
    {
                  
    }
    
    //default destructor
    Dead::~Dead()
    {
                    
    }
    
    //function that will return a ENUM or a String holding the current units state (Dead)
    std::string Dead::GetState()
    {
        //TO DO              
        //1
        //return DEAD;
        //2
        return "DEAD";
        
    }
