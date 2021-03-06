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

    PersonCollector collector = PersonCollector(argv[1]);
    Analyzer analyze(collector, argv[2]);
    /**
    std::map<std::string, int> count = analyze.find_count();
    for (auto it = count.begin(); it != count.end(); ++it)
        std::cout << it->first << " , " << it->second << "\n";
    std::cout << analyze.find_match(count) << std::endl;
    */
    
}