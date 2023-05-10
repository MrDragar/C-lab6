#include "file.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "list.h"

bool read_data_from_file(struct list* list){
    std::fstream file("data.txt");
    if (!file.is_open()) return true;
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
        auto* new_FIO = new struct FIO;
        new_FIO->first_name = strs[0];
        new_FIO->second_name = strs[1];
        new_FIO->surname = strs[2];

        auto* new_user = new struct user;
        new_user->fio = new_FIO;
        new_user->position = strs[3];
        new_user->home_location = strs[4];

        auto* new_node = new struct node;
        new_node->data = new_user;
        add_node(list, new_node);
    }
    file.close();

    return false;
}
