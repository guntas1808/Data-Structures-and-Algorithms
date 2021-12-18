#include "include/ArrayAlgorithms.h"
#include <iostream>

std::vector<int>& generate_array(int size){
    std::vector<int> vec(size);

    srand(time(0));

    for(int i=0; i<size; ++i){
        vec[i] = rand();
    }
    return vec;
}

void merge(std::vector<int>& vec, int start, int mid, int end){
    int ptr1 = start;
    int ptr2 = mid+1;

    std::vector<int> temp_vec;
    for(int i=0; i<end-start+1; ++i){
        if(ptr1 == mid+1){
            temp_vec.push_back(vec[ptr2]);
            ++ptr2;
        }else if(ptr2 == end+1){
            temp_vec.push_back(vec[ptr1]);
            ++ptr1;
        }else if(vec[ptr1] < vec[ptr2]){
            temp_vec.push_back(vec[ptr1]);
            ++ptr1;
        }else{
            temp_vec.push_back(vec[ptr2]);
            ++ptr2;
        }
    }

    for(int i=start; i<=end ; ++i)
        vec[i] = temp_vec[i-start];
    
}

void merge_sort_util(std::vector<int>& vec, int start, int end){
    if(start==end)
        return;
    
    int mid = (start + end)/2;
    merge_sort_util(vec, start, mid);
    merge_sort_util(vec, mid+1, end);
    merge(vec, start, mid, end);
}

/**
 * Merge sort
 * @param vec vector containing elements to be sorted
*/
void merge_sort(std::vector<int>& vec){
    if(vec.size()<=1)
        return;

    merge_sort_util(vec, 0, vec.size()-1);
}

int partition(std::vector<int>& vec, int start, int end){
    if(start==end)
        return start;
    
    int ptr = start;
    int pivot = vec[end];
    int mid = -1;

    for(; ptr<end; ++ptr){
        if (vec[ptr] < pivot){
            ++mid;
            int temp = vec[ptr];
            vec[ptr] = vec[mid];
            vec[mid] = temp;
        }
    }
    
    int temp = vec[mid+1];
    vec[mid+1] = vec[end];
    vec[end] = temp;
    
    return mid+1;
}

void quick_sort_util(std::vector<int>& vec, int start, int end){
    if(start >= end)
        return;

    int mid = partition(vec, start, end);
    quick_sort_util(vec, start, mid-1);
    quick_sort_util(vec, mid+1, end);
}

/**
 * Quick sort
 *  @param vec vector containing elements to be sorted
*/
void quick_sort(std::vector<int>& vec){
    if(vec.size()<2)
        return;

    quick_sort_util(vec, 0, vec.size()-1);
}

/**
 * Binary search for an element in the array
 * @param vec a vector of sorted elements
 * @param k key to search for in the vector
 * @param is_inc true if the vector is sorted in increasing order
 */
int binary_search(std::vector<int>& vec, int k, bool is_inc){
    if(vec.size()==0)
        return -1;
    
    int start = 0;
    int end = vec.size()-1;
    int mid;

    while (start <= end){
        int mid = (start+end)/2;
        if(vec[mid]==k)
            return mid;
        else if(((vec[mid] < k) && is_inc) || ((vec[mid] > k) && !is_inc))
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

/**
 * Returns the boundary indices of the contiguous subarray with largest sum
 * using Kadane's Algorithm
 * @param vec
*/
std::pair<int, int> kadanes_algorithm(std::vector<int>& vec){
    return std::make_pair(0,0);
}


std::pair<long long int, std::pair<int, int>> max_sum_crossing_subarray(std::vector<int>& vec, int start, int mid, int end){
    long long sum = 0;
    long long l_sum = -__LONG_LONG_MAX__;
    int l_idx = mid;
    
    for(int i=mid; i>=start; --i){
        sum += vec[i];
        if(sum > l_sum){
            l_idx = i;
            l_sum = sum;
        }
    }

    sum = 0;
    long long r_sum = -__LONG_LONG_MAX__;
    int r_idx = mid+1;
    for(int i=mid+1; i<=end; ++i){
        sum += vec[i];
        if(sum > r_sum){
            r_idx = i;
            r_sum = sum;
        }
    }
    
    return std::make_pair(l_sum+r_sum, std::make_pair(l_idx, r_idx));
}

std::pair<long long int, std::pair<int, int>> largest_sum_contiguous_subarray_util(std::vector<int>& vec, int start, int end){
    if(start==end)
        return std::make_pair(vec[start], std::make_pair(start, end));

    int mid = (start+end)/2;

    auto left = largest_sum_contiguous_subarray_util(vec, start, mid);
    auto right = largest_sum_contiguous_subarray_util(vec, mid+1, end);
    auto cross = max_sum_crossing_subarray(vec, start, mid, end);
    
    if(cross.first >= left.first && cross.first >= left.first)
        return cross;
    else if(left.first >= right.first)
        return left;
    else
        return right;
}

/**
 * Returns the boundary indices and the sum of the contiguous subarray with largest sum
 * using recursion
 * @param vec
*/
std::pair<long long int, std::pair<int, int>> largest_sum_contiguous_subarray(std::vector<int>& vec){
    
    return largest_sum_contiguous_subarray_util(vec, 0, vec.size()-1);
}