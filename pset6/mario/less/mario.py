# get the input in string
s = input("Enter the number of rows please: ")
# statement to ask the user for number if the valid number is not entered
while s.isnumeric() == False or int(s) > 8 or int(s) < 1:
    s = input("Enter the number of rows again! : ")
# convert the string value to an integer
s = int(s)
# a variable called k for hashtags
k = 1
# a variable for j to make the number of hashes
j = 1
# a for loop to do the following in range of the input number
for i in range(s):
    # an statement to print the hashesh in a single line
    if j <= s:
        print(" " * (s-j), end="")
        print("#" * j, end="")
        j += 1
    k += 1
    # printing a new row
    print("")