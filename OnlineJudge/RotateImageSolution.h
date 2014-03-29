//
//  RotateImageSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/29/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RotateImageSolution_h
#define OnlineJudge_RotateImageSolution_h

/** http://oj.leetcode.com/problems/rotate-image/
 * You are given an n x n 2D matrix representing an image. Rotate the image by
 * 90 degrees (clockwise).
 * Follow up: could you do this in-place?
 *
 * Analysis: simulating the rotation is a simple solution, but it requires O(n)
 * extras space. We need to find another way:
 * Step 1: flip the matrix by the diagonal line
 * Step 2: flip the matrix by the horizontal middle line.
 */
class RotateImageSolution {
public:
  void rotate(vector<vector<int> > &matrix) {
    const int n = matrix.size();
    for (int i = 0; i < n-1; ++i) {
      for (int j = 0; j < n-1-i; ++j) {
        swap(matrix[i][j], matrix[n-1-j][n-1-i]);
      }
    }
    
    const int half = (n >> 1);
    for (int i = 0; i < half; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n-1-i][j]);
      }
    }
  }
};

#endif
