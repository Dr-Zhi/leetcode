//
//  ValidParenthesesSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/25/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ValidParenthesesSolution_h
#define OnlineJudge_ValidParenthesesSolution_h

/** http://oj.leetcode.com/problems/valid-parentheses/
 * Given a string containing just the characters '(', ')', '{', '}', '[' 
 * and ']', determine if the input string is valid. The brackets must close in
 * the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are 
 * not.
 *
 * Analysis: using a LIFO stack.
 */
class ValidParenthesesSolution {
    public:
        bool isValid(string s) {
            const string left = "([{";
            const string right = ")]}";
            stack<char> stk;
            for (auto c : s) {
                if (left.find(c) != string::npos) {
                    stk.push(c);
                }
                else {
                    int idx = right.find(c);
                    if (idx != string::npos) {
                        if (stk.empty() || stk.top() != left[idx]) {
                            return false;
                        }
                        stk.pop();
                    }
                }
            }
            return stk.empty();
        }
};

#endif
