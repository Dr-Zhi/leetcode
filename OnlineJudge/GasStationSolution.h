//
//  GasStationSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/1/14.
//  Copyright (c) 2014 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_GasStationSolution_h
#define OnlineJudge_GasStationSolution_h

/** http://oj.leetcode.com/problems/gas-station/
 *
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i]. You have a car with an unlimited gas tank and it costs 
 * cost[i] of gas to travel from station i to its next station (i+1). You begin
 * the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 *
 * Note: the solution is guaranteed to be unique.
 */
class GasStationSolution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0, index = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            total += (gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
            if (sum < 0) {
                sum = 0;
                index = i;
            }
        }
        return total >= 0 ? index + 1 : -1;
    }
};

#endif
