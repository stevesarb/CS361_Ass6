#include "prototypes.h"

int main() {
    int input = 1;
    int num_dirs = 0;
    Dir* dirs = NULL;

    // process file
    string username = process_file(dirs, num_dirs);

    cout << "\nWelcome " << username << "! What would you like to do?" << endl;

    if (DEBUG_MODE)
        print_info(dirs, num_dirs);

    while (input != 5) {
        // prompt menu
        input = prompt_menu();

        // implement functionalities
    }

    return 0;
}

/* 
in the future:
Instead of writing all the information to one file, I could actually make new directories that can easily have 
subdirectories, and then within each directory I could have .txt files for each person 
*/