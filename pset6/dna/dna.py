import csv
from sys import argv, exit
import cs50
import re


# our main function which opens the files and search through the DNA sequences


def main():
    if len(argv) != 3:
        print("wrong input")
        exit(1)

    with open(argv[1], "r") as file:
        reader = csv.reader(file, delimiter=',')
        # for j in reader:
        # print(j)
        all_sequences = next(reader)[1:]
        with open(argv[2]) as file2:
            reader2 = file2.read()
            actual = []
            for seq in all_sequences:
                actual.append(maximum(reader2, seq))
        print_match(reader, actual)


# the maximum finction which finds the numbers of the largest sequences repeated in the DNA


def maximum(s, sub):
    answer = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                answer[i] = 1
            else:
                answer[i] = 1 + answer[i + len(sub)]
    return max(answer)

# the final function which prints the winner or the match of the DNA sequences


def print_match(reader, actual):
    for l in reader:
        p = l[0]
        values = []
        for v in l[1:]:
            values.append(int(v))
        if values == actual:
            print(p)
            return
    print("No Match")


# calling the main function
# if __name__ == "__main__":
main()