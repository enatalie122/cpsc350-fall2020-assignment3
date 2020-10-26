/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

syntax_checker.cpp is the implementation file for the SyntaxChecker class.
*/

#include "syntax_checker.h"

SyntaxChecker::SyntaxChecker(){
  opening_delimiters_ = "([{";
  closing_delimiters_ = ")]}";
  user_file_  = "";
  number_of_lines_ = 0;
  delimiters_ = new GenStack<char>();
  file_ = new string[number_of_lines_];
}

SyntaxChecker::SyntaxChecker(string user_file, int number_of_lines){
  opening_delimiters_ = "([{";
  closing_delimiters_ = ")]}";
  user_file_  = user_file;
  number_of_lines_ = number_of_lines;
  delimiters_ = new GenStack<char>();
  file_ = new string[number_of_lines_];
  InitializeArray();
}

SyntaxChecker::~SyntaxChecker(){
  delete delimiters_;
  delete[] file_;
}


void SyntaxChecker::CatchErrors(){
  for(int i = 0; i < number_of_lines_; ++i){
    for(int j = 0; j < file_[i].size(); ++j){
      char delimiter = file_[i].at(j);
      if(opening_delimiters_.find(delimiter) != string::npos){
        delimiters_->Push(delimiter);
      } else if(closing_delimiters_.find(delimiter) != string::npos) {
        bool is_match = CheckMatch(delimiter);
        if (!is_match){
          PrintErrorMessage(i + 1, delimiter);
          abort();
        } else {
          delimiters_->Pop();
        }
      }
    }
  }
  if(!delimiters_->IsEmpty()){
    PrintErrorMessage();
    abort();
  }
}

void SyntaxChecker::PrintErrorMessage(){
  char correction = GetCorrectDelimiter(delimiters_->Peek());
  cout << "Reached end of file, missing " << correction << endl;
}

void SyntaxChecker::PrintErrorMessage(int line_number, char d){
  char correction = GetCorrectDelimiter(d);
  if(opening_delimiters_.find(correction) != string::npos)
    cout << "Line " << line_number << ": Found " << d << " Missing " << correction << endl;
  else if(closing_delimiters_.find(correction) != string::npos)
    cout << "Line " << line_number << ": Expected " << correction << " Found " << d << endl;
}

char SyntaxChecker::GetCorrectDelimiter(char delimiter){
  char correct_delimiter = ' ';
  char top = delimiters_->Peek();
  if(top == '(')
    correct_delimiter = ')';
  else if (top == '[')
    correct_delimiter = ']';
  else if (top == '{')
    correct_delimiter = '}';
  else if (top == '\0'){
    if (delimiter == ')')
      correct_delimiter = '(';
    else if (delimiter == ']')
      correct_delimiter = '[';
    else if (delimiter == '}')
      correct_delimiter = '{';
  }
  return correct_delimiter;
}

bool SyntaxChecker::CheckMatch(char d){
  char match = delimiters_->Peek();
  if (match == '(' && d != ')'){
    return false;
  } else if (match == '[' && d != ']'){
    return false;
  } else if (match == '{' && d != '}'){
    return false;
  } else if (match == '\0'){
    return false;
  }
  return true;
}

void SyntaxChecker::InitializeArray(){
  int j = 0;
  int length = 0;
  for(int i = 0; i < number_of_lines_; ++i){
    int end_location = user_file_.find('\n', j);
    length = end_location - j;
    file_[i] = user_file_.substr(j, length);
    j = end_location + 1;
  }
}
