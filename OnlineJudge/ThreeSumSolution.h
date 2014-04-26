//
//  ThreeSumSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/26/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ThreeSumSolution_h
#define OnlineJudge_ThreeSumSolution_h

/** http://oj.leetcode.com/problems/3sum/
 * Given an array S of n integers, are there elements a, b, c in S such that 
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of 
 * zero.
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4}, a solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 *
 * Note the removal of duplicate in lines 33-35 and 37-40.
 */
class ThreeSumSolution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        const int n = (int)num.size();
        const int target = 0;
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i+1, k = n-1; j < k;) {
                if (j > i+1 && num[j] == num[j-1]) {
                    ++j;
                    continue;
                }
                const int val = num[i] + num[j] + num[k];
                if (val == target) {
                    result.push_back({num[i], num[j], num[k]});
                    ++j, --k;
                }
                else if (val < target) {
                    ++j;
                }
                else { // val > target
                    --k;
                }
            }
        }
        return result;
    }
};
#endif
