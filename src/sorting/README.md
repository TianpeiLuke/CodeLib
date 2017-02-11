# Sorting algorithms
This subsection includes implementation of several useful sorting algorithms.

## Comparison-based sorting

The __comparison-based sorting__ algorithms do __not have direct access to the value__ of elements in an unsorted array but __only__ a method to __compare__ one element with another. The time complexity at least i \(\Omega\) (n log(n)).

  1. __quickSort__

    A classical and most commonly used sorting method. Based on __divide-and-conquer__. 

    1. pick a __pivot__ element, 

    2. then __partially sort__ the sequence so that the sequence __partitioned__ as 
      ` [ (subsequence 1) < pivot < (subsequence 2) ]`

    Then the pivot location is fixed in the final solution.
 
    3. In two subsequences, repeat the previous step. 

   Worst case O(n^2), expected O(n log(n)). Use __random pivot__. 
   __Unstable sorting for in-place implementation__, i.e. element with _same value may exchange positions_. Implemented in O(1) space complexity, using __three-way partition__

     `[pivot, (subseq 1, partial ordered < pivot), (subseq 2, partial ordered > piot), (subseq 3, unordered) ]`



  2. __mergeSort__

    1. begin with merging successive single elements and sort

    2. at each step, merging two _successive_ __completely sorted__ subsequence

   Worst case O(n log(n)) and expected case O(n log(n)). In practice, slower than quickSort. Merging takes O(n) at each step.  

   Need __O(n) extra space__, __not in-place__. __Stable Sorting__. Some other advantage in implementation includes: __memory-efficient__ (only access data locally), stable sort, __linear speedup in parallelization__,  _external sorting_ (no need the locality of reference).
   


  3. __heapSort__
   
    1. `make_heap` for existing unsorted array 
    
    2. A new element comes in by `push` operation to the heap 

    3. Retrieve the ordered array by iteratively `pop` out the top root elements (i.e. the maximum/minimum depending on the min-heap or max-heap)

    Need O(n log(n)) to make heap for existing array. time complexity O(n log(n)) and it is a __const__ upper bound.__in-place sorting__ but  __Unstable sorting__.



## Non-comparsion sorting
  
   When additional assumptions are made on the __values__ of the elements in unsorted array, the sorting algorithm is __non-comparison based__.

  1. __countingSort__

   An __integer__ sorting algorithm. an non-comparative sorting. Count a __histogram__ that record the __number of occurances for each integers__ in the unsorted array.

     

  2. __bucketSort__

   A __distribution sort__. Requires data values are __bounded__.  In essence, construct a __histogram__ of data values. 


  3. __radixSort__

   A _non-comparative_ __integer__ sorting algorithm. Sort data with __integer keys__ by __grouping keys__ by individual digits which __share the same significant position and value__. 

   
