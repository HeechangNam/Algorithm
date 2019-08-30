#2577 숫자의 개수
a = int(input())
b = int(input())
c = int(input())
num = a*b*c
lst = []
for i in range(10):
    lst.append(0)
#print(lst)
for i in str(num):
    lst[int(i)] += 1
for i in lst:
    print(i)
