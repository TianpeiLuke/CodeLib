
import numpy as np
import networkx as nx


def read_file(filename):

    edgeList = []
    with open(filename, 'r') as f:
        
        for line in f:
            container = []
            line_parse = line.split()
            # [source target1,weight1 target2,weight2 target3,weight3 ... ]
            source = line_parse[0]
            for i, val in enumerate(line_parse[1:len(line_parse)]):
                target, data = val.split(',')
                edge = [source] + [target] + [data]
                edgeList.append(edge)

    return edgeList

def write_to_txt(filename, edgeList):
    with open(filename, 'w') as f:
        for edge in edgeList:
           f.write("{} {} {}".format(edge[0], edge[1], edge[2]))

def build_graph(filename):
    G = nx.read_weighted_edgelist(filename, nodetype=int)
    return G

def path_single_source_dijkstra(G, source):
    #path = nx.single_source_dijkstra_path(G, source)
    path_length = nx.single_source_dijkstra_path_length(G, source)
    return path_length


if __name__ == '__main__':
 
   fileData = "../../data/dijkstraData.txt"
   fileList = "../../data/dijkstraEdgeList.txt"

   edgeList= read_file(fileData)
   #write_to_txt(fileList, edgeList)
   
   G = build_graph(fileList)

   path_length = path_single_source_dijkstra(G, 1)
   query_list = [7, 37, 59, 82, 99, 115, 133, 165, 188, 197]

   ans = []
   for q in query_list:
       path = path_length[q]
       ans.append(path)
       print(path)