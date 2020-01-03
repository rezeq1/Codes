
#////////////////////////////////Question number 4
def Make_iterator(fn):
    i=-1
    def func():
        nonlocal i
        i+=1
        return fn(i)
    return func

#////////////////////////////////Question number 5
def listFilter(list, f) :
    newList=[]
    for i in list:
        if f(i)==True:
            newList.append(i)
    return  newList

def isPrime(number):
    if number==1:
        return False
    if number==2:
        return True
    else:
        for i in range(2,number):
            if(number % i==0):
                return False
        return True

def isFib(number):
    num1,num2=0,1
    while num1<number:
        num1,num2=num2,num1+num2
        if num1==number and number!=0:
            return True
    return False


def listFilterMulti(list,fList):

    newList=[]
    def CheckNumber(num):
        for func in fList:
            if not(func(num)):
                return False
        return True
    for number in list:
        if CheckNumber(number)==True:
            newList.append(number)
    return newList

#////////////////////////////////Question number 6
def Fixe_point(f,number):

    guss=number
    def improve():
        return f(number)

    def abslot(num):
        if num<0:
            return -num
        return num

    def isGood():
        ebselon=0.0000000000000001
        if abslot(number-improve())<=ebselon:
            return True
        return  False
    def Update():
        nonlocal number
        number=improve()

    while not(isGood()):
        Update()
        if(improve()>number):
            return
    return number




