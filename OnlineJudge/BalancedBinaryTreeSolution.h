//
//  BalancedBinaryTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/25/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BalancedBinaryTreeSolution_h
#define OnlineJudge_BalancedBinaryTreeSolution_h

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isBalancedRecursive(root, 0);
    }
    
private:
    bool isBalancedRecursive(TreeNode * root, int depth) {
                
    }
};

#endif
