# Searching and Tracking Algorithms

This subsection implements various efficient searching data structure and their associated algorithms.

There are two main data strcutures in searching

## Binary Search Tree (BST)

A __binary search tree (BST)__ contains a struct `BST_Node`, each tree node contains a `key` and two children. The basic rule for BST is that the keys for _all left sub-tree are less than the root_, and _the keys for all right sub-tree are greater than the root_. 



## Heap (Priority queue)

A __Heap__ is conceptually a perfect BST that every node either has two childrenor has no children. In implementation, it usually use an array since it do not need additional bits to store the pointers of the children  

The children of index `i` is $2i+1$ and $2i+2$





