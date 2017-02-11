# Dynamic Programming
This subsection includes several hard problems that have fast implementation based on __dynamic programming__. 

## Charateristics of dynamic programming

  1. __Optimal substructures__
  
    The __optimal solution__ of the original problem __contains within__ __optimal solutions__ of a sequence of _subproblems_. Each subproblem has exactly the same structure but with smaller size of state space (e.g. the dimension of state space, size of data involved etc.)


  2. __Sharing of resources (overlapping subproblems)__

    The successive subproblems share resources (e.g. sharing of hidden states, the optimal value of previous subproblem, or intermedia solution of previous problem). The subproblems should have smaller state space, and can be solved using recursion over and over again __without generating new problem__. 

    The _dependency_ of subproblems to master problem can be describled as __trees__. Note that due to repeating structure, many intermediate subproblems are exactly the same. The total number of __distinct subproblems__ is much smaller than the total number of intermedia nodes in the tree.  

  3. __Reconstructing of optimal solution via memoization__ 

    The __efficiency__ of dynamic programming lies in its __bookkeeping property__, i.e. it __store the state of previous solved subproblems__. Then when the same problem occur again, it does not need to solve it again. 

    Also, the optimal solution of each subproblem can be __reconstructed__ from a small amount of previous states (e.g. optimal solution of previous subproblems). 



    1. Different from __divide-and-conquer__: _divide-and-conquer_ __partition__ the state space into __non-overlapping region__. But dynamic programming _cover_ the state space with __overlapping region__. Although both can be solved recursively, divide-and-conquer algorithm solves new subproblem at each branch, while the dynamic programming do not solve "unseen new" problems.


    2. Different from __greedy algorithms__: the optimal solution of _greedy algorithm_ _only_ depends on _current_ information available. the optimal solution of dynamic programming depends on the __entire trajectory of optimal solutions__ in past history. 

    3. Benefits over the __recursion__: __avoid repeating__ solving previous solved problems by __bookkeeping__ or tabluar storage. Require __additional spaces__.



## Examples 

  1. Finding the __maximum sum of subarray__ 
  
   From an array of numbers, find a __contiguous subarray with maximum sum__. This problem can be solved in divide-and-conquer with O(n log(n)) time complexity, but using dynamic programming, we can solve it in O(n) time complexity with an additional O(n) space complexity. 


  2. __Edit distance__
 
   Finding how many operations (insertion, deletion, substitution) __at least__ needed to tranform one string to another string. Naive implementation with O(2^n) time complexity with recursion. The dynamic programming reduce it to O(mn) time complexity and O(mn) space complexity (can be O(min(m,n))), with m,n are size of two strings, respectively. 


  3. Finding the __longest common subsquences__

   Want to find the __maximum length of common subsequence__ in both strings. Naive implementation requires O(2^(m+n)) time complexity. The dynamic programming requires O(m+n) time complexity with O(mn) space complexity.

 
  4. __Optimal binaray search tree (BST)__

   Given additional information for each key value (tree node) including the __ranking__ of the key, (e.g. probability of appearence of each key).

   Want to construct a BST whose __expected cost of searching is minimized__, where the cost is a _weighted sum_ of the __depth__ of each key value and the weights are _ranking weights_.
    
