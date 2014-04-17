//
//  SearchA2DMatrixSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/17/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SearchA2DMatrixSolution_h
#define OnlineJudge_SearchA2DMatrixSolution_h

/** Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the 
 * previous row.
 * For example, consider the following matrix:
 * [
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 *
 * Analysis: using binary search. 
 */
class SearchA2DMatrixSolution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        for (int first = 0, last = m * n; first < last;) {
            int mid = first + (last-first) / 2;
            int value = matrix[mid/n][mid%n];
            if (value == target) {
                return true;
            }
            else if (value < target) {
                first = mid + 1;
            }
            else { // value > target
                last = mid;
            }
        }
        return false;
    }
};

#endif
