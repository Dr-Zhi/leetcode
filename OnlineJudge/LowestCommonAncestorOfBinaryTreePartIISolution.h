//
//  LowestCommonAncestorOfBinaryTreePartIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/18/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LowestCommonAncestorOfBinaryTreePartIISolution_h
#define OnlineJudge_LowestCommonAncestorOfBinaryTreePartIISolution_h

#include<algorithm>

using std::swap;

/** Binary tree node extended with parent node */
struct TreeNodeExtended {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() { // destroy subtrees, assume they are allocated by new
        delete left;
        delete right;
    }
};

int getHeight(TreeNodeExtended *p) {
    int height = 0;
    while (p) {
        ++height;
        p = p->parent;
    }
    return height;
}

/** http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-ii.html
 * Given a binary tree, find the lowest common ancestor of two given nodes
 * in the tree. Each node contains a parent pointer which links to its
 * parent.
 *
 * A variation of this problem which seemed to be more popular is:
 * Given two singly linked lists and they both intersect at one point
 * (ie, forming a Y shaped list). Find where the two linked lists merge.
 *
 * Lesson learnt! - how to clean the code:
 * 1. make duplicated code a subroutine 
 * 2. remove (reuse) duplicated code inside a method
 * 3. swap some variables for convenience
 */
TreeNodeExtended * LowestCommonAncestor(TreeNodeExtended *p, TreeNodeExtended *q) {
    int h1 = getHeight(p), h2 = getHeight(q);
    if (h1 < h2) {
        swap(h1, h2);
        swap(p, q);
    }
    // invariant: h1 >= h2
    int diff = h1 - h2;
    while (diff > 0) {
        p = p->parent;
        --diff;
    }
    while (p && q) {
        if (p == q)
            return p;
        p = p->parent;
        q = q->parent;
    }
    return NULL; // p and q are not in the same tree
}

#endif
