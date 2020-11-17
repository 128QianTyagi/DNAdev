#include "../includes/Analyzer.h"
#include "../includes/PersonCollector.h"
#include "../includes/Person.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[]) {
    if (argc < 3) {
        std::cout << "ERROR: Please specify CSV file as the first argument and the DNA sequence as the second argument\n";
        return -1;
    }
    // std::fstream input_file = std::fstream(argv[1]);

    // std::string line;
    // std::string attribute_line;

    // std::getline(input_file, attribute_line);
    // std::vector<std::string> attributes = split_line(attribute_line, ',');

    // std::vector<std::string> strs;
    // strs.assign(attributes.begin() + 1, attributes.end());
    
    // Person p;
    // while (std::getline(input_file, line)) {

    //     std::vector<std::string> values = split_line(line, ',');
    //     std::map<std::string, int> map;
    //     for (size_t i = 1; i < values.size(); i++)
    //         map.insert(std::pair<std::string, int>(attributes[i], std::stoi(values[i])));
    //     p = Person(map, values[0]);
    //     for (auto it = map.begin(); it != map.end(); ++it)
    //         std::cout << (*it).first << " , " << (*it).second << "\n";
    // }
    // std::vector<Person> people = csvReader(std::fstream(argv[1]));
    // input_file.close();
    
    // Analyzer analyze(people);
    // std::map<std::string, int> test = analyze.find_count(argv[2]);
    //std::cout << test.find([""]);
    // std::unordered_map<std::string, int> parth_map;
    // parth_map.insert(std::pair<std::string, int>("AGAT", 3));
    // Person parth = Person(parth_map, "Parth");
    // std::unordered_map<std::string, int> daniel_map;
    // daniel_map.insert(std::pair<std::string, int>("AGAT", 5));
    // Person daniel = Person(daniel_map, "Daniel");

    // std::vector<Person> vec = {parth, daniel};

    // Analyzer analyzer = Analyzer(vec);

    // std::vector<Person> people = CSVReader::process_file(argv[1]);
    // // for (Person & p : people) {
    // //     std::cout << p.get_name() << "\n";\
    // //     std::map<std::string, int> map = p.get_values();
    // //     for (auto it = map.begin(); it != map.end(); ++it)
    // //         std::cout << it->first << " , " << it->second << "\n";
    // // }

    PersonCollector collector = PersonCollector(argv[1]);
    Analyzer analyze(collector, argv[2]);
    std::map<std::string, int> count = analyze.find_count();
    for (auto it = count.begin(); it != count.end(); ++it)
        std::cout << it->first << " , " << it->second << "\n";
    std::cout << analyze.find_match(count) << std::endl;
    
}