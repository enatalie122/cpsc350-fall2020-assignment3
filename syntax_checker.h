/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

syntax_checker.h is the header file for the SyntaxChecker class.
*/

#ifndef SYNTAX_CHECKER_H
#define SYNTAX_CHECKER_H

#include <iostream>
#include "gen_stack.h"

using namespace std;

//The SyntaxChecker checks for correct delimiter syntax in source code.
class SyntaxChecker{

public:
  //Default constructor: SyntaxChecker
  SyntaxChecker();
  /*Overloaded constructor: SyntaxChecker
  Parameters:
    user_file: string represting the contents of a user file.
    number_of_lines: int represting the number of lines in a file.
  */
  SyntaxChecker(string user_file, int number_of_lines);
  //~SyntaxChecker
  ~SyntaxChecker();
  //CatchErrors
  void CatchErrors();

private:
  //InitializeArray
  void InitializeArray();
  /*CheckMatch
  Parameters:
    d: a char representing a delimiter in the user file.
  Returns a boolean represting whether or not the delimiter on the top of the stack corresponds to the delimiter from the file.
  */
  bool CheckMatch(char d);
  //PrintErrorMessage
  void PrintErrorMessage();
  /*Overloaded: PrintErrorMessage
  Parameters:
    line_number: an int represting the line where a mismatch in delimiters was found.
    d: a char represting the incorrect delimiter found
  */
  void PrintErrorMessage(int line_number, char d);
  /*GetCorrectDelimiter
  Parameters:
    delimiter: a char represting the delimiter being checked from the file.
  */
  char GetCorrectDelimiter(char delimiter);

  /*opening_delimiters_
  A string containing opening delimiters.
  */
  string opening_delimiters_;
  /*closing_delimiters_
  A string containing closing delimiters.
  */
  string closing_delimiters_;
  /*user_file_
  A string represting the contents of a user-provided file.
  */
  string user_file_;
  /*number_of_lines_
  An int represting the number of lines in a user file.
  */
  int number_of_lines_;
  /*delimiters_
  A pointer to a stack of chars representing opening delimiters that haven't been matched with their closing delimiter yet.
  */
  GenStack<char> *delimiters_;
  /* *file_
  A pointer to an array of strings that represt each line of a file.
  */
  string *file_;

};
#endif
