#!/usr/bin/env python3

'''
Given a rod of length n inches and a table of prices for each length, determine the maximum revenue
'''

p = [0,1,5,8,10,13,17,18,22,25,30]

# Receives an array of prices and initial length of rod
# Returns maximum revenue
def min_rod(p, n):

  r = [0]
  s = [0]
  #r.append(1)
  #s.append(1)

  for j in range(1,n+1):
    s.append(0)
    current_max = -1

    for i in range(1, j+1):
      if current_max < p[i] + r[j-i]:
        current_max = p[i] + r[j-i]
        s[j] = i

    r.append(current_max)

  return r[n], s[n]
  

for i in range(0,len(p)):
  print(min_rod(p, i))