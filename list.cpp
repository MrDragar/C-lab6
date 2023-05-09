#include "list.h"
#include <iostream>


struct list* init_list(){
    auto* list = new struct list;
    list->start = nullptr;
    return list;
}

void add_node(struct list* list, struct node* new_node){
    struct node* current_node = list->start;
    if (!current_node){
        list->start = new_node;
        return;
    }
    while (true) {
        if(current_node->next_node){
            current_node = current_node->next_node;
        }
        else break;
    }
    current_node->next_node = new_node;
}

size_t get_list_length(struct list* list){
    struct node* current_node = list->start;
    if (!current_node) return 0;
    size_t count = 1;
    while (true) {
        if (current_node->next_node) {
            count += 1;
            current_node = current_node->next_node;
        }
        else break;
    }
    return count;
}

bool remove_last_node(struct list* list){
    struct node* current_node = list->start;
    if (!current_node) return true;
    if (!current_node->next_node) {
        delete current_node;
        return true;
    }
    while (true) {
        if (current_node->next_node) {
            if (!current_node->next_node->next_node){
                delete current_node->next_node->next_node;
                current_node->next_node->next_node = nullptr;
            }
            current_node = current_node->next_node;
       }
        else break;
    }
    return false;
}

void clear_list(struct list** list) {
    while (true) if (remove_last_node(*list)) break;
    *list = init_list();
}

struct user* get_user_by_index(struct list* list, size_t index){
    struct node* current_node = list->start;
    if(!current_node) return nullptr;
    for (size_t i=0; i < index; i++) {
        current_node = current_node->next_node;
        if(!current_node) return nullptr;
    } 
    return current_node->data;
}

struct list* copy_list(struct list* list) {
    size_t len = get_list_length(list);
    struct list* new_list = init_list();
    for (size_t i=0; i < len; i++) {
        struct user* user = get_user_by_index(list, i);
        auto* node = new struct node;
        node->data = user;
        add_node(new_list, node);
    }
    return new_list;
}