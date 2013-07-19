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

/** http://leetcode.com/onlinejudge#question_2
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0, v1, v2, value;
        ListNode *fakeHead = new ListNode(0), *cur = fakeHead;
        while (l1 || l2) {
            v1 = l1 ? l1->val : 0;
            v2 = l2 ? l2->val : 0;
            value = v1 + v2 + carry;
            carry = value / 10;
            cur->next = new ListNode(value % 10);
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0)
            cur->next = new ListNode(carry);
        ListNode * head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};

#endif
