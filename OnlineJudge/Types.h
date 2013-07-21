//
//  Types.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/19/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_Types_h
#define OnlineJudge_Types_h

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/** Binary tree node.
 */
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


/** Binary tree node extended with parent node */
struct TreeNodeExtended {
    int val;
    TreeNodeExtended *left;
    TreeNodeExtended *right;
    TreeNodeExtended *parent;
    TreeNodeExtended(int x) : val(x), left(NULL), right(NULL) {}
    TreeNodeExtended() { // destroy subtrees, assume they are allocated by new
        delete left;
        delete right;
    }
};

#endif
