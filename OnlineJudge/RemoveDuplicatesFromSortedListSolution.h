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

/** http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once. 
 * For example, given 1->1->2, return 1->2; given 1->1->2->3->3, 
 * return 1->2->3.
 *
 * Analysis: focus on the current pointer. Remove the next pointer if necessary.
 */
class RemoveDuplicatesFromSortedListSolution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode * cur = head, * tmp;
    while (cur) {
      if (cur->next && cur->next->val == cur->val) {
        tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
      }
      else {
        cur = cur->next;
      }
    }
    return head;
  }
};

#endif
