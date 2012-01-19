/// \file
/// \brief Defines the Weapons header file
/// Define the weapon class. Is derived from the equippable class. Simply stores
/// information to memory about one weapon that can be equipped to a unit.

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Equipable.h"

class Weapon : public virtual Equipable {

private:
    int attackValue; ///< Defines how much attack the weapon has.

public:
    /// \brief Weapon Default Constructor
    Weapon();

    ~Weapon();

    /// \brief Special Constructor, sets the values for name, description, price.
    Weapon(std::string name, std::string description, int price, int attackVal);

    /// Initializes the attack Value of the weapon.
    /// \brief Change Attack Value
    /// Changes the attack value of the weapon.
    /// \pre Item passed must be an integer value
    /// \param [in] value
    void ChangeAttackValue(const int& newValue);
    /// \brief Get Attack Value
    /// Get current attack value of the weapon
    /// \pre Attack Value must be set already.
    /// \return attackValue
    int& GetAttackValue();

};

#endif
