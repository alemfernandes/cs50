from cs50 import SQL
import csv
from sys import argv, exit

# checks if the user is executing the correct number of arguments
if len(argv) != 2:
    print("Usage: python import.py data.csv")
    exit(1)

csv_path = argv[1]

# Create database
open("students.db", "w").close()
db = SQL("sqlite:///students.db")

# Create table
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

# Open file provided by the user
with open(csv_path, "r") as file:

    # Create reader
    reader = csv.DictReader(file)

    # Iterate over CSV file
    for row in reader:

        # split the name
        names = row["name"].split()  # the base case is space, no argument needed

        # execute the inserction of data
        if len(names) > 2:  # if the the student has a middle name
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], names[1], names[2], row["house"], int(row["birth"]))
        else:  # if the student has not a middle name
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       names[0], None, names[1], row["house"], int(row["birth"]))
