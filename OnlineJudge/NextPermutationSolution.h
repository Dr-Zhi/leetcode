//
//  NextPermutationSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/25/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_NextPermutationSolution_h
#define OnlineJudge_NextPermutationSolution_h

/** http://oj.leetcode.com/problems/next-permutation/
 * Implement next permutation, which rearranges numbers into the 
 * lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest 
 * possible order (ie, sorted in ascending order). The replacement must be 
 * in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its 
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * Introduction:
 * Step 1: from the last element to the first one, find the first element (pivot)
 * that violates the increasing trend
 * Step 2: if not finding any element in Step 1, the array is the largest one.
 * Reverse the array and return.
 * Step 3: from the last element to the first one, find the first element that
 * is larger than the pivot, called the exchange element
 * Step 4: swap the pivot and exchange element. 
 * Step 5: reverse the subarray on the right of the pivot *index*.
 *
 */
class NextPermutationSolution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2)
            return;
        
        int pivotIdx = -1, exchangeIdx = -1;
        for (int i = (int)num.size() - 2; i >= 0; --i) {
            if (num[i] < num[i+1]) {
                pivotIdx = i;
                break;
            }
        }
        if (pivotIdx == -1) {
            reverse(num.begin(), num.end());
            return;
        }

        for (int i = (int)num.size() - 1; i >= 0; --i) {
            if (num[i] > num[pivotIdx]) {
                exchangeIdx = i;
                break;
            }
        }
        swap(num[pivotIdx], num[exchangeIdx]);
        reverse(next(num.begin(), pivotIdx+1), num.end());
    }
};


#endif
