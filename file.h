/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

file.h is the header file for the File class.
*/

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <iostream>
#include "gen_stack.h"

using namespace std;


//The File class reads files.
class File{

public:

  /*Default constructor: File
  Sets ints to 0 and strings to be empty.
  */
  File();
  //~File
  ~File();

  /*get_file_contents
  Returns a string representing the contents of a file.
  */
  string get_file_contents();
  /*get_number_of_lines
  Returns an int represting the number of lines in a file.
  */
  int get_number_of_lines();
  /*set_file_name
  Parameters:
    file_name: a string represting the name of a file to be processed.
  */
  void set_file_name(string file_name);

  /*ProcessFile
  Parameters:
    name: a string represting the name of a file to be processed
  */
  void ProcessFile(string name);

private:
  //ReadFile
  void ReadFile();
  //CountLines
  void CountLines();

  /*file_name_
  A string representing the name of a file.
  */
  string file_name_;
  /*file_contents_
  A string represting the contents of a file
  */
  string file_contents_;
  /*number_of_lines
  An int represting the number of lines in a file.
  */
  int number_of_lines_;

};

#endif
