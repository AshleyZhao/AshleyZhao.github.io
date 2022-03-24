#!/usr/bin/env python3

import math

infinity = math.inf

'''
Calculate the minimum coins needed to get n, with 1, 4, and 9.

We construct an array A and initialize n = 0 for A to 0. If the value is below 0, then we return infinity.

This program uses dynamic programming paradigm.
'''
def min_coin(n):
    A = [0] * (n+1) # 0 is not counted as one of the values leading up to A[n]
    A[1] = 1
    
    for i in range(2, n+1): # Construct the array
        A[i] = 1 + min(Val(A, i-1), Val(A, i-4), Val(A, i-9))
            
        # print("i: ",i)
        # print("Min Coins: ", A[i])
        
    print("Coins used: ",min_values(n,A))
    return A[n]

def min_values(n, A):
  Values = []
  j = n
  while j > 0:
    temp_coin_value = min_results(A[j-1], A[j-4], A[j-9])
    Values.append(temp_coin_value)
    j -= temp_coin_value
    # print("min_value j: ",j)    
  return Values

def Val(A, i):
    if i < 0:
        return infinity
    else:
        return A[i]
    
def min_results(a, b, c):
    if a <= b and a <= c:
        return 1
    elif b <= a and b <= c:
        return 4
    else:
        return 9
    
print("Final result: ",min_coin(12))
