//
//  SqrtSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/2/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SqrtSolution_h
#define OnlineJudge_SqrtSolution_h

/** http://oj.leetcode.com/problems/sqrtx/
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 */
class SqrtSolution {
public:
    int sqrt(int x) {
        if (x < 2)
            return x;
        int left = 1, right = x/2, mid, div, last_mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            div = x / mid;
            if ( div > mid) {
                left = mid + 1;
                last_mid = mid;
            }
            else if (div < mid) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return last_mid;
    }
};

#endif
