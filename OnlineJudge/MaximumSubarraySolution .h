//
//  MaximumSubarraySolution .h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/13/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MaximumSubarraySolution__h
#define OnlineJudge_MaximumSubarraySolution__h

/** http://oj.leetcode.com/problems/maximum-subarray/
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray
 * [4,−1,2,1] has the largest sum = 6.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 */
class MaximumSubarraySolution {
public:
    /** Dynamic programming
     * sub[j] = max {sub[j-1] + A[j]} with sub[0] = A[0], 1 <= j < n,
     * target = max {sub[j]}, 0 <= j < n
     */
    int maxSubArray(int A[], int n) {
        int sub = 0, result = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sub = max(sub + A[i], A[i]);
            result = max(result, sub);
        }
        return result;
    }
    
    int maxSubArray_II(int A[], int n) {
        int lowest = 0, sum = 0, result = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            result = max(result, sum - lowest);
            lowest = min(lowest, sum);
        }
        return result;
    }
};

#endif
