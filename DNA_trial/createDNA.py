str_1 = "AGAT"
str_2 = "AATG"
str_3 = "TATC"

test = "AGACGGGTTACCATGACTATCTATCTATCTATCTATCTATCTATCTATCACGTACGTACGTATCGAGATAGATAGATAGATAGATCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA"
print(len(test))

with open('DNAseq.txt', 'w') as writer:
    for i in range(50):
        writer.write("YA")