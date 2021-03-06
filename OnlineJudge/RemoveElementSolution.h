//
//  RemoveElementSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveElementSolution_h
#define OnlineJudge_RemoveElementSolution_h

/** 
 * Given an array and a value, remove all instances of that value in place
 * and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 */
class RemoveElementSolution {
public:
    /** keeps the original order but may have O(n) copies.*/
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[len] = A[i];
                ++len;
            }
        }
        return len;
    }
  
    /** An improved version, which does NOT keep the original order but has
     * better performance
     */
    int removeElementV2(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i < n) {
            if (A[i] == elem)
                A[i] = A[--n];
            else
                ++i;
        }
        return n;
    }    

};

#endif
