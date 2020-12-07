#include "../includes/PersonCollector.h"

PersonCollector::PersonCollector(const std::string & filename) {
    std::fstream input_file = std::fstream(filename);
    std::string line;
    std::string attribute_line;

    // Read the first line in the file 
    std::getline(input_file, attribute_line);

    // Split the first line by commas
    strs_ = Utilities::split_line(attribute_line, ',');

    // Erase the first element so we now have a vector of the STRS
    strs_.erase(strs_.begin());
    

    while (std::getline(input_file, line)) {
        person_vector_.push_back(Utilities::create_person(line, strs_));
    }

    // Close the file
    input_file.close();
}

const std::vector<Person> & PersonCollector::get_persons() const {
    return person_vector_;
}

const std::vector<std::string> & PersonCollector::get_strs() const {
    return strs_;
}