#include "prototypes.h"

int prompt_menu() {
    cout << "What would you like to do?" << endl << endl;
    cout << "1. Search for a person by navigating directories" << endl;
    cout << "2. Search for a person by name" << endl;
    cout << "3. Make a new entry" << endl;
    cout << "4. Edit an existing entry" << endl;
    cout << "5. Quit program (all entries/edits will be saved)" << endl;
    cout << endl;

    cout << "Please make a selection (1-5): ";

    string inStr;
    getline(cin, inStr);
    int input = stoi(inStr);

    return input;
}

string process_file(Dir*& dirs, int& num_dirs) {
    ifstream file ("steven.txt"); // hardcoded file name
    if (!file.is_open()) {
        cout << "Could not open file" << endl;
        exit(1);
    }

    string username;
    file >> username;

    file >> num_dirs;

    dirs = new Dir[num_dirs];

    if (DEBUG_MODE)
        cout << "num_dirs: " << num_dirs << endl;

    string newlineChar;

    // populate arrays
    for (int i = 0; i < num_dirs; i++) {
        // read line
        file >> dirs[i].name >> dirs[i].num_ppl;
        if (DEBUG_MODE)
            cout << "\ndir name: " << dirs[i].name << endl;
        // allocate person array
        dirs[i].arr = new Person[dirs[i].num_ppl];
        // grab the newline character so it doesn't mess up further input getting
        getline(file, newlineChar);
        // loop through people
        for (int j = 0; j < dirs[i].num_ppl; j++) {
            getline(file, dirs[i].arr[j].name);
            getline(file, dirs[i].arr[j].description);
            if (DEBUG_MODE) {
                cout << dirs[i].arr[j].name << endl;
                cout << dirs[i].arr[j].description << endl;
            }
        }
    }

    return username;
}

void print_info(Dir* dirs, int num_dirs) {
    if (DEBUG_MODE)
        cout << "IN PRINT INFO" << endl;

    for (int i = 0; i < num_dirs; i++) {
        cout << dirs[i].name << " " << dirs[i].num_ppl << endl;
        // loop through people
        for (int j = 0; j < dirs[i].num_ppl; j++) {
            cout << dirs[i].arr[j].name << endl;
            cout << dirs[i].arr[j].description << endl;
        }
        cout << endl;
    }
}

void search_by_dir(Dir* dirs, int num_dirs) {
    // display directories
    cout << "\nWhich directory would you like to search?" << endl;
    for (int i = 0; i < num_dirs; i++) 
        cout << i + 1 << ". " << dirs[i].name << endl;

    // prompt to choose dir to search
    cout << "\nPlease make a selection: ";
    string inStr;
    getline(cin, inStr);
    int input = stoi(inStr);

    // display people info for that directory
    dirs[input - 1].display_ppl();
}

void search_by_name(Dir* dirs, int num_dirs) {
    // prompt for a name
    cout << "\nEnter a name to search for: ";
    string name;
    getline(cin, name);

    // search for that name
    bool found = 0;
    for (int i = 0; i < num_dirs; i++) {
        dirs[i].search_for_person(name, found);
    }

    if (!found) {
        cout << "\nNo person by that exact name in database" << endl << endl << endl;
    }
}

void make_new_entry(Dir* dirs, int num_dirs) {
    // prompt for name and description
    cout << "Enter the name: ";
    string newName;
    getline(cin, newName);
    cout << "Enter a description: ";
    string newDesc;
    getline(cin, newDesc);

    // prompt for new or existing directory
    cout << "\nWould you like to place this new entry into an existing directory or create a new one for it?\n";
    cout << "1. Existing directory" << endl;
    cout << "2. New directory" << endl;
    cout << "\nPlease make a selection (1 or 2): ";
    string inStr;
    getline(cin, inStr);
    int input = stoi(inStr);

    // add new entry in appropriate location
    if (input == 1) {
        // prompt for a directory
        for (int i = 0; i < num_dirs; i++) 
            cout << i + 1 << ". " << dirs[i].name << endl;
        cout << "Please make a selection (1-" << num_dirs << "): ";
        getline(cin, inStr);
        input = stoi(inStr);
        cout << "\nNew entry added to the " << dirs[input - 1].name << " directory.\n\n\n";

        // add entry to array
    }
}