//
//  LongestConsecutiveSequenceSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 2/18/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LongestConsecutiveSequenceSolution__h
#define OnlineJudge_LongestConsecutiveSequenceSolution__h

#include <unordered_set>

using std::unordered_set;

/** http://oj.leetcode.com/problems/longest-consecutive-sequence/
 * Given an unsorted array of integers, find the length of the longest 
 * consecutive elements sequence.
 * For example, given [100, 4, 200, 1, 3, 2], the longest consecutive elements 
 * sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 *
 * Note: it'd better use for-loop instead of while-loop for the reason that the 
 * increment operation must be in a correct position.
 */
class LongestConsecutiveSequenceSolution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> mapping;
        for (int i = 0; i < num.size(); ++i) {
            mapping.insert(num[i]);
        }
        
        int longest = 0;
        for (int i = 0; i < num.size(); ++i) {
            int val = num[i];
            if (mapping.find(val) == mapping.end())
                continue;
            
            int length = 1;
            for (int j = val + 1; mapping.find(j) != mapping.end(); ++j) {
                ++length;
                mapping.erase(j);
            }
            for (int j = val - 1; mapping.find(j) != mapping.end(); --j) {
                ++length;
                mapping.erase(j);
            }
            longest = max(longest, length);
        }
        return longest;
    }
};

#endif
