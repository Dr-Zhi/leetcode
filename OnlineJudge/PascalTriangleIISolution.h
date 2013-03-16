//
//  PascalTriangleIISolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 3/12/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_PascalTriangleIISolution_h
#define LeetCode_Solutions_PascalTriangleIISolution_h

#include <vector>

using std::vector;

/** http://leetcode.com/onlinejudge#question_119
 * Given an index k, return the kth row of the Pascal's triangle.
 
 * For example, given k = 3, Return [1,3,3,1]. Note: Could you optimize your
 * algorithm to use only O(k) extra space?
 */

class PascalTriangleIISolution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row;
        if (rowIndex < 0) {
            return row;
        }
        row.resize(rowIndex+1);
        row[0] = 1;
        for (int i = 1; i < rowIndex+1; ++i) {
            row[i] = row[i-1] * (rowIndex+1-i) / i;
        }
        return row;
    }
    
    vector<int> getRowV2(int rowIndex) {
        vector<int> row;
        if (rowIndex < 0) {
            return row;
        }
        row.resize(rowIndex+1);
        row[0] = 1;
        vector<int> prevRow(rowIndex+1);
        for (int i = 1; i <= rowIndex; ++i) {
            std::swap(row, prevRow);
            row[0] = prevRow[0];
            for (int j = 1; j < i; ++j) {
                row[j] = prevRow[j-1]+prevRow[j];
            }
            row[i] = prevRow[i-1];
        }
        return row;
    }
};

#endif
