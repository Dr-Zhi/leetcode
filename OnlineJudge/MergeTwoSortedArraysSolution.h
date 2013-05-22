//
//  MergeTwoSortedArrays.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 5/20/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MergeTwoSortedArraysSolution_h
#define OnlineJudge_MergeTwoSortedArraysSolution_h

/** http://leetcode.com/onlinejudge#question_88
 * Given two sorted integer arrays A and B, merge B into A as one sorted
 * array.
 
 * Note: you may assume that A has enough space to hold additional elements
 * from B. The number of elements initialized in A and B are m and n
 * respectively.
 */
class MergeTwoSortedArraysSolution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (n > 0) {
            if (m > 0 && A[m-1] > B[n-1]) {
                A[n+m-1] = A[--m];
            }
            else {
                A[n+m-1] = B[--n];
            }
        }
    }
};


#endif
