//
//  RemoveDuplicatesFromSortedArrayIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/22/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveDuplicatesFromSortedArrayIISolution_h
#define OnlineJudge_RemoveDuplicatesFromSortedArrayIISolution_h

/** http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Follow up for "Remove Duplicates": What if duplicates are allowed at most 
 * twice? For example, given sorted array A = [1,1,1,2,2,3], your function
 * should return length = 5, and A is now [1,1,2,2,3].
 */
class RemoveDuplicatesFromSortedArrayIISolution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) {
            return n;
        }
        
        int idx = 2;
        for (int i = 2; i < n; ++i) {
            if (A[i] != A[idx-2]) {
                A[idx++] = A[i];
            }
        }
        return idx;
    }
};

#endif
