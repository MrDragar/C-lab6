#include <iostream>
#include <string>
#include "actions.h"
#include "list.h"


std::string get_and_validate_data() {
    std::string str;
    while (true) {
        getline(std::cin, str);
        if (str.find(";") == std::string::npos) break;
        std::cout << "Ваши данные содержит разделитель ';'. Повторите ввод" << std::endl;;
    }
    std::system("clear");
    return str;
}

void Actions::add_element(struct list* list){
    struct FIO* fio = (struct FIO*) malloc(sizeof(struct FIO));
    std::cout << "Введите имя пользователя" << std::endl;
    std::string str = get_and_validate_data();
    fio->first_name = str;
    std::cout << "Введите фамилию пользователя" << std::endl;
    str = get_and_validate_data();
    fio->second_name = str; 
    std::cout << "Введите отчество пользователя" << std::endl;
    str = get_and_validate_data();
    fio->second_name = str;

    struct user* user = (struct user*) malloc(sizeof(struct user));
    user->fio = fio;

    std::cout << "Введите должность пользователя" << std::endl;
    str = get_and_validate_data();
    user->position = str;    
    std::cout << "Введите место проживания пользователя" << std::endl;    
    str = get_and_validate_data();
    user->home_location = str;    
}
