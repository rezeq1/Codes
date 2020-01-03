# ------------------------------------------------
#               Unordered Types - Dictionary
# ------------------------------------------------
'''
s = { 'x' : 2, 'y' : [1,2], (3,4) : 5}
s[(3,4)]            # => 5
s['x'] = s['y']
s                   # => {'y': [1, 2], 'x': [1, 2], (3, 4): 5}
s['x'][0] = 7
s                   # => {'y': [7, 2], 'x': [7, 2], (3, 4): 5}
len(s)              # => 3
'x' in s            # => True

# ------------------------------------------------
# Dispatch function
# ------------------------------------------------
def make_nums( x, y):
    count = 0
    def dispatch(op):
        nonlocal count
        val = 0
        def func1(var):
            nonlocal x, y
            if var=='x':
                x += val
                return x
            elif var=='y':
                y += val
                return y
            else:
                return 'Error'
        if op=='view':
            return (x,y,count)
        elif op=='add':
            count+=1
            return x+y
        elif op=='sub':
            count+=1
            return x-y
        elif op == 'inc':
            val = 1
            return func1
        elif op == 'dec':
            val = -1
            return func1
        else:
            return 'Incorrect parameter'
    return dispatch
# ------------------------------------------------
n1=make_nums(31,4)
print(n1('view'))     # => (31, 4, 0)
print(n1('add') )     # => 35
print(n1('view') )    # => (31, 4, 1)
print(n1('mul') )     # => 'Incorrect parameter'
print(n1('inc')('y')) # => 5
print(n1('dec')('x')) # => 30
print(n1('sub'))      # => 25
print(n1('view') )    # => (30, 5, 2)
