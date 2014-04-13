//
//  FirstMissingPositiveSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/13/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_FirstMissingPositiveSolution_h
#define OnlineJudge_FirstMissingPositiveSolution_h

/** http://oj.leetcode.com/problems/first-missing-positive/
 * Given an unsorted integer array, find the first missing positive integer.
 * For example, given [1,2,0] return 3, and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 * Analysis: similar bucket sort, try to move every integer into its right 
 * position.
 */
class FirstMissingPositiveSolution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            while (A[i] != i+1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};

#endif
