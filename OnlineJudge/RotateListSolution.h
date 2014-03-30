//
//  RotateListSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/30/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RotateListSolution_h
#define OnlineJudge_RotateListSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/rotate-list/
 * Given a list, rotate the list to the right by k places, where k is 
 * non-negative. For example: given 1->2->3->4->5->NULL and k = 2, return 
 * 4->5->1->2->3->NULL.
 *
 *
 */
class RotateListSolution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || k <= 0)
      return head;
    
    int n = 1;
    ListNode * cur = head;
    while (cur->next) {
      ++n;
      cur = cur->next;
    }
    
    k = n - k % n;
    cur->next = head; // form a cycle
    while ( k > 0) {
      --k;
      cur = cur->next;
    }
    head = cur->next; // new head
    cur->next = NULL; // break the cycle
    return head;
  }
};

#endif
