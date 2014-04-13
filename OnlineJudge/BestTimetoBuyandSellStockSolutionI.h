//
//  BestTimetoBuyandSellStockSolution.h
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 1/23/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef LeetCode_Solutions_BestTimetoBuyandSellStockSolution_h
#define LeetCode_Solutions_BestTimetoBuyandSellStockSolution_h

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

/** http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. If you were only permitted to complete at most one transaction (ie,
 * buy one and sell one share of the stock), design an algorithm to find the 
 * maximum profit.
 *
 * Analysis: at most one transaction is allowed. Scan from left to right, buy at
 * the lowest price, and sell at the highest price.
 */
class BestTimetoBuyandSellStockSolutionI {
public:
    int maxProfit(vector<int> &prices) {
        int low = INT_MAX, profit = 0;
        for (int price : prices) {
            low = min(low, price);
            profit = max(profit, price - low);
        }
        return profit;
    }
};
#endif
