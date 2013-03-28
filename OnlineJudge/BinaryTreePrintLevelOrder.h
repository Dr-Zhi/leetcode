//
//  BinaryTreePrintLevelOrder.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/27/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreePrintLevelOrder_h
#define OnlineJudge_BinaryTreePrintLevelOrder_h

#include <queue>
#include <iostream>

using std::queue;
using std::cout;
using std::endl;

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

/**  A modified version of http://leetcode.com/onlinejudge#question_102
 * Given a binary tree, print the level order traversal of its nodes' 
 * values. (ie, from left to right, level by level). For example: given a 
 * binary tree {3,9,20,#,#,15,7},
       3
      / \
     9  20
    /    \
   15     7
 * print its level order traversal as:
   3    9    20    15    7
 */
class BinaryTreeLevelOrderTraversal {
public:
    void printLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> nodes;
        if (root) {
            nodes.push(root);
        }
        while (!nodes.empty()) {
            TreeNode * pNode = nodes.front();
            nodes.pop();
            std::cout << pNode->val << "\t";
            if (pNode->left) {
                nodes.push(pNode->left);
            }
            if (pNode->right) {
                nodes.push(pNode->right);
            }
        }
    }
};


#endif
