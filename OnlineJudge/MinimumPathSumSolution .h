//
//  MinimumPathSumSolution .h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/19/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MinimumPathSumSolution__h
#define OnlineJudge_MinimumPathSumSolution__h

/** http://oj.leetcode.com/problems/minimum-path-sum/
 * Given a m x n grid filled with non-negative numbers, find a path from top 
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Analysis: dynamic programming with sliding array.
 */
class MinimumPathSumSolution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int m = grid.size(), n = grid.front().size();
        vector<int> row(n, INT_MAX);
        row[0] = 0;
        for (int i = 0; i < m; ++i) {
            row[0] = row[0] + grid[i][0];
            for(int j = 1; j < n; ++j) {
                row[j] = min(row[j-1], row[j]) + grid[i][j];
            }
        }
        return row[n-1];
    }
};

#endif
