#include "../includes/PersonCollector.h"

PersonCollector::PersonCollector(const std::string & filename) {
    std::fstream input_file = std::fstream(filename);
    std::string line;
    std::string attribute_line;

    // Read the first line in the file 
    std::getline(input_file, attribute_line);

    // Split the first line by commas
    strs = split_line(attribute_line, ',');

    // Erase the first element so we now have a vector of the STRS
    strs.erase(strs.begin());
    

    while (std::getline(input_file, line)) {
        //person_vector.push_back(create_person(line, strs));
    }

    // Close the file
    input_file.close();
}

std::vector<Person> PersonCollector::get_persons() const {
    return person_vector;
}

std::vector<std::string> PersonCollector::get_strs() const {
    return strs;
}

std::vector<std::string> PersonCollector::split_line(std::string input, char delimiter) {
    std::vector<std::string> data;
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        data.push_back(token);
        input.erase(0, pos + 1);
    }
    data.push_back(input);
    return data;
}