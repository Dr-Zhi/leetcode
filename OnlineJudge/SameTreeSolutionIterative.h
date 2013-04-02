//
//  SameTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SameTreeSolution_h
#define OnlineJudge_SameTreeSolution_h

#include <stack>

using std::stack;

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
 * This is an iterative (non-recursive) algorithm. 
 */
class SameTreeSolution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode *> pStack, qStack;
        pStack.push(p); qStack.push(q);
        // preorder traversal for the two trees
        while (!pStack.empty() && !qStack.empty()) {
            p = pStack.top(); pStack.pop();
            q = qStack.top(); qStack.pop();
            if (p && q && p->val == q->val) {
                pStack.push(p->right), pStack.push(p->left);
                qStack.push(q->right), qStack.push(q->left);
            }
            else if (p == NULL && q == NULL) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

#endif
