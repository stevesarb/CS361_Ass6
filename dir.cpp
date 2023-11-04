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

void Dir::display_ppl() {
    cout << "Name:\t\tDescription:" << endl;
    for (int i = 0; i < this->num_ppl; i++) {
        cout << this->arr[i].name << "\t\t" << this->arr[i].description << endl;
    }
    cout << endl << endl;
}

void Dir::search_for_person(string& name, bool& found) {
    for (int i = 0; i < this->num_ppl; i++) {
        if (this->arr[i].name == name) {
            if (!found) {
                cout << endl << "Results:\nName:\t\tEntry Location:\t\tDescription:\n"; // why aren't the newlines working?
                found = 1;
            }
            cout << this->arr[i].name << "\t\t" << this->name << "\t\t" << this->arr[i].description << endl;
        }
    }
    if (found)
        cout << endl << endl;
}

void Dir::add_person(string& name, string& desc) {
    // create a new array of size +1
    Person* tempArr = new Person[this->num_ppl + 1];

    // copy data
    for (int i = 0; i < this->num_ppl; i++) {
        tempArr[i] = this->arr[i]; // need AOO? Answer: no.
    }
    tempArr[this->num_ppl].name = name;
    tempArr[this->num_ppl].description = desc;

    this->num_ppl += 1;
    delete[] this->arr;

    this->arr = tempArr;
}