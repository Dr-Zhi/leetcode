//
//  BinaryTreeLevelOrderTraversalIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/28/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreeLevelOrderTraversalIISolution_h
#define OnlineJudge_BinaryTreeLevelOrderTraversalIISolution_h

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;
using std::swap;

/**
 * Definition for binary tree
 */
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

/** http://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to 
 * root). For example: given a binary tree {3,9,20,#,#,15,7},
       3
      / \
     9  20
    /    \
   15     7
 * return its bottom-up level order traversal as:
   [
   [15,7]
   [9,20],
   [3],
   ]
 */
class BinaryTreeLevelOrderTraversalIISolution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<TreeNode *> current, next;
        vector<int> level;
        vector<vector<int> > result;
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
            swap(current, next);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif
