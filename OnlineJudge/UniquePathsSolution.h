//
//  UniquePathsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/14/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_UniquePathsSolution_h
#define OnlineJudge_UniquePathsSolution_h

/** http://oj.leetcode.com/problems/unique-paths/
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' 
 * in the diagram below).
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in 
 * the diagram below). How many possible unique paths are there?
 *
 * Analysis: dynamic programming f[i][j] = f[i-1][j] + f[i][j-1] with initial
 * value: f[0][0] = 1.
 *
 * An alternative method: mathematical formula: choose m-1 down steps in the 
 * total m+n-2 steps = C^{m-1}_{m+n-2}.
 */
class UniquePathsSolution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 0);
        f[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] = f[j-1] + f[j];
            }
        }
        return f[n-1];
    }
};

#endif
