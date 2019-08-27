year = int(input())
if year%4 != 0:
    ans = 0
else:
    if(year%100 == 0):
        ans = 0
        if(year%400 == 0):
            ans = 1
    else:
        ans = 1
print(ans)
