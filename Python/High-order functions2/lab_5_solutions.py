#Q1
print ("start of lambda functions")
var=lambda x: x+2
print (var(4)) #6
var = lambda x: x**2+3*x-2
print (var(3))#16
var=lambda x,y: (x+y)/(x-y)
print (var(8,4))#3
print ("end of lambda functions")
print()

#Q2
def summ(a,b,f,nextt):
    total=0
    while a<b:
        total+=f(a)
        a=nextt(a)
    return total

def integral1 (a,b,f):
    dx=(b-a)/1000
    def add_dx(x):
        return x+dx
    return summ(a,b,f,add_dx)*dx

def integral2(a,b,f):
    dx=(b-a)/1000
    return summ(a,b,f,lambda x: x+dx)*dx

def integral3(a,b,f):
    total=0
    dx=(b-a)/100
    for k in range(100):
        total+=f(a+k*dx)*dx
    return total

import math
print(integral1(0,1,lambda x: x**2))
print(integral2(0,1,lambda x: x**2))
print(integral3(0,1,lambda x: x**2))

print(integral1(0,math.pi,math.sin))
print(integral2(0,math.pi,math.sin))
print(integral3(0,math.pi,math.sin))
#Q3
def derivat1(f):
    eps=0.0001
    def calc(x):
        return (f(x+eps)-f(x))/eps
    return calc
def derivat2(f):
    eps=0.0001
    return lambda x: (f(x+eps)-f(x))/eps
#Q4
def derivat_twice(f):
    return derivat1(derivat1(f))
print("derivat",derivat1 (lambda x: x**2) (3))   
print("derivat",derivat2 (lambda x: x**2) (3))
print("derivat",derivat1  (math.sin) (math.pi) )
print(derivat_twice(lambda x : x**2)(13))
#Q5
def f(x,y):
    return x*y**2-2*x*y

def partial_derivat_x(pf):
    dx=0.001
    return lambda x,y: (pf(x+dx,y)-pf(x,y))/dx
    
def partial_derivat_y(pf):
    dy=0.001
    return lambda x,y: (pf(x,y+dy)-pf(x,y))/dy

print ("partial_derivat_x ", partial_derivat_x ( f )(2,3))
print ("partial_derivat_y ", partial_derivat_y(  f )(2,3))
print()

#Q6
def like_fib(f):
    return lambda n: f(n-1)+f(n-2)
def f(n):
    return 5-n
def g():
    return like_fib(f)
print("Q6",g()(3))
#Q7
def smooth(f):
    return lambda x:(f(x-1)+f(x)+f(x+1))/3
def gg():
    return smooth(f)
print("Q7",gg()(2))##smooth(2)= (f(1)+f(2)+f(3))/3 = (4+3+2)/3 = 9/3 = 3








   
