#include "prototypes.h"

int prompt_menu() {
    cout << endl;
    cout << "1. Search for a person by navigating directories" << endl;
    cout << "2. Serach for a person by name" << endl;
    cout << "3. Make a new entry" << endl;
    cout << "4. Edit an existing entry" << endl;
    cout << "5. Quit program (all entries/edits will be saved)" << endl;
    cout << endl;

    cout << "Please make a selection (1-5): ";

    int input;
    cin >> input;

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