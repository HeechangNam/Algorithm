class Tree:
    '''나무 객체
    live - 1이면 살고 0이면 죽은 것
    age - 나이'''
    
    def __init__(self,age):
        self.live = 1
        self.age = age
    
    def grow(self, nuriment):
        if nuriment < age:
            self.live = 0
            return nuriment
        else:
            self.age += 1
            return nuriment-age
    
    def death(self):
        if self.live == 0:
            return age//2
        else:
            return 0
    
    def seedable(self):
        if self.age%5 == 0:
            return True
        else:
            return False
        
class Land:
    def __init__(self,nuriment):
        self.nuriment = nuriment
        self.tree = []
    
    def plant(self, age):
        self.tree.append(Tree(age))
        
    def tree_sort(self):
        self.tree.sort()
    
    def add_nuriment(nuriment):
        self.nuriment += nuriment
        
n,m,k = map(int,input().split())
a = [[int(i) for i in input().split()] for i in range(n)]
lands = [[Land(5) for j in range(n)] for i in range(n)]

#print(type(a)) -> <class 'list'>
#print(type(a[0])) -> <class 'list'>
#print(type(a[0][0])) -> <class 'int'>
#print(a[0][0]) -> Okay!

#print(type(lands)) -> <class 'list'>
#print(type(lands[0])) -> <class 'list'>
#print(type(lands[0][0])) -> <class '__main__.Land'>

for i in range(m):
    x,y,age = map(int,input().split())
    lands[x-1][y-1].plant(age)
    
for year in range(k):
    
    #봄
    for i in range(n):
        for j in range(n):
            lands[i][j].tree_sort()
            for tree in lands[i][j].tree:
                lands[i][j].nuriment = tree.grow(lands[i][j].nuriment)
    
    #for land in lands:
    #    land.tree_sort()
    #    for tree in land:
    #        land.nuriment = tree.grow(land.nuriment)
    #3중포문을 2중으로 바꿀 수 있지 않을까 싶었으나
    #land가 Land객체 type이 아닌 list type으로 잡혀서 의미 없었음
                
    #여름
    for i in range(n):
        for j in range(n):
            for tree in lands[i][j].tree:
                lands[i][j].nuriment += tree.death()
    
    #for land in lands:
    #    for tree in land:
    #        land.nuriment += tree.death()
    
    #가을
    for i in range(n):
        for j in range(n):
            for tree in lands[i][j].tree:
                if tree.seedable():
                    
