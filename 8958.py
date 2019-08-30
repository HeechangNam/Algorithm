#8958 OX퀴즈
n = int(input())
for i in range(n):
    lst = input()
    total = score = 0
    #print(total,score)
    for l in lst:
        if l == 'O':
            score += 1
            total += score
        else:
            score = 0
    print(total)
