//
//  PopulatingNextRightPointersInEachNodeIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/16/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PopulatingNextRightPointersInEachNodeIISolution_h
#define OnlineJudge_PopulatingNextRightPointersInEachNodeIISolution_h

/**
 * Definition for binary tree with next pointer.

 struct TreeLinkNode {
     int val;
     TreeLinkNode *left, *right, *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 */

/** http://leetcode.com/onlinejudge#question_116
 * Given a binary tree
 * struct TreeLinkNode {
 *   TreeLinkNode *left;
 *   TreeLinkNode *right;
 *   TreeLinkNode *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL. Initially, all next
 * pointers are set to NULL.
 * For example, Given the following perfect binary tree,
 *     1
 *    /  \
 *   2    3
 *  / \    \
 * 4   5    7
 * After calling your function, the tree should look like:
 *      1 -> NULL
 *    /   \
 *   2 ->  3 -> NULL
 *  / \     \
 * 4-> 5 ->  7 -> NULL
 
 * Note:
 * 1. You may only use constant extra space.
 * 2. The binary tree may be any tree. 
 */
class PopulatingNextRightPointersInEachNodeIISolution {
public:    
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *start = root;
        while (start) {
            TreeLinkNode *node = start, *prev = NULL;
            start = NULL;
            while (node) {
                prev = connectChild(node->left, prev);
                prev = connectChild(node->right, prev);
                if (!start) // update next start
                    start = node->left ? node->left : node->right;
                node = node->next;
            }
        }
    }
    /** connect current node with previous node */
    TreeLinkNode * connectChild(TreeLinkNode *cur, TreeLinkNode *prev) {
        if (!cur)
            return prev;
        if (prev)
            prev->next = cur;
        return cur;
    }
};

//        if (root == NULL || (root->left == NULL && root->right == NULL)) {
//            return;
//        }
//        TreeLinkNode * lpRightNextSibling = findRightNextSibling(root->next);
//        if (root->right) {
//           root->right->next = lpRightNextSibling;
//        }
//        if (root->left) {
//            root->left->next = root->right ? root->right : lpRightNextSibling;
//        }
//        
//        connect(root->right);
//        connect(root->left);
//    }
//
//    /// find the right next sibling
//    inline TreeLinkNode * findRightNextSibling(TreeLinkNode * node) {
//        while (node) {
//            if (node->left) {
//                return node->left;
//            }
//            if (node->right) {
//                return node->right;
//            }
//            node = node->next;
//        }
//        return NULL;
//    }
//};


#endif
