//
//  CombinationsSolutino.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 9/14/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_Combinations_Solution_h
#define OnlineJudge_Combinations_Solution_h

/** http://leetcode.com/onlinejudge#question_77
 * Given two integers n and k, return all possible combinations of k 
 * numbers out of 1 ... n. For example, if n = 4 and k = 2, a solution is:
 * [
 *  [2,4],
 *  [3,4],
 *  [2,3],
 *  [1,2],
 *  [1,3],
 *  [1,4],
 * ]
 *
 */
class CombinationsSolution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > combinations;
        if (n < k || k <= 0)
            return combinations;
        vector<int> cur;
        combineRecursive(1, n, k, cur, combinations);
        return combinations;
    }
private:
    void combineRecursive(int start, int n, int k, vector<int> & cur, vector<vector<int> > &combinations) {
        if (cur.size() == k) {
            combinations.push_back(cur);
            return;
        }
        for (int i = start; i <= n; ++i) {
            cur.push_back(i);
            combineRecursive(i+1, n, k, cur, combinations);
            cur.pop_back();
        }
    }
};
#endif
