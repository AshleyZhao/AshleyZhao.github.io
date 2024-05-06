#!/usr/bin/env python3

import re

path = "/Users/ashleyzhao/GitHub/Docs/cpd-mddoc-src/topics/analyze-data/ml-orchestration-config.liquid.md"
output = 'new_config.liquid.md'

with open(path, "r") as rfile:
    s = rfile.read()
    rplce = re.sub(r'\{% render(.*)title: "(.*)"(.*)%\}\n\n', "### "+r"\2\n", s)
with open(output, "w") as wfile:
    wfile.write(rplce)