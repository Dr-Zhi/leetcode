//
//  BinaryTreePreorderTraversalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/23/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreePreorderTraversalSolution_h
#define OnlineJudge_BinaryTreePreorderTraversalSolution_h

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * For example: given binary tree {1,#,2,3},
 * 1
 *  \
 *   2
 *  /
 * 3
 * return [1,2,3].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
class BinaryTreePreorderTraversalSolution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        if (root) {
            s.push(root);
        }
        while (!s.empty()) {
            TreeNode * node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return result;
    }
};

//private:
//    void preorderTraversalInternal(TreeNode * root, vector<int> & result) {
//        if (!root) {
//            return;
//        }
//        result.push_back(root->val);
//        preorderTraversalInternal(root->left, result);
//        preorderTraversalInternal(root->right, result);
//    }
};

#endif
