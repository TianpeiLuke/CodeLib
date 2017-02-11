# Dynamic Programming
This subsection includes several hard problems that have fast implementation based on __dynamic programming__. 

## Charateristics of dynamic programming

  1. __Optimal substructures__
  
    The __optimal solution__ of the original problem __contains within__ __optimal solutions__ of a sequence of _subproblems_. Each subproblem has exactly the same structure but with smaller size of state space (e.g. the dimension of state space, size of data involved etc.)


  2. __Sharing of resources (non-independent)__

    The successive subproblems share resources (e.g. sharing of hidden states, the optimal value of previous subproblem, or intermedia solution of previous problem)

    The _dependency_ of subproblems to master problem can be describled as __trees__. Note that due to repeating structure, many intermediate subproblems are exactly the same. 

    The __efficiency__ of dynamic programming lies in its __bookkeeping property__, i.e. it __store the state of previous solved subproblems__. Then when the same problem occur again, it does not need to solve it again. 



    1. Different from __divide-and-conquer__: _divide-and-conquer_ __partition__ the state space into __non-overlapping region__. But dynamic programming _cover_ the state space with __overlapping region__

    2. Different from __greedy algorithms__: the optimal solution of _greedy algorithm_ _only_ depends on _current_ information available. the optimal solution of dynamic programming depends on the __entire trajectory of optimal solutions__ in past history. 

    3. Benefits over the __recursion__: __avoid repeating__ solving previous solved problems by __bookkeeping__ or tabluar storage. Require __additional spaces__. 