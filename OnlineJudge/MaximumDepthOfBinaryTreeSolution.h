//
//  MaximumDepthOfBinaryTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include <algorithm>

using std::max;

#ifndef OnlineJudge_MaximumDepthOfBinaryTreeSolution_h
#define OnlineJudge_MaximumDepthOfBinaryTreeSolution_h

/**
 * Definition for binary tree
 *
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() { // destroy subtrees, assume they are allocated by new
        delete left;
        delete right;
    }
};
*/

/** http://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 * Given a binary tree, find its maximum depth. The maximum depth is the 
 * number of nodes along the longest path from the root node down to the
 * farthest leaf node.
 */
class MaximumDepthOfBinaryTreeSolution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


#endif
