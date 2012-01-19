/// \file
/// \brief Defines the Weapons header file
/// Define the weapon class. Is derived from the equippable class. Simply stores
/// information to memory about one weapon that can be equipped to a unit.

#ifndef WEAPON_H
#define WEAPON_H

#include "Equipable.h"
#include <string>

class Weapon : public virtual Equipable
{
private:
    int attackValue; ///< Defines how much attack the weapon has.
    int defenseValue; ///< Defines how much of a defense the weapon or shield gives the wearer

public:
    /// \brief Weapon Default Constructor
    Weapon();

    /// \brief Weapon Default Destructor
    ~Weapon();

    /// \brief Special Constructor, sets the values for name, description, price.
    Weapon(std::string name, std::string description, int price, int attackVal, int defenseValue);

    /// Initializes the attack Value of the weapon.
    /// \brief Change Attack Value
    /// Changes the attack value of the weapon.
    /// \pre Item passed must be an integer value
    /// \param [in] value
    void ChangeAttackValue(const int& newValue);
    void ChangeDefenseValue(const int & newValue);
    /// \brief Get Attack Value
    /// Get current attack value of the weapon
    /// \pre Attack Value must be set already.
    /// \return attackValue
    int& GetAttackValue();

    /// \brief Get Defense Value
    /// Returns the defense value of the 'weapon'
    /// Even a Weapon/Shield can have a defense value (i.e. a weapon with a strength buff, hand guard, magic, etc.)
    /// \pre Defense value must already be set
    /// \return defenseValue.
    int& GetDefenseValue();

    ///\brief overloading equivalency operator for Weapon class
    bool operator==(Weapon* otherWeapon);

     ///\brief clone method to create a copy of the object passed to it
    Weapon operator=(Weapon origWeapon);


};

#endif
