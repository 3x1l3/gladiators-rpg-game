/******************************************************
/// \file
/// \brief Implimentation file for the StoryEvent Class
///
/// Displays the story based on what battle the user is at.
///
/// For many fights, simply displays a stock statement.
/// Also contains the final story and beginning story.
///
/// There is a function for printing the story, however
/// I have also allowed for the construction of this object
/// with a story event.
///
///
/// \author Adam Shepley
/// \date November 24th, 2010
*******************************************************/


#include <string>
#include <iostream>


#include "StoryEvent.h"

using std::cout;
using std::string;

StoryEvent::StoryEvent() throw()
{
    ConstructStory();
    storyNumber = 0;
}

StoryEvent::StoryEvent(const int newStoryNumber) throw()
{
    ConstructStory();
    storyNumber = newStoryNumber;
    PrintStory(storyNumber);
}

void StoryEvent::ConstructStory() throw()
{
    banner = ".......\n...........\nYou wake up, surrounded by your disabled comrades.\nThe air around you is thick and unwelcoming. You fear that the carcass in the east may be that of a GrueHunter.\nA friendly storekeeper calls you over and explains where you are.\n\nYou are in The Colosseum, a royal arena where slaves and enemies of the state are forced to fight for the Leader's amusement.\n \"Why are we here?\", you ask, knowing full well the answer.\n\"What will happen to us?\" - yet you already know what you will have to do.\nYou will have to fight. But first, you may need to prepare yourselves...\n\n";
    finalStory = "\n\n\n\nIt's a cold day...\t\tin the Colluseum...\nMany have died by your hands\t...by your friends' hands...\nAs you're about to leave the arena, chills come up your back...then you see him...\n\nIt's\n\n\t\tsir MANSBRIDGE\n\nBack, after all of these years of reporting the news.\n\n\tHe shuffles over to you...\n\tAnd makes you an offer you can (but probably won't) refuse.\n\n\n\t\tCONGRADULATIONS, YOUR WINNER!\n\t\tGAME OVER.";

    defaultStory1 = "Ah! Another victory for the newbie!\n\tCongradulations for nothing,\n\t you slumdog prisoner.";
    defaultStory2 = "Hmm! Another win? Perhaps you aren't absolute garbage.\n\tOh Wait,\n\tYou still are.";
    defaultStory3 = "Another victory for our undefeated champions!\n\tSurely our venerable leader has a challenge worthy of them!";
    defaultStory4 = "Amazing, Spectacular, Flabbergasting and belt blasting.\n\tAnother victory and another tick off of the victory\n\tmark...";

    string storyInit[] =
    {
            banner
            ,"Your first victory I see. Interesting. Your team might last till next mealcall!"
            ,"Hmm. Two wins. Perhaps you meat bags might last longer than your weapons!"
            ,defaultStory1
            ,defaultStory1
            ,"Well well well, it seems like we have a group of rising stars on our hands."
            ,defaultStory1
            ,defaultStory1
            ,defaultStory1
            ,defaultStory1
            ,"10 victories already? I doubt a streak like this can last."
            ,defaultStory1
            ,defaultStory1
            ,defaultStory1
            ,defaultStory1
            ,"What could this mean? Another victory and another exciting end to our slaveful entertainment!"
            ,defaultStory2
            ,defaultStory1
            ,defaultStory1
            ,defaultStory1
            ,"They've survived 20 rounds? In the Arena? A persistent lot, they are!"
            ,defaultStory1
            ,defaultStory2
            ,defaultStory1
            ,"BOOM goes the...what was I saying again?"
            ,defaultStory2
            ,defaultStory1
            ,defaultStory2
            ,defaultStory1
            ,defaultStory1
            ,"Thirty? For real? Unpossible. There you have it, folks, a grand victory count for these warriors."
            ,defaultStory2
            ,defaultStory1
            ,defaultStory1
            ,defaultStory2
            ,"And the hits keep on rolling!"
            ,defaultStory2
            ,defaultStory1
            ,defaultStory2
            ,defaultStory2
            ,"Amazing! Nearly halfway to winning their freedom, and this lot shows no sign of stopping."
            ,defaultStory2
            ,defaultStory2
            ,defaultStory2
            ,defaultStory2
            ,"Not many have the fortitude to survive the Orichalchum!"
            ,defaultStory2
            ,defaultStory2
            ,defaultStory2
            ,defaultStory2
            ,"Fifty wins and fifty less to go before this stallwort lot gains their freedom.\nFame, it appears, is not fleeting."
            ,defaultStory2
            ,defaultStory2
            ,defaultStory2
            ,defaultStory3
            ,"You must defeat Shen-Long to stand a chance!"
            ,defaultStory2
            ,defaultStory2
            ,defaultStory3
            ,defaultStory2
            ,"60 wins! That's how much you'd pay in zeniShillings for four hens and a new wife!"
            ,defaultStory3
            ,defaultStory2
            ,defaultStory2
            ,defaultStory3
            ,"Quite fantastic, these stalwart warriors are. Coincidentally, they are covered in lambastic warts."
            ,defaultStory2
            ,defaultStory3
            ,defaultStory2
            ,defaultStory3
            ,"Seventy! Seventy bloody wins! Not to be confused with 17, the age of the you wench the King took into the, ahem, \"special dungeon\" last night."
            ,defaultStory3
            ,defaultStory2
            ,defaultStory3
            ,defaultStory3
            ,"hmm. Hmm. HMMMMM. What's that? They're still alive? Surprising, not."
            ,defaultStory2
            ,defaultStory3
            ,defaultStory3
            ,defaultStory3
            ,"At eighty wins and counting, it's seemed like the group has given up already...on LOSING!"
            ,defaultStory3
            ,defaultStory3
            ,defaultStory3
            ,defaultStory4
            ,"VICTORY! 100 wins! Congradulations.\nHAHAHA JUST KIDDING YOU'RE STILL STUCK HERE."
            ,defaultStory3
            ,defaultStory4
            ,defaultStory3
            ,defaultStory4
            ,"And at Ninety vitories, our amazing challengers are close to doing the impossible, and actually leaving the Arena!\nGive them a hand folks...no, not your actual hand."
            ,defaultStory1
            ,defaultStory2
            ,defaultStory4
            ,defaultStory1
            ,"ZALGO, HE COMES++++++++=====================------------"
            ,defaultStory3
            ,defaultStory1
            ,defaultStory2
            ,defaultStory1
            ,"Amazing, they finally did it!\nAll 100 victories!\n\tGive these amazing warriors around of applause and..."
            + finalStory

    };
    //copies story into the stored story array
    for(int i=0; i<101; i++)
    {
        story[i] = storyInit[i];
    }
}

StoryEvent::~StoryEvent() throw()
{

}

void StoryEvent::PrintStory(const int storyNumber) throw()
{
    cout << story[storyNumber] << std::endl;
    cout << "\n\nPress Any Key to Continue...";
    std::cin.get();
}
