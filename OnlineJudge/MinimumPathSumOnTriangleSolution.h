//
//  MinimumPathSumOnTriangleSolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 3/9/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_MinimumPathSumOnTriangleSolution_h
#define LeetCode_Solutions_MinimumPathSumOnTriangleSolution_h

#include <cassert>

using std::vector;

/** http://leetcode.com/onlinejudge#question_120
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 may move to adjacent numbers on the row below. For example, given the following
 triangle
 [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note: Bonus point if you are able to do this using only O(n) extra space,
 where n is the total number of rows in the triangle.
 */
class MinimumPathSumOnTriangleSolution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() == 0) {
            return 0;
        }
        vector<int> prevMinSums(triangle.size(), 0);
        vector<int> curMinSums(triangle.size(), 0);
        curMinSums[0] = triangle[0][0];

        for (size_t i = 1; i < triangle.size(); ++i) {
            std::swap(prevMinSums, curMinSums);
            size_t n = triangle[i].size();
            assert(n == i+1);
            curMinSums[0] = prevMinSums[0] + triangle[i][0];
            for (size_t j = 1; j < n-1; ++j) {
                    curMinSums[j] = std::min(prevMinSums[j-1], prevMinSums[j]) + triangle[i][j];
            }
            curMinSums[n-1] = prevMinSums[n-2] + triangle[i][n-1];
        }
        return *std::min_element(curMinSums.begin(), curMinSums.end());
    }
};

#endif
