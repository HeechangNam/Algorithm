n = int(input())
x = 0
for numbers in range(0,n):
    p = input()
    #x += int(p[:-2])**int(p[-1])
    x += int(p[:-1])**int(p[-1])
    #print(p[:-1])
    #print(x)
print(x)
