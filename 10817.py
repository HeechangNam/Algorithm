#def list_gen(lst=[]):
#    for i in lst:
#        yield int(i)

input_list = input().split()
#num_list = list(list_gen(input_list))
num_list = [int(i) for i in input_list]
num_list.sort()
print(num_list[1])
