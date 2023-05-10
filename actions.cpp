#include <iostream>
#include <string>
#include <iomanip>
#include "actions.h"
#include <regex>
#include "list.h"
#include "file.h"


bool is_positive_integer(const std::string& str) {
    std::regex integerRegex("\\d+");
    return std::regex_match(str, integerRegex);
}

uint64_t get_and_validate_number() {
    std::string str;
    while (true) {
        getline(std::cin, str);
        if(!is_positive_integer(str)){
            std::cout << "Your line isn't an positive integer" << std::endl;
            continue;
        }
        try {
            uint64_t result = std::stoull(str);
            std::system("clear");
            return result;
        }

        catch (const std::out_of_range& e) {
            std::cerr << "Your integer is too big" << std::endl;
        }
    }
}


void wait_key_press(){
    std::cout << "Press any button for continue" << std::endl;
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
        if (str.find(';') != std::string::npos) {
            std::cout << "Your data has separator ';'. Retry input" << std::endl;
            continue;
        }
        if (str.empty()) {
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
    
    auto fio = new struct FIO;
    std::cout << "Put user's first name" << std::endl;
    std::string str = get_and_validate_data();
    fio->first_name = str;

    std::cout << "Put user's second name" << std::endl;
    str = get_and_validate_data();
    fio->second_name = str;

    std::cout << "Put user's surname" << std::endl;
    str = get_and_validate_data();
    fio->surname = str; 
    auto* user = new struct user;
    user->fio = fio;

    std::cout << "Put user's age" << std::endl;
    uint64_t age = get_and_validate_number();
    user->age = age;
    

    std::cout << "Put user's marital status" << std::endl;
    str = get_and_validate_data();
 
    std::cout << str << std::endl; 

    user->marital_status = str;

    wait_key_press();
    auto* Node = new struct node;
    Node->data = user;
    add_node(list, Node);
}

void Actions::get_number_by_field(struct list* list, int (*func) (struct list*, const std::string&)){
    if (!list->start){
        std::cout << "List is empty" << std::endl;
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
    std::cout << std::setw(15) << "Age";
    std::cout << std::setw(15) << "Marital status" << std::endl;
    std::cout << std::setfill('*') << std::setw(80) << "*" << std::endl;

    for (size_t i=0; i < len; i++) {
        struct user* user = get_user_by_index(list, i);
        std::cout << std::setfill(' ');
        std::cout << std::left;
        std::cout << std::setw(4) << i + 1;
        std::cout << std::setw(15) << user->fio->first_name;
        std::cout << std::setw(15) << user->fio->second_name;
        std::cout << std::setw(15) << user->fio->surname;
        std::cout << std::setw(15) << user->age;
        std::cout << std::setw(15) << user->marital_status << std::endl;
        std::cout << std::setfill('*') << std::setw(80) << "*" << std::endl;

    }
    std::cout << std::setfill(' ');

    wait_key_press();
}

void Actions::read_from_file(struct list **list) {
    auto* new_list = init_list();
    bool error = read_data_from_file(new_list);
    if (error) {
        std::cout << "Some errors while reading file" << std::endl;
        delete new_list;
        wait_key_press();
        return;
    }
    clear_list(list);
    delete *list;
    *list = new_list;
    std::cout << "Data was read successful" << std::endl;
    wait_key_press();
}

void Actions::save_to_file(struct list* list){
    bool error = save_data_into_file(list);
    if (error) std::cout << "Some errors while reading file" << std::endl;
    else std::cout << "Data was saved successful" << std::endl;
    wait_key_press();
}

void Actions::set_default_values(struct list* list){
    if (!list->start) {
        std::cout << "List is empty" << std::endl;
        wait_key_press();
        return;
    }
    struct node* current_node = list->start;
    while (true){
        current_node->data->fio->first_name = "-";
        current_node->data->fio->second_name = "-";
        current_node->data->fio->surname = "-";
        current_node->data->age = 0;
        current_node->data->marital_status = "-";
        if(!current_node->next_node) break;
        current_node = current_node->next_node;
    }
    std::cout << "Values of list were reset" << std::endl;
    wait_key_press();
}