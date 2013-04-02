//
//  SymmetricTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SymmetricTreeSolutionRecursive_h
#define OnlineJudge_SymmetricTreeSolutionRecursive_h

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

/** http://leetcode.com/onlinejudge#question_101
 * Given a binary tree, check whether it is a mirror of itself (ie, 
 * symmetric around its center). For example, this binary tree is
 * symmetric:
       1
      /  \
     2    2
    / \  / \
   3   4 4  3
 * But the following is not:
     1
    /  \
    2   2
    \    \
     3    3
 * Note: bonus points if you could solve it both recursively and 
 * iteratively.
 * This is a recursive version.
 */
class SymmetricTreeSolutionRecursive {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        return isSymmetricRecursive(root->left, root->right);
    }
    
private:
    bool isSymmetricRecursive(TreeNode * rootLeft, TreeNode * rootRight) {
        if (rootLeft == NULL || rootRight == NULL) {
            return rootLeft == rootRight; // symmetric if both == NULL
        }
        
        if (rootLeft->val != rootRight->val) {
            return false;
        }
        return (isSymmetricRecursive(rootLeft->left, rootRight->right) &&
                isSymmetricRecursive(rootLeft->right, rootRight->left));
    }
};


#endif
