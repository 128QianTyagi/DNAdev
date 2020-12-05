#include "../includes/Analyzer.h"

Analyzer::Analyzer(const PersonCollector & collector, const std::string & dna_strand) : strand(dna_strand), person_collector(collector) {}

std::map<std::string, int> Analyzer::find_count() {
    for (std::string s : person_collector.get_strs())
        std::cout << s << "\n";

    std::vector<std::string> strs = person_collector.get_strs();

    std::string temp = "";
    std::map<std::string, int> count;
    for (const std::string & s : strs)
        count[s] = 0;
    int max = 1;
    int same = 0;
    int prev = -1;
    for (int j = 0; j < (int)strs[0].length(); j++) {
        for (int i = j; i < (int)strand.length(); i+=strs[0].length()) {
            temp = "";
            temp = strand.substr(i, strs[0].length());
            same = check_match(strs, temp);
            if (same > -1) {
                if (prev == same) {
                    max++;
                }
                if (count.find(strs[same]) -> second <= max) {
                    count[strs[same]] = max;
                }
            } else {
                max = 1;
            }
            prev = same;
        }
    }
    return count;
} 

int Analyzer::check_match(std::vector<std::string> string_list, std::string check) {
    for (int i = 0; i < (int)string_list.size(); i++) {
        if (check == string_list[i]) {
            return i;
        }
    }
    return -1;
}

bool Analyzer::find_diff(Person person, std::map<std::string, int> count) {
    std::vector<std::string> strs = person_collector.get_strs();
    int index = 0;
    for (size_t i = 0; i < strs.size(); i++) {
        if (person.get_values(strs[i]) != count.find(strs[i])->second) {

            return false;
        }
        index++;
    }
    return true;
}

std::string Analyzer::analyze() {
    std::map<std::string, int> count = find_count();
    std::string result = "No Match";
    std::vector<Person> people = person_collector.get_persons();
    for (size_t i = 0; i < people.size(); i++) {
        if (find_diff(people[i], count)) {
            if (result == "No Match") {
                result = people[i].get_name();
            } else {
                return "Ambiguous Match";
            }
        }
    }
    return result;
}

