#include "catch.hpp"
#include "../includes/Analyzer.h"
#include "../includes/PersonCollector.h"
#include "../includes/Person.h"
#include <iostream>
#include <fstream>
#include <string>

TEST_CASE("Find Michael 1", "[Match]") {
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    Analyzer analyze(people, test);
    std::string name = analyze.analyze();
    REQUIRE(name=="Michael");
}

TEST_CASE("Find Reese 1", "[Match]") {
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    Analyzer analyze(people, test);
    std::string name = analyze.analyze();
    REQUIRE(name=="Reese");
}


TEST_CASE("Find Nathan 1", "[Match]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze(people, test);
    std::string name = analyze.analyze();
    REQUIRE(name=="Nathan");
}

TEST_CASE("Find Fake Michael", "[Edge]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze1(people, test);
    std::string name = analyze1.analyze();
    REQUIRE(name == "No Match");
    
    test = "AGACGGGTTACCATGACACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze2(people, test);
    name = analyze2.analyze();
    REQUIRE(name == "No Match");

    test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze3(people, test);
    name = analyze3.analyze();
    REQUIRE(name == "No Match");
}


TEST_CASE("Find Fake Reese", "[Edge]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze1(people, test);
    std::string name = analyze1.analyze();
    REQUIRE(name=="No Match");

    test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGA";
    Analyzer analyze2(people, test);
    name = analyze2.analyze();
    REQUIRE(name=="No Match");

    test = "AACCCTGCGCGCGCGCGATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze3(people, test);
    name = analyze3.analyze();
    REQUIRE(name=="No Match");
}

TEST_CASE("Find Fake Nathan", "[Edge]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "CCGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze1(people, test);
    std::string name = analyze1.analyze();
    REQUIRE(name=="No Match");

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze2(people, test);
    name = analyze2.analyze();
    REQUIRE(name=="No Match");

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze3(people, test);
    name = analyze3.analyze();
    REQUIRE(name=="No Match");
}

TEST_CASE("Find Ambiguous", "[Ambiguous]") {
    PersonCollector people = PersonCollector("tests/datum/AMB_set.csv");
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze(people, test);
    std::string name = analyze.analyze();
    REQUIRE(name=="Ambiguous Match");
}

//Extra Credit, they test their own helper methods while we test only for final answers