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
    exit(1)
argv = argv[1]
if argv == "Gryffindor":
    a = db.execute("SELECT * FROM students WHERE house = 'Gryffindor' ORDER BY last, first")
elif argv == "Slytherin":
    a = db.execute("SELECT * FROM students WHERE house = 'Slytherin' ORDER BY last, first")
elif argv == "Ravenclaw":
    a = db.execute("SELECT * FROM students WHERE house = 'Ravenclaw' ORDER BY last, first")
elif argv == "Hufflepuff":
    a = db.execute("SELECT * FROM students WHERE house = 'Hufflepuff' ORDER BY last, first")
for i in a:
    first = i['first']
    middle = i['middle']
    last = i['last']
    birth = i['birth']
    print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")