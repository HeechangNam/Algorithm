class Tree:
    def __init__(self,age):
        self.live = 1
        self.age = age
    
    def grow(self, nuriment):
        if nuriment < age:
            self.live = 0
        else:
            self.age += 1
    
    def death(self):
        if self.live == 0:
            return age//2
    
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
        
    def fertile(self):
        for i in self.tree:
            self.nuriment += i.death()
    
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
