# Find K Closest Elements
## Problem Explanation
parameters:  
 - std::vector<int> arr
 - int quantity
 - int target
   
&nbsp;&nbsp;&nbsp;&nbsp;The problem `Find K Closest Elements` is to find the `k` closest elements to some `target` in the array `arr`.  Closeness is defines as a distance metric; for some element `a_x` in arr, its distance from the target is defined as `abs(target - a_x)`; when there is a tie, `arr`=`[1,3]` and `target = 2`, we pick the lesser of the two values.  
&nbsp;&nbsp;&nbsp;&nbsp;Formally, an integer `a` is closer to `x` than `b` if `(abs(a - x) < abs(b-x)) || ((abs(a-x) == abs(b-x)) && a < b)`.  
&nbsp;&nbsp;&nbsp;&nbsp;For example with a target value of `12`, given an array `[1, 2, 10, 11, 12, 14, 16, 18, 20]` and a `quantity` of 3, our result would be `[10, 11, 12]`.
## Solutions
### Unsorted Array
This solution is implemented in `src/PriorityQueueSolution.cxx`.
#### Solution thought process
&nbsp;&nbsp;&nbsp;&nbsp;In this case, as the array is unsorted, is only one reasonable solution, we take the array, dump it into a max heap where max is defined by distance to the `target`, continuously popping the values once the size of the heap is greater than `quantity`. The final values in the max heap are reorganized into a sorted vector and returned.  
&nbsp;&nbsp;&nbsp;&nbsp;This reorganization requires creating a `deque` (for O(1) insert at end and beginning), and popping elements off the top of the heap. These popped elements are then added to the end or beginning of the deque depending on if they're less than or greater than the very first value in the heap.
#### Time and Space complexity of unsorted solution
&nbsp;&nbsp;&nbsp;&nbsp;The time complexity of this solution is `O(n*log(k) + k)` where `n = size of the parameter vector "arr"` and `k = the parameter "quantity"` is the parameter `quantity`. We only need to loop through the parameter `arr` once, and inserting into the max heap takes `log(k)` time, as the max size of the heap is kept at `k`. The reorganization process from `heap` to `std::vector` also takes `k` time as it requires just a comparison and insert into a `deque` which is then looped through to create the result returned as a `std::vector`.


### Sorted Array
