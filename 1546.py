#1546 평균
n = int(input())
lst = [int(i) for i in input().split()]
sum = max = 0
for i in lst:
    sum += i
    max = max if max > i else i
print(sum/n*100/max)
