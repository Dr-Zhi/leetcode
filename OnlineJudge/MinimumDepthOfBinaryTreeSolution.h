//
//  MinimumDepthOfBinaryTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/24/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MinimumDepthOfBinaryTreeSolution_h
#define OnlineJudge_MinimumDepthOfBinaryTreeSolution_h

using std::min;

/**
 * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

/** http://leetcode.com/onlinejudge#question_111
 * Given a binary tree, find its minimum depth. The minimum depth is the
 * number of nodes along the shortest path from the root node down to the 
 * nearest leaf node.
 */
class MinimumDepthOfBinaryTreeSolution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }
        
        if (root->left==NULL && root->right==NULL) { // leaf node
            return 1;
        }
        
        int left = INT_MAX, right = INT_MAX;
        if (root->left) {
            left = minDepth(root->left);
        }
        if (root->right) {
            right = minDepth(root->right);
        }
        return min(left, right) + 1;
    }
};

#endif
