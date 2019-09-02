#10039 평균점수(https://www.acmicpc.net/problem/10039)
def score():
    for i in range(5):
        sc = int(input())
        if sc < 40:
            yield 40
        else: yield sc
        
lst = score()
sum = 0
for i in lst :
    sum += i
print(sum//5)
