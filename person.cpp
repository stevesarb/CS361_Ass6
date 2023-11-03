#include "prototypes.h"

// constructor
Person::Person() {
    this->name = "Default";
    this->description = "Default";
}

// alternate constructor
Person::Person(string name, string d) {
    this->name = name;
    this->description = d;
}

