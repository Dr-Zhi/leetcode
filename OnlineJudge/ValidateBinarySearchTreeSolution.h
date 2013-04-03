//
//  ValidateBinarySearchTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/3/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ValidateBinarySearchTreeSolution_h
#define OnlineJudge_ValidateBinarySearchTreeSolution_h

#include <climits>

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

/** http://leetcode.com/onlinejudge#question_98
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * 1. The left subtree of a node contains only nodes with keys less than
 * the node's key.
 * 2. The right subtree of a node contains only nodes with keys greater
 * than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */
class ValidateBinarySearchTreeSolution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValidBSTRecursive(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBSTRecursive(TreeNode * root, int lower, int upper) {
        if (root == NULL) {
            return true;
        }
        if (root->val > lower && root->val < upper) {
            return (isValidBSTRecursive(root->left, lower, root->val) &&
                    isValidBSTRecursive(root->right, root->val, upper));
        }
        return false;
    }
};

#endif
