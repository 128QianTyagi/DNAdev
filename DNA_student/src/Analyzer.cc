#include "../includes/Analyzer.h"

Analyzer::Analyzer(PersonCollector collector, const std::string & dna_strand) : strand(dna_strand), person_collector(collector) {}

std::string Analyzer::analyze() const {
    return "";
}
