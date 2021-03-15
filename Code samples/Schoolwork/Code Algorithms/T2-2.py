#!/usr/bin/env python3

'''
1) Let us consider finding maximum subsequence sum. The key to a linear-time solution is that we know the greatest sequence will be the sequence with the most positive numbers. If we think about it, this can be done with a temporary variable, which starts at some temporary max sum, then adds the next element. If the sum is greater than the current max sum, it replaces it. If it is not, then it continues. We never have to worry about any other case because as long as the sum remains positive, it will contribute to a greatest sum. 

max_subseq(A, temp=0, final_sum=0)

if A is empty: //Recursion base case
  return final_sum
else:
  temp += A[0]
  if (temp > final_sum):
    final_sum = temp

  remove A[0]
  if temp < 0 // We're further from getting to a great sum
    return max_subseq(A, 0, final_sum) // set temp to 0 again
  else:
    return max_subseq(A, temp, final_sum) // otherwise proceed

2) All the codelines in the function are constant time. The recursion itself will loop through all of the array elements, therefore T(n) = c1 x T(n) time, which is O(n).

3) Implementation below: 

'''

def max_subseq(A, max_tent, max_sum):

  if A == []: # Base case
    return max_sum 

  else:
    max_tent = max_tent + A[0]

    if (max_tent > max_sum): # If temporary sum is greater than current sum, set current sum = temporary sum
      max_sum = max_tent
    
    if max_tent < 0: # If temporary sum goes beneath 0, reset
      return max_subseq(A[1:], 0, max_sum)

    else: # Otherwise continue
      return max_subseq(A[1:], max_tent, max_sum)


'''
===Test cases===
num_list = [10, -20, 3,4,5,-1,-1,12,-3,-1]
print(max_subseq(num_list, 0, 0))

num_list = [1,1,1,-1,2,2,2]
print("final ",max_subseq(num_list, 0, 0))

num_list = [3,4,5,-11,1,2]
print("final ", max_subseq(num_list, 0, 0))
'''