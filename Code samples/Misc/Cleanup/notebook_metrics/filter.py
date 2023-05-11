#!/usr/bin/env python3

import os
import pandas as pd
import numpy

"""
This script takes a csv file and a text file. 
It drops rows that are not found in the text file.
"""

# Get the file path for the data
data_path = "/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/Datasets/Non-IBMers for notebooks.csv"
raw_data = pd.read_csv(data_path, names=['Title', 'CTA'])
raw_data['Title'] = raw_data['Title'].str.replace('\t','')

# Get the list of notebooks
nb_file = open("Notebook_List.txt", "r")
nb_list = [line.strip('\n') for line in nb_file.readlines()]
nb_file.close()

#print("notebook list:", nb_list)
#print(raw_data['Title'].apply(lambda x: x not in nb_list))

# Takes a parameter nb and checks if it's in the list.
# If not, drop the row from the data table.
raw_data.drop(raw_data[raw_data['Title'].apply(lambda x: x not in nb_list)].index, inplace=True)

print(raw_data)

raw_data.to_csv("Notebooks_CTA.csv")