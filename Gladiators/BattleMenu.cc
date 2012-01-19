#include "BattleMenu.h"

using std::cout;
using std::cerr;
using std::endl;



             BattleMenu::BattleMenu() throw()
	     {
	     }


             BattleMenu::BattleMenu(const int curTurn) throw()
	     {}


             BattleMenu::~BattleMenu() throw()
	     {delete choiceList;}

             void BattleMenu::Run() throw()
	     {	      
		  
		  Menu::DrawMenu();

	     }


	     
	     void BattleMenu::HandleInput() throw()
	     {}


/*             int currentUnitTurn; ///< An integer variable to keep track/determine the current player turn

             //a basic string list for the menu contents
             list<string>*  choiceList; ///< A list of Menu Choices to be Rendered by DrawMenu
             */
