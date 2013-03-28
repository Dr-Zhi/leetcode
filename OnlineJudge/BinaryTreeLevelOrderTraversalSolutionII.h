//
//  BinaryTreeLevelOrderTraversalSolutionII.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/27/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreeLevelOrderTraversalSolutionII_h
#define OnlineJudge_BinaryTreeLevelOrderTraversalSolutionII_h

#include <queue>

using std::queue;

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

/** http://leetcode.com/onlinejudge#question_102
 * This is another solution by Dr. Zhi: using only one single queue. 
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
class BinaryTreeLevelOrderTraversalSolutionII {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> nodes;
        int nCurRowNodes = 0, nNextRowNodes = 0;
        vector<vector<int> > rows;
        vector<int> curRow;
        if (root) {
            nodes.push(root);
            ++nCurRowNodes;
        }
        while (!nodes.empty()) {
            TreeNode * pNode = nodes.front();
            nodes.pop();
            --nCurRowNodes;
            curRow.push_back(pNode->val);
            if (pNode->left) {
                nodes.push(pNode->left);
                ++nNextRowNodes;
            }
            if (pNode->right) {
                nodes.push(pNode->right);
                ++nNextRowNodes;
            }
            if (nCurRowNodes == 0) {
                rows.push_back(curRow);
                curRow.clear();
                nCurRowNodes = nNextRowNodes;
                nNextRowNodes = 0;
            }
        }
        
        return rows;
    }
};


#endif
