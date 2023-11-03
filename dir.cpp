#include "prototypes.h"

// constructor
Dir::Dir() {
    this->name = "Default_Dir";
    this->arr = NULL;
    this->num_ppl = 0;
}

// alternate constructor
Dir::Dir(string name, Person* arr) {
    this->name = name;
    this->arr = arr;
}

// destructor
Dir::~Dir() {
    if (this->arr != NULL)
        delete [] arr;
}