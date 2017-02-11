# Graph-based Algorithms
This subsection implements a set of graph-based algorithms. It consists of three sub-categories: 

## Graph Construct
   This includes graph load algorithms and construction of various _graph representations_.The main graph representation uses an __adjacency list__. An __edge list__ representation is also available. Using __hash table__.  

## Graph Search Algorithms
   1. __Depth-First-Search (DFS)__ and __Breadth-First-Search (BFS)__

      The basic traversal and searching algorithm. Implemented via recursion and backtracking using stack (DFS) and queue (BFS). 
  
   2. Layer-wise searching 

   3. __Topological Ordering and Topological Sort__

    The topological ordering of graph nodes requires all parents occurs before their children. Basic ordering on a graph. For undirected graph, can be implemented using BFS. For __directed graph__, __only DFS__ can be used 

## Graph Topology Algorithms
   1. __Strong Connected Components (directed graph)__ and __Connected Components (undirected graph)__ 

      Using Kosaraju's two-pass DFS implementation for __SCC__. Using BFS for __CC__

     `../../bin/graph_algo/test_scc "../../data/SCC.txt 0"`

   2. __Min Cut (undirected graph)__

      Using Karger's randomized algorithm and node group-merging   
  
      `../../bin/graph_algo/test_mincut "../../data/kargerMinCut.txt" 23 0`


   3. __Union Find__
   
      Using in find set union. Using additional one bit to construct a merge-tree and keep track of a common root within all nodes in one group. 

   4. __Dijkstra's Algorithm in Single-Source-Shortest-Path for nonnegative weighted directed graph__

      Implementation using a min-heap maintaining `<node, key>` pair with key = Dijkstra's greedy score. Updating for each edges that passing from visited nodes to unvisited nodes. Very Fast implementation $O(m\log(n))$

       `../../bin/test_dijkstra "../../data/dijkstraData.txt"`