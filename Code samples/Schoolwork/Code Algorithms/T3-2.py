#!/usr/bin/env python3

lamp = [2, 2, 1, 1, 1, 3]

'''
We always try to avoid turning on the current lamp by looking at the right lampost, if it will cover up all the area that is dark so far on its left. If it does we move 1 to the right and stick with the current lampost (we are safe) and increment area of darkness by 1 also. If the next right lamp does not cover up the accumulated darkness, then we turn on the current lamp. 

The pseudocode is:

Initialize darkness to 0

For each lamp:
  
  If there is one lamp left, we turn it on if it can cover the darkness. If not, we declare no solution.

  Else:
    If right lamp's radius covers darkness so far
      Move to the right lamp
      Increment darkness
    Else
      If current lamp and right lamp cannot cover darkness
        No solution
      Else
        We turn on the current lamp and move to the lampost that is beyond its light's radius to the right


We run through all the lamps once and therefore this is in O(n).
'''

def min_lamp(lamp):

  darkness = 0 # length of darkness 
  n = len(lamp) - 1 # indexes of the lamps
  cur_lamp = 0 # the current lamppost that we iterate through
  indexes = [] # Initializing indexes of lamps to turn on


  while cur_lamp <= n:

    # We've reached the last lamppost and there is still darkness. We turn on the last light and finish, or if the last light is not working, we return no solution.
    if cur_lamp == n:
      if darkness > 0 and lamp[cur_lamp] >= darkness:
        indexes.append(cur_lamp)

      elif darkness > 0 and lamp[cur_lamp] < darkness:
      
        # No solution
        indexes = None
      
      else:
        return indexes

      #print("This is end. ", indexes)
      return indexes

    else:
      # If the next lamp has a radius greater than darkness, we jump to the next lampost
      if lamp[cur_lamp+1]*2 >= darkness+1:
        print("Moving one")
        cur_lamp += 1
        darkness += 1
        #print("darkness: ", darkness)

      # Else, if we find the accummulated darkness is too great
      elif lamp[cur_lamp] + lamp[cur_lamp+1]*2 < darkness+1:
        print("Caught too much darkness")
        indexes = None
        # No solution
        return indexes

      # Otherwise, we turn on the current lamp.
      else:
        print("Turning on lamp")
        indexes.append(cur_lamp)
        if cur_lamp + lamp[cur_lamp] > n:
          return indexes
        else:
          cur_lamp += lamp[cur_lamp]
        
        darkness = 0

  return None # We should never reach this code


print(lamp)
print(min_lamp(lamp))