import cs50
import math

# getting the input
sentence = input("Please write your sentence here: ")
# int variables
k = 0
k1 = 1
k2 = 0
a = 0
b = 0
c = 0

# for loops to determine the rules
for i in range(len(sentence)):
    if (sentence[i] >= 'a' and sentence[i] <= 'z') == True or (sentence[i] >= 'A' and sentence[i] <= 'Z') == True:
        k += 1

for i in range(len(sentence)):
    if sentence[i] == ' ':
        k1 += 1

for i in range(len(sentence)):
    if sentence[i] == '.' or sentence[i] == '!' or sentence[i] == '?':
        k2 += 1

a = a + k
b = b + k1
c = c + k2
# Operations :
L = round(a * 100 / b)
S = round(c * 100 / b)
index = (0.0588 * L) - (0.296 * S) - 15.8
# rounding the index
index = round(index)
# statements for Grades
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade: {index}")