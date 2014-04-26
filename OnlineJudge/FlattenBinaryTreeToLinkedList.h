//
//  FlattenBinaryTreeToLinkedList.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_FlattenBinaryTreeToLinkedList_h
#define OnlineJudge_FlattenBinaryTreeToLinkedList_h

/** Definition for binary tree
 *
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

/** http://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Given a binary tree, flatten it to a linked list in-place. For example,
 * Given
     1
    / \
   2   5
  / \   \
 3   4   6
 * The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 * Hints: If you notice carefully in the flattened tree, each node's right 
 * child points to the next node of a pre-order traversal.
 */
class FlattenBinaryTreeToLinkedListSolution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode * node = s.top();
            s.pop();
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
            
            if (!s.empty()) {
                node->right = s.top();
                node->left = nullptr;
            }
        }
    }
    
    // Recursive solution
    void flattenRecursive(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        flatten(root->left);
        flatten(root->right);
        if (root->left == nullptr) {
            return;
        }
        
        TreeNode * tail = root->left;
        while (tail->right) {
            tail = tail->right;
        }
        tail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};

#endif
