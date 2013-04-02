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

/** http://leetcode.com/onlinejudge#question_103
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rows;
        if (root == NULL) {
            return rows;
        }
        
        vector<TreeNode *> curLevel(1, root);
        vector<TreeNode *> nextLevel;
        vector<int> curRow;
        bool isLeftToRight = true;
        while (!curLevel.empty()) {
            for (size_t i = 0; i < curLevel.size(); ++i) {
                TreeNode * pNode = curLevel[i];
                curRow.push_back(pNode->val);
                if (isLeftToRight) {
                    if (pNode->left) {
                        nextLevel.push_back(pNode->left);
                    }
                    if (pNode->right) {
                        nextLevel.push_back(pNode->right);
                    }
                }
                else {
                    if (pNode->right) {
                        nextLevel.push_back(pNode->right);
                    }
                    if (pNode->left) {
                        nextLevel.push_back(pNode->left);
                    }
                }
            }
            rows.push_back(curRow);
            curRow.clear();
            curLevel.clear();
            reverse(nextLevel.begin(), nextLevel.end());
            swap(curLevel, nextLevel);
            isLeftToRight = !isLeftToRight;
        }
        
        return rows;
    }
};

#endif
