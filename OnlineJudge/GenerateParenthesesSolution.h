//
//  GenerateParenthesesSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/22/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_GenerateParenthesesSolution_h
#define OnlineJudge_GenerateParenthesesSolution_h

/** http://oj.leetcode.com/problems/generate-parentheses/
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses. For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 * Analysis: ( + inner + ) + outer
 */
class GenerateParenthesesSolution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>(1, "");
        }
        
        if (n == 1) {
            return vector<string>(1, "()");
        }
        
        vector<string> result;
        for (int i = 0; i < n; ++i) {
            for (string inner : generateParenthesis(i)) {
                for (string outer : generateParenthesis(n-1-i)) {
                    result.push_back("(" + inner + ")" + outer);
                }
            }
        }
        return result;
    }
};

#endif
