/// \file
/// \brief Unit class header file.
/// \author Jason Racine
/// \date November 25, 2010
/// Header file defining the Commoner class, a derived class from Job that is
/// used as a base default job.

#ifndef COMMONER_H
#define COMMONER_H

#include "Job.h"
#include "EnemyCharacter.h"


class Commoner : virtual public Job
{
    private:
        std::string specialAttackName;         ///<Name of the Wizard's special Attack
    protected:

    public:

	    ///\brief Default constructor
	    Commoner() throw();

        ///\brief Destructor
        virtual ~Commoner() throw();

        ///\brief Special ability for the Commoner Job.
        /// The Commoner has a very distinct special ability...
        void Special(const int attackVal, const std::vector <EnemyCharacter*>, const unsigned target1 ) throw();

};

#endif
