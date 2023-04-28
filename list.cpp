#include "list.h"


struct list* init_list(){
    struct list* list= (struct list*) malloc(sizeof(struct list));
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
    size_t count = 0;
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
    if (!current_node) return 1;
    while (true) {
        if (current_node->next_node) {
            if (!current_node->next_node->next_node){
                free(current_node->next_node->next_node);
                current_node->next_node->next_node = nullptr;
            }
            current_node = current_node->next_node;
       }
        else break;
    }
    return 0;
}

void clear_list(struct list* list) {
    while (true) if (remove_last_node(list)) break;
}