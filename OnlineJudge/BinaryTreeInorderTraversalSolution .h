//
//  BinaryTreeInorderTraversalSolution .h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/23/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreeInorderTraversalSolution__h
#define OnlineJudge_BinaryTreeInorderTraversalSolution__h

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * For example: given binary tree {1,#,2,3},
 * 1
 *  \
 *   2
 *  /
 * 3
 * return [1,3,2].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode * cur = root;
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
    
//private:
//    void inorderTraversalInternal(TreeNode * root, vector<int> & result) {
//        if (!root) {
//            return;
//        }
//        
//        if (root->left) {
//            inorderTraversalInternal(root->left, result);
//        }
//        result.push_back(root->val);
//        if (root->right) {
//            inorderTraversalInternal(root->right, result);
//        }
//    }
};

#endif
