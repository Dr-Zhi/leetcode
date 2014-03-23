//
//  ReverseIntegerSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/18/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ReverseIntegerSolution_h
#define OnlineJudge_ReverseIntegerSolution_h

/** http://oj.leetcode.com/problems/reverse-integer/
 * Reverse digits of an integer. 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 
 * Have you thought about this? Here are some good questions to ask before 
 * coding. Bonus points for you if you have already thought through this!
 * If the integer's last digit is 0, what should the output be? ie, cases 
 * such as 10, 100.
 * Did you notice that the reversed integer might overflow? Assume the 
 * input is a 32-bit integer, then the reverse of 1000000003 overflows. 
 * How should you handle such cases? Throw an exception? Good, but what if
 * throwing an exception is not an option? You would then have to re-design
 * the function (ie, add an extra parameter).
 *
 * The sign of modulo is the same as the dividend.
 */
class ReverseIntegerSolution {
public:
    int reverse(int x) {
        int result = 0;
        for (; x != 0; x /= 10) {
            result = result * 10 + x % 10;
        }
        return result;
    }
};

#endif
