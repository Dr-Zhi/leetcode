//
//  RemoveDuplicatesFromSortedArraySolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveDuplicatesFromSortedArraySolution_h
#define OnlineJudge_RemoveDuplicatesFromSortedArraySolution_h

/** http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Given a sorted array, remove the duplicates in place such that each 
 * element appear only once and return the new length. Do not allocate 
 * extra space for another array, you must do this in place with constant
 * memory. For example, given input array A = [1,1,2], your function should
 * return length = 2, and A is now [1,2].
 *
 * Note: this actually implements the unique() method in STL. 
 * Ref: http://www.cplusplus.com/reference/algorithm/unique/
 */
class RemoveDuplicatesFromSortedArraySolution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
        
        int i = 0, last = 0;
        while (++i != n) {
            if (A[i] != A[last])
                A[++last] = A[i];
        }
        return last + 1;
    }
    
    // a much more simple version
    int removeDuplicatesV2(int A[], int n) {
        return distance(A, unique(A, A+n));
    }
};

#endif
