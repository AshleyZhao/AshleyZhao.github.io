#!/usr/bin/env python3

# get the file
def read_file():
    path = "/Users/ashleyzhao/GitHub/Docs/cpd-mddoc-src/topics/analyze-data/ml-orchestration-expr-builder.liquid.md"
    f = open(path, "r")
    print(f.readline())
    return f

# print every line (for debug)
def print_lines(Lines):
    count = 0
    # Strips the newline character
    for line in Lines:
        count += 1
        print("Line: {}".format(line.strip()))

# expression to replace
import re
ex = "^####( \w+)$"
# print(p.sub('test',Lines))

text = read_file()

# read every line in the text
Lines = text.readlines()

new_Lines = []

for line in Lines:
    if re.match(ex,line ):
        print("Match found")
        print(line.strip())
        new_Line = line.strip()
        new_Line= new_Line.replace('#### ', '')
        new_Line = '<h4>'+new_Line+'</h4>'
        new_Lines.append(new_Line)
        # debug
    else:
        new_Line = line.strip()
        new_Lines.append(new_Line)
        # debug
        print("Line: {}".format(line.strip()))
#    if (re.match())
#    print("Line: {}".format(line.strip()))

print(new_Lines)

file = open('new_expr_builder_2.md','w')
for line in new_Lines:
	file.write(line+"\n")
file.close()

# new_Line = "#### Syntax"
# new_Line.replace('#### ', '')
# print(new_Line)
#print(p.sub('<h1>\w*</h1>',text))