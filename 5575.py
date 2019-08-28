def time_calc(lst =[]):
    if lst[5] < lst[2]:
        if lst[4] == 0:
            lst[3] -= 1
            lst[4] = 60
        lst[4] -= 1
        lst[5] += 60
    yield lst[5]-lst[2]
    
    if lst[4] < lst[1]:
        lst[3] -= 1
        lst[4] += 60
    yield lst[4]-lst[1]
    yield lst[3]-lst[0]

for i in range(0,3):
    lst = [int(i) for i in input().split()]
    ret = list(time_calc(lst))
    for i in reversed(ret):
        print(i, end = " ")
