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

/** http://leetcode.com/onlinejudge#question_104
 * Given a binary tree, find its maximum depth. The maximum depth is the 
 * number of nodes along the longest path from the root node down to the
 * farthest leaf node.
 */
class MaximumDepthOfBinaryTreeSolution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};


#endif
