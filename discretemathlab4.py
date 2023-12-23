import sys
sys.setrecursionlimit(100000)

def factorial(n):
    x = 1
    if n < 0:
        print("There's no factorial for negative numbers")
    elif n == 0:
        return 1
    else:
        for i in range(1, n + 1):
            x = x * i
        return x
        
# print ("factorial(5):", factorial(5))

def fib(n):
    if n < 0:
        print("Has to be a positive number.")
    elif n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fib(n-1) + fib(n-2)
        
# print ("fib(7):", fib(7))

def equal(A, B):
    if A == B:
        return True
    else:
        return False
    
# print ("equal('ALICE', 'BOB):", equal('ALICE', 'BOB'))
# print ("equal('ALICE', 'ALICE'):", equal('ALICE', 'ALICE'))

def addup(list):
    final_number = 0
    for i in list:
        final_number = final_number + i
    return final_number

# print ("addup([1,2,3,4,5]):", addup([1,2,3,4,5]))
# print ("addup(range(101)):", addup(range(101)))

def reverse(A):
    new_string = ""
    for i in A:
        new_string = i + new_string
    return new_string
        
        
# print ("reverse('hello'):", reverse('hello'))
