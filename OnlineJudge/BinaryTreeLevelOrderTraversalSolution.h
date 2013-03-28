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

/** http://leetcode.com/onlinejudge#question_102
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> curLevelNodes, nextLevelNodes;
        vector<vector<int> > rows;
        vector<int> curRow;
        if (root) {
            curLevelNodes.push_back(root);
        }
        while (!curLevelNodes.empty()) {
            for (size_t i = 0; i < curLevelNodes.size(); ++i) {
                TreeNode * pNode = curLevelNodes[i];
                curRow.push_back(pNode->val); // add the value
                // add children nodes to next row
                if (pNode->left) {
                    nextLevelNodes.push_back(pNode->left);
                }
                if (pNode->right) {
                    nextLevelNodes.push_back(pNode->right);
                }
            }
            rows.push_back(curRow);
            curRow.clear();
            curLevelNodes.clear();
            swap(nextLevelNodes, curLevelNodes); // specialization for vector
        }
        
        return rows;
    }
};

#endif
