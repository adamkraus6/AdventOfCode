with open("input.txt") as file:
	input = file.readlines()

pt1_sum=0
pt2_sum=0

rep = [
	["one", 'one1one'],
	["two", 'two2two'],
	["three", 'three3three'],
	["four", 'four4four'],
	["five", 'five5five'],
	["six", 'six6six'],
	["seven", 'seven7seven'],
	["eight", 'eight8eight'],
	["nine", 'nine9nine'],
	["zero", 'zero0zero']
]

for i in range(len(input)):
	inp = input[i]
	inp_rev = input[i][::-1]
	inp_2 = input[i]

	for j in range(len(rep)):
		inp_2 = inp_2.replace(rep[j][0], rep[j][1])

	inp_2_rev = inp_2[::-1]

	for j in range(len(inp)):
		if inp[j].isnumeric():
			first_digit_pt1 = inp[j]
			break

	for j in range(len(inp)):
		if inp_rev[j].isnumeric():
			last_digit_pt1 = inp_rev[j]
			break
	
	pt1_sum += int(first_digit_pt1 + last_digit_pt1)
	
	for j in range(len(inp_2)):
		if inp_2[j].isnumeric():
			first_digit_pt2 = inp_2[j]
			break
	
	for j in range(len(inp_2)):
		if inp_2_rev[j].isnumeric():
			last_digit_pt2 = inp_2_rev[j]
			break

	pt2_sum += int(first_digit_pt2 + last_digit_pt2)

print(f'Part 1: {pt1_sum}')
print(f'Part 2: {pt2_sum}')