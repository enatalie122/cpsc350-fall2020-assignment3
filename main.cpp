/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 3

main.cpp contains the main method for the syntax_checker program.
*/

#include "gen_stack.h"
#include "file.h"
#include "syntax_checker.h"
#include "errors.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){

  bool can_run = true;
  string user_file = argv[1];
  char user_input;

  while(can_run){
    File *processor = new File();
    processor->ProcessFile(user_file);

    SyntaxChecker *checker = new SyntaxChecker(processor->get_file_contents(), processor->get_number_of_lines());
    checker->CatchErrors();

    cout << endl;
    cout << "Delimiter syntax is correct." << endl;
    cout << "Would you like to check another file? (y/n)" << endl;

    int loop_counter = 0;
    Errors e;
    while (user_input != 'y' && user_input != 'n'){
     user_input = e.CheckCharInput(loop_counter, "Enter y or n: ");
     loop_counter++;
    }

    if(user_input == 'y' || user_input == 'Y'){
      cout << "Enter a file name: " << endl;
      getline(cin, user_file);
      user_input = '!';
    } else if (user_input == 'n' || user_input == 'N'){
      can_run = false;
    }
    
    delete processor;
    delete checker;
  }

  return 0;
}
