# ------------------------------------------------
# List
# ------------------------------------------------
#a=[1,2,3,4,5,6]
#a[0]               # => 1
#len(a)             # => 6
#a[2:4]             # => [3, 4]
#a[1:]              # => [2, 3, 4, 5, 6]
#a[:3]              # => [1, 2, 3]
#a[:-1]             # => [1, 2, 3, 4, 5]
#a[:-2]             # => [1, 2, 3, 4]
#b=[6,5,4,3,2,1]    
#a+b                # => [1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1]
#a[0]+b[-1]         # => 2
#[a[0]]+[b[-1]]     # => [1, 1]

# ------------------------------------------------
# Linked List
# ------------------------------------------------
class Node(object):
    def __init__(self,data=0):
        self.value = data
        self.next = None
    def insert(self,data):
        temp = self
        while temp.next is not None:
            temp = temp.next
        temp.next = Node(data)                
    def printList(self):
        temp = self
        while temp is not None:
            print( temp.value, end=', ')
            temp = temp.next
        print()

# ------------------------------------------------
head = Node(1)
head.insert(2)
head.insert(3)
head.insert(4)
head.insert(5)
head.insert(6)
#head.printList()    # => 1, 2, 3, 4, 5, 6,

# ------------------------------------------------
# Memoization
# ------------------------------------------------
# memoized: fib is executed 40 times, 
# unmemoized: 102,334,155 times
# ------------------------------------------------
def fib(n):
    if n == 1:
        return 0
    if n == 2:
        return 1
    return fib(n-2) + fib(n-1)
# ------------------------------------------------
# fib(10)   # => 34

# ------------------------------------------------
def memo(f):
    '''Return a memoized version of single-argument function f.'''
    cache = {}
    def memoized(n):
#        print('n-',n)
        if n not in cache:
            cache[n] = f(n)
#        print(cache)
        return cache[n]
    return memoized
# ------------------------------------------------
#fib(40)        # =>   63245986
#fib = memo(fib)
#fib(40)        # =>   63245986


# ------------------------------------------------
def fread_print(fname):
    out=open(fname,"r")
    text=tuple((out.read()).split(' '))
    out.close()      
    i=1
    for s in text:
        print(i,"-",s)
        i=i+1
#fread_print('1.txt')
