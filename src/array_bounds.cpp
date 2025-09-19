//src/array_bounds.cpp
#include "array_bounds.hpp"
#include <algorithm> // std::lower_bound, std::upper_bound
#include <iostream>

// Standard library function for testing
int std_lower_bound(const int* arr, int n, int target) {//const- dont change array
    auto it = std::lower_bound(arr, arr + n, target);//
    int idx = it - arr; // convert iterator to index
    return idx;
}

// Standard library function for testing
int std_upper_bound(const int* arr, int n, int target) {
    auto it = std::upper_bound(arr, arr + n, target);
    int idx = it - arr; // convert iterator to index
    return idx;
}

// Standard library function for testing
int std_frequency(const int *arr, int n, int target) {
    int lb = std_lower_bound(arr, n, target);
    int ub = std_upper_bound(arr, n, target);
    return ub - lb;
}

// Recursive versions
int lower_bound(const int* arr, int n, int target){
    
    return lower_bound_recursive(arr, 0,n,target);
   
}
int upper_bound(const int* arr, int n, int target){
    
    return upper_bound_recursive(arr,0,n,target);
}
int frequency(const int * arr, int n, int target){//number of occurrences of the target value in the array
 return upper_bound(arr,n,target)-lower_bound(arr,n,target);
}

// Recursive helper versions
int lower_bound_recursive(const int* arr, int low, int high, int target){
    
    if (target>=arr[low]) {//position of the first element that is not less than the target.
        return low;//return index where above is true
    }
    else{
        if (low==high) return high;//if meet end of array, send n=high
        low++;//increment to continue to next element
        lower_bound_recursive(arr, 0,high,target);//repeat check w/ new low val                 
    }
}
int upper_bound_recursive(const int* arr, int low, int high, int target){
    if (target>arr[low]) {//position of the first element that is greater than (>) the target value
        return low;//return index where above is true
    }
    else{
        if (low==high) return high;//if meet end of array, send n=high
        low++;//increment to continue to next element
        lower_bound_recursive(arr, 0,high,target);//repeat check w/ new low val               
    }
}

// Iterative versions
int lower_bound_iterative(const int* arr, int n, int target){
    
    for (int i=0; i< n; i++){//go through all values//sizeof(*arr)
        if (arr[i]>=target){//position of the first element that is not less than the target.
            return i;//return the index to insert the target value to maintain the sorted order
        }
    }
    return n;// if target is not = to any values return n
}
int upper_bound_iterative(const int* arr, int n, int target){
    for (int i=0; i< n; i++){//go through all values//sizeof(*arr)
        if (arr[i]>target){//position of the first element that is greater than the target value
            return i;//return the index to insert the target value to maintain the sorted order
        }
    }
    return n;// if target is not > to any values return n
}

int frequency_iterative(const int *arr, int n, int target){//number of occurrences of the target value in the array
   return upper_bound_iterative(arr,n,target)-lower_bound_iterative(arr,n,target);
}
