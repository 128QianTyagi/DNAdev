#include "../includes/Person.h"

Person::Person() {}

Person::Person(std::map<std::string, int> v, std::string name) {
    str_map_ = v;
    this->name_ = name;
}

std::string Person::get_name() const {
    return name_;
}

int Person::get_values(std::string str) const {
    return str_map_.find(str)->second;
}