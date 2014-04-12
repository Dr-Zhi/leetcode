//
//  AddBinarySolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/15/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_AddBinarySolution_h
#define OnlineJudge_AddBinarySolution_h

#include <algorithm>

using std::max;
using std::reverse;

/** http://oj.leetcode.com/problems/add-binary/
 * Given two binary strings, return their sum (also a binary string).
 * For example, a = "11", b = "1", return "100".
 * 
 * Analysis: note the order of the characters in a string as a number. "100" 
 * indicates that the first character is the most significant bit (MSB), i.e.,
 * in a reverse order. 
 */
class AddBinarySolution {
public:
    string addBinary(string a, string b) {
        string result;
        result.reserve(max(a.size(), b.size()) + 1);
        int carry = 0;
        for (int i = (int)a.size() - 1, j = (int)b.size() - 1; i >= 0 || j >= 0
             || carry > 0; --i, --j) {
            int va = (i >= 0 ? (a[i] - '0') : 0);
            int vb = (j >= 0 ? (b[j] - '0') : 0);
            int sum = va + vb + carry;
            result.push_back('0' + (sum & 0x1));
            carry = (sum >> 1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif
