//
//  BinaryTreeZigzagLevelOrderTraversalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/2/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreeZigzagLevelOrderTraversalSolution_h
#define OnlineJudge_BinaryTreeZigzagLevelOrderTraversalSolution_h

#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;
using std::swap;

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

/** http://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Given a binary tree, return the zigzag level order traversal of its 
 * nodes' values. (ie, from left to right, then right to left for the next
 * level and alternate between). For example: given binary tree,
       3
      / \
     9  20
    /     \
   15      7
 * return its zigzag level order traversal as:
   [
   [3],
   [20,9],
   [15,7]
   ]
 */
class BinaryTreeZigzagLevelOrderTraversalSolution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<TreeNode *> current, next;
        vector<int> level;
        vector<vector<int> > result;
        if (root) {
            current.push_back(root);
        }
        bool leftToRight = true;
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
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }
            leftToRight = !leftToRight;
            result.push_back(level);
            level.clear();
            current.clear();
            swap(current, next);
        }
        return result;
    }
};

#endif
