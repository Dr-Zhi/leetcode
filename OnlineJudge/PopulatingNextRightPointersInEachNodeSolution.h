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

/** http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
 * 2. You may assume that it is a PERFECT binary tree (ie, all leaves are at 
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
class PopulatingNextRightPointersInEachNodeSolution {
public:
    void connect(TreeLinkNode *root) {
        // assumption: perfect binary tree
        TreeLinkNode *start = root;
        while (start) {
            TreeLinkNode *cur = start;
            while (cur && cur->left) {
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            start = start->left;
        }
    }
    
    // remove the perfect binary tree assumption.
    void connect_generic(TreeLinkNode *root) {
        TreeLinkNode dummy(0);
        TreeLinkNode * cur = root;
        while (cur) {
            dummy.next = NULL;
            TreeLinkNode * prev = &dummy;
            while (cur) {
                if (cur->left) {
                    prev->next = cur->left;
                    prev = prev->next;
                }
                if (cur->right) {
                    prev->next = cur->right;
                    prev = prev->next;
                }
                cur = cur->next;
            }
            cur = dummy.next;
        }
    }
};

#endif
