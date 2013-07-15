//
//  BestTimetoBuyandSellStockII.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 1/31/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_BestTimetoBuyandSellStockII_h
#define LeetCode_Solutions_BestTimetoBuyandSellStockII_h

#include <vector>

using std::vector;

/** http://leetcode.com/onlinejudge#question_122
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. Design an algorithm to find the maximum profit. You may complete as
 * many transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
 */
class BestTimetoBuyandSellStockSolutionII {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i-1] > 0)
                maxProfit += (prices[i] - prices[i-1]);
        }
        return maxProfit;
    }
};


#endif
