#include <string>
#include <iostream>
#include "console.h"
#include "list.h"
#include "utils.h"
#include "actions.h"

using std::cout;
using std::endl;
using std::cin;


void get_user_count_by_field(struct list* list){
    int (*func) (struct list*, std::string);
    while (true){
        cout << "1. Get number of users by first name" << endl; 
        cout << "2. Get number of users by second name" << endl; 
        cout << "3. Get number of users by surname" << endl;
        cout << "4. Get number of users by position" << endl; 
        cout << "5. Get number of users by home location" << endl; 
        cout << "6. Back" << endl; 
        std::string action;
        getline(cin, action);
        std::system("clear");
        if (action == "1") func = &get_number_by_first_name;
        else
            if (action == "2") func = &get_number_by_surname;
            else
                if (action == "3") func = &get_number_by_second_name;
                else
                    if (action == "4") func = &get_number_by_position;
                    else
                        if (action == "5") func = &get_number_by_home_location;
                        else
                            if (action == "6") break;
                            else continue;
        Actions::get_number_by_field(list, func);
        break;
    }
}



void start_session(){
    Actions actions;
    struct list* list = init_list();
    std::system("clear");

    while (true) {
        cout << "Choose option" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Print list on screen" << endl;
        cout << "3. Get number of users by field" << endl; 
        cout << "4. Save file into file" << endl;
        cout << "5. Read file from file" << endl; 
        cout << "6. Clear list" << endl;      
        cout << "7. Set default values for elements" << endl;      
        cout << "8. Exit" << endl;
        std::string action;
        getline(cin, action);
        std::system("clear");

        if(action == "1") {
            Actions::add_element(list);
            continue;
        }
        if(action == "2") {
            Actions::print_list(list);
            continue;
        }
        if(action == "3") {
            get_user_count_by_field(list);
            continue;
        }
        if(action == "4") {
            continue;
        }
        if(action == "5") {
            continue;
        }
        if(action == "6") {                        
            clear_list(&list);
            continue;
        }
        if(action == "7") {
            continue;
        }
        if(action == "9") {
            continue;
        }
        if(action == "8") {
            break;
        }

   }  
}
