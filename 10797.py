#10797 10부제(https://www.acmicpc.net/problem/10797)
n = int(input())
lst = [int(i) for i in input().split()]

cnt = 0
for i  in lst:
    if i == n:
        cnt += 1
print(cnt)
