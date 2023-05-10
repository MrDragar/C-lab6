#ifndef ACTIONS_H
#define ACTIONS_H
#include <string>
#include "list.h"

class Actions{
    public:
            static void add_element(struct list* list);
            static void get_number_by_field(struct list* list, int (*func) (struct list*, const std::string&));
            static void print_list(struct list* list);
            static void read_from_file(struct list** list);
            static void save_to_file(struct list* list);
            static void set_default_values(list *list);
};

#endif