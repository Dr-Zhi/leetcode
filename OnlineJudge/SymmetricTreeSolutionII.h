//
//  SymmetricTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SymmetricTreeSolution_h
#define OnlineJudge_SymmetricTreeSolution_h

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
 * This is the iterative version.
 */
class SymmetricTreeSolutionII {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }

        stack<TreeNode *> nodes;
        retuk

    }
};


#endif
