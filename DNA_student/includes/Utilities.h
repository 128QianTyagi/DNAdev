#pragma once
#include <string>
#include <vector>
#include "Person.h"

namespace Utilities {
    std::vector<std::string> split_line(std::string input, char delimiter);
    Person create_person(std::string input_line, std::vector<std::string> strs);
};