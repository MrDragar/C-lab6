#ifndef LIST_H
#define LIST_H

#include <string>
using std::string;

struct FIO{
    string first_name;
    string second_name;
    string surname;
};

struct user{
    struct FIO* fio;
    string age;
    string marital_status;
};

struct node{
    struct user* data{};
    struct node* next_node = nullptr; 
};

struct list{
    struct node* start;
};

struct list* init_list();
void add_node(struct list* list, struct node* new_node);
size_t get_list_length(struct list* list);
bool remove_last_node(struct list* list);
void clear_list(struct list** list);
struct list* copy_list(struct list* list);
struct user* get_user_by_index(struct list* list, size_t index);
void sort_list_by_first_name(struct list* list);
void sort_list_by_second_name(struct list* list);
void sort_list_by_surname(struct list* list);
void sort_list_by_position(struct list* list);
void sort_list_by_marital_status(struct list* list);
#endif