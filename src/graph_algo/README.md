# Graph-based Algorithms
This subsection implements a set of graph-based algorithms. It consists of three sub-categories: 

## Graph Construct
   This includes graph load algorithms and construction of various _graph representations_.The main graph representation uses an __adjacency list__. An __edge list__ representation is also available. Using Hash table.  

## Graph Search Algorithms
   1. __Depth-First-Search (DFS)__ and __Breadth-First-Search (BFS)__
      The basic traversal and searching algorithm. Implemented via recursion and backtracking using stack (DFS) and queue (BFS). 
  
   2. Layer-wise searching 

   3. __Topological Ordering__

    The topological ordering of graph nodes requires all parents occurs before their children. Basic ordering on a graph. For undirected graph, can be implemented using BFS. For __directed graph__, __only DFS__ can be used 

## Graph Topology Algorithms
   1. __Strong Connected Components (directed graph)__ and __Connected Components (undirected graph)__ 

      Using Karger's two-pass DFS implementation for __SCC__. Using BFS for __CC__

   2. 