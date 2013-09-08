//
//  BalancedBinaryTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/25/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BalancedBinaryTreeSolution_h
#define OnlineJudge_BalancedBinaryTreeSolution_h

#include <algorithm>
#include "Types.h"

using std::max;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** http://leetcode.com/onlinejudge#question_110
 * Given a binary tree, determine if it is height-balanced. 
 * For this problem, a height-balanced binary tree is defined as a binary 
 * tree in which the height of the two subtrees of every node never differ 
 * by more than 1.
 */
class BalancedBinaryTreeSolution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return true;
        int depth = 0;
        return isBalancedRecursive(root, depth);
    }
    bool isBalancedRecursive(TreeNode *root, int &depth) {
        int leftDepth = depth + 1, rightDepth = depth + 1;
        bool left = root->left ? isBalancedRecursive(root->left, leftDepth) : true;
        if (!left)
            return false;
        bool right = root->right ? isBalancedRecursive(root->right, rightDepth) : true;
        depth = max(leftDepth, rightDepth);
        return right && (abs(rightDepth-leftDepth) <= 1);
    }
};

#endif
