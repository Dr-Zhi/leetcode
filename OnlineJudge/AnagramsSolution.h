//
//  AnagramsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/6/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_AnagramsSolution_h
#define OnlineJudge_AnagramsSolution_h

/** http://oj.leetcode.com/problems/anagrams/
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.
 * 
 * Analysis: use a hash map.
 */
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > groups;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            groups[s].push_back(strs[i]);
        }
        vector<string> result;
        for (auto iter = groups.cbegin(); iter != groups.cend(); ++iter) {
            if ((iter->second).size() > 1) {
                result.insert(result.end(), iter->second.begin(), iter->second.end());
            }
        }
        
        return result;
    }
};

#endif
