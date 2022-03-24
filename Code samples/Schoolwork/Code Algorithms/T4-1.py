#!/usr/bin/env python3

'''
The function island_hopping takes an array of island costs i and returns the minimum cost of hopping to island n, where n = len(i) - 1 (for example, going to island 0 would be 1 - 1).

To solve this with dynamic programming, we create an array m (minimum cost) that builds up to the minimum cost of hopping from 0..n. We start with the base case of I0. We have no choice here so m[0] = i0. We can only take 1 step to the next island, so m[1] = i0 + i1. 

Now when we get to I2, we can either go from i0 or i1. So the cost will either be m0 + c2 or m1 + c2, which is m(i-2) or m(i-1), where i is in range of (2,n) and i = 2. Thus we have found the recurrence relationship to find the optimal cost. To find the hopping path, we simply need to trace back.

====================
Psuedocode
====================

func island_hopping(i_cost)
  n = length of i_cost

  // Base cases
  m[0] = i_cost[0]
  m[1] = i_cost[1]

  // We construct the minimum cost table
  i from 2..n:
    m[i] = minimum of m[i-2]+i_cost[i] or m[i]+i_cost[i]

  // To trace back, we start from the end of the dynamic array pick the optimal path to reach the first island, tracing the path as we go:
  j = n
  while j > 0:
    temp_optimal path = if m[i-1] < m[i-2] then i-1 else i-2
    append temp_optimal_path to o
    j -= temp_coin_value  
  
  return m[n-1], o

====================
Complexity
====================
As we can see above, the two functions used are both in O(n). O(n+n) still belongs to O(n). Therefore the complexity is O(n).
'''

def island_hopping(i):

  i.append(0) # Add a dummy cost to the last island

  n = len(i)
  m = [0] * (n) # stores minimum cost
  o = [] # stores optimal steps

  # Base cases
  m[0] = i[0]
  m[1] = i[1] + i[0]

  # Find the minimum cost of island j
  for j in range(2,n):
    m[j] = min(m[j-2]+i[j],m[j-1]+i[j])

  # Traceback
  j = n-1
  while j > 0:
    if m[j] == m[j-2] + i[j]:
      o.append(j-2)
      j -= 2
    else:
      o.append(j-1)
      j -= 1

  # While reverse is linear, again this just adds to O(n), so time complexity is still O(n)
  o.reverse()
  o.append(n-1)

  return m[n-1],o


print(island_hopping([2,15,32,3]))
print(island_hopping([15, 3, 11, 36]))
print(island_hopping([10, 10, 40, 33, 15, 1]))
print(island_hopping([15, 3, 11, 36, 2, 18]))
  