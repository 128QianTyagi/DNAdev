#include "../catch/catch.hpp"
#include "../includes/Analysis.h"

TEST_CASE("Find Difference 1", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {3, 7, 4}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"AGAT", "AATG", "TATC"};
    std::vector<DNA> dna;
    DNA trial("AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);
    REQUIRE(go.findDiff(people[0], {5, 2, 8}) == 0);
}

TEST_CASE("For Reese", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {3, 7, 4}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"AGAT", "AATG", "TATC"};
    std::vector<DNA> dna;
    DNA trial("AACCCTGCGCGCGCGCGATCTATCTATCTATCTATCCAGCATTAGCTAGCATCAAGATAGATAGATGAATTTCGAAATGAATGAATGAATGAATGAATGAATG", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);

    REQUIRE( go.findMatch(go.findCount(trial)) == "Reese" );
}

TEST_CASE("For Nathan", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {3, 7, 4}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"AGAT", "AATG", "TATC"};
    std::vector<DNA> dna;
    DNA trial("CCAGATAGATAGATAGATAGATAGATGTCACAGGGATGCTGAGGGCTGCTTCGTACGTACTCCTGATTTCGGGGATCGCTGACACTAATGCGTGCGAGCGGATCGATCTCTATCTATCTATCTATCTATCCTATAGCATAGACATCCAGATAGATAGATC", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);

    REQUIRE( go.findMatch(go.findCount(trial)) == "Nathan" );
}

TEST_CASE("For Michael", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {3, 7, 4}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"AGAT", "AATG", "TATC"};
    std::vector<DNA> dna;
    DNA trial("AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);

    REQUIRE( go.findMatch(go.findCount(trial)) == "Michael" );
}

TEST_CASE("For Random", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {15, 12, 10}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"AGAT", "AATG", "TATC"};
    std::vector<DNA> dna;
    DNA trial("TGTATCTATCTATCTATCTATCTATCTATCTATCTATCTATCAATGAATGAATGACAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGATAGGAGTGCGTGTAGAATTCAGAC", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);

    REQUIRE( go.findMatch(go.findCount(trial)) == "Reese" );
}

TEST_CASE("For Different String List", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {15, 12, 10}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"ATTA", "AGTC", "AAGC"};
    std::vector<DNA> dna;
    DNA trial("TCAAGCAAGCAAGCAAGCAAGCAAGCAAGCAAGCAAGCAAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAATTAAAGGTTGTTTTCTGGAAGCCTCC", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);

    REQUIRE( go.findMatch(go.findCount(trial)) == "No Match" );
}

TEST_CASE("For Fake DNA", "[weight=1]") {
    std::vector<std::vector<int>> people = {{5, 2, 8}, 
                                            {3, 7, 4}, 
                                            {6, 1, 5}};
    std::vector<std::string> str_list = {"AGAT", "AATG", "TATC"};
    std::vector<DNA> dna;
    DNA trial("AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA", str_list);
    dna.push_back(trial);
    std::vector<std::string> n_list = {"Michael", "Reese", "Nathan"};

    People p(dna, people, n_list);
    Analysis go(p);

    REQUIRE( go.findMatch(go.findCount(trial)) == "No Match" );

    DNA new_trial("AGACGGGTTACCATGACACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA", str_list);
    dna.push_back(new_trial);
    REQUIRE( go.findMatch(go.findCount(new_trial)) == "No Match" );

    DNA diff_trial("AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCCCAATAGACAAAA", str_list);
    dna.push_back(diff_trial);
    REQUIRE( go.findMatch(go.findCount(diff_trial)) == "No Match" );
}

// AGAT repeats 4 then 5 later