n = int(input())
m = int(input())
point = [0 for i in range(0,n)]
#print(point)
target = [int(i)-1 for i in input().split()]
#print(a)
for i_target in range(0,m):
    vote = [int(i)-1 for i in input().split()]
    #print(vote)
    for v_point in range(0,n):
        if target[i_target] == vote[v_point]:
            point[v_point]+=1
        else:
            point[target[i_target]] += 1
    #print(point)
for pt in point:
    print(pt)
