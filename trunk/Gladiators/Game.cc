#include "Game.h"
#include <iostream>

Game::Game() throw()
{}

Game::~Game() throw()
{
    delete bs;
}

void Game::Run() throw()
{
  try
  {
    bs = new BackstageMenu();
    bs->Run();
  }
  catch(invalid_file e)
  {
      cout << "Caught Exception: " << e.what() << "\nEnding game." << endl;
  }
  catch(input_format_error e)
  {
      cout << "Caught Exception: " << e.what() << "\nEnding game." << endl;
  }
  catch(insufficient_funds e)
  {
      cout << "Caught Exception: " << e.what() << "\nEnding game." << endl;
  }
  catch(invalid_menu_choice e)
  {
      cout << "Caught Exception: " << e.what() << "\nEnding game." << endl;
  }
  catch(unable_to_equip e)
  {
      cout << "Caught Exception: " << e.what() << "\nEnding game." << endl;
  }
  catch(lost_game_over e)
  {
      cout << "Caught Exception: " << e.what() << "\nEnding game." << endl;
  }


  catch (...)
  {
    std::cout<<"General Exception Found!"<<std::endl;
  }


}

void Game::Quit() throw()
{
    cout << "\nExiting the game. Press ENTER to continue." << endl;
    std::cin.ignore();
    std::cin.get();

}
