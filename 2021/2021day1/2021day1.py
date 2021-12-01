with open("input.txt") as input:
    depths = [int(depth) for depth in input]

increases = 0
for i in range(len(depths)-1):
    if depths[i] < depths[i+1]:
        increases += 1
print(increases)

increases_sliding = 0
for i in range(len(depths)-3):
    if depths[i] < depths[i+3]:
        increases_sliding += 1
print(increases_sliding)