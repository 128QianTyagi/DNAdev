#include "../includes/Utilities.h"

Person Utilities::create_person(std::string input_line, std::vector<std::string> strs) {
    std::map<std::string, int> map;
    std::vector<std::string> values = split_line(input_line, ',');
    for (size_t i = 0; i < strs.size(); i++)
        map.insert(std::pair<std::string, int>(strs[i], std::stoi(values[i + 1])));
    return Person(map, values[0]);
}

std::vector<std::string> Utilities::split_line(std::string input, char delimiter) {
    std::vector<std::string> data;
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        data.push_back(token);
        input.erase(0, pos + 1);
    }
    data.push_back(input);
    return data;
}