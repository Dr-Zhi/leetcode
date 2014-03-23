//
//  DecodeWaysSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/23/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_DecodeWaysSolution_h
#define OnlineJudge_DecodeWaysSolution_h

/** http://oj.leetcode.com/problems/decode-ways/
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of 
 * ways to decode it. For example, given encoded message "12", it could be
 * decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.
 *
 * Notes: dynamic programming.
 */
class DecodeWaysSolution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        
        int prev = 0, cur = 1, tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i]))
                return 0;
            
            if (s[i] == '0') {
                if (i < 1 || s[i-1] > '2')
                    return 0;
                cur = 0;
            }
            
            if (i < 1 || !(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))) {
                prev = 0;
            }
            tmp = cur;
            cur += prev;
            prev = tmp;
        }
        return cur;
    }
};

#endif
