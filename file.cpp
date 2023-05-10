#include "file.h"
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "list.h"

bool is_positive_integer(const std::string& str);

bool read_data_from_file(struct list* list){
    std::fstream file("data.txt");
    if (!file.is_open()) return true;
    uint64_t age;
    while (true) {
        std::string input_line;
        std::getline(file, input_line);
        if(input_line.empty()) break;
        std::vector<std::string> strs;
        boost::split(strs, input_line, boost::is_any_of(";"));
        if (strs.size() != 5) return true;
        for (size_t i=0; i < 5; i++) {
            if (strs[i].length() >= 15) return true;
        }
        if(!is_positive_integer(strs[3])){
            return true;
        }
        try {
            age = std::stoull(strs[3]);
        }

        catch (const std::out_of_range& e) {
            return true;
        }

        auto* new_FIO = new struct FIO;
        new_FIO->first_name = strs[0];
        new_FIO->second_name = strs[1];
        new_FIO->surname = strs[2];

        auto* new_user = new struct user;
        new_user->fio = new_FIO;
        new_user->age = age;
        new_user->marital_status = strs[4];

        auto* new_node = new struct node;
        new_node->data = new_user;
        add_node(list, new_node);
    }
    file.close();

    return false;
}
bool save_data_into_file(struct list* list) {
    std::ofstream file("data.txt");
    if(!file.is_open()) return true;
    struct node* current_node = list->start;
    if (get_list_length(list) == 0) {
        file.close();
        return false;
    }
    while (true){
        std::string output_line;
        output_line += current_node->data->fio->first_name + ";";
        output_line += current_node->data->fio->second_name + ";";
        output_line += current_node->data->fio->surname + ";";
        output_line += std::to_string(current_node->data->age) + ";";
        output_line += current_node->data->marital_status;
        file << output_line << std::endl;
        if(!current_node->next_node) break;
        current_node = current_node->next_node;
    }
    file.close();
    return false;
}
