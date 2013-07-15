//
//  ValidPalindromeSolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 1/22/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_ValidPalindromeSolution_h
#define LeetCode_Solutions_ValidPalindromeSolution_h

#include <string>

/**
 * http://leetcode.com/onlinejudge#question_125
 * Valid PalindromeJan
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases. For example, "A man, a plan, 
 * a canal: Panama" is a palindrome. "race a car" is not a palindrome.
 * Note: Have you consider that the string might be empty? This is a good
 * question to ask during an interview. For the purpose of this problem, we
 * define empty string as valid palindrome.
 */
class ValidPalindromeSolution {
public:
    bool isPalindrome(std::string s) {
        int i = 0, j = (int)s.size()-1;
        while(i < j) {
            while(!isalnum(s[i]) && i < j)
                ++i;
            while(!isalnum(s[j]) && j > i)
                --j;
            if(i >= j)
                break;
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i, --j;
        }
        return true;
    }
};


#endif
