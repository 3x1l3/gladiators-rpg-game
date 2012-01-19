/// \file UnitEquipment.h
//
/// \brief UnitEquipment Header File
/// Define how units will have equipment, where the equipment will be attached
/// all defined in this class.
/// \author Chad Klassen, Altered by Adam Shepley
/// \date Altered on November 23rd
#ifndef UNITEQUIPMENT_H
#define UNITEQUIPMENT_H

#include <string>
#include "Unit.h"
#include "Weapon.h"
#include "Armor.h"

using std::string;

class UnitEquipment {
	private:
	// METHOD ONE
	//Pointer the weapon class for the right hand of equipment
	Weapon* rightHand;
	//Pointer to the weapon class, left hand equipment
	Weapon* leftHand;
	//Pointer to the armour class, chest
	Armor* chest;
	
	//Default weapon/armor for when nothing is equipped
	Weapon* fist;
	Armor* skin;
	
	// METHOD ONE END
/*
	// METHOD TWO START
	#include <utility>
	std::pair <std::string,std::Weapon> WeaponsList;
	std::pair <std::string,std::Armor> ArmorList;
	// METHOD TWO END
*/
	public:

	/// \brief Default Constructor
	//
	/// Default constructor to initialize weapon /armour points
	UnitEquipment();
	
	~UnitEquipment();

	/// \brief Unequip Weapon from unit's right hand
	//
	///This will ultimately remove an Weapon that is equipped to a unit's right hand.
	/// \pre Item must exist and be equipped already.
	/// \post Item will exist still, the item should not be on the list anymore
	void UnequipRightHand();

	/// \brief Equip Weapon to Unit's Right Hand
	/// Equip a weapon to a unit.
	/// \param [in] weapon
	/// \pre Item must exist already
	/// \post Item will be assigned to equipment location.
	void EquipRightHand(Weapon* weaponAddress);



	/// \brief Unequip Weapon from unit's Left Hand
	///This will ultimately remove an Weapon that is equipped to a unit's left hand.
	/// \pre Item must exist and be equipped already.
	/// \post Item will exist still, the item should not be on the list anymore
	void UnequipLeftHand();

	/// \brief Equip Weapon to Unit's Left Hand
	/// Equip a weapon to a unit.
	/// \param [in] weapon
	/// \pre Item must exist already
	/// \post Item will be assigned to equipment location.
	void EquipLeftHand(Weapon* weaponAddress);


	/// \brief Unequip Armour from unit
	//
	///This will ultimately remove an armor that is equipped to a unit.
	/// \pre Item must exist and be equipped already.
	/// \post Item will exist still, the item should not be on the list anymore
	/// \return bool (True if successfully unequipped)
	void UnequipArmor();
	/// \brief Equip armor to Unit
	/// Equip a armor to a unit.
	/// \param [in] weapon
	/// \pre Item must exist already
	/// \post Item will be assigned to equipment location.
	void EquipArmor(Armor* armorAddress);

	/*
	Extra methods, it would almost seem like for these to work that the weapon and armour pointers
	will have to be a vector or some sort of list. What do you think?
	*/

	/// \\Add Equipment Weapon Point (optional)
	//
	/// Add a Weapon Equipable point to a unit. Thus making it possible to add more weapons to a unit
	/// in order to increase attack power
	/// \param [in] name
	void AddEquipableWeaponPoint(const std::string& weaponBodyPoint);
	/// \brief Add Equipment Armour Point (optional)
	//
	/// Add armour equipable point to a unit. Thus ultimately raising the defence of the character
	/// \param [in] name
	void AddEquipableArmorPoint(const std::string& armorBodyPoint);
	
	Weapon* GetRightHandWeapon();
    
    Weapon* GetLeftHandWeapon();
    
    Armor* GetChestArmor();


};


#endif
