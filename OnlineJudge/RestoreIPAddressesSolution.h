//
//  RestoreIPAddressesSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 9/4/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_RestoreIPAddressesSolution_h
#define OnlineJudge_RestoreIPAddressesSolution_h

#include <vector>
#include <string>

using std::vector;
using std::string;

/** http://oj.leetcode.com/problems/restore-ip-addresses/
 * Given a string containing only digits, restore it by returning all 
 * possible valid IP address combinations.
 * For example: given "25525511135", return ["255.255.11.135", 
 * "255.255.111.35"]. (Order does not matter)
 */
class RestoreIPAddressesSolution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        ip.reserve(s.size() + 3);
        vector<string> result;
        restoreIpAddresses(s, 0, 0, ip, result);
        return result;
    }
    
private:
    void restoreIpAddresses(const string & s, int start, int step, string & ip, vector<string> & result) {
        if (step == 4 && start == s.size()) {
            ip.resize(ip.size()-1);
            result.push_back(ip);
            return;
        }
        
        int remaining = (int)s.size() - start;
        if (remaining < (4-step) || remaining > (4-step) * 3) { // prune
            return;
        }
        
        int value = 0;
        for (int i = start; i < start + 3 && i < s.size(); ++i) {
            value = value * 10 + (s[i] - '0');
            if (value >= 256) {
                break;
            }
            
            ip.push_back(s[i]);
            size_t currentSize = ip.size();
            ip.push_back('.');
            restoreIpAddresses(s, i+1, step+1, ip, result);
            ip.resize(currentSize);
            
            if (value == 0) { // 0 is allowed only once
                break;
            }
        }
    }
};

#endif
