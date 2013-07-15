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
        int maxProfit = 0, minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }    
};
#endif
