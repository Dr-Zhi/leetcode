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

/** http://oj.leetcode.com/problems/symmetric-tree/
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
        return root ? isSymmetricInternal(root->left, root->right) : true;
    }
    
private:
    bool isSymmetricInternal(TreeNode * left, TreeNode * right) {
        if (!left || !right) {
            return !left && !right;
        }
        return left->val == right->val &&
        isSymmetricInternal(left->left, right->right) &&
        isSymmetricInternal(left->right, right->left);
    }
};


#endif
