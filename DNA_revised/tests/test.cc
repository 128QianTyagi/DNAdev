#include "catch.hpp"
#include "../includes/Analyzer.h"
#include "../includes/PersonCollector.h"
#include "../includes/Person.h"
#include <iostream>
#include <fstream>
#include <string>

TEST_CASE("Find Michael 1", "[weight=1]") {
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    Analyzer analyze(people, test);
    std::map<std::string, int> count = analyze.find_count();
    std::string name = analyze.find_match(count);
    REQUIRE(name=="Michael");
}

TEST_CASE("Find Reese 1", "[weight=1]") {
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    Analyzer analyze(people, test);
    std::string name = analyze.find_match(analyze.find_count());
    REQUIRE(name=="Reese");
}


TEST_CASE("Find Nathan 1", "[weight=1]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze(people, test);
    std::string name = analyze.find_match(analyze.find_count());
    REQUIRE(name=="Nathan");
}

TEST_CASE("Find Fake Michael", "[weight=1]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze1(people, test);
    std::string name = analyze1.find_match(analyze1.find_count());
    REQUIRE(name == "No Match");
    
    test = "AGACGGGTTACCATGACACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze2(people, test);
    name = analyze2.find_match(analyze2.find_count());
    REQUIRE(name == "No Match");

    test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze3(people, test);
    name = analyze3.find_match(analyze3.find_count());
    REQUIRE(name == "No Match");

}


TEST_CASE("Find Fake Reese", "[weight=1]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze1(people, test);
    std::string name = analyze1.find_match(analyze1.find_count());
    REQUIRE(name=="No Match");

    test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGA";
    Analyzer analyze2(people, test);
    name = analyze2.find_match(analyze2.find_count());
    REQUIRE(name=="No Match");

    test = "AACCCTGCGCGCGCGCGATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze3(people, test);
    name = analyze3.find_match(analyze3.find_count());
    REQUIRE(name=="No Match");
}

TEST_CASE("Find Fake Nathan", "[weight=1]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "CCGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze1(people, test);
    std::string name = analyze1.find_match(analyze1.find_count());
    REQUIRE(name=="No Match");

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze2(people, test);
    name = analyze2.find_match(analyze2.find_count());
    REQUIRE(name=="No Match");

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze3(people, test);
    name = analyze3.find_match(analyze3.find_count());
    REQUIRE(name=="No Match");
    
}

TEST_CASE("Find Ambiguous", "[weight=1]") {
    PersonCollector people = PersonCollector("tests/datum/AMB_set.csv");
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze(people, test);
    std::string name = analyze.find_match(analyze.find_count());
    REQUIRE(name=="Ambiguous Match");
}

