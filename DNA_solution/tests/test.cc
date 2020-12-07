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
    try {
        Person& name = analyze.analyze();
        REQUIRE(name.get_name()=="Michael");
    } catch (std::string e) {
        FAIL("Find Match Fails");
    }
}

TEST_CASE("Find Reese 1", "[Match]") {
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    Analyzer analyze(people, test);
    try {
        Person& name = analyze.analyze();
        REQUIRE(name.get_name()=="Reese");
    } catch (std::string e) {
        FAIL("Find Match Fails");
    }
}


TEST_CASE("Find Nathan 1", "[Match]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze(people, test);
    try {
        Person& name = analyze.analyze();
        REQUIRE(name.get_name()=="Nathan");
    } catch (std::string e) {
        FAIL("Find Match Fails");
    }
}

TEST_CASE("Find Fake Michael", "[Edge]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze1(people, test);
    try {
        Person& name = analyze1.analyze();
        REQUIRE(name.get_name()=="Michael");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }
    
    test = "AGACGGGTTACCATGACACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze2(people, test);
    try {
        Person& name = analyze2.analyze();
        REQUIRE(name.get_name()=="Michael");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }

    test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze3(people, test);
    try {
        Person& name = analyze3.analyze();
        REQUIRE(name.get_name()=="Michael");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }
}


TEST_CASE("Find Fake Reese", "[Edge]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze1(people, test);
    try {
        Person& name = analyze1.analyze();
        REQUIRE(name.get_name()=="Reese");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }

    test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGA";
    Analyzer analyze2(people, test);
    try {
        Person& name = analyze2.analyze();
        REQUIRE(name.get_name()=="Reese");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }

    test = "AACCCTGCGCGCGCGCGATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze3(people, test);
    try {
        Person& name = analyze3.analyze();
        REQUIRE(name.get_name()=="Reese");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }
}

TEST_CASE("Find Fake Nathan", "[Edge]") {
    PersonCollector people = PersonCollector("tests/datum/MRN_set.csv");
    std::string test = "CCGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze1(people, test);
    try {
        Person& name = analyze1.analyze();
        REQUIRE(name.get_name()=="Nathan");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze2(people, test);
    try {
        Person& name = analyze2.analyze();
        REQUIRE(name.get_name()=="Nathan");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze3(people, test);
    try {
        Person& name = analyze3.analyze();
        REQUIRE(name.get_name()=="Nathan");
    } catch (std::string e) {
        REQUIRE(e == "No Match");
    }
}

TEST_CASE("Find Ambiguous", "[Ambiguous]") {
    PersonCollector people = PersonCollector("tests/datum/AMB_set.csv");
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze(people, test);
    try {
        Person& name = analyze.analyze();
        REQUIRE(name.get_name()=="Nathan");
    } catch (std::string e) {
        REQUIRE(e == "Ambiguous Match");
    }
}

//Extra Credit, they test their own helper methods while we test only for final answers
