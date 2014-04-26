//
//  EvaluateReversePolishNotationSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/25/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_EvaluateReversePolishNotationSolution_h
#define OnlineJudge_EvaluateReversePolishNotationSolution_h

/** http://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another 
 * expression.
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
class EvaluateReversePolishNotationSolution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (!isOperator(token)) {
                s.push(atoi(token.c_str()));
                continue;
            }
            
            if (s.size() < 2) { // double check
                return 0;
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (token[0]) {
                case '+':
                    a += b; break;
                case '-':
                    a -= b; break;
                case '*':
                    a *= b; break;
                case '/':
                    a /= b; break;
                default:
                    break;
            }
            s.push(a);
        }
        return s.empty() ? 0 : s.top();
    }
    
private:
    bool isOperator(string token) {
        const static string operators("+-*/");
        return (token.size() == 1) && operators.find(token) != string::npos;
    }
};

#endif
