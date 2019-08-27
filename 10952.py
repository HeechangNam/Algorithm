A,B = 0,0

def inputAB():
    global A,B
    A, B = input().split()
    A = int(A)
    B = int(B)

inputAB()
while A!=0 or B!=0:
    print(A+B)
    inputAB()
