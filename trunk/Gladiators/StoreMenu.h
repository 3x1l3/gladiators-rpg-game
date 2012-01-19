/***************************************************
/// \file
/// \brief Specification for the Store Menu childclass
///
/// This menu is responsible for the purchasing and sale
/// of all player items;
///
/// It allows the player to buy or sell equipment or
/// consumable items.
///
/// \author Adam Shepley, RPG Project
/// \date November 1st to 10th
***************************************************/

#ifndef STOREMENU_H
#define STOREMENU_H

//related or important headers
#include "Menu.h"


//headers related to the information being edited

#include "UnitEquipment.h"
#include "Weapon.h"
#include "PotionItem.h"
#include "Armor.h"

#include "GameData.h"


#include <string>
#include <list>

using std::list;
using std::string;

class StoreMenu : public Menu
{

      public:

             /// \brief Default Constructor for the Store Menu
             /// sets Money to 0;
             StoreMenu() throw();

             /// \brief Special Constructor for the Store Menu
             /// special constructor, takes the character's money pointer from
             /// Backstage and copies it into a local pointer;
             /// the value is also copied to a local variable
             StoreMenu(int * inMoney) throw();

             /// \brief Default destructor for the store menu
             /// destroys any duplicate pointers thus far.
             ~StoreMenu() throw();

             /// \brief Menu Function for buying a given item
             /// presents the user with a list of purchasable items (consumable)
             /// and their current money count.
             /// If the user chooses an item from the list, they are prompted for
             /// a confirmation. If they choose yes, WalletCheck is called.
             /// If true, the item is added to the player's inventory and the
             /// money subtracted from their total (local money variable).
             void BuyConsumeableItem() throw();

             /// \brief Menu Function for buying armor.
             /// similar to BuyItem, but it loads the armor vector/list instead
             void BuyArmor() throw();

             /// \brief Menu Function for buying weapons
             /// similar to BuyItem, but it loads the weapon vector/list instead
             void BuyWeapon() throw();

             /// \brief Menu function for selling player armor in the store
             /// presents the user with a list of their armor and a monetary
             /// amount attached to them. If the user chooses yes, the armor is
             /// removed from their inventory.
             /// NOTE: Any player wearing sold armor will now be wearing nothing
             /// (default);
             void SellArmor() throw();

             /// \brief Menu function for selling player weapons in the store
             /// presents the user with a list of their saleable weapons and a monetary
             /// amount attached to them. If the user chooses yes, the weapon is
             /// removed from their inventory.
             /// NOTE: Any player equipped with the weapon will now be holding nothing
             /// (default);
             void SellWeapon() throw();

             /// \brief Menu Function for Selling player items
             /// Similar to SellEquipment, but it does not effect the individual player
             /// information, only the ItemInventory. Loads items from the fullgame
             /// ItemList.
             void SellConsumeableItem() throw();

             /// \brief Menu function for checking the player's money
             /// checks the price of an item and the money the player has
             /// returns a true for if they can afford, false if they cannot
             bool WalletCheck(const int price) throw();

//UN-NEEDED?
             /// \brief Menu function for leaving the store
             /// applies the changes made to the local Money integer to the
             /// money variable pointer passed in.
             /// Destroys the local StoreMenu/quits back to BackStage.
//  void Quit();

             /// \brief Runs the menu class construction and awaits input via related
             /// Loops for menu construction, destruction, etc.
             /// utilizes the Input handler.
             void Run() throw();

             /// \brief Menu construction definitions as specified by the Abstract Parent
             /// As defined in Menu
             /// Tailored to the StoreMenu items - writes or 'deletes'
             /// menu items to corrospond to the above functions.
             /// In this case, the options to buy and sell equipment, or quit
             void HandleInput() throw();

             void HandleInput2(const char menuChoice) throw();


      private:
             int localMoney;         ///< Local variable for calculations regarding the player's money

             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu


};

#endif
