/***********************************************************
/// \file
/// \brief The main Driver program for the Game
///
/// This is the Main program. Use this with make (make Mansbridge)
///
/// Embark on a harrowing tale of adventure and...well, not really.
/// Battle ferocious, well depicted enem...well, not really.
/// See our experimental battle engine and class struct-well, that's at least correct.
///
/// Must include but a few crucial header files!
///
/// \author Adam Shepley, revision 1
/// \date November 25th, 2010
***********************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//#include "Menu.h"
#include "GameData.h"
//#include "XMLWrapper.h"
//#include "Game.h"

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	std::stringstream sbanner;
	std::string banner;
    sbanner <<
    				"=================================\n" <<
                    "|    The Ballad of Mansbridge   |\n" <<
                    "|                               |\n" <<
                    "|          ver. 1.0             |\n" <<
                    "|   A Manly Tale of Manliness   |\n" <<
                    "=================================\n";
    banner = sbanner.str();
    
	std::stringstream smenu;
    smenu << "Choose one of the following Manly Options (MO) to continue:\n" <<
                       "1. Start a New Adventure \t(New Game)[N]\n" <<
                       "2. Continue an Old Adventure \t(Load Game) [L]\n" <<
                       "3. Abandon All Adventures \t(Quit) [T]\n" <<
                       "4. There is no option\n";
    std::string menu = smenu.str();

    int fixedInput;
    bool quit;


  
    //GameData* GD = GameData::GetInstance();    //Must use GetInstance, cannot directly call new GameData()  J.R.
    //Game MansbridgeGame = new Game;
    do
    {
        cout << banner << endl << menu;
		cin >> fixedInput;
        switch(fixedInput)
        {
            case 1:
                   //GD.New();
                  // MansbridgeGame->Run();
                   quit = true;
                   break;
            case 2:
                   //GD.Load();
                   //MansbridgeGame->Run();
                   quit = true;
                   break;
            case 3:
                   quit = true;
                   break;
            case 4:
                   std::cout << "You found an easter egg!\nPlease pick a valid option.";
                   break;
            default:
                   std::cout << "Please enter a valid option, for Mansbridge's sake.";
                   break;
        }


    }
    while(quit == false);

    return 0;
}
		
