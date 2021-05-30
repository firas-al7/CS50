import csv

with open('table.csv', 'r') as FILE:
    read = csv.reader(FILE, delimiter="|")
    with open('table.csv', 'w') as FILE2:
        write = csv.writer(FILE2)
        for i in read:
            write.append("HELLO")
    for j in read:
        print(j)