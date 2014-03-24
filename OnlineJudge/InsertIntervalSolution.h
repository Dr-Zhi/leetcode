//
//  InsertIntervalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 6/1/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_InsertIntervalSolution_h
#define OnlineJudge_InsertIntervalSolution_h

#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/** http://oj.leetcode.com/problems/insert-interval/
 * Given a set of non-overlapping intervals, insert a new interval into
 * the intervals (merge if necessary). You may assume that the intervals 
 * were initially sorted according to their start times.
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as 
 * [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 * Algorithms in two steps.
 * Step 1: calculate the merged interval
 * Step 2: erase the overlapped intervals, and insert the merged interval
 */
class InsertIntervalSolution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto iter = intervals.begin(), first = intervals.end(), last = intervals.end();
        while (iter != intervals.end()) {
            if (iter->start > newInterval.end) {
                break;
            }
            else if (iter->end < newInterval.start) {
                ++iter;
            }
            else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                if (first == intervals.end()) {
                    first = iter;
                }
                last = ++iter;
            }
        }
        if (first != intervals.end()) {
            iter = intervals.erase(first, last);
        }
        intervals.insert(iter, newInterval);
        return intervals;
    }
    
    // a simple version but has a complexity of O(n^2) in worst case
    vector<Interval> insert_(vector<Interval> &intervals, Interval newInterval) {
        auto iter = intervals.begin();
        while (iter != intervals.end()) {
            if (iter->start > newInterval.end) {
                intervals.insert(iter, newInterval);
                return intervals;
            }
            else if (iter->end < newInterval.start) {
                ++iter;
                continue;
            }
            else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                iter = intervals.erase(iter);
            }
        }
        intervals.insert(iter, newInterval);
        return intervals;
    }
};
    


#endif
