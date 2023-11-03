#include "prototypes.h"

int main() {
    int input = 1;
    int num_dirs = 0;
    Dir* dirs = NULL;

    // process file
    string username = process_file(dirs, num_dirs);

    cout << "\nWelcome " << username << "! ";

    if (DEBUG_MODE)
        print_info(dirs, num_dirs);

    int dummy;

    while (input != 5) {
        // prompt menu
        input = prompt_menu();

        // implement functionalities
        if (input == 1)
            search_by_dir(dirs, num_dirs);
        else if (input == 2)
            search_by_name(dirs, num_dirs);
        else if (input == 3)
            make_new_entry(dirs, num_dirs);
        else if (input == 4)
            dummy = 1;
    }

    // update file

    if (dirs != NULL)
        delete [] dirs;

    return 0;
}

/* 
in the future:
Instead of writing all the information to one file, I could actually make new directories that can easily have 
subdirectories, and then within each directory I could have .txt files for each person 
*/

/*
Note: Kaden could implement microservice that checks for a name that is similar to the one entered
    Same first name, different last name
    any capitalization
    slightly different names (EX: Sarah & Sara)
*/