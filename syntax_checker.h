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
  /*Default constructor: SyntaxChecker
  Sets opening_delimiters_ to contain the 3 opening delimiters we are checking, closing_delimiters_ to
  contain the 3 closing delimiters we are checking, user_file_ to be an empty string, number_of_lines_ to 0,
  delimiters_ to point to an empty stack, and file_ to point to an array of strings.
  */
  SyntaxChecker();

  /*Overloaded constructor: SyntaxChecker
  Sets opening_delimiters_ to contain the 3 opening delimiters we are checking, closing_delimiters_ to
  contain the 3 closing delimiters we are checking, user_file_ to the provided file contents, number_of_lines_ to the
  provided number of lines, delimiters_ to point to an empty stack, and file_ to point to an array of strings.
  Parameters:
    user_file: string represting the contents of a user file.
    number_of_lines: int represting the number of lines in a file.
  */
  SyntaxChecker(string user_file, int number_of_lines);

  /*Delimiter: ~SyntaxChecker
  Deletes the stack, delimiters_, and the array, file_.
  */
  ~SyntaxChecker();

  /*CatchErrors
  Adds every opening delimiter to the stack, and pops off each delimiter when a matching closing delimiter is found.
  If an opening or closing delimiter is missing, other methods are called to report the error.
  */
  void CatchErrors();

private:
  /*InitializeArray
  Itializes the array, file_, so that each element contains a line from the user file.
  */
  void InitializeArray();

  /*CheckMatch
  Parameters:
    d: a char representing a delimiter in the user file.
  Returns a boolean represting whether or not the delimiter on the top of the stack corresponds to the delimiter from the file.
  */
  bool CheckMatch(char d);

  /*PrintErrorMessage
  Prints a message letting the user know that it's reached the end of the file and a closing delimiter is missing.
  */
  void PrintErrorMessage();

  /*Overloaded: PrintErrorMessage
  Prints a message letting the user know which delimiter is missing, and on what line the delimiters stopped matching.
  Parameters:
    line_number: an int represting the line where a mismatch in delimiters was found.
    d: a char represting the incorrect delimiter found
  */
  void PrintErrorMessage(int line_number, char d);

  /*GetCorrectDelimiter
  Parameters:
    delimiter: a char represting the delimiter being checked from the file.
  Returns a char representing the matching delimiter that is missing from the file.
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
  A pointer to an array of strings that represents each line of a file.
  */
  string *file_;

};
#endif
