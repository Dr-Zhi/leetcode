//
//  PascalTriangleSolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 3/10/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_PascalTriangleSolution_h
#define LeetCode_Solutions_PascalTriangleSolution_h

#include <vector>

using std::vector;

/** http://oj.leetcode.com/problems/pascals-triangle/
 * Given numRows, generate the first numRows of Pascal's triangle.
 For example, given numRows = 5, return
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 *
 * Analysis: using sliding array.
 */
class PascalTriangleSolution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        vector<int> line;
        line.reserve(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = i-1; j > 0; --j) {
                line[j] = line[j] + line[j-1];
            }
            line.push_back(1);
            triangle.push_back(line);
        }
        return triangle;
    }
};

#endif
