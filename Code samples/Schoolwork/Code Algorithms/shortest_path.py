#!/usr/bin/env python3


horizontal = [[1,5,8],[7,3,4],[2,1,5],[6,9,3]]
vertical = [[6,4,3],[5,2,2],[2,8,1],[5,4,7]]

## This is a recursive method
def pacman_rec(x, y, nx, ny):
  cost = 0

  if x != nx or y != ny:

    # We've hit the edge for x
    if x >= 3 or x == nx:
      #print("Hit edge for x. Current position: ",x," ",y)
      # We can only go down
      down = vertical[x][y]
      #print("Going down: ",down)
      cost = cost + down + pacman_rec(x,y+1,nx,ny)

    elif y >= 3 or y == ny:
      #print("Hit edge for y. Current position: ",x," ",y)
      # We can only go right
      right = horizontal[y][x]
      #print("Going right: ",right)
      cost = cost + (right + pacman_rec(x+1,y,nx,ny))

    else:

      #print("Moving somewhere: ",x," ",y)
      right = horizontal[y][x]
      down = vertical[x][y]

      cost = cost + min(right + pacman_rec(x+1,y,nx,ny), down + pacman_rec(x, y+1, nx, ny))

  return cost


def pacman(x,y,nx,ny):
  p = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]

  for i in range(1,4):
    #print(i)
    p[i][0] = p[i-1][0] + vertical[0][i-1]

  for j in range(1,4):
    #print(j)
    p[0][j] = p[0][j-1] + horizontal[0][j-1]

  print(p)

  for i in range(1,nx+1):
    for j in range(1, ny+1):
      print(i,j)
      # Contrary to instinct, i actually points to y and j points to x due to the way the matrix is set up
      # We either come from vertical (p[i-1][j] or horizontal (p[i][j-1]))
      p[i][j] = min(p[i-1][j]+vertical[j][i-1], p[i][j-1]+horizontal[i][j-1]) 

  print(p)
  return p[nx][ny]

print("Lowest cost recursive: ",pacman_rec(0,0,3,3))
print("new")
print("Testing: ",pacman(0,0,3,3))

horizontal = [[1,5,8],[7,3,4],[2,1,5],[6,9,3]]
vertical = [[6,4,3],[5,2,2],[2,8,1],[5,4,7]]