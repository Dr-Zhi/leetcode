//
//  BinaryTreeLevelOrderTraversalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/27/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreeLevelOrderTraversalSolution_h
#define OnlineJudge_BinaryTreeLevelOrderTraversalSolution_h

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

/**
 * Definition for binary tree
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

/** http://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 * Given a binary tree, return the level order traversal of its nodes' 
 * values. (ie, from left to right, level by level). For example: given a
 * binary tree {3,9,20,#,#,15,7},
       3
      / \
     9  20
    /    \
   15     7
 * return its level order traversal as:
   [
   [3],
   [9,20],
   [15,7]
   ]
 */
class BinaryTreeLevelOrderTraversalSolution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<TreeNode *> current, next;
        vector<int> level;
        if (root) {
            current.push_back(root);
        }
        while (!current.empty()) {
            for (TreeNode * node : current) {
                level.push_back(node->val);
                if (node->left) {
                    next.push_back(node->left);
                }
                if (node->right) {
                    next.push_back(node->right);
                }
            }
            result.push_back(level);
            level.clear();
            current.clear();
            swap(next, current);
        }
        return result;
    }
};

#endif
