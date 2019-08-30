#3052 나머지
def lst_build():
    for i in range(10):
        num = int(input())
        yield(num%42)

lst = set(lst_build())
print(len(lst))
