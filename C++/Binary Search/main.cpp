#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int l, int r, int key) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == key) 
            return mid; 
   
        if (arr[mid] > key) 
            return binarySearch(arr, l, mid - 1, key); 
  
        return binarySearch(arr, mid + 1, r, key); 
    } 
   
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = { 23,45,67,87,98 }; 
    int key = 98; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int pos = binarySearch(arr, 0, n - 1, key); 
    (pos == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at position " << pos+1; 
    return 0; 
} 
