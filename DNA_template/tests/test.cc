#include "catch.hpp"
#include "../includes/Analyzer.h"

TEST_CASE("Find Michael 1", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 3;
    r_values["AATG"] = 7;
    r_values["TATC"] = 4;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Michael");
}

TEST_CASE("Find Reese 1", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 3;
    r_values["AATG"] = 7;
    r_values["TATC"] = 4;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Reese");
}

TEST_CASE("Find Nathan 1", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 3;
    r_values["AATG"] = 7;
    r_values["TATC"] = 4;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Nathan");
}

TEST_CASE("Find Fake Michael", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 3;
    r_values["AATG"] = 7;
    r_values["TATC"] = 4;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name == "No Match");
    
    test = "AGACGGGTTACCATGACACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA";
    name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name == "No Match");

    test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name == "No Match");

}

TEST_CASE("Find Fake Reese", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 3;
    r_values["AATG"] = 7;
    r_values["TATC"] = 4;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Reese");

    test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Reese");

    test = "AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG";
    name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Reese");
}

TEST_CASE("Find Fake Nathan", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 3;
    r_values["AATG"] = 7;
    r_values["TATC"] = 4;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "CCGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="No Match");

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC";
    name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="No Match");

    test = "CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCCTATAGCATAGACATCCAGATAGATAGATC";
    name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="No Match");
    
}

TEST_CASE("Find Ambiguous", "[weight=1]") {
    std::map<std::string, int> m_values;
    m_values["AGAT"] = 5;
    m_values["AATG"] = 2;
    m_values["TATC"] = 8;
    Person m(m_values, "Michael");

    std::map<std::string, int> r_values;
    r_values["AGAT"] = 5;
    r_values["AATG"] = 2;
    r_values["TATC"] = 8;
    Person r(r_values, "Reese");

    std::map<std::string, int> n_values;
    n_values["AGAT"] = 6;
    n_values["AATG"] = 1;
    n_values["TATC"] = 5;
    Person n(n_values, "Nathan");

    std::vector<Person> people = {m, r, n};
    std::string test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA";
    Analyzer analyze(people);
    std::string name = analyze.find_match(analyze.find_count(test));
    REQUIRE(name=="Ambiguous Match");
}

