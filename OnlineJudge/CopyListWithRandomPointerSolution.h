//
//  CopyListWithRandomPointerSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/21/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_CopyListWithRandomPointerSolution_h
#define OnlineJudge_CopyListWithRandomPointerSolution_h

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/** http://oj.leetcode.com/problems/copy-list-with-random-pointer/
 * A linked list is given such that each node contains an additional random 
 * pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 * Analysis:
 */
class CopyListWithRandomPointerSolution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode * cur = head; cur; cur = cur->next) {
            RandomListNode * copy = new RandomListNode(cur->label);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy;
        }
        
        for (RandomListNode * cur = head; cur; cur = cur->next->next) {
            cur->next->random = cur->random ? cur->random->next : NULL;
        }
        
        RandomListNode dummyHead(0);
        for (RandomListNode * cur = head, * copyCur = &dummyHead; cur; cur = cur->next) {
            copyCur->next = cur->next;
            copyCur = copyCur->next;
            cur->next = copyCur->next;
        }
        
        return dummyHead.next;
    }
};

#endif
