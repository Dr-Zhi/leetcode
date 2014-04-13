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

/** http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Say you have an array for which the ith element is the price of a given 
 * stock on day i. Design an algorithm to find the maximum profit. You may
 * complete at most two transactions. 
 *
 * Note: You may not engage in multiple transactions at the same time (ie, you
 * must sell the stock before you buy again).
 *
 * Analysis: let f(i) denote the maximum profit for the prices of [0, i], g(i)
 * denote the maximum profit for the prices of [i, n-1]. Then the maximum profit
 * = max(f(i), g(i)), 0 <= i <= n-1.
 */
class BestTimetoBuyandSellStockSolutionIII {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        
        int n = (int)prices.size();
        int profit = 0;
        vector<int> profitRightArray(n, 0);
        for (int i = n - 2, peak = prices[n-1]; i >= 0; --i) {
            peak = max(peak, prices[i]);
            profitRightArray[i]  = max(profitRightArray[i+1], peak-prices[i]);
        }
        
        for (int i = 1, valley = prices[0], profitLeft = 0; i < n; ++i) {
            valley = min(valley, prices[i]);
            profitLeft = max(profitLeft, prices[i] - valley);
            profit = max(profit, profitLeft + profitRightArray[i]);
        }
        
        return profit;
    }
};
#endif
