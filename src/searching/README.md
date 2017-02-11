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

   Commonly implemented in __recursive version__. In this code, implemented with a __stack__ of node-path and a __hash table__ of visited nodes. Backtracking implements a DFS-style traverse across the entire space. Also used in enumeration of all possible combination of components.  
   
   Advantages for __recursive__ mode is that it is easy to code. The __disadvantages__ is that _repeated function calls_ waste time. Also for some applications, the DFS-based backtracking would go __too deep__ so that the system stack is __overflow__. 

   The advantage of __stack-implemented__ version is that it saves time in function calls and also it can be modified to avoid repeated computing the same subproblem. 
  
   1. All paths in a graph 


   2. All subsets 
  
 
   3. Sudoku


3. __Augmented BST and kth-order Statistics__

   For each node, adding additional bits to record the __size of the sub-tree rooted at given node__. Note that the __insertion__ of each node means that the size of _all nodes along path from the given node (leaf) to the root_ will increase by one. 

   Finding the k-th order statistics reduces to finding __size of left-children as `k-1`__.

## Heap (Priority queue)

A __Heap__ is conceptually a complete BST that every node either has two childrenor has no children. In implementation, it usually use an array since it do not need additional bits to store the pointers of the children  

The __heap property__: if __A__ is a _parent_ node __B__, then the _key_ of node __A__ is ordered with respect to the key of __B__ with the _same_ ordering apping to the heap. For instance, the __min heap__ has root as the minimal of the list and int each subtree, the key of root is smaller than all of its descendants.  

The children of index `i` is `2i+1` and `2i+2`. The parent of index `i` is `
\lfloor{\frac{i-1}{2}\rfloor}`

Find the max/min value takes O(1) time, while `pop` and `push` takes O(log(n)) time. `make_heap(n)` takes O(n log(n)) time. 

1. __Heap Sort__

   A heap sort takes O(n log(n)). It is a version of __comparison-based sorting__. 


2. __Median of Streaming data__

   Use a __min-heap__ to maintain all exists keys that __greater than (>)__ _current_ key and a __max-heap__ to maintian all existing keys that __less than (<=)__ _current key_. Then to as long as two heaps are of the same size, (or __max-heap.size__ < __min-heap.size__ <= __max-heap.size + 1__), the top in __min-heap__ is the median.

   Note that if the size of two heaps are not balanced, pop the top elements in one heap and push into the other heap. 

   In total, takes O(n log(n)) times with O(n) space. 

3. __kth-order statistics in Streaming data__

   Similar to above, only to make sure the size of __min-heap__ is exactly $k$.


