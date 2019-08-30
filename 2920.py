#2920 음계
lst = [int(i) for i in input().split()]
flag = 1 # -1 : ascending, 1(default) : descending, 0: mixed
i = 0
while(flag != 0 and i < 8):
    if i == 0:
        if lst[i] == 1:
            flag = -1
        elif lst[i] == 8:
            flag = 1
        else:
            flag = 0
    else:
        if flag == -1:
            if lst[i] != i+1 : flag = 0
        if flag == 1:
            if lst[i] != 8-i : flag = 0
    #print(lst[i])
    i += 1
    
if flag == -1:
    print("ascending")
elif flag == 1:
    print("descending")
else:
    print("mixed")
