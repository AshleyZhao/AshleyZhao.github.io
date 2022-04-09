#!/usr/bin/env python3

import os
import pandas as pd

filepaths = ["/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/Notebook_List.xlsx"]

for fp in filepaths:
    # Split the extension from the path and normalise it to lowercase.
    ext = os.path.splitext(fp)[-1].lower()
    try:
        if ext == ".xlsx":
            data = pd.read_excel(fp, engine='openpyxl', index_col=0, skiprows=lambda x: x%2 != 0)
        elif ext == ".csv":
            data = pd.read_csv(fp, index_col=0)
        elif ext == ".txt":
            data = pd.read_csv(fp, index_col=0)
        else:
            print("unknown file format.")
    except:
        print("An error occurred when parsing files")

    try:
        # Get every nth row
        #data_even = data.iloc[::n, :]

        if 'Notebook' in fp:

            path = '/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/Datasets/notebooks.csv'
            data.to_csv(path)
            
            test = pd.read_csv(path, names=["Notebooks"])

            test2 = pd.read_csv('/Users/ashleyzhao/Downloads/Event.csv', skiprows=lambda x: x < 8, names=['Cohort', 'Assets', 'CTA'])
            test2 = test2.replace(r'\t','', regex=True)

            test2["Assets"] = test2["Assets"].astype(str)

            print(test2.head())

            def get_cta(x):
                found = test2[test2['Assets'].str.contains(str(x))] 
                if (found.empty):
                    return 0
                else:
                    return found.iloc[0][2]

            test["CTA"] = test['Notebooks'].apply(lambda x: get_cta(x))

            print(test.head())

            test.to_csv('Notebook_CTA.csv')

        elif 'Project' in fp:
            data.to_csv('/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/Datasets/projects.csv')
        elif 'Data_Set' in fp:
            data.to_csv('/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/Datasets/data.csv')
        else:
            data.to_csv('/Users/ashleyzhao/GitHub/AshleyZhao.github.io/Code samples/Data Science/Datasets/unknown.csv')
        
    except:
        print("An error occurred when saving the CSV file")

    


