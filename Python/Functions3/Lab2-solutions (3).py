from math import sqrt

# ------------------------------------------------
#                       Q1
# ------------------------------------------------
def tri_surf(a,b):
    if a<0 :
        a=abs(a)
    if b<0:
        b=abs(b)
    return (a*b)/2
#print ('Area of the triangle: ',tri_surf(int(input('enter a: ')),int(input('enter b: '))),'\n\n')

# ------------------------------------------------
#                       Q2
# ------------------------------------------------
def absolute(x):
    if x<0:
        return -x
    return x
#print ('The result is: '+ str(absolute(float(input('enter number: ')))))

# ------------------------------------------------
#                       Q3
# ------------------------------------------------
def Multiply2Larges(a,b,c):
    if a<=b and a<=c:
        return b*c
    elif b<=a and b<=c:
        return a*c
    else:
        return b*a

#print (Multiply2Larges(2,3,4))

# ------------------------------------------------
#                       Q3v2
# ------------------------------------------------
def Multiply2Largesv2(a,b,c):
    if a>b:
        temp=a
        a,b=b,temp
    if b>c:
        temp = b
        b,c = c,temp
    if a>b:
        temp=a
        a,b=b,temp
    return b*c    
#print (Multiply2Largesv2(3,2,4))

# ------------------------------------------------
#                       Q4.1
# ------------------------------------------------
'''
def average(x,y):
    return (x+y)/2
def square(x):
    return x**2
def abss(x):
    if x<0:
        return -x
    return x
def good_enough(y,x):
    return abss(square(y)-x)<0.001
def improve(y,x):
    return average(y,x/y) 
def sqrt_iter(y,x):
    while not good_enough(y,x):
        y=improve(y,x)
    return y
def mySqrt(x):
    return sqrt_iter(1,x)

print('mySqrt')
print(mySqrt(2))
print(mySqrt(25))
print('sqrt')
print(sqrt(2))
print(sqrt(25))
'''

# ------------------------------------------------
#                       Q4.2
# ------------------------------------------------
'''
def mySqrt(x):
    def average(x,y):
        return (x+y)/2
    def square(x):
        return x**2
    def abss(x):
        if x<0:
            return -x
        return x
    def good_enough(y,x):
        return abss(square(y)-x)<0.001
    def improve(y,x):
        return average(y,x/y) 
    def sqrt_iter(y,x):
        while not good_enough(y,x):
            y=improve(y,x)
        return y
    return sqrt_iter(1,x)
print('mySqrt')
print(mySqrt(2))
print(mySqrt(25))
print('sqrt')
print(sqrt(2))
print(sqrt(25))
'''
# ------------------------------------------------
#                       Q4.3
# ------------------------------------------------
'''
def mySqrt(x):
    def average(y,x):
        return (x+y)/2
    def square(x):
        return x**2
    def abss(x):
        if x<0:
            return -x
        else:
            return x
    def good_enough(y):
        return abss(square(y)-x)<0.001
    def improve(y):
        return average(y,x/y) 
    def sqrt_iter(y):
        while not good_enough(y):
            y=improve(y)
        return y
    return sqrt_iter(1)
print('mySqrt')
print(mySqrt(2))
print(mySqrt(25))
print('sqrt')
print(sqrt(2))
print(sqrt(25))
'''
# ------------------------------------------------
#                       Q5
# ------------------------------------------------

def average_passed_grade():
    def checkGrade(x):
        return  100>=x>=56
    def checkPresence(x):
        return x!=199
    def gradeAfterFactor(x):
        return 10*sqrt(x)
    avg,count=0,0
    flag=True
    while flag:
        mark=int(input('Enter Mark: '))
        if mark==-1:
            flag=False
        else:
            if checkPresence(mark) and checkGrade(gradeAfterFactor(mark)):
                avg+=gradeAfterFactor(mark)
                count+=1
    if count==0:
        return 0
    return avg/count
# ------------------------------------------------
#print('{0:.1f}'.format(average_passed_grade()))

