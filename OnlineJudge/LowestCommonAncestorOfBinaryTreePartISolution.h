//
//  LowestCommonAncestorOfBinaryTreePartISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/19/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LowestCommonAncestorOfBinaryTreePartISolution_h
#define OnlineJudge_LowestCommonAncestorOfBinaryTreePartISolution_h

#include "Types.h"

/** http://leetcode.com/2011/07/lowest-common-ancestor-of-a-binary-tree-part-i.html
 * BOTTOM-UP approach (implemented recursively): 
 * Using a bottom-up approach, we can improve over the top-down approach by
 * avoiding traversing the same nodes over and over again.
 * We traverse from the bottom, and once we reach a node which matches one 
 * of the two nodes, we pass it up to its parent. The parent would then 
 * test its left and right subtree if each contain one of the two nodes.
 * If yes, then the parent must be the LCA and we pass its parent up to the
 * root. If not, we pass the lower node which contains either one of the 
 * two nodes (if the left or right subtree contains either p or q), or NULL
 * (if both the left and right subtree does not contain either p or q) up.
 *
 * Notes: The LCA problem had been studied extensively by many computer 
 * scientists. There exists efficient algorithms for finding LCA in 
 * constant time after initial processing of the tree in linear time. 
 * For the adventurous reader, please read this article for more details: 
 * http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=lowestCommonAncestor
 *
 * !Lessons learnt - bottom-up implementation:
 * It is hard to implement a bottom-up traversal for a binary tree 
 * intuitively. Think of a bottom-up traversal level by level. However, 
 * a recursive one can make this.
 */
TreeNodeExtended * LowestCommonAncestorPartI(TreeNodeExtended *root,
                                             TreeNodeExtended *p,
                                             TreeNodeExtended *q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    TreeNodeExtended * left = LowestCommonAncestorPartI(root->left, p, q);
    TreeNodeExtended * right = LowestCommonAncestorPartI(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}


#endif
