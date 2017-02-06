/*
implementation of Dijkstra's algorithm to find the minimal path from 
one single source s to every other node in directed graph.

Note that the distance on each edge is non-negative

===========================================================
Let X = {s}
A[s] = 0 = shortest path distance from s-s

naive implementation:
while (X != V){
   Ex = {edges from X -> V-X }
   for( (v,w) in Ex){
        find w such that A[v]+ d[v,w] is minimized
   }
   X = X \cup w
   A[w] = A[v] + d[v,w] where (v,w) is the minimizer given 
}

naive implementation need O(m*n)

=============================================================

could use min Heap data structure (at every node, key<= children's keys)
    extract-min by swapping up last leaf, bubbling down O(log(n))
    insert via bubbling up O(log(n))

Invariant #1:
    all elemnts (node) in heap =  vertices in V-X

Invariant #2
    for v in V-X
       key[v] = smallest Dijkstra's greedy score of an edge (u,v) in E with u\in X
   note that key[v] = \infty  if not directed link from X -> v 

The min-heap will find the minimizer of Dijkstra's greedy score in O(1) time 


To maintain invariant #2: when a new node x added to X, the frontier changes. This will add more edges ((w->*) for * in V-X) so those corresponding vertices will have key[*] decrease. 

for(each edge (w,v) in E){
   if(v in V-X){
      delete v in heap
      recompute key[v] = min{key[v], A[w]+d(w,v)}
      insert v according to new key[v]
   }
}

in total O(m+n) = O(m) for large m, heap operations,  running time O(m*log(n))

*/

#include "../../include/graph_algo/graph_search.hpp"
