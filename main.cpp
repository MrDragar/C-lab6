#include <string>
#include "console.h"
#include <regex>

int main(){
    std::string str = "123";
    std::regex pattern("([А-Яа-я]*)([\\s]?)([А-Яа-я]*)([\\s]?)([А-Яа-я]*);([0-9]{0,3});([А-Яа-я]*)");
    // std::regex_match(str.c_str(), pattern);
    start_session();
}