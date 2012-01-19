/********************************************************
/// \file
/// \brief Story Event Class header file
/// \author Jason Racine (Altered by Adam Shepley)
/// \date November 1, 2010 (Altered on November 24th)
/// Header file for the StoryEvent class, which is responsible for displaying
/// story elements to the user.
///
/// Note: There's a function that can be accessed to
///
*********************************************************/

#ifndef STORY_EVENT_H
#define STORY_EVENT_H

#include <string>
#include <iostream>
#include <vector>

using std::string;

class StoryEvent
{
    private:
        int storyNumber; ///< number representing the current battle in the sequential story
        std::vector<string> Story[101]; ///< an array housing the entire story, in strings
        string banner; ///< a banner printed at the start of the game; the first story
        string defaultStory1; ///< a story element printed several times
        string defaultStory2; ///< a story element printed several times
        string defaultStory3; ///< a story element printed several times
        string defaultStory4;

        string finalStory;

    public:
        ///\brief Default constructor
        /// Initialize battleNumber to 1 as a default
        ///This is called when there is a new game.
        StoryEvent() throw();

        /// \brief Special Constructor for a given Story element
        /// User sends in a storynumber, the corresponding story element is played.
        StoryEvent(const int storyNumber)  throw();

        ~StoryEvent() throw();


        /// \brief Method that displays the appropriate story text
        /// Prints story text depending on current battle number
        void PrintStory(const int storyNumber) throw();

        /// \brief Constructs the array of stories.
        /// Constructs an accessible story event from a set of preset
        /// strings.
        void ConstructStory() throw();

        std::string story[103];

};

#endif
