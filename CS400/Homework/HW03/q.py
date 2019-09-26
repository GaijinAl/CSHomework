f = open("nums.txt", "r")
sum = 0
for line in f:
    sum = int(line) + sum
    print(sum)
