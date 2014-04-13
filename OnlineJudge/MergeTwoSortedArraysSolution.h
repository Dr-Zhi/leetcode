//
//  MergeTwoSortedArrays.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 5/20/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MergeTwoSortedArraysSolution_h
#define OnlineJudge_MergeTwoSortedArraysSolution_h

/** http://oj.leetcode.com/problems/merge-sorted-array/
 * Given two sorted integer arrays A and B, merge B into A as one sorted
 * array.
 
 * Note: you may assume that A has enough space to hold additional elements
 * from B. The number of elements initialized in A and B are m and n
 * respectively.
 */
class MergeTwoSortedArraysSolution {
public:
    void merge(int A[], int m, int B[], int n) {
        while (n > 0) {
            if (m > 0 && A[m-1] > B[n-1]) {
                A[m+n-1] = A[m-1];
                --m;
            }
            else {
                A[m+n-1] = B[n-1];
                --n;
            }
        }
    }
};



#endif
