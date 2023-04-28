#include "utils.h"
#include "list.h"
#include <string>
#include <iostream>

int get_number_by_first_name(struct list* list, std::string name){
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

int get_number_by_second_name(struct list* list, std::string name){
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

int get_number_by_surname(struct list* list, std::string name){
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

int get_number_by_home_location(struct list* list, std::string str){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->home_location == str) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

int get_number_by_position(struct list* list, std::string str){
    int count = 0;    
    struct node* current_node = list->start;
    while(true){
        if(current_node->data->position == str) count ++;
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}