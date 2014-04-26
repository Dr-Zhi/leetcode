//
//  MergeKSortedListsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/26/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_MergeKSortedListsSolution_h
#define OnlineJudge_MergeKSortedListsSolution_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/merge-k-sorted-lists/
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Complexity: O(nlog(k)), where n is the number of all the elements.
 */
class MergeKSortedListsSolution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        while (n > 1) {
            for (int i = 0; i < (n >> 1); ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[n-1-i]);
            }
            n = (n+1) >> 1;
        }
        return lists.empty() ? nullptr : lists[0];
    }
    
private:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode dummy(-1);
        ListNode * cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else { // l1->val <= l2->val
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
