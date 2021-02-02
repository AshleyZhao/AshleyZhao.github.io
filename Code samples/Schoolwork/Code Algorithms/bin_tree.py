#!/usr/bin/env python3

def create_tree():
  import random
  from binarytree import tree

  h = random.randint(0,9)
  mytree = tree(height= h, is_perfect=False)
  print("real height",h)
  #print("the tree",mytree)
  return mytree

def traverse_tree(root):
  if root == None:
    return None
  else:
    print(root.value)
  
  traverse_tree(root.left)
  traverse_tree(root.right)

def height_tree(root):

  h = 0

  if root == None:
    return h
  
  else:
    if root.left != None or root.right != None:
      h += 1

  h_left = height_tree(root.left)
  h_right = height_tree(root.right)

  if h_left > h_right:
    return h + h_left
  else:
    return h + h_right

    


root = create_tree()
# traverse_tree(root)
print("height", height_tree(root))