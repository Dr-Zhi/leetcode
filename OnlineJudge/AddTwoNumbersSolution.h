//
//  AddTwoNumbersSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/18/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_AddTwoNumbersSolution_h
#define OnlineJudge_AddTwoNumbersSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/add-two-numbers/
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
class AddTwoNumbersSolution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2)
            return NULL;
        
        ListNode dummy(0);
        ListNode * cur = &dummy;
        int carry = 0, val1 = 0, val2 = 0, sum = 0;
        while (l1 || l2 || carry > 0) {
            val1 = (l1 ? l1->val : 0);
            l1 = (l1 ? l1->next : NULL);
            val2 = (l2 ? l2->val : 0);
            l2 = (l2 ? l2->next : NULL);
            sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy.next;
    }
};

#endif
