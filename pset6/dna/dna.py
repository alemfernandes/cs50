import csv
import sys

# checks if the user is executing the correct number of arguments
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

csv_path = sys.argv[1]
txt_path = sys.argv[2]

# function for calculate the max number of sequencial aparences of a substring in a sequency of DNA


def get_maxstrs(seq, substr):
    seq_strcounter = [0] * len(seq)
    for i in range(len(seq) - len(substr), -1, -1):
        if seq[i: i + len(substr)] == substr:
            if i + len(substr) > len(seq) - 1:
                seq_strcounter[i] = 1
            else:
                seq_strcounter[i] = 1 + seq_strcounter[i + len(substr)]
    return max(seq_strcounter)


# function to check if the max strs of a sequence match an individual on the csv database

def match(reader, max_strs):
    for row in reader:
        ind = row[0]
        values = []
        for val in row[1:]:
            values.append(int(val))
        # values = [int(val) for val in row[1:]] in python this does the same as the above
        if values == max_strs:
            print(ind)
            return
    print("No Match")

# open the csv file


with open(csv_path) as csvfile:
    reader = csv.reader(csvfile)
    substr_list = next(reader)[1:]  # take the header of the file and creates a list of STRs (Short Tandem Repeats of DNA)

    with open(txt_path) as txtfile:  # open the txt file
        seq = txtfile.read()
        max_strs = []
        for substr in substr_list:
            max_strs.append(get_maxstrs(seq, substr))  # for each STR, find the max and store it in a list
            # max_strs = [get_maxstrs(seq, substr) for substr in substr_list] is the same of the above

        match(reader, max_strs)

