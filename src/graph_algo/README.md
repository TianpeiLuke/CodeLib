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

      Using __Kosaraju__'s two-pass DFS implementation for __SCC__. 
      
    1. The first DFS pass over the __reverse graph__ to compute a `finishing time` which provides an node ordering (i.e.an  _decreasing ordering_ of _visit_ by DFS). 

    2. The second DFS pass over the __original graph__ and choose _root_ according to the __decreasing ordering__ of `finishing time` of nodes. Each _complete DFS_ pass over one single strong connected components.

     `../../bin/graph_algo/test_scc "../../data/SCC.txt 0"`


      Using BFS for __CC__

   2. __Min Cut (undirected graph)__

      Using Karger's randomized algorithm and node group-merging   
  
      `../../bin/graph_algo/test_mincut "../../data/kargerMinCut.txt" 23 0`


   3. __Union Find__
   
     A __disjoint-set data structure__, or __union-find data strcuture__ is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It supports two basic operations

    1. `Find`: determine which subset a particular elem belongs to. Find a _representative (root)_ in the group. 

    2. `Union`: join two subsets into one. eps. merge the representative of two groups by making one representative be the _root_ of the other.
 
    Here `numIsLands.cpp` uses union-find data structure.


   4. __Dijkstra's Algorithm in Single-Source-Shortest-Path__ for nonnegative weighted directed graph

      Implementation using a min-heap maintaining `<node, key>` pair with key = Dijkstra's greedy score. Updating for each edges that passing from visited nodes to unvisited nodes. Very Fast implementation O(|E| + |V| log(|V|)) compared with a naive implementation which requires O(|V|^2)

       `../../bin/test_dijkstra "../../data/dijkstraData.txt"`