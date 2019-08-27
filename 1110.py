N = input()
new_n = N
added_n = 0
len_cycle = 0

def n_add():
    global new_n, added_n
    if len(new_n)==1:
        added_n = new_n
    else:
        added_n = str(int(new_n[0])+int(new_n[1]))
    #print(new_n, added_n)
    #print(type(new_n))
    #print(type(added_n))
    #print(len(new_n))
    #print(new_n[0], new_n[1])

def n_extend():
    global new_n, added_n
    if new_n[-1] == '0':
        new_n = added_n[-1]
    else:
        new_n = new_n[-1] + added_n[-1]

while len_cycle==0 or N != new_n:
    #if(len_cycle != 0 and N == new_n):
        #break
    n_add()
    n_extend()
    len_cycle += 1
    #print(new_n, added_n)
print(len_cycle)
