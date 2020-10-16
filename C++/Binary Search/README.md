
Binary search is a fast search algorithm with run-time complexity of Ο(log n). This search  algorithm works on the principle of divide and conquer. For this algorithm to work  properly, the data collection should be in the sorted form. 

Binary search starts by comparing the key element with the middle element of the array.If  key matches the middle element of array then match is found. If the middle item is greater  than the key, then the key is searched in the sub-array to the left of the middle element.  Otherwise, the key is searched for in the sub-array to the right of the middle element.  This process continues on the sub-array as well until the size of the subarray reduces to zero. 

In this algorithm we are using recursion to find the element in a sorted array. 
This is how it works. 
We basically ignore half of the elements just after one comparison. 

Compare key with the middle element. 

If key matches with middle element, we return the mid index. 

Else If key is greater than the mid element, then key can only lie in right half subarray  after the mid element. So we perform recursion for right half. 

Else (key is smaller) recursion is done for the left half. 