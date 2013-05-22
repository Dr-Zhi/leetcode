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

/** http://leetcode.com/onlinejudge#question_21
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */
class MergeTwoSortedListsSolution {
public:
    ListNode *mergeTwoLists(ListNode * l1, ListNode * l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * pNewHead = getSmallerNode(l1, l2);
        ListNode * pCurrent = pNewHead;
        while (l1 || l2) {
            (pCurrent == l1) ? (l1 = l1->next) : (l2 = l2->next);
            pCurrent->next = getSmallerNode(l1, l2);
            pCurrent = pCurrent->next;
        }
        return pNewHead;
    }
    
private:
    inline ListNode * getSmallerNode(ListNode * l1, ListNode * l2) {
        if (l1 && l2) {
            return l1->val < l2->val ? l1 : l2;
        }
        return l1 ? l1 : l2;
    }
};



#endif
