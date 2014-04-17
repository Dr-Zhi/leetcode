//
//  SortColorsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/17/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SortColorsSolution_h
#define OnlineJudge_SortColorsSolution_h

/** http://oj.leetcode.com/problems/sort-colors/
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red, 
 * white and blue. Here, we will use the integers 0, 1, and 2 to represent the
 * color red, white, and blue respectively.
 * Note: you are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting 
 * sort. First, iterate the array counting number of 0's, 1's, and 2's, then 
 * overwrite array with total number of 0's, then 1's and followed by 2's. 
 * Could you come up with an one-pass algorithm using only constant space?
 *
 * Cout sort is probahibited here. We can use bucket sort.
 */
class SortColorsSolution {
public:
    void sortColors(int A[], int n) {
        int redIdx = 0, blueIdx = n-1;
        for (int i = 0; i <= blueIdx;) {
            if (A[i] == 0) {
                swap(A[redIdx++], A[i++]);
            }
            else if (A[i] == 2) {
                swap(A[blueIdx--], A[i]);
            }
            else { // A[i] == 1
                ++i;
            }
        }
    }
};

#endif
