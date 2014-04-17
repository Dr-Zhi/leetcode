//
//  SearchInsertPositionSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SearchInsertPositionSolution_h
#define OnlineJudge_SearchInsertPositionSolution_h

#include <cassert>

/** http://leetcode.com/onlinejudge#question_35
 * Given a sorted array and a target value, return the index if the target
 * is found. If not, return the index where it would be if it were inserted
 * in order.
 * You may assume no duplicates in the array.
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 * Analysis: equivalent to std::lower_bound().
 */
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int first = 0, last = n;
        while(first < last) {
            int mid = first + (last - first) / 2;
            if (A[mid] >= target) {
                last = mid;
            }
            else {
                first = mid + 1;
            }
        }
        return first;
    }
};

#endif
