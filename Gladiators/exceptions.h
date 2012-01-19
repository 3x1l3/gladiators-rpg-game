//****************************************************************************//
///\file
/// \brief Defines custom exception classes for project
///
/// \author Jason Racine
/// \date Nov 28, 2010
///
/// Developed for 2720 Assignment 2
//****************************************************************************//
#ifndef exceptions_h
#define exceptions_h

#include <stdexcept>
#include <string>
using std::string;
using std::runtime_error;

///Thrown if given filename does not specify a file that can be opened.
class invalid_file : public runtime_error
{
      public:
             invalid_file(const string& what):runtime_error(what){}
};

///Thrown when input data is not formatted correctly for the program.
class input_format_error : public runtime_error
{
      public:
             input_format_error(const string& what):runtime_error(what){}
};

///Thrown when an account withdrawl would result in a negative account balance.
class insufficient_funds : public runtime_error
{
      public:
             insufficient_funds(const string& what):runtime_error(what){}
};

///Thrown when a selected menu option is not valid
class invalid_menu_choice : public runtime_error
{
      public:
 invalid_menu_choice():runtime_error("Invalid Menu Choice Selected") {}
             invalid_menu_choice(const string& what):runtime_error(what){}
};

///Thrown when trying to equip an item that is already
class unable_to_equip : public runtime_error
{
      public:
	     unable_to_equip(const string& what):runtime_error(what){}
};

class lost_game_over : public runtime_error
{
    public:
        lost_game_over(const string& what):runtime_error(what){}
};



#endif
