#pragma once
#include <string>
#include <vector>
#include "Person.h"

namespace Utilities {
    /**
    * Split a line into a vector based on a delimiter
    * @param input The string to split
    * @param delimiter The character to use to split the string
    * @return A vector of strings split using the delimiter  
    */
    std::vector<std::string> split_line(std::string input, char delimiter);

    /**
    * Convert one line from the input file into a Person object
    * @param input_line The line as a string to process into a Person object 
    * @param strs The STRs found in this line
    * @return The person object the input_line represetns  
    */
    Person create_person(std::string input_line, std::vector<std::string> strs);
};