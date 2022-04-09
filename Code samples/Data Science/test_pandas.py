#!/usr/bin/env python3

import pandas as pd

df = pd.DataFrame(
	[[88, 72, 67],
	[23, 78, 62],
	[55, 54, 76]],
	columns=['a', 'b', 'c'])

print(df.head(3))

#print(df.index % 2 == 0)

#df1 = df[df.index % 2 == 0]

#print(df1)

print(df.loc[1][0])

# If the column assets contain an element from the notebooks list (as Series s1)
#found = test2[test2['Assets'].str.contains(s1[0])]
#print("found", found)
#print("try", found.iloc[0][2])
#not_found = test2[test2['Assets'].str.contains("randomstringhere")]
#print(not_found.empty)