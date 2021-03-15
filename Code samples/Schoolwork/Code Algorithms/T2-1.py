#!/usr/bin/env python3

'''
Single letter

1) Assuming we only have cases of 2 consecutive letters that are unique and one singular letter among them, we just have to compare the letter at index i with letter at i + 1. If they do not match, we return i (since we know i - 1 == i - 2 for sure, i must be the index of unique letter). If they do match, we move on to i + 2. 

Pseudo-code:

find_single(A)
  index = 0
  while (index < A.length):
    if (A[index] equals A[index + 1])
      index = index + 2
    else if (A[index] does not equal A[index + 1])
      return index
  
  return None

2) Although there is a while loop implemented, at worst case we go over a list that has no unique letters, we only go over half of the list because indexes increase at 2. Therefore T(n) = c0 + T(n/2) x c1 + c2 time and is in O(lg n) time.

3) Implementation below:

'''

def find_single(A, A_max):
  index = 0

  if (A_max % 2 == 0): # An even-sized array will never contain an odd number
    return None 

  while (index < A_max):
    if (A_max - index == 1): # The single letter is at the end
      return index
    elif (A[index] == A[index + 1]): 
      index = index + 2 # An odd index will never come up, we decrement loop time by 2
    else:
      return index # The single letter is found
  
  return None # If we do not find the single letter, we return None





'''
===Test cases===

test_string = "ccddabbffgg"
print(test_string)
print(find_single(test_string, len(test_string)))

test_string = "ddccaahhbb"
print(test_string)
print(find_single(test_string,len(test_string)))

test_string = "iihhjjyyc"
print(test_string)
print(find_single(test_string, len(test_string)))

test_string = "hhijjyyc"
print(test_string)
print(find_single(test_string, len(test_string)))
'''






