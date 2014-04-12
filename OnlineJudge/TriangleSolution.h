//
//  MinimumPathSumOnTriangleSolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 3/9/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_TriangleSolution_h
#define OnlineJudge_TriangleSolution_h

#include <cassert>

using std::vector;

/** http://oj.leetcode.com/problems/triangle/
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below. For example, given the 
 * following triangle
 * [
 *    [2],
 *   [3,4],
 *  [6,5,7],
 * [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 * Note: Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 * 
 * Analysis: it is assumed that the values in triangle cannot be altered. Thus
 * we need a sliding array for the dynamic programming to solve the problem.
 * Please note the bottom-up fashion.
 */
class TriangleSolution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = (int)triangle.size();
        vector<int> pathSum(triangle[n-1]);
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                pathSum[j] = triangle[i][j] + min(pathSum[j], pathSum[j+1]);
            }
        }
        return pathSum[0];
    }
};

#endif
