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

/** http://oj.leetcode.com/problems/balanced-binary-tree/
 * Given a binary tree, determine if it is height-balanced. 
 * For this problem, a height-balanced binary tree is defined as a binary 
 * tree in which the height of the two subtrees of every node never differ 
 * by more than 1.
 */
class BalancedBinaryTreeSolution {
public:
    bool isBalanced(TreeNode *root) {
        return balancedHeight(root) >= 0;
    }
    
private:
    int balancedHeight(TreeNode * root) {
        if (!root) {
            return 0;
        }
        int left = balancedHeight(root->left);
        int right = balancedHeight(root->right);
        return (left < 0 || right < 0 || abs(left-right) > 1) ? -1 : (max(left, right) + 1);
    }
};
#endif
