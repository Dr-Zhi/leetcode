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

/** http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
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
 * 1. all numbers on nodes are non-negative
 * 2. No overflow
 */
class SumRootToLeafNumbersSolution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
    
private:
    int sumNumbers(TreeNode * root, int value) {
        if (root == nullptr) {
            return value;
        }
        value = value * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return value;
        }
        int left = root->left ? sumNumbers(root->left, value) : 0;
        int right = root->right ? sumNumbers(root->right, value) : 0;
        return left + right;
    }
};

#endif
