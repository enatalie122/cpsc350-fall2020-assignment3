/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

errors.h is the header file for the Errors class.
*/

#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <iostream>

using namespace std;

//The Errors class checks for and reports errors in user input
class Errors{

public:
  /*Default constructor: Errors
  Sets string yesOrNo_ to contain proper characters that represent yes or no.
  */
  Errors();

  /*Destructor: ~Errors
  Does not delete anything because no memory is allocated to the heap.
  */
  ~Errors();

  /*CheckCharInput
  Used when a char is requested from the user. The method checks if the user entered a char, and then
  compares the user input to acceptable chars.
  Parameters:
    loop_number: an int representing the number of iterations in a loop
    message: a string representing instructions for the user to proceed after an error
  Throws std::exception if user input does not match what was requested.
  Returns a char represting acceptable user input.
  */
  char CheckCharInput(int loop_number, string message);

private:
  /*yesOrNo_
  A string represting acceptable answers to the question "yes or no?"
  */
  string yesOrNo_;
};
#endif
