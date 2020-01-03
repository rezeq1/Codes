
def Younger():
    '''
    The function gets information from the user about two peoples and prints the younger from the two peoples.
    '''
    name1=input("Enter a name of the first person:\n")
    day1=int(input("Enter a birthday of {0} :\nDay:".format(name1)))
    month1=int(input("Month:"))
    year1=int(input("Year:"))
    
    name2=input("Enter a name of the seconde person:\n")
    day2=int(input("Enter a birthday of {0} :\nDay:".format(name1)))
    month2=int(input("Month:"))
    year2=int(input("Year:"))
    
    def CountOld(day,month,year):
        '''
        the function gets a day,month,year and calculate the old on days since year 0.
        Constraints:the variables are integers and positive
        '''
        return day+month*30+year*365
    
    
    if CountOld(day1,month1,year1)<CountOld(day2,month2,year2):
        print("{0} is younger.\n".format(name2))
    elif CountOld(day1,month1,year1)>CountOld(day2,month2,year2):
        print("{0} is younger.\n".format(name1))
    else:
        print("{0} and {1} are same age\n".format(name1,name2))


def ReverseNumber(number):
    '''
    The function gets an variable called number,the function returns the reverse of the number .
    Constraints : that the variable number should be integer or long.
    '''
    def CountDigits(number):
        '''
        The function gets an variable called number and returns how much digits the number contain.
        Constraints : that the variable number should be integer or long.
        '''
        counter=0
        while not(number==0):
            counter=counter+1
            number=number//10
        return counter
    NewNumber=0
    counter=CountDigits(number)
    while number!=0:
        digit=number%10
        number=number//10
        counter=counter-1
        NewNumber=NewNumber+digit*(10**counter)
    return NewNumber




def SortedDigits(number):
    '''
    The function gets an variable called number and checks if the number is sorted in increase order from the lift digit to right one, if  yes the function returns true else returns false  .
     Constraints : that the variable number should be integer or long.
    '''
    def CountDigits(number):
        '''
        The function gets an variable called number and returns how much digits the number contain.
        Constraints: that the variable number should be integer or long.
        '''
        counter=0
        while not(number==0):
            counter=counter+1
            number=number//10
        return counter
    counter=CountDigits(number)-1
    digit1=number//(10**counter)
    number=number%(10**counter)
    counter=counter-1
    while number!=0:
        digit2=number//(10**counter)
        number=number%(10**counter)
        counter=counter-1
        if digit1>digit2:
            return False
        digit1=digit2
    return True

    
def Test():
    '''
    The function prints the numbers that the sum of the digits's factorial is equal to the number factorial
    '''
    def Atsert(number):
        '''
        The function gets an variable called number and returns the factorial of the number .
        Constraints : that the variable number should be integer or long.
        '''
        if number==0 or number==1:
            return 1
        else:
            NewNumber=1
            for i in range(number):
                NewNumber=NewNumber*number
                number=number-1
        return NewNumber
    i=0
    while i<100000:
        i=i+1
        help=i
        NewNumber=0
        while help!=0:
            digit=help%10
            help=help//10
            NewNumber=NewNumber+Atsert(digit)
        if i==NewNumber:
            print("{0}".format(NewNumber))
                


def PrintFigure(size):
    '''
    The function gets an variable called size,and prints a square with width size and prints the two slants
    Constraints: that the variable size should be integer and positive and odd.
    '''
    if size%2==0 or size<=0:
        print("Error because size is illigal")
    else:
        i=0
        while i<size//2:
            for y in range(i):
                print(" ",end="")
            print('{0:<{1}}'.format('\\',size//2-i),end="")
            print("|",end="")
            print('{0:>{1}}'.format('/',size//2-i),end="")
            print()
            i=i+1
        for n in range(size):
            if n==(size//2):
                print("*",end="")
            else:
                print("-",end="")
        print()
        i=0
        while i<size//2:
            for f in range(size//2-1-i):
                print(" ",end="")
            print("/",end="")
            for h in range(i):
                print(" ",end="")
            print("|",end="")
            for b in range(i):
                print(" ",end="")
            print('{0:<{1}}'.format('\\',size//2-i))
            
            i=i+1

def RecPrint(begin,end,skip):
    '''
    A recursion function that prints the numbers between begin and end with steps skip.
    Constraints: the variables begin,end and skip are integers
    examples:
    >>>RecPrint(83,100,5)
    83 88 93 98
    '''
    if begin>end:
        return
    else:
        print(begin,end=" ")
        RecPrint(begin+skip, end, skip)


def Repeat(digit,lenght):
    '''
    A recursion function that returns a new number that contain digit lenght times.
    Constraints: the variables digit and leght are integers . the variale digit should be between 0-9
    examples:
    >>>print(Repeat(5,4))
    5555
    '''
    if digit==0 or lenght==0:
        return 0
    if lenght==1:
        return digit
    elif lenght>1:
        return digit*(10**(lenght-1))+Repeat(digit, lenght-1)


