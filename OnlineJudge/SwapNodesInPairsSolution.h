//
//  SwapNodesInPairsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SwapNodesInPairsSolution_h
#define OnlineJudge_SwapNodesInPairsSolution_h

#include "Types.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://leetcode.com/onlinejudge#question_24
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example, given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the 
 * values in the list, only nodes itself can be changed.
 *
 * !Lesson Learnt:
 * after programming, simulate the execution process with a simple input.
 */
class SwapNodesInPairsSolution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        
        ListNode dummy(0);
        dummy.next = head;
        for (ListNode * prev = &dummy, * cur = head, * next = head->next; next;
             prev = cur, cur = cur->next, next = cur ? cur->next : nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};
#endif
