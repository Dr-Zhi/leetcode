//
//  GrayCodeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/29/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_GrayCodeSolution_h
#define OnlineJudge_GrayCodeSolution_h

/**
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit. given a non-negative integer n representing the total 
 * number of bits in the code, print the sequence of gray code. A gray code
 * sequence must begin with 0.
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note: for a given n, a gray code sequence is not uniquely defined. for
 * example, [0,2,3,1] is also a valid gray code sequence according to the above
 * definition. 
 *
 * Binary to gray code formula: g_i = b_i ^ b_(i-1).
 */
class GrayCodeSolution {
public:
  vector<int> grayCode(int n) {
    const size_t size = 1 << n;
    vector<int> result;
    result.reserve(size);
    
    for (int i = 0; i < size; ++i) {
      result.push_back(i ^ (i >> 1)); // binary to gray code
    }
    return result;
  }
};

#endif
