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
        Analyzer(PersonCollector collector, const std::string & dna_strand);
        
        /**
         * Find which index a particular string occurs in a vector
         * @return The name of the person who matches the DNA
         */
        std::string analyze() const;
        
    private:
        std::string strand;
        PersonCollector person_collector;
};