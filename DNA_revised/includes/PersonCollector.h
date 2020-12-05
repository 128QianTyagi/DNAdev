#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "../includes/Person.h"
#include "../includes/Utilities.h"

class PersonCollector {
    public:
        PersonCollector(const std::string & filename);
        std::vector<Person> get_persons() const;
        std::vector<std::string> get_strs() const;
    private:
        std::vector<Person> person_vector;
        std::vector<std::string> strs;
};