//
//  LinkedListCycleIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 11/2/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LinkedListCycleIISolution_h
#define OnlineJudge_LinkedListCycleIISolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** https://oj.leetcode.com/problems/linked-list-cycle-ii/
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 * 
 * Mathematical Deduction:
 * 2s = s + nr; => s = nr;
 * s = x + a; => x = nr - a;
 */
class LinkedListCycleIISolution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

#endif
