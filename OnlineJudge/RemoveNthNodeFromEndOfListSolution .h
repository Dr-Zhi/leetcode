//
//  RemoveNthNodeFromEndOfListSolution .h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/30/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveNthNodeFromEndOfListSolution__h
#define OnlineJudge_RemoveNthNodeFromEndOfListSolution__h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Given a linked list, remove the nth node from the end of list and return 
 * its head. For example, given linked list: 1->2->3->4->5, and n = 2. After
 * removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * 1. Given n will always be valid.
 * Try to do this in one pass.
 */
class RemoveNthNodeFromEndOfListSolution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * slow = &dummy, * fast = &dummy;
        for (int i = 0; i <= n && fast; ++i) { // n+1 steps
            fast = fast->next;
        }
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode * tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy.next;
    }
};

#endif
