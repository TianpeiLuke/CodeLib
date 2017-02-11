# Searching and Tracking Algorithms

This subsection implements various efficient searching data structure and their associated algorithms.

There are two main data strcutures in searching

## Binary Search Tree (BST)

A __binary search tree (BST)__ contains a struct `BST_Node`, each tree node contains a `key` and two children. The basic rule for BST is that the keys for _all left sub-tree are less than the root_, and _the keys for all right sub-tree are greater than the root_. 



## Heap (Priority queue)

A __Heap__ is conceptually a complete BST that every node either has two childrenor has no children. In implementation, it usually use an array since it do not need additional bits to store the pointers of the children  

The __heap property__: if $A$ is a parent node $B$, then the _key_ of node $A$ is ordered with respect to the key of $B$ with the _same_ ordering apping to the heap. For instance, the __min heap__ has root as the minimal of the list and int each subtree, the key of root is smaller than all of its descendants.  

The children of index `i` is `2i+1` and `2i+2`. The 





