//
//  RemoveDuplicatesFromSortedListSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveDuplicatesFromSortedListSolution_h
#define OnlineJudge_RemoveDuplicatesFromSortedListSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://leetcode.com/onlinejudge#question_83
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once. 
 * For example, given 1->1->2, return 1->2; given 1->1->2->3->3, 
 * return 1->2->3.
 */
class RemoveDuplicatesFromSortedListSolution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
            return NULL;
        ListNode *prev = head, *cur = head->next;
        int value = head->val;
        while (cur) {
            if(cur->val == value)
                prev->next = cur->next;
            else {
                value = cur->val;
                prev = cur;
            }
            cur = prev->next;
        }
        return head;
    }
};

#endif
