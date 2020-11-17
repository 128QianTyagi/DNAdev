#pragma once
#include "../includes/PersonCollector.h"
#include "Person.h"
#include "PersonCollector.h"
#include <iostream>
#include <vector>
#include <map>

class Analysis {
    public:
        /**
         *  Constructor for Analysis class
         * @param given_people A vector of people to analyze 
         */
        Analysis(const PersonCollector & collector, const std::string & dna_strand) : person_collector(collector), strand(dna_strand) {};

        /**
         * Check if the DNA map belongs to a particular person
         * @param person The indivdual to check
         * @param count The map of possible STRs and occurrences
         * @return true if the map belongs to the person
         */ 
        bool find_diff(Person person, std::map<std::string, int> count);

        /**
         * Find which person the given map of DNA and occurences belongs to
         * @param count The map of DNA and occurences
         * @return The name which the person the map belongs to 
         */
        std::string find_match(std::map<std::string, int> count);

        /**
         * Create a map of STRs and their occurences
         * @param strand The string of DNA to analyze
         * @return a map of STRs and their occurences
         */
        std::map<std::string, int> find_count();
        
        /**
         * Find which index a particular string occurs in a vector
         * @param string_list A vector of strings
         * @param check The string to check
         * @return The index at which the string occurs
         */
        int check_match(std::vector<std::string> string_list, std::string check);
        
    private:
        // std::vector<Person> people;
        // std::vector<std::string> strs;
        std::string strand;
        PersonCollector person_collector;
};