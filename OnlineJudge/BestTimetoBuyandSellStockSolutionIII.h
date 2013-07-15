//
//  BestTimetoBuyandSellStockSolutionIII.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 2/8/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_BestTimetoBuyandSellStockSolutionIII_h
#define LeetCode_Solutions_BestTimetoBuyandSellStockSolutionIII_h

#include <vector>

using std::vector;
using std::max;
using std::min;

/** http://leetcode.com/onlinejudge#question_123
 * Say you have an array for which the ith element is the price of a given 
 * stock on day i. Design an algorithm to find the maximum profit. You may
 * complete at most two transactions. Note: You may not engage in multiple
 * transactions at the same time (ie, you must sell the stock before you
 * buy again).
 */
class BestTimetoBuyandSellStockSolutionIII {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> profitRight(prices.size()+1, 0);
        int maxPrice = INT_MIN, minPrice = INT_MAX, maxProfit = 0, profitSum = 0;
        int n = (int)prices.size();
        for (int i = n-1; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            profitRight[i] = max(profitRight[i+1], maxPrice - prices[i]);
        }
        for (int i = 0; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
            profitSum = max(profitSum, maxProfit + profitRight[i+1]);
        }
        return profitSum;
    }
};

#endif
