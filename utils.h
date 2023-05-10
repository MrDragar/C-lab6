#ifndef UTILS_H
#define UTILS_H

#include <string>

int get_number_by_first_name(struct list* list, const std::string& name);
int get_number_by_second_name(struct list* list, const std::string& name);
int get_number_by_surname(struct list* list, const std::string& name);
int get_number_by_home_location(struct list* list, const std::string& str);
int get_number_by_position(struct list* list, const std::string& str);
bool is_bigger(const std::string& str1, const std::string& str2);

#endif