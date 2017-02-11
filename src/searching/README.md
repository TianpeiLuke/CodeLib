# Searching and Tracking Algorithms

This subsection implements various efficient searching data structure and their associated algorithms.

There are two main data strcutures in searching: 

## Binary Search Tree (BST)

A __binary search tree (BST)__ contains a struct `BST_Node`, each tree node contains a `key` and two `children`. The basic rule for BST is that the keys for _all left sub-tree are less than the root_, and _the keys for all right sub-tree are greater than the root_. 

1. __Pre-order Traversal__, __In-order Traversal__, __Post-order Traversal__

   Easy to implement in recursion. Drawbacks are slow in execution. Fast implementation using stack as tracker and __backtracking__ in combination with record (hash table) of __visited__ node. 
   
   1. _In-order Traversal_ implements using a stack to keep track of an __entire__ _left sub-tree_ and backtracking _only when_ no left sub-tree exists on __unvisited__ nodes. After visit of root, track the root of right sub-tree. 

       In-order traverse ouput the strict linear ordering of keys due to the defintion of BST.  
 
       [left sub-tree < root < right sub-tree]

   2. _Pre-order Traversal_ uses a stack to keep track of the __root__ of all _right subtree_ __along successive visits__ of the _left subtree_. Backtracking _only when_ the left sub-tree is _empty_.  

   3. _Post-order Traversal_ uses a stack to keep track of __both__ _left sub-tree_ and _right sub-tree_ at first. Backtracking only when __both__ left sub-tree and right sub-tree are _empty_ or __visited__.  


2. __Backtracking__

Implemented with a stack of node path and a hash table of visited nodes. Backtracking implements a DFS-style traverse across the entire space. 


## Heap (Priority queue)

A __Heap__ is conceptually a complete BST that every node either has two childrenor has no children. In implementation, it usually use an array since it do not need additional bits to store the pointers of the children  

The __heap property__: if $A$ is a _parent_ node $B$, then the _key_ of node $A$ is ordered with respect to the key of $B$ with the _same_ ordering apping to the heap. For instance, the __min heap__ has root as the minimal of the list and int each subtree, the key of root is smaller than all of its descendants.  

The children of index `i` is `2i+1` and `2i+2`. The parent of index `i` is `
\lfloor{\frac{i-1}{2}\rfloor}`

Find the max/min value takes $O(1)$ time, while `pop` and `push` takes $O(\log(n))$ time. `make_heap(n)` takes $O(n\log(n))$ time. 

1. __Heap Sort__

   A heap sort takes $O(n\log(n))$. It is a version of __comparison-based sorting__. 


2. __Median of Streaming data__

Use a __min-heap__ to maintain all exists keys that __greater than (>)__ current key and a __max-heap__ to maintian all existing keys that __less than (<=)__ current key. Then to as long as two heaps are of the same size, (or __max-heap.size__ < __min-heap.size__ <= __max-heap.size + 1__), the top in __min-heap__ is the median.

Note that if the size of two heaps are not balanced, pop the top elements in one heap and push into the other heap. 

In total, takes $O(n\log(n))$ times with $O(n)$ space. 


