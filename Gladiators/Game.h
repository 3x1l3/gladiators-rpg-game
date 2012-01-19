#ifndef GAME_H
#define GAME_H

#include "BackstageMenu.h"


//setup for Game();
//1st Edition by Jordan Peoples on October 29, 2010.



//////QUESTIONS///////
// - 1 - the stat increases on level up have been moved to job right? - each job knowing what stats to increase with each new level gained?

// - 2 - do we really need a loadmenu and save menu object in here?  wouldnt we need to make a start game menu from main, then wait for load or new game.... 
//.......then create the game object based on loading or saveing? (2 differnet constructors)

// - 3 - are we gonna check if you have won the game when the user exits the backstageMenu object and control is given back to game? in Run()?....
//...seems kinda silly to check it here.  then everytime the user exits they will see "GAME OVER".....?


class Game {
      
      private:
              //once the game has been satrted or loaded, game.run() will use this backstageMenu to start the game.
                //this will take the user into the main screen of the game, where they can see units, store, fight etc....
               BackstageMenu *bs;
      public: 
                
                //new game constructor     
                //will get called if user selects New Game in the  StartGame Menu created in main.  
                Game() throw();
                
                
                //destructor
                virtual ~Game() throw();
                
          
         
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2
                
                
                
                //will contain the main excecution of game class.  will call backstageMenu.run() and pass it control to handle the game.
                //once the user quits or saves the game, control will be passed back to game, and we will clean everything up and close the game.
                //we will rap the backstageMenu.run() in try catch blocks so we can handle any error that might occur.
                // **(also might be checking if you beat the game here? - check battle number and print you won, or game over??)**///////////////////////////////3
                void Run() throw();
                
                //will be used to exit the program gracefully and cleanly after control is regained from the backstage menu.
                void Quit() throw();
};               
#endif





