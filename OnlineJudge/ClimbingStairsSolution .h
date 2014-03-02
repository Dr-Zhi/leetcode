//
//  ClimbingStairsSolution .h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/1/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ClimbingStairsSolution__h
#define OnlineJudge_ClimbingStairsSolution__h

#include <cmath>

/** http://oj.leetcode.com/problems/climbing-stairs/
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways 
 * can you climb to the top?
 * Induction: f(n) = f(n-1) + f(n-2), with f(1) = 1, f(2) = 2. 
 * => equivalent to solve: given an n, solve f(n+1).
 *
 * Fibonacci series: f(0) = 0, f(1) = 1.
 * Ref: http://en.wikipedia.org/wiki/Fibonacci_number
 */
class ClimbingStairsSolution {
public:
    int climbStairs(int n) {
        if (n < 0)
            return 0;
        int prev = 1, cur = 1, temp;
        for (int i = 2; i <= n; ++i) {
            temp = cur;
            cur += prev;
            prev = temp;
        }
        return cur;
    }
    
    // Formula method
    int climbStairsFormulaMethod(int n) {
        if (n < 0)
            return 0;
        ++n;
        const double s = sqrt(5);
        return round((pow((1+s)/2, n) - pow((1-s)/2, n)) / s);
    }
};


#endif
