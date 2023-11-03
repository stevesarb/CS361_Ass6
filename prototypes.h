#ifndef PROTOTYPES_H
#define PROTOTYPES_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const bool DEBUG_MODE = 0;

class Person {
    public:
        string name;
        string description;

        // default constructor
        Person();
        // alternate constructor
        Person(string, string);
};

class Dir {
    public:
        string name;
        int num_ppl;
        Person* arr;

        // default constructor
        Dir();
        // alternate constructor
        Dir(string, Person*);
        // destructor
        ~Dir();
};

// helper functions
int prompt_menu();
string process_file(Dir*&, int&);
void print_info(Dir*, int);





#endif