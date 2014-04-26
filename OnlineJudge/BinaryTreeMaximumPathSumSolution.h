//
//  BinaryTreeMaximumPathSumSolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 1/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_BinaryTreeMaximumPathSumSolution_h
#define LeetCode_Solutions_BinaryTreeMaximumPathSumSolution_h

#include <algorithm>

using std::max;

/**
 * Definition for binary tree
 *
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */

/** http://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 * Given a binary tree, find the maximum path sum. The path may start and
 * end at any node in the tree. For example: Given the below binary tree,
 *     1
 *    / \
 *   2   3
 * return 6.
 */
class BinaryTreeMaximumPathSumSolution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
    
private:
    int maxPathSum(TreeNode * root, int & maxSum) {
        if (!root) {
            return 0;
        }
        
        int pathSum = root->val;
        int left = maxPathSum(root->left, maxSum);
        if (left > 0) {
            pathSum += left;
        }
        int right = maxPathSum(root->right, maxSum);
        if (right > 0) {
            pathSum += right;
        }
        maxSum = max(maxSum, pathSum);
        
        return root->val + max(0, max(left, right));
    }
};

#endif
