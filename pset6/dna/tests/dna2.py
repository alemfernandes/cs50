import csv
import sys
import pandas as pd

# checks if the user is execution the correct number of arguments
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

csv_path = sys.argv[1]
txt_path = sys.argv[2]

df_base = pd.read_csv(csv_path)
seq = open(txt_path, 'r').read()

str_list = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]

n_AGATC = 0
n_TTTTTTCT = 0
n_AATG = 0
n_TCTAG = 0
n_GATA = 0
n_TATC = 0
n_GAAA = 0
n_TCTG = 0

for j in range(4, 9):
    for i in range(0, len(seq) - j):
        if seq[i:j + i] == str_list[0]:
            n_AGATC += 1
        elif seq[i:j + i] == str_list[1]:
            n_TTTTTTCT += 1
        elif seq[i:j + i] == str_list[2]:
            n_AATG += 1
        elif seq[i:j + i] == str_list[3]:
            n_TCTAG += 1
        elif seq[i:j + i] == str_list[4]:
            n_GATA += 1
        elif seq[i:j + i] == str_list[5]:
            n_TATC += 1
        elif seq[i:j + i] == str_list[6]:
            n_GAAA += 1
        elif seq[i:j + i] == str_list[7]:
            n_TCTG += 1

print(n_AGATC)
print(n_TTTTTTCT)
print(n_AATG)
print(n_TCTAG)
print(n_GATA)
print(n_TATC)
print(n_GAAA)
print(n_TCTG)


#with open(sys.argv[1], newline='') as csvfile:
#    file = csv.DictReader(csvfile)
#    for row in file:
#        print(row['name'])