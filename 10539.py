N = int(input())
B = map(int,input().split())
A = []
sum = 0
for i in B:
    if len(A)==0:
        A.append(i)
        sum = i
    else:
        A.append(i*(len(A)+1)-sum)
        sum += A[-1]
    #print(i,sum,A[-1])
#print(A)
for i in A:
    print(i, end=" ")
