/// \file
/// \brief Defines the armors header file
///\date Dec 1, 2010
/// Define the armor class. Is derived from the equippable class. Simply stores
/// information to memory about one armor that can be equipped to a unit.

#ifndef ARMOR_H
#define ARMOR_H

//#include "Item.h"
#include "Equipable.h"

using std::string;

class Armor : public virtual Equipable {

private:
int defenseValue; ///< Defines how much defence the armor has.

public:
    /// \brief armor Default Constructor
    /// Initializes the attack Value of the armor.
 Armor() throw();

    /// \brief Special Constructor, sets name, price, etc.
    ///\param [in] name Name of the armor to be constructed
    ///\param [in] description Description of armor to be constructed
    ///\param [in] defVal Defense value of armor to be constructed
 Armor(const string name, const string description, const int price, const int defVal) throw();

    ///\brief Destructor
 ~Armor() throw();

    /// \brief Change Defence Value
    /// Changes the Defense value of the armor.
    /// \pre Item passed must be an integer value
    /// \param [in] newDefense Integer value to change the armor's defense value to
 void ChangeDefenseValue(const int& newDefense) throw();
    /// \brief Get Attack Value
    /// Get current attack value of the armor
    /// \pre Defence Value must be set already.
    /// \return integer representing defense value of the armor
 int& GetDefenseValue() throw();


};

#endif
