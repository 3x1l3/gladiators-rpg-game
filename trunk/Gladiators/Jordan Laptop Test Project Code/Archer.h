/// \file
/// \brief Unit class header file.
/// \author Jordan Peoples
/// \date November 24th, 2010
/// Header file defining the Archer job class. Specialized version of Job 

#include "Unit.h"
#include "Item.h"
#include "Equipable.h"

#ifndef ARCHER_H
#define ARCHER_H
class Archer : virtual public Job
{
    private:
        std::string specialAttackName;         ///<Name of the Wizard's special Attack
    protected:
        
    public:  
	
	    ///\brief Constructor with pointer to Unit that has this job
	    Archer();
        
        ///\brief Destructor
        virtual ~Archer();
           
        ///\brief Special ability for the Wizard job.
        /// Wizard's special ability allows the Wizard to deal a smaller portion
        /// of it's damage to multiple enemies simultaneously
        void Special(int attackVal, std::vector <Unit*>, unsigned target1 );       
      
};

#endif
