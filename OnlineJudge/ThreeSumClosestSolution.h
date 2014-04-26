//
//  ThreeSumClosestSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/26/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ThreeSumClosestSolution_h
#define OnlineJudge_ThreeSumClosestSolution_h

/** http://oj.leetcode.com/problems/3sum-closest/
 * Given an array S of n integers, find three integers in S such that the sum 
 * is closest to a given number, target. Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution. For example,
 * given array S = {-1 2 1 -4}, and target = 1. The sum that is closest to the
 * target is 2. (-1 + 2 + 1 = 2).
 *
 * There may exist duplicates in the array.
 */
class ThreeSumClosestSolution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int minGap = INT_MAX, result = INT_MAX;
        int n = (int)num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i+1, k = n-1; j < k;) {
                if (j > i+1 && num[j] == num[j-1]) {
                    ++j;
                    continue;
                }
                if (k < n-1 && num[k] == num[k+1]) {
                    --k;
                    continue;
                }
                int value = num[i] + num[j] + num[k];
                int gap = abs(value - target);
                if (gap < minGap) {
                    minGap = gap;
                    result = value;
                }
                if (value == target) {
                    return result;
                }
                else if (value > target) {
                    --k;
                }
                else { // value < target
                    ++j;
                }
            }
        }
        return result;
    }
};

#endif
