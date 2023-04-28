#ifndef UTILS_H
#define UTILS_H

#include <string>

int get_number_by_first_name(struct list list, std::string name);
int get_number_by_second_name(struct list list, std::string name);
int get_number_by_surname(struct list list, std::string name);
int get_number_by_home_location(struct list list, std::string str);
int get_number_by_position(struct list list, std::string str);

#endif