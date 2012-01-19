/// \file
/// \brief Unit class header file.
/// \author Jason Racine
/// \date November 2, 2010 updated up till December 2nd.
/// Header file defining the Wizard job class. Specialized version of Job

#ifndef WIZARD_H
#define WIZARD_H

#include "Unit.h"
//#include "Item.h"
//#include "Equipable.h"
#include "Job.h"
#include <vector>


class Wizard : virtual public Job
{
    private:
        std::string specialAttackName; ///<Name of the Job's special Attack
    protected:

    public:

	    ///\brief Constructor with pointer to Unit that has this job
	    Wizard() throw();

        ///\brief Destructor
        virtual ~Wizard() throw();

        ///\brief Special ability for the Wizard job.
        /// Wizard's special ability allows the Wizard to deal a smaller portion
        /// of it's damage to multiple enemies simultaneously
        void Special(const int attackVal, const std::vector <EnemyCharacter*>, const unsigned target1 ) throw();

    ///\brief Returns a string that describes the attack name
    /// Returns information regarding the Special Attack.
	std::string GetSpecialAttackName();

};

#endif
