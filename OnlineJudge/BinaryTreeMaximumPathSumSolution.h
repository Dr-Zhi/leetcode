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

/**
 * http://leetcode.com/onlinejudge#question_124
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int globalMax = INT_MIN;
        maxPathSumRecursive(root, globalMax);
        return globalMax;
    }
    int maxPathSumRecursive(TreeNode *root,  int &globalMax) {
        if (!root) return 0;
        int left = maxPathSumRecursive(root->left, globalMax);
        int right = maxPathSumRecursive(root->right, globalMax);
        int localMax = root->val;
        if (left > 0)
            localMax += left;
        if (right > 0)
            localMax += right;
        if (globalMax < localMax)
            globalMax = localMax;
        return root->val + max(0, max(left, right));
    }
};

#endif
