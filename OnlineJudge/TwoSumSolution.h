//
//  TwoSumSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 2/16/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_TwoSumSolution_h
#define OnlineJudge_TwoSumSolution_h

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

/** http://oj.leetcode.com/problems/two-sum/
 * Given an array of integers, find two numbers such that they add up
 * to a specific target number.
 * The function twoSum should return indices of the two numbers such 
 * that they add up to the target, where index1 must be less than 
 * index2. Please note that your returned answers (both index1 and 
 * index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 * Why using unordered_map? 
 * http://drzhi.org/why-using-unordered_map-c11-feature-for-hashing/
 */
class TwoSumSolution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < numbers.size(); ++i) {
            mapping[numbers[i]] = i;
        }
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i) {
            int gap = target - numbers[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                result.push_back(i+1);
                result.push_back(mapping[gap]+1);
                break;
            }
        }
        return result;
    }
};

#endif
