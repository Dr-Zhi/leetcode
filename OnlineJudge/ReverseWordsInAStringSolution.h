//
//  ReverseWordsInAStringSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 11/2/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ReverseWordsInAStringSolution_h
#define OnlineJudge_ReverseWordsInAStringSolution_h

/** https://oj.leetcode.com/problems/reverse-words-in-a-string/
 * Given an input string, reverse the string word by word.
 * For example, given s = "the sky is blue", return "blue is sky the".
 *
 * Clarification:
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 *
 * Ask before solving this problem:
 * What is the time complexity requirement? O(n)
 * What is the space complexity? O(n) or O(1) (in-place)?
 */
class ReverseWordsInAStringSolution {
public:
    void reverseWords(string &s) {
        removeRedundantSpaces(s);
        reverse(s.begin(), s.end());
        string::iterator start = s.begin();
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
            if (isspace(*iter)) {
                reverse(start, iter);
                start = iter;
                ++start;
            }
        }
        reverse(start, s.end());
    }
    
private:
    void removeRedundantSpaces(string &s) {
        const static char space = ' ';
        int current = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (!isspace(s[i])) {
                s[current++] = s[i];
            }
            else if (current != 0 && !isspace(s[current-1])) {
                s[current++] = space;
            }
        }
        if (current > 0 && s[current-1] == space) {
            --current;
        }
        s.erase(current);
    }
};

#endif
