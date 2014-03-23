//
//  DistinctSubsequencesSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/23/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_DistinctSubsequencesSolution_h
#define OnlineJudge_DistinctSubsequencesSolution_h

/** http://oj.leetcode.com/problems/distinct-subsequences/
 * Given a string S and a string T, count the number of distinct subsequences
 * of T in S. A subsequence of a string is a new string which is formed from 
 * the original string by deleting some (can be none) of the characters without 
 * disturbing the relative positions of the remaining characters. (ie, "ACE"
 * is a subsequence of "ABCDE" while "AEC" is not).
 * Here is an example: 
 * S = "rabbbit", T = "rabbit", return 3.
 *
 * Analysis: dynamic programming with sliding array
 * Let f(i, j) represent # subsequence of T(0...j) in S(0...i). If S[i] == T[j],
 * then f(i, j) = f(i-1, j) + f(i-1, j-1). Otherwise, f(i, j) = f(i-1, j).
 * 
 */
class DistinctSubsequencesSolution {
public:
    int numDistinct(string S, string T) {
        vector<int> f(T.size() + 1, 0);
        f[0] = 1;
        
        for (int i = 0; i < S.size(); ++i) {
            for (int j = T.size() - 1; j >= 0; --j) {
                if (S[i] == T[j]) {
                    f[j+1] += f[j];
                }
            }
        }
        return f[T.size()];
    }
};
#endif
