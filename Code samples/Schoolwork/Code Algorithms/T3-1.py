#!/usr/bin/env python3

Train = [(830, 920), (700, 840), (930, 1100)]

print(Train)

'''
This is similar to the activites selection. 

Sort trains by finish time

For each train:
  If its starting time is earlier than the previous's finish time
    We will need one more platform
  Else:
    Decrement the platforms needed 
'''


def platform_assignment(Train):

  platforms = []
  Train.sort(key=lambda x: x[1]) # Sort by finish time

  for i in range(0,len(Train)):

    if(i == 0):
      platforms = [0]
      cur_p = 0

    elif (Train[i][0] < Train[i-1][1]): # If starting time is earlier than previous's finish time
      cur_p += 1
      platforms.append(cur_p)
    else: # Otherwise
      if cur_p != 0:
        cur_p -= 1
      platforms.append(cur_p)
    
  return platforms 


print(platform_assignment(Train))