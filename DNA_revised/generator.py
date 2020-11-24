import random
import os
from copy import deepcopy

alphabet = ["A", "T", "G", "C"]
str_list = ["AGAT", "AATG", "TATC", "CATG", "TTCA", "ACAG"]
people_list = ["Alice", "Bob", "Charlie", "Parth", "George", "John", "Thomas", "James", "Andrew", "Abraham", "Theodore", "Franklin", "Harry", "Dwight"]


csv_file = open("data.csv", "w")
csv_file.write("names,")
for str_ in str_list:
    csv_file.write(str_ + ",")
csv_file.write("\n")
    
data = dict()
for person in people_list:
    csv_file.write(person)
    occurences = list()
    for str_ in str_list:
        occurence = random.randint(0, 20)
        occurences.append(occurence)
        csv_file.write("," + str(occurence))
    data.update({person: occurences})
    csv_file.write("\n")
    
print(data)
csv_file.close()

solution_file = open("solution.txt", "w")

sequence = ""

match_index = random.randint(0, len(people_list))

if match_index == len(people_list):
    print("No Match!")
    for i in range(20, random.randint(40, 70)):
        sequence += alphabet[random.randint(0, len(alphabet) -1)]
else:
    print(people_list[match_index])
    solution_file.write(people_list[match_index] + "\n")
    
    required = deepcopy(data.get(people_list[match_index]))
    while sum(required) != 0:
        str_index = random.randint(0, len(str_list) * 3)
        if str_index >= len(str_list):
            print("Inserting random char")
            sequence += alphabet[random.randint(0, len(alphabet) - 1)]
        elif required[str_index] > 0:
            print("Generating: " + str_list[str_index] + " " + str(required[str_index]) + " times")
            for i in range(required[str_index]):
                sequence += str_list[str_index]
            required[str_index] = 0
        
print(sequence)
solution_file.write(sequence + "\n")
solution_file.close()

for i in range(0, len(data.get(people_list[match_index]))):
    desired = data.get(people_list[match_index])[i]
    print("Expect " + str_list[i - 1] + " " + str(desired) + " times")

#print("std::vector<std::string> names = {" + str(people_list).strip('[]') + "};")
#print("\n")
#data_values = "{"
#for value in data.values():
    #data_values += "{" + str(list(value)).strip("[]") + "}, "
#data_values += "};"
#print("std::vector<std::vector<int>> occurences = " + data_values)
