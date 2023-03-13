#!/usr/bin/env python3

path = "/Users/ashleyzhao/GitHub/Docs/cpd-mddoc-src/topics/analyze-data/ml-orchestration-expr-builder.liquid.md"
output = 'new_expr_builder.md'
id_num = 1

# get the file
def read_file():
    
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

def generate_id(header):

    header = header.replace("#### ", "")
    header = header.lower()
    header.replace(' ', '-')

    if header == "syntax" or header == "examples":
        global id_num
        header = header + str(id_num)
        id_num += 1

    id = "{: #" + header + "}"

    return id

for line in Lines:
    if re.match(ex,line ):
        print("Match found")
        print(line.strip())
        new_Line = line.strip()
        #Old code to replace markdown tagging
        #new_Line= new_Line.replace('#### ', '')
        #new_Line = '<h4>'+new_Line+'</h4>'
        new_Lines.append(new_Line)
        new_Lines.append(generate_id(new_Line))
        # debug
    else:
        new_Line = line.strip()
        new_Lines.append(new_Line)
        # debug
        print("Line: {}".format(line.strip()))
#    if (re.match())
#    print("Line: {}".format(line.strip()))

print(new_Lines)

file = open(output,'w')
for line in new_Lines:
	file.write(line+"\n")
file.close()

# new_Line = "#### Syntax"
# new_Line.replace('#### ', '')
# print(new_Line)
#print(p.sub('<h1>\w*</h1>',text))