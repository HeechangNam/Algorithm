import sys
n = int(sys.stdin.readline())
#n = sys.stdin.readline()
#print(n)
for t in range(0,n):
    numbers = [int(i) for i in sys.stdin.readline().split()]
    print(numbers[0]+numbers[1])
