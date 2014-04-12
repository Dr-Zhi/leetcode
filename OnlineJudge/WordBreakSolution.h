//
//  WordBreakSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/12/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_WordBreakSolution_h
#define OnlineJudge_WordBreakSolution_h

/** http://oj.leetcode.com/problems/word-break/
 * Given a string s and a dictionary of words dict, determine if s can be 
 * segmented into a space-separated sequence of one or more dictionary words.
 * For example, given s = "leetcode", dict = ["leet", "code"]. 
 * Return true because "leetcode" can be segmented as "leet code".
 *
 * Analysis: use dynamic programming. Let state f(i) denote s[0, i) can be
 * segmented into words. Then f(i) = \exist j s.t. f(j) && s[j, i) \in dict.
 * Note that initial state f(0) = true.
 */
class WordBreakSolution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> f(n+1, false);
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >= 0 && !f[i]; --j) {
                f[i] = (f[j] && dict.find(s.substr(j, i-j)) != dict.end());
            }
        }
        return f[n];
    }
};

#endif
