//
//  BalancedBinaryTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/25/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BalancedBinaryTreeSolution_h
#define OnlineJudge_BalancedBinaryTreeSolution_h

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
        int height = -1;
        return isBalancedRecursive(root, height);
    }
    
private:
    bool isBalancedRecursive(TreeNode * root, int & height) {
        if (root == NULL) {
            height = -1;
            return true;
        }
        int leftHeight = -1, rightHeight = -1;
        bool leftBalanced = (root->left == NULL) ||
                            isBalancedRecursive(root->left, leftHeight);
        if (leftBalanced == false) { // return early
            return false;
        }
        bool rightBalanced = (root->right == NULL) ||
                             isBalancedRecursive(root->right, rightHeight);
        if (rightBalanced == false) { // return early
            return false;
        }
        height = max(leftHeight, rightHeight) + 1;
        return leftBalanced && rightBalanced &&
               abs(leftHeight-rightHeight) <= 1;
    }
};

#endif
