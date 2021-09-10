import re

fh = open("C:/Users/TOBI/Documents/Belajar Python/Coursera/PY4E/regex_sum_982366.txt")
sum = 0
for line in fh:
    num = re.findall('[0-9]+',line)
    length = len(num)
    for i in range(length):
        sum += int(num[i])
print(sum)