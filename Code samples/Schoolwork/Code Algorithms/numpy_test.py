#!/usr/bin/env python3

import numpy as np

arr1 = np.arange(6) 
print(arr1)

arr2 = np.array([5,4,3,2,1])
print(arr2)

arr = np.delete(arr2, [1,2,3])
print(arr)

arr = np.delete(arr2, 1)
print(arr)

matrix = np.array([[1,2,3],[4,5,6],[7,8,9]])
print(matrix)