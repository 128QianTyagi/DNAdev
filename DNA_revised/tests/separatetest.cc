#include "catch.hpp"
#include "../includes/DNA.h"
#include "../includes/Analysis.h"
#include "../includes/CSVReader.h"

TEST_CASE("CSVReader get_person works", "[weight=1]") {
    std::vector<std::string> strs = {"AGAT", "TAGC", "AACT"};
    std::string line = "Michael,1,2,3";
    std::map<std::string, int> map;
    map["AGAT"] = 1;
    map["TAGC"] = 2;
    map["AACT"] = 3;
    Person p = Person(map, "Michael");
    Person generatedPerson = CSVReader::get_person(line, strs);
    if (p.get_name() != generatedPerson.get_name())
        FAIL("CSVReader -- get_person fails to set name properly");
    if (p.get_values() != generatedPerson.get_values())
        FAIL("CSVReader -- get_person fails to set value map properly");
    REQUIRE(true);
}

TEST_CASE("CSVReader get_person works 2", "[weight=1]") {
    std::vector<std::string> strs = {"AGAT", "TAGC", "AACT", "GACA", "CCTG", "ATGC"};
    std::string line = "Michael,1,2,3,4,5,6";
    std::map<std::string, int> map;
    map["AGAT"] = 1;
    map["TAGC"] = 2;
    map["AACT"] = 3;
    map["GACA"] = 4;
    map["CCTG"] = 5;
    map["ATGC"] = 6;
    Person p = Person(map, "Michael");
    Person generatedPerson = CSVReader::get_person(line, strs);
    if (p.get_name() != generatedPerson.get_name())
        FAIL("CSVReader -- get_person fails to set name properly");
    if (p.get_values() != generatedPerson.get_values())
        FAIL("CSVReader -- get_person fails to set value map properly");
    REQUIRE(true);
}

TEST_CASE("CSVReader process_file works", "[weight=1]") {
    std::vector<std::string> strs = {"AGTC","TGCA","TGCT","GCAT","GGAT"};
    std::vector<std::string> names = {"Parth", "Daniel", "Michael"};
    int counter = 1;
    std::vector<Person> desired_result;

    for (const std::string & name : names) {
        std::map<std::string, int> map;
        for (size_t i  = 0; i < strs.size(); i++) {
            map[strs[i]] = counter * (i + 1);
        }
        desired_result.push_back(Person(map, name));
        counter++;
    } 

    std::vector<Person> result = CSVReader::process_file("tests/tests_part1_1.csv");
    for (size_t i = 0; i < names.size(); i++) {
        if (result[i].get_name() != desired_result[i].get_name())
            FAIL("CSVReader -- process_file fails to read name properly");
        if (result[i].get_values() != desired_result[i].get_values()) 
            FAIL("CSVReader -- process_file fails to read STR values properly");
    }
    REQUIRE(true);
}

TEST_CASE("CSVReader process_file works 2", "[weight=1]") {
    std::vector<std::string> strs = {"AGTC","TGCA","TGCT","GCAT","GGAT","CCAT","CGAT","ATGG","ATCG","CCCC","AAAG","TTGA","TCTC","CAAT","AATC"};
    std::vector<std::string> names = {"Parth", "Daniel", "Michael", "John", "Ben"};
    int counter = 1;
    std::vector<Person> desired_result;

    for (const std::string & name : names) {
        std::map<std::string, int> map;
        for (size_t i  = 0; i < strs.size(); i++) {
            map[strs[i]] = counter * (i + 1);
        }
        desired_result.push_back(Person(map, name));
        counter++;
    } 

    std::vector<Person> result = CSVReader::process_file("tests/tests_part1_2.csv");
    for (size_t i = 0; i < names.size(); i++) {
        if (result[i].get_name() != desired_result[i].get_name())
            FAIL("CSVReader -- process_file fails to read name properly");
        if (result[i].get_values() != desired_result[i].get_values()) 
            FAIL("CSVReader -- process_file fails to read STR values properly");
    }
    REQUIRE(true);
}


TEST_CASE("Basic Person object works", "[weight=1]") {
    std::map<std::string, int> values;
    values["AGAT"] = 5;
    values["AATG"] = 2;
    values["TATC"] = 8;
    Person p(values, "Michael");
    if (p.get_name() != "Michael")
        FAIL("Person class fails to set name properly");
    if (p.get_values() != values)
        FAIL("Person class fails to set DNA maps properly");
    REQUIRE(true);
}

TEST_CASE("Analysis -- check_match works", "[weight=1]") {
    std::vector<std::string> strs = {"ACAT", "AGAT", "CCGT", "TAGA", "GACG"};
    std::map<std::string, int> map;
    int counter = 0;
    for (const std::string & i : strs)
        map.insert(std::pair<std::string, int>(i, counter++));
    Person p(map, "Michael");
    std::vector<Person> vec = {p};
    Analysis analysis(vec);
    for (size_t i = 0; i < strs.size(); i++) {
        REQUIRE(analysis.check_match(strs, strs[i]) == i);
    }
}

TEST_CASE("Analysis -- check_match return -1 on no match", "[weight=1]") {
    std::vector<std::string> strs = {"ACAT", "AGAT", "CCGT", "TAGA", "GACG"};
    std::map<std::string, int> map;
    int counter = 0;
    for (const std::string & i : strs)
        map.insert(std::pair<std::string, int>(i, counter++));
    Person p(map, "Michael");
    std::vector<Person> vec = {p};
    Analysis analysis(vec);
    for (size_t i = 0; i < strs.size(); i++) {
        REQUIRE(analysis.check_match(strs, strs[i]) == i);
    }
    REQUIRE(analysis.check_match(strs, "testing") == -1);
    REQUIRE(analysis.check_match(strs, "AAAA") == -1);
}

TEST_CASE("Analysis -- find_match return works 1", "[weight=1]") {
    std::vector<Person> result = CSVReader::process_file("tests/tests_part1_1.csv");
    std::map<std::string, int> map;
    map["AGTC"] = 2;
    map["TGCA"] = 4;
    map["TGCT"] = 6;
    map["GCAT"] = 8;
    map["GGAT"] = 10;
    REQUIRE(Analysis(result).find_match(map) == "Daniel");
}

TEST_CASE("Analysis -- find_match return works 2", "[weight=1]") {
    std::vector<Person> result = CSVReader::process_file("tests/tests_part1_2.csv");
    std::map<std::string, int> map;
    map["AGTC"] = 5;
    map["TGCA"] = 10;
    map["TGCT"] = 15;
    map["GCAT"] = 20;
    map["GGAT"] = 25;
    map["CCAT"] = 30;
    map["CGAT"] = 35;
    map["ATGG"] = 40;
    map["ATCG"] = 45;
    map["CCCC"] = 50;
    map["AAAG"] = 55;
    map["TTGA"] = 60;
    map["TCTC"] = 65;
    map["CAAT"] = 70;
    map["AATC"] = 75;
    REQUIRE(Analysis(result).find_match(map) == "Ben");
}

TEST_CASE("Analysis -- find_match return No Match", "[weight=1]") {
    std::vector<Person> result = CSVReader::process_file("tests/tests_part1_2.csv");
    std::map<std::string, int> map;
    map["AGTC"] = 5;
    map["TGCA"] = 10;
    map["TGCT"] = 15;
    map["GCAT"] = 20;
    map["GGAT"] = 25;
    map["CCAT"] = 30;
    map["CGAT"] = 35;
    map["ATGG"] = 40;
    map["ATCG"] = 45;
    map["CCCC"] = 50;
    map["AAAG"] = 55;
    map["TTGA"] = 60;
    map["TCTC"] = 55;
    map["CAAT"] = 70;
    map["AATC"] = 75;
    REQUIRE(Analysis(result).find_match(map) == "No Match");
}

TEST_CASE("Analysis -- basic find_count works", "[weight=1]") {
    std::vector<std::string> strs = {"ACAT", "AGAT", "CCGT", "TAGA", "GACG"};
    std::map<std::string, int> map;
    int counter = 0;
    for (const std::string & i : strs)
        map.insert(std::pair<std::string, int>(i, counter++));
    Person p(map, "Michael");
    std::vector<Person> vec = {p};
    Analysis analysis(vec);
    
    std::string sequence = "ACATAGATCCGTTAGAGACG";
    std::map<std::string, int> result;
    for (size_t i = 0; i < strs.size(); i++) {
        result.insert(std::pair<std::string, int>(strs[i], 1));
    } 
    REQUIRE(analysis.find_count(sequence) == result);
}

// TEST_CASE("Analysis -- basic find_count 2 works", "[weight=1]") {
//     std::vector<std::string> strs = {"ACAT", "AGAT", "CCGT"};
//     std::map<std::string, int> map;
//     int counter = 0;
//     for (const std::string & i : strs)
//         map.insert(std::pair<std::string, int>(i, counter++));
//     Person p(map, "Michael");
//     std::vector<Person> vec = {p};
//     Analysis analysis(vec);
    
//     std::string sequence = "ACATACATAGATCCGTTAGATAGAGACG";
//     std::map<std::string, int> result;
//     for (size_t i = 0; i < strs.size(); i++) {
//         result.insert(std::pair<std::string, int>(strs[i], 1));
//     } 
//     result["ACAT"] = 2;
//     for (auto it = result.begin(); it != result.end(); ++it)
//         std::cout << it->first  << " , " << it->second << "\n";

//     std::map<std::string, int> returned = analysis.find_count(sequence);

//     for (auto it = returned.begin(); it != returned.end(); ++it)
//         std::cout << it->first  << " , " << it->second << "\n";
//     REQUIRE(analysis.find_count(sequence) == result);
// }