//
//  RemoveDuplicatesFromSortedArraySolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveDuplicatesFromSortedArraySolution_h
#define OnlineJudge_RemoveDuplicatesFromSortedArraySolution_h

/** http://leetcode.com/onlinejudge#question_26
 * Given a sorted array, remove the duplicates in place such that each 
 * element appear only once and return the new length. Do not allocate 
 * extra space for another array, you must do this in place with constant
 * memory. For example, given input array A = [1,1,2], your function should
 * return length = 2, and A is now [1,2].
 */
class RemoveDuplicatesFromSortedArraySolution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
            return 0;
        int last = 0, val = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] != val) {
                val = A[i];
                A[++last] = A[i];
            }
        }
        return last+1;
    }
};

#endif
