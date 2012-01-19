// \file
// \brief Normal State class cc file.
// \author Jordan Peoples
// \date November 23, 2010
 



#include "State.h"
#include "Normal.h"
    
    //default contrcutor
    Normal::Normal() throw() : State::State()
    {
                  
    }
    
    //default destructor
    Normal::~Normal() throw()
    {
                    
    }
    
    //function that will return a ENUM or a String holding the current units state (Normal)
    std::string Normal::GetState() throw()
    {
        //TO DO              
        //1
        //return NORMAL;
        //2
        return "NORMAL";
        
    }
                  
