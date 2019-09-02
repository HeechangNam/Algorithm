#5543 상근날드(https://www.acmicpc.net/problem/5543)
def minimum(n):
    min = 2001
    for i in range(n):
        n = int(input())
        min = min if min < n else n
    return min

print(minimum(3) + minimum(2) - 50)
