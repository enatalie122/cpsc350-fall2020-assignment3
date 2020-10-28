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


//The File class reads and collects data from files.
class File{

public:

  /*Default constructor: File
  Sets ints to 0 and strings to be empty.
  */
  File();

  /*Destructor: ~File
  Does not delete anything because no memory is allocated to the heap.
  */
  ~File();

  /*get_file_contents
  Returns a string that contains the contents of a file.
  */
  string get_file_contents();

  /*get_number_of_lines
  Returns an int represting the number of lines in a file.
  */
  int get_number_of_lines();

  /*set_file_name
  Sets the member variable file_name_.
  Parameters:
    file_name: a string represting the name of a file to be processed.
  */
  void set_file_name(string file_name);

  /*ProcessFile
  Sets the name of the file to be processed, reads from that file, and counts the number of lines in the file.
  Parameters:
    name: a string represting the name of a file to be processed
  */
  void ProcessFile(string name);

private:
  /*ReadFile
  Opens and reads a given file. Adds the contents of the file to a string. Once processed, the file is closed.
  If the file could not be opened, the method lets the user know, and allows them to try a new file.
  */
  void ReadFile();

  /*CountLines
  Counts the number of lines in a file.
  */
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
