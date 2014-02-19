//
//  SearchInSortedArraySolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 2/17/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SearchInSortedArraySolution_h
#define OnlineJudge_SearchInSortedArraySolution_h

/** http://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */
class SearchInSortedArraySolution {
public:
    int search(int A[], int n, int target) {
        int first = 0, last = n;
        while (first < last) {
            int mid = first + (last - first) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] >= A[first]) {
                if (A[first] <= target && A[mid] > target)
                    last = mid;
                else
                    first = mid + 1;
            }
            else {
                if (A[mid] < target && A[last-1] >= target)
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        
        return -1;
    }
};

#endif
