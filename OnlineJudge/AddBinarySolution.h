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

/** http://leetcode.com/onlinejudge#question_67
 * Given two binary strings, return their sum (also a binary string).
 * For example, a = "11", b = "1", return "100".
 */
class AddBinarySolution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.empty() || b.empty())
            return (a.empty() ? b : a);
        string sum;
        sum.reserve(max(a.size(), b.size()));
        int s, carry = 0;
        for (int i = (int)a.size() - 1, j = (int)b.size() - 1;
             i >= 0 || j >= 0; --i, --j) {
            int va = (i < 0 ? 0 : (a[i]-'0'));
            int vb = (j < 0 ? 0 : (b[j]-'0'));
            s = carry + va + vb;
            carry = (s > 1 ? 1 : 0);
            sum.push_back((int)(s & 0x1) + '0');
        }
        if (carry > 0)
            sum.push_back('1');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

#endif
