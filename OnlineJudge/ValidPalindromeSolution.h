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

using std::string;

/**
 * http://oj.leetcode.com/problems/valid-palindrome/
 * Valid Palindrome
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases. For example, "A man, a plan, 
 * a canal: Panama" is a palindrome. "race a car" is not a palindrome.
 * Note: Have you consider that the string might be empty? This is a good
 * question to ask during an interview. For the purpose of this problem, we
 * define empty string as valid palindrome.
 */
class ValidPalindromeSolution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!isalnum(*left)) ++left;
            else if (!isalnum(*right)) --right;
            else {
                if (tolower(*left) != tolower(*right))
                    return false;
                ++left, --right;
            }
        }
        
        return true;
    }
};


#endif
