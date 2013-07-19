//
//  ReverseIntegerSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/18/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ReverseIntegerSolution_h
#define OnlineJudge_ReverseIntegerSolution_h

/** http://leetcode.com/onlinejudge#question_7
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
 */
class ReverseIntegerSolution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0, digit;
        while (x != 0) {
            digit = x % 10; // the sign of remainder
            x = x / 10;
            result = result * 10 + digit;
        }
        return result;
    }
};

#endif
