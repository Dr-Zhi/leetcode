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
class TriangleSolution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() == 0)
            return 0;
        vector<int> pathSum(triangle.size(), 0);
        pathSum[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            // note that the i-th value is dependent on the (i-1)-th value
            // so we compute the values from i-th to 0-th
            pathSum[i] = pathSum[i-1] + triangle[i][i];
            for (int j = i-1; j >= 1; --j) {
                pathSum[j] = min(pathSum[j-1], pathSum[j]) + triangle[i][j];
            }
            pathSum[0] += triangle[i][0];
        }
        return *min_element(pathSum.begin(), pathSum.end());
    }
};

#endif
