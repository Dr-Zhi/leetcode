//
//  CandySolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/2/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_CandySolution_h
#define OnlineJudge_CandySolution_h

/** http://oj.leetcode.com/problems/candy/
 * There are N children standing in a line. Each child is assigned a rating 
 * value. You are giving candies to these children subjected to the following 
 * requirements:
 * 1. Each child must have at least one candy.
 * 2. Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
class CandySolution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> increments(n);
        for (int i = 1, inc = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                increments[i] = max(increments[i], inc);
                ++inc;
            }
            else {
                inc = 1;
            }
        }
        
        for (int i = n-2, inc = 1; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                increments[i] = max(increments[i], inc);
                ++inc;
            }
            else {
                inc = 1;
            }
        }
        
        return accumulate(increments.begin(), increments.end(), n);
    }
};

#endif
