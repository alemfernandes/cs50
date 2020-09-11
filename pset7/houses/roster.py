from cs50 import SQL
from sys import argv, exit

# checks if the user is executing the correct number of arguments
if len(argv) != 2:
    print("Usage: python roster.py ""name_of_the_house""")
    exit(1)

housename = argv[1]

# create a database in pythom to interact with sql one
db = SQL("sqlite:///students.db")

# create a file in python with the sql query (return is a list of Python dicts)
query = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC", housename)

# iterate throught the file
for row in query:
    print(f"{row['first']} {row['middle'] + ' ' if row['middle'] else ''}{row['last']}, born {row['birth']}")

    #this does same in 2 lines of codes, without indenting everything
    #first, middle, last, birth = row["first"], row["middle"], row["last"], row["birth"]
    #print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")

    # this code does the same in an uglier version
    #if row["middle"] == None:
    #    print(row["first"] + " " + row["last"] + ", " + "born " + str(row["birth"]))
    #else:
    #    print(row["first"] + " " + row["middle"] + " " + row["last"] + ", " + "born " + str(row["birth"]))
