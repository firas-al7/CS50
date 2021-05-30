import csv
import cs50
import re
import sys
from sys import argv, exit
from cs50 import SQL
import string

db = SQL("sqlite:///students.db")
if len(sys.argv) != 2:
    sys.exit("Missing command line argument")

# s = "HELLO WORLD"
# print(s.split())
argv = argv[1]
b = 0
with open(argv, "r") as FILE:
    reader = csv.DictReader(FILE)
    for row in reader:
        name = row["name"].split()
        if len(name) >= 3:
            name
        else:
            name = [name[0], None, name[1]]
        # print(name2)
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                   name[0], name[1], name[2], row['house'], row['birth'])
