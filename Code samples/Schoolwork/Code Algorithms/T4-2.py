#!/usr/bin/env python3

'''
We already have a n x n matrix of the ghosts in pacman's paths. We can simply create another n x n matrix that stores, at each location, the maximum paths to reach that particular point. 

For our base cases, we know at the edges, pacman can only move right and down. thus if there is a ghost on the edge, pacman will not be able to move to cherries at all if it's on the edge behind that ghost. Thus for our edge cases we will fill with 1 as long as there is no ghost, and once we hit a ghost we will propulgate with 0's immediately.

For the rest of the table, to check if a point i > 0 and j > 0 is accessible, we first check if there's a ghost on the coordinate. If there is the accessible path to reach it is automatically 0. Otherwise, we know if we are to land on the coordinate, pacman will come either from the top or the left. Then we just have to check the minimum paths to reach its left coordiante and top coordinate and add them together.

====================
Pseudocode
====================

func pacman(ghost_matrix)
  paths is a n x n table

  // Base cases
  // Note: i is y coordinate and j is x coordinate
  paths[0][0] = 1
  paths[0][j] = 1 if ghost_matrix[0][j] = 0, else 0 until j caps at n - 1
  paths[i][0] = 1 if ghost_matrix[i][0] = 0, else 0 until i caps at n - 1

  // Create the n x n table
  i from 1..n-1
    j from 1..n-1
      // If there's a ghost on this coordinate
      if ghost[i][j] is 1:
        paths[i][j] = 0
      // Otherwise we come from either top or left
      else:
        paths[i][j] = (paths[i][j-1] + paths[i-1][j])

====================
Complexity
====================

We can see that we go through every coordinate on an i x j table, so the complexity is O(n x n) = O(n^2).

Some codes such as initializing the dynamic table and getting the edge cases are O(n^2) + O(n) + O(n). Adding that to our worst case the complexity becomes O(n^2) + O(n) + O(n) + O(n^2) which is still O(n^2)
'''

def pacman(g_m):

  n = len(g_m)

  # Initiate the paths matrix
  # This is O(n^2) but is done once
  paths = []
  for i in range(0,n):
    temp_row = []
    for j in range(0,n):
      temp_row.append(0)
    paths.append(temp_row)

  # Propulgate base (edge) cases
  # All O(n) code
  edge_ghost = False

  for i in range(0,n):

    if g_m[i][0] == 1: # There is a ghost on current coordinate:
      edge_ghost = True

    if edge_ghost == False: # Checks if a ghost has been found 
      paths[i][0] = 1
    else:
      paths[i][0] = 0

  edge_ghost = False

  for j in range(0,n):

    if g_m[0][j] == 1: # There is a ghost on current coordinate:
      edge_ghost = True

    if edge_ghost == False: # Checks if a ghost has been found 
      paths[0][j] = 1
    else:
      paths[0][j] = 0
  
  # For rest of the table, we check if a ghost is on the coordinate
  # If so we set the paths to that coordinate to 0
  # Otherwise we combine the max paths from its left and top coordinates
  for i in range(1,n):
    for j in range(1,n):
      if g_m[i][j] == 1:
        paths[i][j] = 0
      else:
        paths[i][j] = (paths[i][j-1] + paths[i-1][j])

  return paths[n-1][n-1]

# print("temp")
#g_m = [0,0,0],[0,0,0],[0,0,0]
#print(pacman(g_m))
g_m = [0,1],[0,0]
print(pacman(g_m))
g_m = [0,0,0,1], [0,1,0,0], [0,0,0,0], [0,0,0,0]
print(pacman(g_m))