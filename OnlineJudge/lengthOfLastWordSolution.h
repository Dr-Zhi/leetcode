//
//  lengthOfLastWordSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 6/1/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_lengthOfLastWordSolution_h
#define OnlineJudge_lengthOfLastWordSolution_h

/** http://leetcode.com/onlinejudge#question_58
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string. 
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space
 * characters only. For example, given s = "Hello World", return 5.
 *
 * Complexity: O(n).
 */
class lengthOfLastWordSolution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!s)
            return 0;
        int length = 0;
        while (*s) {
            while (isspace(*s))
                ++s;
            if (*s)
                length = 0;
            while (*s && !isspace(*s)){
                ++length, ++s;
            }
        }
        return length;
    }
};


#endif
