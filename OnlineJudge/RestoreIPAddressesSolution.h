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

/** http://leetcode.com/onlinejudge#question_93
 * Given a string containing only digits, restore it by returning all 
 * possible valid IP address combinations.
 * For example: given "25525511135", return ["255.255.11.135", 
 * "255.255.111.35"]. (Order does not matter)
 */
class RestoreIPAddressesSolution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> addresses;
        string curStr;
        restoreIpAddressesRecursive(0, curStr, addresses, s, 0);
        return addresses;
    }
    void restoreIpAddressesRecursive(int digit, string & curStr, vector<string> & addresses, const string & s, int pos){
        int value = 0;
        for (int i = pos; i < min(pos+3, (int)s.size()); ++i) {
            value = value * 10 + (s[i] - '0');
            if (value <= 255) {
                curStr.push_back(s[i]);
                int curSize = curStr.size();
                if (digit < 3) {
                    curStr.push_back('.');
                    restoreIpAddressesRecursive(digit+1, curStr, addresses, s, i+1);
                }
                else if (digit == 3 && i+1 == s.size()) {
                    addresses.push_back(curStr);
                }
                curStr.resize(curSize);
            }
            if (value == 0 || value > 255)
                break;
        }
    }
};

#endif
