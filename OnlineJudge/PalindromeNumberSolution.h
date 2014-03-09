//
//  PalindromeNumberSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PalindromeNumberSolution_h
#define OnlineJudge_PalindromeNumberSolution_h

/** http://oj.leetcode.com/problems/palindrome-number/
 * Determine whether an integer is a palindrome. Do this without extra 
 * space.
 * Some hints: could negative integers be palindromes? (ie, -1)
 * If you are thinking of converting the integer to string, note the 
 * restriction of using extra space.
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might 
 * overflow. How would you handle such case?
 
 * There is a more generic way of solving this problem.
 */
class PalindromeNumberSolution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int divisor = 1;
        while (x / divisor >= 10) {
            divisor *= 10;
        }
        int high, low;
        while (x > 0) {
            high = x / divisor;
            low = x % 10;
            if (high != low)
                return false;
            x = x % divisor / 10;
            divisor /= 100;
        }
        return true;
    }
};

#endif
