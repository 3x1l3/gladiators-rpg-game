/// \file
/// \brief Unit class header file.
/// \author Jordan Peoples, Jason Racine
/// \date Dec 1 2010
/// Header file defining the Archer job class. Specialized version of Job
#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"
//#include "Item.h"
//#include "Equipable.h"
#include "Job.h"
#include <vector>


class Archer: virtual public Job
{
    private:
        std::string specialAttackName;         ///<Name of the Archer's special Attack
    protected:

    public:

	    ///\brief Constructor
	Archer() throw();

        ///\brief Destructor
	    virtual ~Archer() throw();

        ///\brief Special ability for the Archer job.
        /// Archer's special ability ...
        void Special(const int attackVal, const std::vector <EnemyCharacter*>, const unsigned target1 ) throw();

};

#endif
