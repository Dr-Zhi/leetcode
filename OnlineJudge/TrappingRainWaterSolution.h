//
//  TrappingRainWaterSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/29/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_TrappingRainWaterSolution_h
#define OnlineJudge_TrappingRainWaterSolution_h

/** http://oj.leetcode.com/problems/trapping-rain-water/
 * Given n non-negative integers representing an elevation map where the width 
 * of each bar is 1, compute how much water it is able to trap after raining.
 * For example, given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 * Analysis:
 * Water is trapped between two higher peaks. We need to compute the left
 * and right highest peaks for each valley. But it is hard to do this in one 
 * pass. So in the first pass we find the global peak, and divide the
 * whole map into two halves. Then for each half, we can only focus on the left
 * (right) peak for each valley.
 *
 * Complexity: O(n), space O(1);
 */
class TrappingRainWaterSolution {
public:
  int trap(int A[], int n) {
    if (n <= 2)
      return 0;
    
    int partition = 0;
    for (int i = 1; i < n; ++i) {
      if (A[i] > A[partition]) {
        partition = i;
      }
    }
    
    int water = 0;
    for (int i = 1, leftHighest = A[0]; i < partition; ++i) {
      leftHighest = max(leftHighest, A[i]);
      water += (leftHighest - A[i]);
    }
    
    for (int i = n-2, rightHighest = A[n-1]; i > partition; --i) {
      rightHighest = max(rightHighest, A[i]);
      water += (rightHighest - A[i]);
    }
    
    return water;
  }
};


#endif
