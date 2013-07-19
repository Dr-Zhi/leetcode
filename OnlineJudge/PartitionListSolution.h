//
//  PartitionListSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/18/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PartitionListSolution_h
#define OnlineJudge_PartitionListSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://leetcode.com/onlinejudge#question_86
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x. You should preserve
 * the original relative order of the nodes in each of the two partitions.
 * For example, given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
 */
class PartitionListSolution {
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * left = new ListNode(0), * right = new ListNode(0);
        ListNode * leftLast = left, * rightLast = right, * cur = head;
        while (cur) {
            if (cur->val < x) {
                leftLast->next = cur;
                leftLast = leftLast->next;
            }
            else {
                rightLast->next = cur;
                rightLast = rightLast->next;
            }
            cur = cur->next;
        }
        rightLast->next = NULL;
        leftLast->next = right->next;
        head = left->next;
        delete left;
        delete right;
        return head;
    };
};

#endif
