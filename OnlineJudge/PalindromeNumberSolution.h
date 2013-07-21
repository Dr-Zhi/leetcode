//
//  PalindromeNumberSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PalindromeNumberSolution_h
#define OnlineJudge_PalindromeNumberSolution_h

/** http://leetcode.com/onlinejudge#question_9
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return false;
        int div = 10;
        while (x / div >= 10)
            div *= 10;
        int last, first;
        while (x >= 10) {
            last = x / div;
            first = x % 10;
            if (first != last)
                return false;
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
};

#endif
