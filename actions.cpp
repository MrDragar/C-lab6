#include <iostream>
#include <string>
#include <iomanip>
#include "actions.h"
#include <regex>
#include "list.h"


void wait_key_press(){
    std::cout << "Press any butten for continue" << std::endl;
    system("read -n 1");
    system("clear");
}

bool containsRussian(const std::string& str) {
    for (char c : str) {
        if (c >= -128 && c < 0) {
            return true;
        }
    }
    return false;
}


std::string get_and_validate_data() {
    std::string str;
    while (true) {
        getline(std::cin, str);
        if (str.find(";") != std::string::npos) {
            std::cout << "Your data has separator ';'. Retry input" << std::endl;
            continue;
        }
        if (str == "") {
            std::cout << "Your string is emty. Retry input" << std::endl;
            continue;
        }
        if (containsRussian(str)) {
            std::cout << "Don't use russian language. Retry input" << std::endl;
            continue;
        }    
        break;
    }
    std::system("clear");
    return str;
}

void Actions::add_element(struct list* list){
    
    struct FIO* fio = (struct FIO*) malloc(sizeof(struct FIO));
    std::cout << "Put user's first name" << std::endl;
    std::string str = get_and_validate_data();
    fio->first_name = str;

    std::cout << "Put user's second name" << std::endl;
    str = get_and_validate_data();
    fio->second_name = str;

    std::cout << "Put user's surname" << std::endl;
    str = get_and_validate_data();
    fio->surname = str; 
    struct user* user = (struct user*) malloc(sizeof(struct user));
    user->fio = fio;

    std::cout << "Put user's positions" << std::endl;
    str = get_and_validate_data();
    user->position = str;
    

    std::cout << "Put user's home location" << std::endl;     
    str = get_and_validate_data();
 
    std::cout << str << std::endl; 

    user->home_location = str;

    wait_key_press();
    struct node* Node = (struct node*) malloc(sizeof(struct node*));
    Node->data = user;
    add_node(list, Node);
}

void Actions::get_number_by_field(struct list* list, int (*func) (struct list*, std::string)){
    if (!list->start){
        std::cout << "List is emty" << std::endl;
        std::cin.get();
        return;
    }
    std::cout << "Put your data" << std::endl;
    
    std::string str;
    getline(std::cin, str);

    int result = (*func) (list, str);


    std::cout << "Result: " << result << std::endl;
    wait_key_press();
}

void Actions::print_list(struct list* list){
    size_t len = get_list_length(list);
    std::cout << std::setfill('*') << std::setw(80) << "*" << std::endl;
    std::cout << std::left;
    std::cout << std::setfill(' ');
    std::cout << std::setw(4) << "No.";
    std::cout << std::setw(15) << "First name";
    std::cout << std::setw(15) << "Second name";
    std::cout << std::setw(15) << "Surname" ;
    std::cout << std::setw(15) << "Home location";
    std::cout << std::setw(15) << "Position" << std::endl;
    std::cout << std::setfill('*') << std::setw(80) << "*" << std::endl;

    for (size_t i=0; i < len; i++) {
        struct user* user = get_user_by_index(list, i);
        std::cout << std::setfill(' ');
        std::cout << std::left;
        std::cout << std::setw(4) << i + 1;
        std::cout << std::setw(15) << user->fio->first_name;
        std::cout << std::setw(15) << user->fio->second_name;
        std::cout << std::setw(15) << user->fio->surname;
        std::cout << std::setw(15) << user->home_location;
        std::cout << std::setw(15) << user->position << std::endl;
        std::cout << std::setfill('*') << std::setw(80) << "*" << std::endl;

    }
    std::cout << std::setfill(' ');

    wait_key_press();
}
