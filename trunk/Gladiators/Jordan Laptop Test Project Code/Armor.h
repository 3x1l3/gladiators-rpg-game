/// \file
/// \brief Defines the armors header file
/// Define the armor class. Is derived from the equippable class. Simply stores
/// information to memory about one armor that can be equipped to a unit.

#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include "Equipable.h"

using std::string;

class Armor : public virtual Equipable {

private:
int defenseValue; ///< Defines how much defence the armor has.

public:
    /// \brief armor Default Constructor
    /// Initializes the attack Value of the armor.
    Armor();

    /// \brief Special Constructor, sets name, price, etc.
    Armor(string name, string description, int price, int defVal);

    ~Armor();

    /// \brief Change Defence Value
    /// Changes the attack value of the armor.
    /// \pre Item passed must be an integer value
    /// \param [in] value
    void ChangeDefenseValue(const int& newDefense);
    /// \brief Get Attack Value
    /// Get current attack value of the armor
    /// \pre Defence Value must be set already.
    /// \return defenceValue
    int& GetDefenseValue();


};

#endif
