from functools import  reduce
from operator import  add
from random import randrange


'''
Part A Question number 1 
'''
def make_power(x,y):
    '''
    function that make object power and  returns dispatch function
    '''
    def dispatch(index):
        '''
        function that returns an index value of  object power
        '''
        if index==0:
            return  x
        if index==1:
            return  y
    return dispatch
def base(x):
    '''
    returns base of an object
    '''
    return x(0)

def power(x):
    '''
    returns a power of an opject
    '''
    return x(1)

def print_power(x):
        '''
         prints power object
        '''
        if base(x)==0 or base(x)==1:
            print(base(x))
        elif power(x)==0:
            print(1)
        elif power(x)==1:
            print(base(x))
        else:
            print('{0}^{1}'.format(base(x),power(x)))

def calc_power(x):
    '''
    calculate a power object
    '''
    return base(x)**power(x)

def mul_power(x,y):
    '''
    returns the mul bettween two power objects
    '''
    y1 = improve_power(y)
    x1 = improve_power(x)
    if base(x)==base(y):
        return  make_power(base(x),power(x)+power(y))
    elif base(x1)==base(y1):
        return make_power(base(x1), power(x1) + power(y1))
    else:
        return make_power(calc_power(x)*calc_power(y),1)


def div_power(x,y):
    '''
    returns the div bettween two power objects
    '''
    y1 = improve_power(y)
    x1 = improve_power(x)
    if base(x) == base(y):
        return  make_power(base(x),power(x)-power(y))
    elif base(x1) == base(y1):
        return make_power(base(x1), power(x1) - power(y1))
    else:
        return make_power(calc_power(x)/calc_power(y),1)

def improve_power(x):
    '''
    returns the mul bettween two power objects
    '''
    for i in range(2,base(x)+1):
        if ispower(x,i)!=None:
            return make_power(i,ispower(x,i))
    return x


def ispower(x,bas):
    '''
    returns the power of an opject with differnt base
    '''
    sum=0
    i=0
    while sum<calc_power(x):
        sum=bas**i
        i+=1
    if sum==calc_power(x):
        return i-1
    else:
        return  None

############################################################################################
'''
Part A Question number 2 
'''
def make_tree(root,right,left):
    '''
    function that make object tree and  returns dispatch function
    '''
    def dispatch(index):
        '''
        function that return an value of index of  object tree
        '''
        if index==0:
            return root
        elif index==1:
            return right
        elif index==2:
            return left
    return dispatch

def value(tree):
    '''
    returns a value of an tree node
    '''
    return  tree(0)
def left(tree):
   '''
   returns the lift  of an tree node
   '''
   return tree(1)

def right(tree):
   '''
   returns the right of an tree node
   '''
   return tree(2)

def print_tree(tree):
    '''
    print inorder search of a tree
    '''
    if tree!=None:
        print_tree(left(tree))
        print(value(tree),end=" ")
        print_tree(right(tree))

def count_value (tree,x):
    '''
    count how much the values apper in tree
    '''
    if tree==None:
        return 0
    if x==value(tree):
        return 1+count_value (right(tree),x)+count_value (left(tree),x)
    else:
        return count_value(right(tree), x) + count_value(left(tree), x)

def tree_depth(tree):
    '''
    returns a hieght of an tree node
    '''
    if tree == None:
        return -1
    leftDepth = tree_depth(left(tree))
    RightDepth= tree_depth(right(tree))
    if  leftDepth>RightDepth:
        return 1 +  leftDepth
    else:
        return  1+ RightDepth

def tree_BST(tree):
    '''
    returns a true  if  tree is binary search tree
    '''

    if tree== None:
        return True

    if  left(tree)!= None and value(left(tree)) > value(tree):
        return False
    if  right(tree)!= None and value(right(tree))< value(tree):
        return False
    return  tree_BST(left(tree)) and tree_BST(right(tree))


def tree_balanced(tree):
    '''
    returns true if tree is balanced
    '''
    if  tree==None:
        return True

    HighLeft = tree_depth(left(tree))
    HighRight = tree_depth(right(tree))
    abselot=HighRight - HighLeft
    if abselot<0:
        abselot *= -1
    if abselot <= 1:
        if  tree_balanced(left(tree)) and tree_balanced(right(tree)):
            return True
        else:
            return False
    else:
        return False

############################################################################################
'''
Part B Question number 3 
'''

#section A
def get_prices(shop_name,prices,sales):
   '''
   returns the price of products in a shop after assumption
   '''
   return tuple(map(lambda x:(x[0],x[1]*(1-tuple(filter(lambda x:x[0]==shop_name,sales))[0][1])),prices))

#section B
def get_prices_dict(shop_name,prod_dict, sale_dict):
   '''
   returns a dictionary of the products prices in a shop after assumption
   '''
   return dict(map(lambda x:[x,prod_dict[x]*(1-sale_dict[shop_name])],prod_dict))

#section C
def get_prices_by_type(shop_name, prod_dict, sales, types):
   '''
   returns the price of products in a shop after assumption according to types ,returns dictionary
   '''
   return  dict(map(lambda prod:(prod,prod_dict[prod]*(1-sales[shop_name][tuple(filter(lambda type:prod in types[type],types))[0]])),prod_dict))

#section D
def accumulate_prices (shop_name, prod_dict, sales, types,function):
   '''
   triggers an function in price of products in a shop after assumption according to types
   '''
   return reduce(function,get_prices_by_type(shop_name,prod_dict,sales,types).values())


############################################################################################
'''
Part C Question number 4
'''

def coding():
    key= {}
    '''
    function to encoding a string ,using message passing
    '''
    def set_key(_key):
       '''
       set an key to encoding
       '''
       tuple_key = list(_key)
       if _key[0] == 0:
          tuple_key[0] = randrange(-25, 25)

       a = ord('a')
       letters = [chr(i) for i in range(a, a + 26)]
       temp = [chr(i) for i in range(a, a + 26)]
       for i in range(len(letters)):
          if tuple_key[0] > 0:
             if i + tuple_key[0] < len(temp):
                temp[i] = letters[i + tuple_key[0]]
          else:
             if i + tuple_key[0] > -len(temp):
                temp[i] = letters[i + tuple_key[0]]
       key_help1= {}
       if tuple_key[1] == 'yes':
          key_help1['reverse_word'] = True
       else:
          key_help1['reverse_word'] = False
       if tuple_key[2] == 'yes':
          key_help1['reverse_string'] = True
       else:
          key_help1['reverse_string'] = False
       count = 0
       for let in letters:
          key_help1[let] = temp[count]
          count += 1
       return key_help1

    def encoding(line, key_help1):
       '''
       encoding an string according to the key
       '''
       words = line.split()
       temp = []
       word_temp = ''
       if key_help1['reverse_word'] == True:
          words.reverse()
       if key_help1['reverse_word'] == True:
          for i in range(len(words)):
             words[i] = (words[i])[::-1]
       for word in words:
          for letter in word:
             word_temp += key_help1[letter]
          temp.append(word_temp)
          word_temp = ''

       return temp

    def decoding(line):
       '''
       decoding a encoding string according to the key
       '''
       dictlist = []
       for key1, value in key.items():
          if key1 == 'reverse_string' or key1 == 'reverse_word':
             temp = [key1, value]
          else:
             temp = [value, key1]
          dictlist.append(temp)
       return encoding(line, dict(dictlist))

    def dispatch(message,key_tuple=None):
        '''
        dispacth function ,message passing
        '''
        nonlocal key
        if message=='set_key':
            key=set_key(key_tuple)
            print("done")
        elif message=='export_key':
            if len(key)!=0:
                return key
            else:
                return 'key empty'
        elif message=='encoding':
            if len(key)!=0:
                revers=' '.join(encoding(key_tuple,key))
                return revers
            else:
                return 'key empty'
        elif message=='empty_key':
            key={}
            print('done')
        elif message=='import_key':
            key=key_tuple
            print('done')
        elif message=='decoding':
            if len(key)!=0:
                revers2=' '.join(decoding(key_tuple))
                return revers2
            else:
                return 'key empty'

    return dispatch


############################################################################################
'''
Part D Question number 5
'''

def parking(price, regular, priority, vip):
   cars = []
   index_car = 0
   '''
   function to parking system ,using dispatch dictionary
   '''

   def print_list():
      '''
      printin a list of the cars in the parking in order(index)
      '''
      def print_car():
         '''
         printing a car information
         '''
         nonlocal index_car
         print('car:{0} , parking type:{1} , parking time:{2}'.format(cars[index_car][0], cars[index_car][1],                                                              cars[index_car][2]))
         index_car += 1

      def isEnd():
         '''
         check if this car are the last car
         '''
         if index_car < len(cars):
            return False
         return True

      return {'end': isEnd, 'next': print_car}

   def print_parking(type_park):
      '''
      printing the information of cars in a certain type of parking car
      '''
      for i in cars:
         if i[1] == type_park:
            print('car:{0} ,parking time:{1}'.format(i[0], i[2]))

   def next_time(add=1):
      '''
      promotion a time of the cars parking
      '''
      nonlocal cars
      for i in cars:
         i[2] += add

   def start_parking(number_car, type_park):
      '''
      add a car to the parking cars if they are place for it
      '''
      nonlocal cars, vip, regular, priority
      if type_park == 'VIP':
         if vip != 0:
            cars.append(list([number_car, type_park, 0]))
            vip -= 1
         else:
            print("VIP parking is full")
      elif type_park == "Regular":
         if regular != 0:
            cars.append(list([number_car, type_park, 0]))
            regular -= 1
         else:
            print("Regular parking is full")
      elif type_park == "Priority":
         if priority != 0:
            cars.append(list([number_car, type_park, 0]))
            priority -= 1
         else:
            print("Priority parking is full")
      else:
         print("Error the type of parking is not exist")

   def end_parking(number_car):
      '''
      printing the information of car and her payment and remove it from the parking cars
      '''
      flag = 0
      nonlocal cars
      for i in cars:
         if i[0] == number_car:
            flag = 1
            print('car:{0}, parking type:{1}, parking time:{2} '.format(i[0], i[1], i[2]))
            payment = i[2] * price
            if i[1] == "Priority":
               payment *= 2
            elif i[1] == "VIP":
               payment *= 3
            print('payment:{0}'.format(payment))
            cars.remove(i)
      if flag == 0:
         print('car not found')

   return {'print_list': print_list, 'print_parking': print_parking, 'next_time': next_time,
           'start_parking': start_parking, 'end_parking': end_parking}










