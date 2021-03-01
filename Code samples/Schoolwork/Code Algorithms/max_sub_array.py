#!/usr/bin/env python3

print("test")

# Creates a random array
def rand_array():
  import random
  temp_size = random.randint(1,6)
  arr = []

  for i in range(0, temp_size):
    temp_elem = random.randint(-10,9)
    arr.append(temp_elem)
  
  return arr


# Brute-forces through the array
def brute_force(arr, index=0):

  i = index # 'focal' index of the array

  # Debug print
  print("Begin loop")

  # Debug print
  # print("i:"+str(i))

  max_sum = arr[i]

  j = 0

  temp_arr = list(arr)

  temp_sum = 0

  while (j < len(arr)):


    # Should change this to if sum + temp_arr[j] >= max_sum
    
    if (temp_arr[j] + temp_sum > max_sum):
      temp_sum = temp_arr[j] + temp_sum
      max_sum = temp_sum

    
    # Debug print
    
    
    '''
    print("i: "+str(i))
    print("j: "+str(j))
    #print("arr[i]: "+str(arr[i]))
    print("temp_arr: ")
    print(temp_arr)
    #print("slice: ")
    #print(temp_arr[j:(len(arr) - 1)])
    print("max_sum: "+str(max_sum))
    '''
    

    j = j + 1

  if (i+1 >= len(arr)):
    return max_sum
  else:
    temp_sum = brute_force(arr,i+1)
    if (temp_sum > max_sum):
      return temp_sum
    else:
      return max_sum



# Incomplete
def find_max_subarr(arr):

  # Base case
  if len(arr) == 1:
    return arr[0]
  else: 
    mid = len(arr) // 2
    left_sum = find_max_subarr(arr[:mid])
    right_sum = find_max_subarr(arr[mid+1:])
    cross_sum = find_max_subarr(arr[(mid-(mid//2)):(mid+(mid//2))])

    if left_sum >= cross_sum and left_sum >= right_sum:
      return left_sum
    elif right_sum >= cross_sum and right_sum >= left_sum:
      return right_sum
    else:
      return cross_sum
     
    


arr = rand_array()
print(arr)
print(brute_force(arr,0))
print(arr)