#pragma once
#include "../includes/PersonCollector.h"
#include "Person.h"
#include "PersonCollector.h"
#include <iostream>
#include <vector>
#include <map>

class Analyzer {
    public:
        /**
         *  Constructor for Analyzer class
         * @param given_people A vector of people to analyze 
         */
        Analyzer(const PersonCollector & collector, const std::string & dna_strand);
        
        /**
         * Find which index a particular string occurs in a vector
         * @param string_list A vector of strings
         * @param check The string to check
         * @return The index at which the string occurs
         */
        int check_match(std::vector<std::string> string_list, std::string check);
        
    private:
        std::string strand;
        PersonCollector person_collector;
};