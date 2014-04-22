//
//  ReverseLinkedListIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/22/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ReverseLinkedListIISolution_h
#define OnlineJudge_ReverseLinkedListIISolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/reverse-linked-list-ii/
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example: given 1->2->3->4->5->NULL, m = 2 and n = 4, return 
 * 1->4->3->2->5->NULL.
 * Note: given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
 *
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * prev = &dummy;
        for (int i = 0; i < m-1 && prev; ++i) {
            prev = prev->next;
        }
        
        if (prev == nullptr || prev->next == nullptr) {
            return head;
        }
        ListNode * prevHead = prev;
        prev = prev->next;
        ListNode * cur = prev->next;
        for (int i = m; i < n && cur; ++i) {
            prev->next = cur->next;
            cur->next = prevHead->next;
            prevHead->next = cur;
            cur = prev->next;
        }
        
        return dummy.next;
    }
};

#endif
