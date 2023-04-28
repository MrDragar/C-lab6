#ifndef ACTIONS_H
#define ACTIONS_H
#include <string>

class Actions{
    public:
            Actions(){}
            void add_element(struct list* list);
            void get_number_by_field(struct list* list, int (*func) (struct list*, std::string));
};

#endif