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

/** http://leetcode.com/onlinejudge#question_107
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> level;
        vector<TreeNode *> nodes, nextNodes;
        if (root) {
            nodes.push_back(root);
        }
        while (!nodes.empty()) {
            for (int i = 0; i < nodes.size(); ++i) {
                TreeNode * node = nodes[i];
                level.push_back(node->val);
                if (node->left)
                    nextNodes.push_back(node->left);
                if (node->right)
                    nextNodes.push_back(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(nodes, nextNodes);
            nextNodes.clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif
