#include "utils.h"
#include "list.h"
#include <string>

int get_number_by_first_name(struct list* list, const std::string& name){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->fio->first_name == name) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

int get_number_by_second_name(struct list* list, const std::string& name){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->fio->second_name == name) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

int get_number_by_surname(struct list* list, const std::string& name){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->fio->surname == name) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

int get_number_by_home_location(struct list* list, const std::string& str){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->marital_status == str) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

int get_number_by_position(struct list* list, const std::string& str){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->age == str) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

bool is_bigger(const std::string& str1, const std::string& str2) {
    size_t n1 = str1.length();
    size_t n2 = str2.length();
    size_t n = n1;
    if (n1 > n2) n = n2;

    for (size_t i=0; i<n; i++) {
        if (str1[i] > str2[i]) return true;
        if (str2[i] > str1[i]) return false;
    }
    if (n1 < n2) return true;
    return false;
}