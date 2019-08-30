#4344 평균은 넘겠지
c = int(input())
for i in range(c):
    lst = [int(i) for i in input().split()]
    sum = 0
    for j in range(1,lst[0]+1):
        sum += lst[j]
    avg = sum / lst[0]
    #print(avg)
    cnt = 0
    for j in range(1,lst[0]+1):
        if lst[j] > avg:
            cnt += 1
    ans = cnt / lst[0] * 100
    print("%.3f%%"%ans)
