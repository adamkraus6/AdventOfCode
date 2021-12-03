with open("input.txt") as input:
    lines = [line for line in input]

depth = 0
pos = 0
for line in lines:
    parts = line.split()
    ins = parts[0]
    num = int(parts[1])
    if ins == "forward":
        pos += num
    elif ins == "down":
        depth += num
    elif ins == "up":
        depth -= num
print(depth * pos)

aim = 0
depth = 0
pos = 0
for line in lines:
    parts = line.split()
    ins = parts[0]
    num = int(parts[1])
    if ins == "down":
        aim += num
    elif ins == "up":
        aim -= num
    elif ins == "forward":
        pos += num
        depth += num * aim
print(depth * pos)