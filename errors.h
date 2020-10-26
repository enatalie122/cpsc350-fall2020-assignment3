/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

errors.h is the header file for the Errors class.
*/

#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <iostream>

using namespace std;

//The Errors class checks for errors in user input
class Errors{

public:
  /*Default constructor: Errors
  Sets string numbers to contain all 10 digits and a decimal
  */
  Errors();
  //~Errors
  ~Errors();

  /*CheckCharInput
  Parameters:
    loop_number: an int representing the number of iterations in a loop
    message: a string representing instructions for the user to proceed after an error
  Throws std::exception if user input does not match what was requested.
  Returns a char represting acceptable user input.
  */
  char CheckCharInput(int loop_number, string message);

  /*CheckIntInput
  Parameters:
    loop_number: an int representing the number of iterations in a loop
    message: a string representing instructions for the user to proceed after an error
  Throws std::exception if user input does not match what was requested.
  Returns an int represting acceptable user input.
  */
  int CheckIntInput(int loop_number, string message);
  /*CheckDoubleInput
  Parameters:
    loop_number: an int representing the number of iterations in a loop
    message: a string representing instructions for the user to proceed after an error
  Throws std::exception if user input does not match what was requested.  
  Returns a double represting acceptable user input.
  */
  double CheckDoubleInput(int loop_number, string message);

private:
  /*numbers_
  A string representing all 10 digits and a decimal.
  */
  string numbers_;
  /*yesOrNo_
  A string represting acceptable answers to the question "yes or no?"
  */
  string yesOrNo_;
};
#endif
