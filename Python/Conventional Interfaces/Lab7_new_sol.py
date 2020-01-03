from functools import reduce
from operator import add, mul
import math

# ------------------------------------------------
#                       Q1
# ------------------------------------------------
def accumulate(x, op, nlist):
    for y in nlist:
        x = op(x, y)
    return x
# ------------------------------------------------   
#print(accumulate(0, add, (1, 2, 3, 4, 5)))
# => 15
#print(accumulate(1, lambda x,y:x*y, [1, 2, 3, 4, 5]))
# => 120
#print(accumulate(1, lambda x,y:4*x-y, (1, 2, 3, 4, 5)))
# => 571


# ------------------------------------------------
#                       Q2
# ------------------------------------------------
def mymap(func, nlist):
    x = list(nlist)
    for i in range(len(x)):
        x[i] = func(x[i])
    return x
# ------------------------------------------------
#print(tuple(map(lambda x: x*x, range(1, 5))))
# => (1, 4, 9, 16)
#print(tuple(mymap(lambda x: x*x, range(1, 5))))
# => (1, 4, 9, 16)


# ------------------------------------------------
#                       Q3
# ------------------------------------------------
def iseven(x):
    return x % 2 == 0
# ------------------------------------------------
def issquare(x):
    return int(math.sqrt(x))**2 == x
# ------------------------------------------------
def orfilter(f1,f2):
    def filter_func(x):
        return f1(x) or f2(x)
    return filter_func
# ------------------------------------------------
#print(list(filter(orfilter(iseven, issquare), range(20))))
# => [0, 1, 2, 4, 6, 8, 9, 10, 12, 14, 16, 18]
#print(list(filter(accumulate(lambda x: False, orfilter,(iseven, issquare)), range(20))))
# => [0, 1, 2, 4, 6, 8, 9, 10, 12, 14, 16, 18]
#print(list(filter(mymap(lambda f: orfilter(f, issquare), (iseven,))[0], range(20))))
# => [0, 1, 2, 4, 6, 8, 9, 10, 12, 14, 16, 18]

# ------------------------------------------------
#                       Q4
# ------------------------------------------------
from math import sqrt
from operator import add
from functools import reduce
#alef
def average_passed_grade(grades):
    s=tuple(filter(lambda x: x>=56,
                   map(lambda x : 10*sqrt(x),
                       filter(lambda x: x!=199,
                              grades))))
    return reduce(add,s)/len(s)
print(average_passed_grade([23, 64, 199, 20, 77, 98, 100, 199]))

#bet
def average_passed_grade(grades,f):
    s=tuple(filter(lambda x: x>=56,
                   map(lambda x : min(f(x),100),
                       filter(lambda x: x!=199,
                              grades))))
    return reduce(add,s)/len(s)
print(average_passed_grade([23, 64, 199, 20, 77, 98, 100, 199],lambda x:x+15))
# ------------- #

