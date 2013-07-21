//
//  PowerXNSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 6/13/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PowerXNSolution_h
#define OnlineJudge_PowerXNSolution_h

/** http://leetcode.com/onlinejudge#question_50
 * Implement pow(x, n).
 */
class PowerOfXSolution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool isNegative = (n < 0);
        if (isNegative)  n = -n;
        double result = 1;
        while (n > 0) {
            if (n & 1) result *= x;
            x *= x;
            n = n >> 1;
        }
        if (isNegative)
            result = 1.0 / result;
        return result;
    }
};

#endif