//
//  AnagramsSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/6/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_AnagramsSolution_h
#define OnlineJudge_AnagramsSolution_h

/**
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<int> > groups;
        for (int i = 0; i < groups.end(); ++i) {
            string s = groups[i];
            sort(s);
            groups[s].push_back(i);
        }
        vector<string> result;
        for (auto iter = groups.cbegin(); iter != groups.cend(); ++iter) {
            if ((iter->second).size() > 1) {
                for (auto i : iter->second) {
                    result.push_back(strs[i]);
                }
            }
        }
        
        return result;
    }
};

#endif
