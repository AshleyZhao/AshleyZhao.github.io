#!/usr/bin/env python3

import os
import pandas as pd

filepaths = ["/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/rateContent.xlsx", "/Users/ashleyzhao/GitHub/test.csv", "/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/ccs-filtered_sorted.txt"]

files = 1

for fp in filepaths:
    # Split the extension from the path and normalise it to lowercase.
    ext = os.path.splitext(fp)[-1].lower()
    try:
        if ext == ".xlsx":
            data = pd.read_excel(fp, engine='openpyxl', index_col=0)
        elif ext == ".csv":
            data = pd.read_csv(fp, index_col=0)
        elif ext == ".txt":
            data = pd.read_csv(fp, index_col=0)
        else:
            print("unknown file format.")

        data.drop(data.columns[data.columns.str.contains('unnamed',case = False)],axis = 1, inplace = True)

        data.drop_duplicates(keep="first",inplace=True)

        data.to_csv('output' + str(files) + '.csv')
        
        files+=1
    except:
        print("An error occurred when parsing files")