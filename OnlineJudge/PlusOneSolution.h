//
//  PlusOneSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/1/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PlusOneSolution_h
#define OnlineJudge_PlusOneSolution_h

/** http://oj.leetcode.com/problems/plus-one/
 * Given a non-negative number represented as an array of digits, plus one to
 * the number. The digits are stored such that the most significant digit is 
 * at the head of the list.
 */
class PlusOneSolution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, sum;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            sum = *iter + carry;
            *iter = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

#endif
