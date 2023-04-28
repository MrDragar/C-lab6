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
    Actions actions;
    int (*func) (struct list*, std::string);
    while (true){
        cout << "1. Получить количество пользователей по имени" << endl; 
        cout << "2. Получить количество пользователей по фамилии" << endl; 
        cout << "3. Получить количество пользователей по отчеству" << endl;
        cout << "4. Получить количество пользователей по должности" << endl; 
        cout << "5. Получить количество пользователей по месту" << endl; 
        cout << "6. Назад" << endl; 
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
        actions.get_number_by_field(list, func);
        break;
    }
}



void strart_session(){
    Actions actions;
    struct list* list = init_list();
    std::system("clear");

    while (true) {
        cout << "Выберите действие" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Вывод списка на экран " << endl;
        cout << "3. Получить количество пользователей по полю" << endl; 
        cout << "4. Сохранить список в файл" << endl;
        cout << "5. Прочитать список из файла" << endl; 
        cout << "6. Очистить список" << endl;      
        cout << "7. Обнулить элементы списока" << endl;      
        cout << "8. Выход" << endl;
        std::string action;
        getline(cin, action);
        std::system("clear");

        if(action == "1") {
            actions.add_element(list);
            continue;
        }
        if(action == "2") {
            clear_list(list);
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
