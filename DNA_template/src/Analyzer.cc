#include "../includes/Analyzer.h"

Analyzer::Analyzer(const PersonCollector & collector, const std::string & dna_strand) : person_collector(collector), strand(dna_strand) {}

int Analyzer::check_match(std::vector<std::string> string_list, std::string check) {
    return -1;
}
