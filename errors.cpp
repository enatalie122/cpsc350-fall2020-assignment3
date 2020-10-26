/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

errors.cpp is the implementation file for the Errors class.
*/

#include "errors.h"

Errors::Errors(){
  numbers_ = "0123456789.";
  yesOrNo_ = "yYnN";
}

Errors::~Errors(){}

char Errors::CheckCharInput(int loop_number, string message){
  char input = '!';
  if (loop_number != 0){
    cout << "Invalid input." << endl;
    cout << message;
  }
  string temp;
  getline(cin, temp);
  cout << endl;
  try{
    if (temp.size() > 1){
      throw std::exception();
    } else if (yesOrNo_.find(temp.at(0)) == string::npos){
      throw std::exception();
    }
    input = temp.at(0);
  } catch (std::exception e){}
  return input;
}

int Errors::CheckIntInput(int loop_number, string message){
  int input = 0;
  if (loop_number != 0){
    cout << "Invalid input." << endl;
    cout << message;
  }
  string temp;
  getline(cin, temp);
  cout << endl;
  try{
    for (int i = 0; i < temp.length(); ++i){
      if (numbers_.find(temp.at(i)) == string::npos){
        throw std::exception();
      }
    }
    input = stoi(temp);
  } catch (std::exception e){}
  return input;
}

double Errors::CheckDoubleInput(int loop_number, string message){
  double input = 0;
  if (loop_number != 0){
    cout << "Invalid input." << endl;
    cout << message;
  }
  string temp;
  getline(cin, temp);
  cout << endl;
  try{
    for (int i = 0; i < temp.length(); ++i){
      if (numbers_.find(temp.at(i)) == string::npos){
        throw std::exception();
      }
    }
    input = stod(temp);
  } catch (std::exception e){
    return -1;
  }
  return input;
}
