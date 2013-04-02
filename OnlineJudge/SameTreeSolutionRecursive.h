//
//  SameTreeSolutionRecursive.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SameTreeSolutionRecursive_h
#define OnlineJudge_SameTreeSolutionRecursive_h

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

/** http://leetcode.com/onlinejudge#question_100
 * Given two binary trees, write a function to check if they are equal or
 * not. Two binary trees are considered equal if they are structurally
 * identical and the nodes have the same value.
 * This is a recursive version.
 */
class SameTreeSolutionRecursive {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isSameTreeRecursive(p, q);
    }
    
private:
    bool isSameTreeRecursive(TreeNode * p, TreeNode * q) {
        if (p == NULL || q == NULL) {
            return p == q; // if the same, both must be NULL
        }
        if (p->val != q->val) {
            return false;
        }
        return (isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};


#endif
