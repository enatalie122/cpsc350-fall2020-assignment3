/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

errors.cpp is the implementation file for the Errors class.
*/

#include "errors.h"

Errors::Errors(){
  yesOrNo_ = "yYnN";
}

Errors::~Errors(){}

char Errors::CheckCharInput(int loop_number, string message){
  char input = '!';
  if (loop_number != 0){                                                        //if the user hasn't entered data yet, the error message will not print
    cout << "Invalid input." << endl;
    cout << message;
  }
  string temp;
  getline(cin, temp);
  cout << endl;
  try{
    if (temp.size() > 1){                                                       //checking if the user entered a single character 
      throw std::exception();
    } else if (yesOrNo_.find(temp.at(0)) == string::npos){                      //checking if user input matches a char in yesOrNo_
      throw std::exception();
    }
    input = temp.at(0);
  } catch (std::exception e){}
  return input;
}
