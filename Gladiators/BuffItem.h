/// \file 
/// \brief Defines the Buff Item
/// Derives from the consumable class. This class defines how buffed items will behave.
/// Buffed Items are items that increase attack power, and defence?

/* ======================================================================================
					QUESTIONS
=========================================================================================

1. What the hell is the buff type linked to? valueStat of a character? Huh? WTF?
2. Still not too sure how the Use will work. Is it unit or player thats being passed as a parameter?
3. Perhaps we should define buffValues as its own class then make a list of them or something?
*/


class BuffItem : public virtual Consumeable {

private:
int buffValue; ///< Defines how much HP a unit gains by consuming the potion
std::string buffType; ///< Defines what the buff will increase from the player stats
public:
/// \brief Buff Item Default Constructor
/// Sets the buffValue to a default. Inorder for it to be used. 
BuffItem() {};
/// \brief Use Buff Item
/// Use the current buff item on a unit. Will this also 
/// destroy the item from memory?
/// \pre Item must be in the inventory of unit
/// \post Item must remove itself from the inventory
/// \param [in] unit
void Use(Unit&);
/// \brief Set the buff Value
/// Use to set the buff value after the object has been intialized.
/// \param [in] value
void SetHealValue(const int&);
/// \brief Get healing value
/// Used for perhaps displaying the health points value on a menu or something?
/// \pre healValue must be set already.
/// \return buffValue
int GetHealValue();
/// \brief Get Buff Type
/// Standard getter for the Buff Type. Not sure where we will use it. Perhaps
/// in the menu to display to the user?'
/// \pre buffType must be defined
/// \return buffType
std::string GetBuffType();
/// \brief Set Buff Type
/// Set the buff type for this item. Perhaps this will come in handy for changing
/// and upgrading buffs?
/// \param [in] newBuffName
/// \pre buffType must be defined already
void SetBuffType(const std::string&);
};

