//
//  BinaryTreePostorderTraversalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/23/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_BinaryTreePostorderTraversalSolution_h
#define OnlineJudge_BinaryTreePostorderTraversalSolution_h

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * For example: given binary tree {1,#,2,3},
 * 1
 *  \
 *   2
 *  /
 * 3
 * return [3,2,1].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
 */
class BinaryTreePostorderTraversalSolution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<const TreeNode *> s;
        if (root) {
            s.push(root);
        }
        while (!s.empty()) {
            const TreeNode * cur = s.top();
            s.pop();
            result.push_back(cur->val);
            if (cur->left) {
                s.push(cur->left);
            }
            if (cur->right) {
                s.push(cur->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
//private:
//    void postorderTraversalInternal(TreeNode * root, vector<int> & result) {
//        if (!root) {
//            return;
//        }
//        
//        if (root->left) {
//            postorderTraversalInternal(root->left, result);
//        }
//        if (root->right) {
//            postorderTraversalInternal(root->right, result);
//        }
//        result.push_back(root->val);
//    }
};


#endif
