def lst_input():
    for i in range(8):
        yield int(input())

sum = 0
max = 0
#lst = list(lst_input())
lst = [i for i in lst_input()]
for i in range(8):
    sum = 0
    for j in range(i,i+4):
        sum += lst[j%8]
    max = max if max > sum else sum
print(max)
