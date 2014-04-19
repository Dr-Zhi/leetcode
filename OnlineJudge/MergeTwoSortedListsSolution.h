//
//  MergeTwoSortedListsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 5/16/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MergeTwoSortedListsSolution_h
#define OnlineJudge_MergeTwoSortedListsSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/merge-two-sorted-lists/
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */
class MergeTwoSortedListsSolution {
public:
    ListNode *mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode dummy(0);
        ListNode * cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 ? l1 : l2);
        return dummy.next;
    }
};

#endif
