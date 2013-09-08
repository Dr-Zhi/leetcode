//
//  SumRootToLeafNumbersSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 8/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SumRootToLeafNumbersSolution_h
#define OnlineJudge_SumRootToLeafNumbersSolution_h

#include "Types.h"

/** http://leetcode.com/onlinejudge#question_129
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf 
 * path could represent a number. An example is the root-to-leaf path 
 * 1->2->3 which represents the number 123. Find the total sum of all 
 * root-to-leaf numbers.
 * For example,
 *   1
 *  / \
 * 2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Return the sum = 12 + 13 = 25.
 *
 * Assumptions in the algorithm:
 * 1. all numbers on nodes must be non-negative
 * 2. there is no overflow during computation
 */
class SumRootToLeafNumbersSolution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sumNumbersRecursive(root, 0);
    }
    int sumNumbersRecursive(TreeNode *root, int localSum) {
        if (!root)
            return localSum;
        if (root->left == NULL && root->right == NULL)
            return localSum * 10 + root->val;
        int left = root->left ? sumNumbersRecursive(root->left, localSum*10+root->val) : 0;
        int right = root->right ? sumNumbersRecursive(root->right, localSum*10+root->val) : 0;
        return left + right;
    }
};

#endif
