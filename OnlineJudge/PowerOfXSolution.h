//
//  PowerXNSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 6/13/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PowerXNSolution_h
#define OnlineJudge_PowerXNSolution_h

/** http://oj.leetcode.com/problems/powx-n/
 * Implement pow(x, n).
 *
 * Note: %2 == &0x1, /2 == >>1.
 */
class PowerOfXSolution {
public:
    double pow(double x, int n) {
        bool negative = (n < 0);
        if (negative)
            n = -n;
        double result = 1.0;
        while (n > 0) {
            if (n & 0x1)
                result *= x;
            x *= x;
            n = n >> 1;
        }
        
        if (negative)
            result = 1.0 / result;
        return result;
    }
};

#endif
