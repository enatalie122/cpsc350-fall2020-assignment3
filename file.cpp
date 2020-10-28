/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

file.cpp is the implementation file for the File class.
*/

#include "file.h"

File::File(){
  string file_name_ = "";
  file_contents_ = "";
  number_of_lines_ = 0;
}

File::~File(){}

string File::get_file_contents(){
  return file_contents_;
}

int File::get_number_of_lines(){
  return number_of_lines_;
}

void File::set_file_name(string file_name){
  file_name_ = file_name;
}

void File::ProcessFile(string name){
  set_file_name(name);
  ReadFile();
  CountLines();
}

void File::ReadFile(){
  string line;
  ifstream file;
  while (file.is_open() == false){                                              //loop allows user to try multiple files untli one can be opened
    file.open(file_name_);
    if (file.is_open()){
      while (!file.eof()){                                                      //reads each line until reaching the end of the file
        getline(file, line);
        file_contents_ += line + '\n';
      }
      file.close();
      break;
    } else {
      cout << "Unable to open file." << endl;
      cout << "Enter a file name: ";
      cin >> file_name_;
      cout << endl;
    }
  }
}

void File::CountLines(){
  for(int i = 0; i < file_contents_.size(); ++i){
    if(file_contents_.at(i) == '\n'){                                           //counts new line characters to keep tracks of the number of lines
      number_of_lines_++;
    }
  }
}
