#ifndef ACTIONS_H
#define ACTIONS_H
#include <string>

class Actions{
    public:
            Actions(){}
            static void add_element(struct list* list);
            static void get_number_by_field(struct list* list, int (*func) (struct list*, std::string));
            static void print_list(struct list* list);
};

#endif