//
//  RemoveDuplicatesFromSortedListIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/29/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RemoveDuplicatesFromSortedListIISolution_h
#define OnlineJudge_RemoveDuplicatesFromSortedListIISolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 * For example, given 1->2->3->3->4->4->5, return 1->2->5; given 1->1->1->2->3, 
 * return 2->3.
 */
class RemoveDuplicatesFromSortedListIISolution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode * cur = head, * prev = &dummyHead;
    bool duplicated = false;
    while (cur && cur->next) {
      if(cur->val == cur->next->val) {
        duplicated = true;
        cur = removeCurrent(prev, cur);
      }
      else if (duplicated) {
        cur = removeCurrent(prev, cur);
        duplicated = false;
      }
      else {
        prev = cur;
        cur = cur->next;
      }    
    }
    if (duplicated) {
      removeCurrent(prev, cur);
    }
    return dummyHead.next;
  }
  
  inline ListNode * removeCurrent(ListNode * prev, ListNode * cur) {
    if (prev == NULL || cur == NULL)
      return NULL;
    prev->next = cur->next;
    delete cur;
    return prev->next;
  }
};

#endif
