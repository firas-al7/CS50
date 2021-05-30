import re
import cs50
import math

# integers to count the number of coins
a = 0
b = 0
c = 0
d = 0

# get the input in string
change = input("Enter the number of rows please: ")
while change.replace('.', '', 1).isdigit() == False:
    change = input("Enter the number of rows please: ")


# statement to ask the user for number if the valid number is not entered
while float(change) < 0:
    change = input("Enter the number of rows again! : ")
# convert the string value to an integer
# print(change)
change = float(change)
change1 = round(float(change) * 100.00)
# change the input from dollar to cents.
change1 = int(change1)
# print(change1)
while change1 > 0:
    if change1 >= 25:
        c1 = int(change1 / 25)
        a += c1
        change1 = change1 % 25
    if change1 >= 10:
        c2 = int(change1 / 10)
        b += c2
        change1 = change1 % 10
    if change1 >= 5:
        c3 = int(change1 / 5)
        c += c3
        change1 = change1 % 5
    if change1 >= 1:
        c4 = int(change1 / 1)
        d += c4
        change1 = change1 % 1

print(a + b + c + d)

# had some help from stack_overgflow