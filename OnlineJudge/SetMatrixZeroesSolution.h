//
//  SetMatrixZeroesSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/1/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SetMatrixZeroesSolution_h
#define OnlineJudge_SetMatrixZeroesSolution_h

/** http://oj.leetcode.com/problems/set-matrix-zeroes/
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
 * Do it in place.
 *
 * Follow up: did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */
class SetMatrixZeroesSolution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        size_t m = matrix.size();
        size_t n = m > 0 ? matrix[0].size() : 0;
        if (n == 0 || m == 0)
            return;
        
        bool row_has_zero = false, col_has_zero = false;
        for (int i = 0; i < m && !col_has_zero; ++i) {
            col_has_zero = (matrix[i][0] == 0);
        }
        for (int j = 0; j < n && !row_has_zero; ++j) {
            row_has_zero = (matrix[0][j] == 0);
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (col_has_zero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        if (row_has_zero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

#endif
