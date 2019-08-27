HM = input().split()
HM = [int(i) for i in HM]
if HM[1] >= 45:
    print(HM[0],HM[1]-45)
else:
    if(HM[0] == 0):
        print(23,HM[1]+60-45)
    else:
        print(HM[0]-1,HM[1]+60-45)
