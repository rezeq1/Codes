#Q1
def text_preprocessing(text,stopwords):
    bag_words={}
    filtered=filter(lambda x : x not in stopwords and not x.isnumeric(),
        map( lambda x : x.lower(),text.split()))
    for i in filtered:
        if i not in bag_words:
            bag_words[i]=0
        bag_words[i]+=1
    return bag_words
#stop_list = ('is', 'it', 'a', 'the', 'my', 'and')
#print(text_preprocessing('My cat is 10 and it is a very fat cat', stop_list))

#or :
#def check(s):
#        return s not in stopwords and not s.isnumeric()
#filtered = filter(check, map(lambda x: x.lower(),text.split()))
#Q2
def shmeasy_park(fee): 		
    balance=0
    def charge(amount):
        nonlocal balance
        balance+=amount
        
    def park(time):
        nonlocal balance
        balance-=time*fee
        return 'balance left:', balance
    def dispatch(message,args):
        if message=='charge':
            return charge(args)
        elif message=='park':
            return park(args)
        else:
            return 'unknown message:'+message
    return dispatch
	
##k = shmeasy_park(5)
##k('charge', 100)
##print(k('park', 10)) #balance left: 50.0
##print(k('add', 20)) #unknown message: add


#------------------------------------
#Q3
def make_account():
    balance=0
    def dispatch(message):
        if message=='get':
            return balance
        elif message=='change':
            def changer(delta):
                if delta<0 and balance<-delta:
                    return 'out of funds during change'
                else:
                    nonlocal balance
                    balance+=delta
                    return balance
            return changer
        elif message=='move':
            def mover(acc,delta):
                changer1=dispatch('change')
                changer2=acc('change')
                if delta<0:
                    return 'Negative transaction amount'
                elif dispatch('get')<delta :
                    return 'out of funds during move'
                else:
                    return (changer1(-delta),changer2(delta))
            return mover
    return dispatch

##a1 = make_account()
##print (a1)
##a2 = make_account()
##print (a1('change')(20))
##print (a1('get'))
##print (a1('change')(-25))
##print (a1('move')(a2, 7))
##print (a2('move')(a1, 2))
##print (a1('move')(a2, 30))
##print (a1('move')(a2, -30))
#-----------------
#Q4
#a
make_pairs=lambda el,lst:tuple(map(lambda x : (el,x ),lst))
print(make_pairs(5,(1,2,3)))

# b:  two solutions
c_prod = lambda lst1, lst2: tuple(map(lambda x:make_pairs(x,lst2),lst1))
c_prod = lambda lst1, lst2: tuple(make_pairs(x,lst2) for x in lst1)
print(c_prod((1,2),(3,4)))

#c : two solutions
flat_c_prod=lambda lst1,lst2:reduce(add,c_prod(lst1,lst2) ,())
flat_c_prod = lambda lst1, lst2: reduce(lambda x,y:x+y, c_prod(lst1, lst2), ())
print(flat_c_prod((1,2),(3,4)))

#d
cond_c_prod=lambda p,lst1,lst2:flat_c_prod(tuple(filter(p,lst1)),tuple(filter(p,lst2)))
print(cond_c_prod(lambda x :type(x)==int,(1,2,3.5),(3,'a',4)))

# ------------- #



