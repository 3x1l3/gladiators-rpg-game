/******************************************************
/// \file
/// \brief Implimentation file for the Store Menu class
///
/// The implimentation for the functions defined in StoreMenu.h
///
/// This is the store that allows a user to buy and sell
/// armor and equipment.
///
/// \author Adam Shepley
/// \date November 28th, 2010
*******************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "StoreMenu.h"

#include "UnitEquipment.h"
#include "Weapon.h"
#include "PotionItem.h"
#include "Armor.h"

#include "GameData.h"
#include "Menu.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


StoreMenu::StoreMenu() throw()
{
    Menu::AddMenuItem("Buy Consumeable Items");
    Menu::AddMenuItem("Buy Armor");
    Menu::AddMenuItem("Buy Weapons");
    Menu::AddMenuItem("Sell Consumeable Items");
    Menu::AddMenuItem("Sell Armor");
    Menu::AddMenuItem("Sell Weapons");
    Menu::AddMenuItem("Quit");

}

StoreMenu::~StoreMenu() throw()
{

}

void StoreMenu::Run() throw()
{
    //maybe put this in the constructor?
    localMoney = GameData::GetInstance()->GetMoney()->GetMoney();
    char input=0;

    //draws the menu while displaying appropriate info and taking in user choices until the quit option is reached
    do
    {

        cout << "\n\nYou currently have " << localMoney << " DeNiro's.\n=======================================\n" <<endl;
        Menu::DrawMenu();

        cin >>input;

        HandleInput2(input);
    }while(input != '7');

    //set the global equivalent to the local
    GameData::GetInstance()->GetMoney()->SetMoney(localMoney);
}

void StoreMenu::HandleInput2(const char menuChoice) throw()
{
    //the actual menu handling
    switch (menuChoice)
    {
        case '1':
               BuyConsumeableItem();
               break;
        case '2':
               BuyArmor();
               break;
        case '3':
               BuyWeapon();
               break;
        case '4':
               SellConsumeableItem();
               break;
        case '5':
               SellArmor();
               break;
        case '6':
               SellWeapon();
               break;
        case '7':
               cout << "\nPlease come again...If you CAN!" << endl;
               break;
        default:
               cout << "\nThe Storekeeper looks at you with severe discontent...\nHe orders you to make a correct selection." << endl;
               break;

    }
}

void StoreMenu::HandleInput() throw()
{

}



bool StoreMenu::WalletCheck(int price) throw()
{
    if((localMoney - price) < 0)
        return false;
    else
        return true;
}

void StoreMenu::BuyConsumeableItem() throw()
{
    string menuChoice;
    int choice;
    bool canAfford;

    //the output of the store should be outside the do loop
    //but I am including it here because our store is currently small and it is more user friendly
    //this way.
    int storeSize = GameData::GetInstance()->GetAllConsume().size()-1;



    //as well, we go back to the SuperStore(tm) because the user should see their wallet again.
    //also, it's simpler that way.
    do
    {
        cout << "Please choose an item to buy (Enter Q to Leave)[#]: \n" << endl;
        for(int i=0; i < storeSize; i++)
        {
            //show data of all weapons from the Item superclass
            cout << (i+1) << ". " << GameData::GetInstance()->GetAllConsume().at(i)->GetName() << "\t\t€"
                << GameData::GetInstance()->GetAllConsume().at(i)->GetPrice() << endl;
        }

        cin >> menuChoice;

        choice = atoi(menuChoice.c_str());
        if(menuChoice == "Q" || menuChoice == "q")
        {
            cout << "Leaving so soon?\n" << endl;
            return;
        }

    }while(choice > storeSize || choice < 1);

    //We take in the price of the given item at the index, and check if the
    //player can afford it.

    int price = GameData::GetInstance()->GetAllConsume().at(choice-1)->GetPrice();
    canAfford = WalletCheck(price);

    if(canAfford)
    {
        //check to see if they really want to buy the item
        char confirm;
        cout << "Are you sure you want to buy  "
             << GameData::GetInstance()->GetAllConsume().at(choice-1)->GetName()
             << "for €" << price << " ?" << endl;
        cin >> confirm;

        //if they're sure, subtract the price from their wallet
        //and then give them the item.
        if(confirm == 'Y' || confirm == 'y')
        {
            localMoney -= price;

            GameData::GetInstance()->GetPlayerConsumeInv()->push_back
                                    (GameData::GetInstance()->GetAllConsume().at(choice-1));

        }
    }
    else
        cout << "\nYou cannot Afford this item!\n" << endl;
}

void StoreMenu::BuyArmor() throw()
{
    int choice;
    string menuChoice;
    bool canAfford;

    //the output of the store should be outside the do loop
    //but I am including it here because our store is currently small and it is more user friendly
    //this way.
    int storeSize = GameData::GetInstance()->GetAllArmor().size()-1;

    //as well, we go back to the SuperStore(tm) because the user should see their wallet again.
    //also, it's simpler that way.
    do
    {
        cout << "\nWe have the following items:\n" << endl;
        for(int i=0; i < storeSize; i++)
        {
            //display all weapons, using data from the Item superclass
            cout << (i+1) << ". " << GameData::GetInstance()->GetAllArmor().at(i)->GetName() << "\t\t€"
                << GameData::GetInstance()->GetAllArmor().at(i)->GetPrice() << endl;
        }

        cout << "\nWhich would you like to buy?(Enter Q to Leave)[#]: " << endl;
        //create a sanitized version of the input for vector access later
        cin >> menuChoice;
        choice = atoi(menuChoice.c_str());

        //if they want to quit, break out
        if(menuChoice == "Q" || menuChoice == "q")
        {
            cout << "Leaving so soon?\n" << endl;
            return;
        }
    }while(choice > storeSize || choice < 1);

    //We take in the price of the given item at the index, and check if the
    //player can afford it.
    unsigned int price = GameData::GetInstance()->GetAllArmor().at(choice-1)->GetPrice();
    canAfford = WalletCheck(price);
    if(canAfford)
    {
        //check to see if they really want to buy the item
        char confirm;
        cout << "Are you sure you want to buy "
             << GameData::GetInstance()->GetAllArmor().at(choice-1)->GetName()
             <<" ? [Y/N]" << endl;
        cin >> confirm;

        //if they're sure, subtract the price from their wallet
        //give them the armor from the global allarmor...as in, give them a pointer to it.
        if(confirm == 'Y' || 'y')
        {
            localMoney -= price;

            GameData::GetInstance()->GetPlayerArmorInv()->push_back
                          (GameData::GetInstance()->GetAllArmor().at(choice-1));
            GameData::GetInstance()->GetPlayerArmorInv()->back()->IncrementQuantity();
        }
    }
    else
        cout << "\nYou cannot Afford this item!\n" << endl;

}
void StoreMenu::BuyWeapon() throw()
{
    int choice;
    string menuChoice;
    bool canAfford;

    //the output of the store should be outside the do loop
    //but I am including it here because our store is currently small and it is more user friendly
    //this way.
    int storeSize = GameData::GetInstance()->GetAllWeapons().size()-1;

    //as well, we go back to the SuperStore(tm) because the user should see their wallet again.
    //also, it's simpler that way.
    do
    {
        cout << "\nWe have the following items:\n" << endl;
        for(int i=0; i < storeSize; i++)
        {
            //display all weapons, using data from the Item superclass
            cout << (i+1) << ". " << GameData::GetInstance()->GetAllWeapons().at(i)->GetName() << "\t\t€"
                << GameData::GetInstance()->GetAllWeapons().at(i)->GetPrice() << endl;
        }

        cout << "\nWhich would you like to buy?(Enter Q to Leave)[#]: " << endl;
        //create a sanitized version of the input for vector access later
        cin >> menuChoice;
        choice = atoi(menuChoice.c_str());

        //if they want to quit, break out
        if(menuChoice == "Q" || menuChoice == "q")
        {
            cout << "Leaving so soon?\n" << endl;
            return;
        }
    }while(choice > storeSize || choice < 1);

    //We take in the price of the given item at the index, and check if the
    //player can afford it.
    unsigned int price = GameData::GetInstance()->GetAllWeapons().at(choice-1)->GetPrice();
    canAfford = WalletCheck(price);
    if(canAfford)
    {
        //check to see if they really want to buy the item
        char confirm;
        cout << "Are you sure you want to buy "
             << GameData::GetInstance()->GetAllWeapons().at(choice-1)->GetName()
             <<" ? [Y/N]" << endl;
        cin >> confirm;

        //if they're sure, subtract the price from their wallet
        //give them the armor from the global allarmor...as in, give them a pointer to it.
        if(confirm == 'Y' || 'y')
        {
            localMoney -= price;
            GameData::GetInstance()->GetPlayerWeaponInv()->push_back
                          (GameData::GetInstance()->GetAllWeapons().at(choice-1));
            GameData::GetInstance()->GetPlayerWeaponInv()->back()->IncrementQuantity();
        }
    }
    else
        cout << "\nYou cannot Afford this item!\n" << endl;

}

void StoreMenu::SellConsumeableItem() throw()
{
    int choice;
    string menuChoice;

    //count all of the consumable items in the player's inventory
    int consumeItemCount = (GameData::GetInstance()->GetPlayerConsumeInv()->size());

    if(consumeItemCount < 0)
    {
        cout << "You don't have any consumables to sell! Get out!\n" << endl;
        return;
    }

    //loop until they sell something
    do
    {
        cout << "Please choose an item to sell (Enter Q to Quit Out) [#]: \n" << endl;
        for(int i=0; i < consumeItemCount; i++)
        {
            int curprice = GameData::GetInstance()->GetPlayerConsumeInv()->at(i)->GetPrice();
            //display all weapons, using data from the Item superclass
            cout << (i+1) << ". " << GameData::GetInstance()->GetPlayerConsumeInv()->at(i)->GetName()
                << "\t\t Purchase Price: €" << curprice << " Resale Price: €"
                << curprice - (curprice / 8) << endl;
        }

        cin >> menuChoice;
        choice = atoi(menuChoice.c_str());

        //get out if they want to quit out
        if(menuChoice == "Q" || menuChoice == "q")
        {
            cout << "If you're not going to sell something, get out of here!\n" << endl;
            return;
        }

    }while(choice > consumeItemCount || choice < 1);

   //if they don't want to quit...
    //confirm the sale
    char confirm;
    int itemWorth = GameData::GetInstance()->GetPlayerConsumeInv()->at(choice-1)->GetPrice();
    cout << "Are you sure you want to sell this item? [Y/N]\t"
         << GameData::GetInstance()->GetPlayerConsumeInv()->at(choice-1)->GetName() << "\t€"
         << itemWorth - ((itemWorth) / 8) << endl;
    cin >> confirm;
    if(confirm == 'Y' || confirm == 'y')
    {
        GameData::GetInstance()->GetPlayerConsumeInv()->erase
                                (
                                 GameData::GetInstance()->GetPlayerConsumeInv()->begin()+(choice-1)
                                );
        localMoney += (itemWorth - (itemWorth / 8));
        cout << "Item Sold";
    }
    else
        cout << "Can't bear to let it go, eh?\n" << endl;

}

//WORKING
////USE THIS ARMOR SELLER
//////HE'S TRUSTWORTHY, LIKE THAT GUY FROM RESIDENT EVIL 4.

void StoreMenu::SellArmor() throw()
{
    unsigned int choice;
    string menuChoice;


    //count the total number of items in their inventory
    unsigned int armorItemCount = GameData::GetInstance()->GetPlayerArmorInv()->size();

    do
    {
        cout << "\n\nYou have the following Armor: \n" << endl;
        unsigned int i = 0;
        //display the armor information
        for(; i < armorItemCount; i++)
        {
            unsigned int tempWorth = GameData::GetInstance()->GetPlayerArmorInv()->at(i)->GetPrice()
                      - (GameData::GetInstance()->GetPlayerArmorInv()->at(i)->GetPrice() / 8);
            cout << "\n" << i+1 << ". " << GameData::GetInstance()->GetPlayerArmorInv()->at(i)->GetName()
                << "\t\tPrice: €" << tempWorth;

        }

        if(i == 0)
        {
            cout << "\nYou have no armor to sell." << endl;
            return;
        }
        cout << "\nWhich would you like to sell (Enter Q to Cancel) [#]:  " << endl;
        cin >> menuChoice;
        choice = atoi(menuChoice.c_str());

    //leave if they want to quit
        if(menuChoice == "Q" || menuChoice == "q")
        {
            cout << "If you're not going to sell something, get out of here!\n" << endl;
            return;
        }

    }while(choice > armorItemCount || choice < 1);


    if(!(GameData::GetInstance()->GetPlayerArmorInv()->at(choice-1)->Usable()))
    {
        cout << "\n\n\nThough you could pull a fast one on us, eh?"
             << "\nTrying to sell something you're already wearing, eh?"
             << "\nNot on my watch!" << endl;
             return;
    }
    //confirm the sale
    char confirm;


    unsigned int itemWorth = GameData::GetInstance()->GetPlayerArmorInv()->at(choice-1)->GetPrice();

    cout << "Are you sure you want to sell this item? [Y/N]\t"
         << GameData::GetInstance()->GetPlayerArmorInv()->at(choice-1)->GetName() << "\t€"
         << (itemWorth - (itemWorth / 8)) << endl;
    cin >> confirm;


    //if they're sure they want to sell, erase the item pointer in their inventory
    //at the spot they specified
    if(confirm == 'Y' || confirm == 'y')
    {
        //if we have more than one, decrement for the sake of equipping functions
        if(GameData::GetInstance()->GetPlayerArmorInv()->at(choice-1)->GetQuantity() > 1)
            GameData::GetInstance()->GetPlayerArmorInv()->at(choice-1)->DecrementQuantity();

        GameData::GetInstance()->GetPlayerArmorInv()->erase
                                (
                                 GameData::GetInstance()->GetPlayerArmorInv()->begin()+(choice-1)
                                );
        cout << "Item Sold for " << itemWorth - (itemWorth / 8) << " DeNiro's.";
        localMoney += (itemWorth - (itemWorth / 8));
    }
    else
        cout << "Can't bear to let it go, eh?\n" << endl;


}


void StoreMenu::SellWeapon() throw()
{
    unsigned int choice;
    string menuChoice;


    //count the total number of items in their inventory
    unsigned int weaponItemCount = GameData::GetInstance()->GetPlayerWeaponInv()->size();

    do
    {
        unsigned int i = 0;
        cout << "\n\nYou have the following Weapons: \n" << endl;

        //display the armor information
        for(; i < weaponItemCount; i++)
        {
            unsigned int tempWorth = GameData::GetInstance()->GetPlayerWeaponInv()->at(i)->GetPrice()
                      - (GameData::GetInstance()->GetPlayerWeaponInv()->at(i)->GetPrice() / 8);
            cout << "\n" << i+1 << ". " << GameData::GetInstance()->GetPlayerWeaponInv()->at(i)->GetName()
                << "\t\tPrice: €" << tempWorth << endl;

        }

        if(i == 0)
        {
            cout << "\nYou have no weapons to sell." << endl;
            return;
        }
        cout << "\nWhich would you like to sell (Enter Q to Cancel) [#]:  " << endl;
        cin >> menuChoice;
        choice = atoi(menuChoice.c_str());

    //leave if they want to quit
        if(menuChoice == "Q" || menuChoice == "q")
        {
            cout << "If you're not going to sell something, get out of here!\n" << endl;
            return;
        }

    }while(choice > weaponItemCount || choice < 1);

    //if the item is not usable, kick them out!
    if(!(GameData::GetInstance()->GetPlayerWeaponInv()->at(choice-1)->Usable()))
    {
        cout << "\n\n\nThough you could pull a fast one on us, eh?"
             << "\nTrying to sell me a sword you've locked in its Sheath, eh?"
             << "\nNot on my watch!" << endl;
             return;
    }
    //confirm the sale
    char confirm;

    //check that they actually want to sell this item
    unsigned int itemWorth = GameData::GetInstance()->GetPlayerWeaponInv()->at(choice-1)->GetPrice();


    cout << "Are you sure you want to sell this item? [Y/N]\t"
         << GameData::GetInstance()->GetPlayerWeaponInv()->at(choice-1)->GetName() << "\t€"
         << (itemWorth - (itemWorth / 8)) << endl;
    cin >> confirm;


    //if they're sure they want to sell, erase the item pointer in their inventory
    //at the spot they specified
    if(confirm == 'Y' || confirm == 'y')
    {
        //if we have more than one, decrement for the sake of equipping functions
        if(GameData::GetInstance()->GetPlayerWeaponInv()->at(choice-1)->GetQuantity() > 1)
            GameData::GetInstance()->GetPlayerWeaponInv()->at(choice-1)->DecrementQuantity();

        GameData::GetInstance()->GetPlayerWeaponInv()->erase
                                (
                                 GameData::GetInstance()->GetPlayerWeaponInv()->begin()+(choice-1)
                                );
        cout << "Item Sold for " << itemWorth - (itemWorth / 8) << " DeNiro's.";
        localMoney += (itemWorth - (itemWorth / 8));
    }
    else
        cout << "Can't bear to let it go, eh?\n" << endl;

}

