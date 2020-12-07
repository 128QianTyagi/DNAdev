#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "../includes/Person.h"
#include "../includes/Utilities.h"

class PersonCollector {
    public:
        /**
         * Custom constructor
         * @param filename The path to the CSV file which contains data  
        */
        PersonCollector(const std::string & filename);

        /**
         * Get the Person objects associated with this PersonCollector object
         * @return A vector of Person objects  
        */
        const std::vector<Person> & get_persons() const;

        /**
         * Get the Short Tandem Repeats (STRs) associated with this PersonCollector object
         * @return A vector of strings of the STRS
        */
        const std::vector<std::string> & get_strs() const;
    private:
        std::vector<Person> person_vector_;
        std::vector<std::string> strs_;
};