//
//  PopulatingNextRightPointersinEachNodeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/16/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PopulatingNextRightPointersinEachNodeSolution_h
#define OnlineJudge_PopulatingNextRightPointersinEachNodeSolution_h

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

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
 
 * Note: 
 * 1. You may only use constant extra space.
 * 2. You may assume that it is a perfect binary tree (ie, all leaves are at 
 * the same level, and every parent has two children). For example, Given the
 * following perfect binary tree,
 *     1
 *    /  \
 *   2    3
 *  / \  / \
 * 4   5 6  7
 * After calling your function, the tree should look like:
 *      1 -> NULL
 *    /   \
 *   2 ->  3 -> NULL
 *  / \   / \
 * 4->5->6-> 7 -> NULL
 */
class PolulatingNextRightPointersInEachNodeSolution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        // Assumption: perfect binary tree
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->right) {
            root->right->next = root->next ? root->next->left : NULL;
        }
        connect(root->right);
        connect(root->left);
    }
};

#endif
