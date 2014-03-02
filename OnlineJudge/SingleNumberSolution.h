//
//  SingleNumberSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/1/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SingleNumberSolution_h
#define OnlineJudge_SingleNumberSolution_h

/** http://oj.leetcode.com/problems/single-number/
 * 
 * Given an array of integers, every element appears twice except for one. 
 * Find that single one.
 * Note: your algorithm should have a linear runtime complexity. Could you 
 * implement it without using extra memory?
 */
class SingleNumberSolution {
public:
    int singleNumber(int A[], int n) {
        if (n <= 0)
            return 0;
        
        int result = A[0];
        for (int i = 1; i < n; ++i) {
            result ^= A[i];
        }
        return result;
    }
};

#endif
