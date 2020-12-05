#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "../includes/Person.h"

class PersonCollector {
    public:
        PersonCollector(const std::string & filename);
        std::vector<Person> get_persons() const;
        std::vector<std::string> get_strs() const;
    private:
        std::vector<Person> person_vector;
        std::vector<std::string> strs;
        std::vector<std::string> split_line(std::string input, char delimiter);
        Person create_person(std::string input_line, std::vector<std::string> strs);
};