//
//  LinkedListCycleSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/30/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LinkedListCycleSolution_h
#define OnlineJudge_LinkedListCycleSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/linked-list-cycle/
 * Given a linked list, determine if it has a cycle in it.
 * Follow up: can you solve it without using extra space?
 *
 * Use two pointers, one moving slow and another one faster. If there is cycle,
 * they will meet at some point, otherwise not.
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

#endif
