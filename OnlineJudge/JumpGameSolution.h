//
//  JumpGameSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/22/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_JumpGameSolution_h
#define OnlineJudge_JumpGameSolution_h

/** http://oj.leetcode.com/problems/jump-game/
 * Given an array of non-negative integers, you are initially positioned at
 * the first index of the array. Each element in the array represents your
 * maximum jump length at that position. Determine if you are able to reach the
 * last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 *
 * Greedy method: the last step can be reached <=> every step can be reached.
 * Calculating the leftmost index that can be reached can solve the problem.
 *
 * Complexity: O(n) in time, O(1) in space.
 */
class JumpGameSolution {
public:
    bool canJump(int A[], int n) {
        int reach = 1;
        for (int i = 0; i < reach && reach < n; ++i) {
            reach = max(reach, i + 1 + A[i]);
        }
        return reach >= n;
    }
};

#endif
