# Sorting algorithms
This subsection includes implementation of several useful sorting algorithms.

## Comparison-based sorting

The __comparison-based sorting__ algorithms do __not have direct access to the value__ of elements in an unsorted array but __only__ a method to __compare__ one element with another. The time complexity at least $\Omega(n\log(n))$.

  1. __quickSort__
    A classical and most commonly used sorting method. Based on __divide-and-conquer__. 

    1. pick a __pivot__ element, 

    2. then __partially sort__ the sequence so that the sequence __partitioned__ as 

    [ (subsequence 1) < pivot < (subsequence 2) ]

    Then the pivot location is fixed in the final solution.
 
    3. In two subsequences, repeat the previous step. 