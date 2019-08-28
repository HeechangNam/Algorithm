n,x = map(int,input().split())
numbers = [int(i) for i in input().split()]
for number in numbers:
    if number < x:
        print(number,end=" ")
