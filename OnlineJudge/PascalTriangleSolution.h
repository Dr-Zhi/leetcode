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
using std::swap;

/** http://leetcode.com/onlinejudge#question_118
 * Given numRows, generate the first numRows of Pascal's triangle.
 For example, given numRows = 5, return
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 */
class PascalTriangleSolution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > triangle;
        if (numRows <= 0) {
            return triangle;
        }
        vector<int> previousLine;
        vector<int> currentLine(1, 1);
        triangle.push_back(currentLine);
        for (int i = 1; i < numRows; ++i) {
            swap(previousLine, currentLine);
            currentLine.resize(i+1);
            currentLine[0] = previousLine[0];
            for (int j = 1; j < i; ++j) {
                currentLine[j] = previousLine[j-1]+previousLine[j];
            }
            currentLine[i] = previousLine[i-1];
            triangle.push_back(currentLine);
        }
        return triangle;
    }
};

#endif
