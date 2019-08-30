#2562 최댓값
max = 0

def lst_build():
    global max
    for i in range(9):
        num = int(input())
        max = max if max > num else num
        yield(num)

lst = list(lst_build())

print(max)
print(lst.index(max)+1)
