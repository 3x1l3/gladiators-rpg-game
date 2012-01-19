/// \file
/// \brief Unit class header file.
/// \author Jason Racine
/// \date November 2, 2010
/// Header file defining the Wizard job class. Specialized version of Job 

#include "Unit.h"
#include "Item.h"
#include "Equipable.h"

#ifndef WIZARD_H
#define WIZARD_H
class Wizard : virtual public Job
{
    private:
        std::string specialAttackName;         ///<Name of the Wizard's special Attack
    protected:
        
    public:  
	
	    ///\brief Constructor with pointer to Unit that has this job
	    Wizard();
        
        ///\brief Destructor
        virtual ~Wizard();
           
        ///\brief Special ability for the Wizard job.
        /// Wizard's special ability allows the Wizard to deal a smaller portion
        /// of it's damage to multiple enemies simultaneously
        void Special(int attackVal, std::vector <Unit*>, unsigned target1 );       
      
};

#endif
