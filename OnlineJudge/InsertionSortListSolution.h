//
//  InsertionSortListSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/12/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_InsertionSortListSolution_h
#define OnlineJudge_InsertionSortListSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/insertion-sort-list/
 * Sort a linked list using insertion sort.
 *
 * Insertion sort is O(n^2).
 */
class InsertionSortListSolution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        for (ListNode * cur = head; cur != NULL;) {
            ListNode * pos = findInsertPosition(&dummy, cur->val);
            ListNode * tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
    
private:
    ListNode * findInsertPosition(ListNode * head, int value) {
        ListNode * prev = NULL, * cur = head;
        while (cur && cur->val <= value) {
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }
};


#endif
