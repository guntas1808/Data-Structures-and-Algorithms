#include "include/ArrayAlgorithms.h"
#include <iostream>

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

void quick_sort(std::vector<int>& vec){
    if(vec.size()<2)
        return;

    quick_sort_util(vec, 0, vec.size()-1);
}