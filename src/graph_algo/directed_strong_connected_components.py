import numpy as np
import graph_tool.all as gt #install the graph_tool packages
from graph_tool.topology import *

g = gt.Graph()

filename = "../../data/SCC.txt"

f = open(filename, "r");
lines = [[int(s) for s in x.split()] for x in f.readlines()]

#adds enough vertices (the "1 + " is for position 0)
g.add_vertex(1+ max([w[0] for w in lines] + [w[1] for w in lines]))

#add edges
for line in lines:
   g.add_edge(g.vertex(line[0]), g.vertex(line[1]))


# compute the strong-connected-components

[comp, hist, is_attractor] = gt.label_components(g, directed=True, attractors=True )

#sort and only show the first 5 largest components
hists = sorted(hist, reverse=True)

print("size of Largest 5 directed components")
print(hists[0:5])