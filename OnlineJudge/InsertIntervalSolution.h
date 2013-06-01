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

/** http://leetcode.com/onlinejudge#question_57
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
 * References:
 * [1] http://fisherlei.blogspot.com/2012/12/leetcode-insert-interval.html
 */
class InsertIntervalSolution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval>::iterator iterRemoveStart = intervals.end(), iterRemoveEnd = intervals.end();
        for (vector<Interval>::iterator iter = intervals.begin();
             iter != intervals.end(); ++iter) {
            if (newInterval.end < iter->start) {
                if (iterRemoveStart == intervals.end()) {
                    intervals.insert(iter, newInterval);
                    return intervals;
                }
                else {
                    break;
                }
            }
            else if (newInterval.start > iter->end) {
                continue;
            }
            else { // has intersection
                newInterval.start = min(newInterval.start, iter->start);
                newInterval.end = max(newInterval.end, iter->end);
                if (iterRemoveStart == intervals.end()) {
                    iterRemoveEnd = iterRemoveStart = iter;
                }
                else {
                    iterRemoveEnd = iter;
                }
            }
        }
        if (iterRemoveStart != intervals.end()) {
            iterRemoveStart->start = newInterval.start;
            iterRemoveStart->end = newInterval.end;
            intervals.erase(++iterRemoveStart, ++iterRemoveEnd);
        }
        else {
            intervals.push_back(newInterval);
        }
        return intervals;
    }
};

#endif
