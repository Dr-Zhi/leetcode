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

using std::vector;
using std::max;
using std::min;

/** http://leetcode.com/onlinejudge#question_121
 * Say you have an array for which the ith element is the price of a given stock
 * on day i. If you were only permitted to complete at most one transaction (ie,
 * buy one and sell one share of the stock), design an algorithm to find the 
 * maximum profit.
 */
class BestTimetoBuyandSellStockSolutionI {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxProfit = 0, lowestPriceSoFar = INT_MAX, localMaxProfit;
        for (size_t i = 0; i < prices.size(); ++i) {
            if (lowestPriceSoFar > prices[i])
                lowestPriceSoFar = prices[i];
            localMaxProfit = prices[i] - lowestPriceSoFar;
            if (maxProfit < localMaxProfit)
                maxProfit = localMaxProfit;
        }
        return maxProfit;
    }
    
    int maxProfit_V2(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int maxProfit = 0, profit = 0, priceToBuy = prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            profit += prices[i] - prices[i-1];
            if (maxProfit < profit) {
                maxProfit = profit;
            }
            if (priceToBuy > prices[i]) {
                priceToBuy = prices[i];
                profit = 0;
            }

        }
        
        return maxProfit;
    }
    
    int maxProfit_V3(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int maxProfit = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
    
};
#endif
