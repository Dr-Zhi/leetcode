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
        if (prices.size() < 2) {
            return 0;
        }
        
        int n = (int)prices.size();
        vector<int> vProfitsSecond(n, 0);
        int maxPrice = prices[n-1], maxProfitSecond = 0;
        for (int i = n-2; i >= 0; --i) {
            vProfitsSecond[i] = maxProfitSecond = max(maxProfitSecond, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        
        vector<int> vProfitsFirst(n, 0);
        int minPrice = prices[0], maxProfitFirst = 0;
        for (int i = 1; i < n; ++i) {
            vProfitsFirst[i] = maxProfitFirst = max(maxProfitFirst, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < n-1; ++i) {
            maxProfit = max(maxProfit, vProfitsFirst[i]+vProfitsSecond[i]);
        }
        
        return maxProfit;
    }
};

#endif
