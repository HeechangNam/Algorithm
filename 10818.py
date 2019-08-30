#10818 최소,최대
N = int(input())
lst = [int(i) for i in input().split()]
lst.sort()
print(lst[0],lst[-1])
