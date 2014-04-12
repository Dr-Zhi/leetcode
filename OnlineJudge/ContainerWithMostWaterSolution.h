//
//  ContainerWithMostWaterSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/1/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ContainerWithMostWaterSolution_h
#define OnlineJudge_ContainerWithMostWaterSolution_h

/** http://oj.leetcode.com/problems/container-with-most-water/
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with 
 * x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 *
 * Analysis: use greedy method. Start with the container with largest width 
 * (from left to right), find the bottleneck, and then iterate by "removing"
 * the bottleneck.
 */
class ContainerWithMostWaterSolution {
public:
    int maxArea(vector<int> &height) {
        int area = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            area = max(area, (j-i) * min(height[j], height[i]));
            if (height[j] > height[i]) {
                ++i;
            }
            else {
                --j;
            }
        }
        return area;
    }
};

#endif
