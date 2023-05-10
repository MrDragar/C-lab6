#include "list.h"
#include <iostream>
#include "utils.h"


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
        if (!current_node->next_node->next_node){
            delete current_node->next_node->data->fio;
            delete current_node->next_node->data;
            delete current_node->next_node;
            current_node->next_node = nullptr;
            break;
        }
        current_node = current_node->next_node;
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
        auto* new_user = new struct user;
        auto* new_fio = new struct FIO;
        new_fio->first_name = user->fio->first_name;
        new_fio->second_name = user->fio->second_name;
        new_fio->surname = user->fio->surname;
        new_user->fio = new_fio;
        new_user->age = user->age;
        new_user->marital_status =  user->marital_status;
        node->data = new_user;
        add_node(new_list, node);
    }
    return new_list;
}

void sort_list_by_surname(struct list* list) {
    if (get_list_length(list) < 2) return;
    size_t n = get_list_length(list);
    for (size_t i = 0; i < n - 1; i++) {
        struct node* current_node = list->start;
        struct node* next_node = current_node->next_node;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (is_bigger(current_node->data->fio->surname, next_node->data->fio->surname)) {
                struct user* user = current_node->data;
                current_node->data = next_node->data;
                next_node->data = user;
            }
            current_node = current_node->next_node;
            next_node = current_node->next_node;
        }
    }
}

void sort_list_by_first_name(struct list* list) {
    if (get_list_length(list) < 2) return;
    size_t n = get_list_length(list);
    for (size_t i = 0; i < n - 1; i++) {
        struct node* current_node = list->start;
        struct node* next_node = current_node->next_node;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (is_bigger(current_node->data->fio->first_name, next_node->data->fio->first_name)) {
                struct user* user = current_node->data;
                current_node->data = next_node->data;
                next_node->data = user;
            }
            current_node = current_node->next_node;
            next_node = current_node->next_node;
        }
    }
}

void sort_list_by_second_name(struct list* list) {
    if (get_list_length(list) < 2) return;
    size_t n = get_list_length(list);
    for (size_t i = 0; i < n - 1; i++) {
        struct node* current_node = list->start;
        struct node* next_node = current_node->next_node;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (is_bigger(current_node->data->fio->second_name, next_node->data->fio->second_name)) {
                struct user* user = current_node->data;
                current_node->data = next_node->data;
                next_node->data = user;
            }
            current_node = current_node->next_node;
            next_node = current_node->next_node;
        }
    }
}

void sort_list_by_position(struct list* list) {
    if (get_list_length(list) < 2) return;
    size_t n = get_list_length(list);
    for (size_t i = 0; i < n - 1; i++) {
        struct node* current_node = list->start;
        struct node* next_node = current_node->next_node;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (is_bigger(current_node->data->age, next_node->data->age)) {
                struct user* user = current_node->data;
                current_node->data = next_node->data;
                next_node->data = user;
            }
            current_node = current_node->next_node;
            next_node = current_node->next_node;
        }
    }
}

void sort_list_by_marital_status(struct list* list) {
    if (get_list_length(list) < 2) return;
    size_t n = get_list_length(list);
    for (size_t i = 0; i < n - 1; i++) {
        struct node* current_node = list->start;
        struct node* next_node = current_node->next_node;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (is_bigger(current_node->data->marital_status, next_node->data->marital_status)) {
                struct user* user = current_node->data;
                current_node->data = next_node->data;
                next_node->data = user;
            }
            current_node = current_node->next_node;
            next_node = current_node->next_node;
        }
    }
}