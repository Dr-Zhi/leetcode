//
//  ConvertSortedListToBinarySearchTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/26/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ConvertSortedListToBinarySearchTreeSolution_h
#define OnlineJudge_ConvertSortedListToBinarySearchTreeSolution_h

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for binary tree
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

/** http://leetcode.com/onlinejudge#question_109
 * Given an array where elements are sorted in ascending order, convert it 
 * to a height balanced BST.
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 0;
        for (ListNode * node = head; node; node = node->next) {
            ++n;
        }
        ListNode * pCurNode = head;
        TreeNode * root = sortedListToBSTRecursive(pCurNode, 0, n);
        return root;
    }
    
private:
    TreeNode * sortedListToBSTRecursive(ListNode * & pCurNode,
                                        int startIndex, int endIndex) {
        if (startIndex >= endIndex) {
            return NULL;
        }
        int midIndex = startIndex + (endIndex-startIndex)/2;
        TreeNode * pLeft = sortedListToBSTRecursive(pCurNode,
                                                   startIndex, midIndex);
        TreeNode * root = new TreeNode(pCurNode->val);
        pCurNode = pCurNode->next;
        TreeNode * pRight = sortedListToBSTRecursive(pCurNode,
                                                     midIndex+1, endIndex);
        root->left = pLeft;
        root->right = pRight;
        return root;
    }
};

#endif
