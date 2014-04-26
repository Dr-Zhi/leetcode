//
//  LongestCommonPrefixSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/26/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LongestCommonPrefixSolution_h
#define OnlineJudge_LongestCommonPrefixSolution_h

/** http://oj.leetcode.com/problems/longest-common-prefix/
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 */
class LongestCommonPrefixSolution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        
        for (int len = 0; len < strs[0].size(); ++len) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].size() <= len || strs[i][len] != strs[0][len]) {
                    return strs[0].substr(0, len);
                }
            }
        }
        return strs[0];
    }
};

#endif
