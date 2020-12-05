#include "../includes/Person.h"

Person::Person() {}

Person::Person(std::map<std::string, int> v, std::string name) {
    str_map = v;
    this->name = name;
}

std::string Person::get_name() const {
    return name;
}

int Person::get_values(std::string str) const {
    return str_map.find(str)->second;
}