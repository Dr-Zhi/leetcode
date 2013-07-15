//
//  SubsetsSolutionRecursive.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/14/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SubsetsSolutionRecursive_h
#define OnlineJudge_SubsetsSolutionRecursive_h

/** http://leetcode.com/onlinejudge#question_78
 * Given a set of distinct integers, S, return all possible subsets.
 * Note: Elements in a subset must be in non-descending order. The solution
 * set must not contain duplicate subsets. For example, if S = [1,2,3], a
 * solution is:
 [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
 ]
 */
class SubsetsSolutionRecursive {
public:
    // recursive solution
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        result.reserve(1 << S.size()); // reserve space
        vector<int> cur;
        cur.reserve(S.size());         // reserve space
        subsetsRecursive(S, 0, cur, result);
        return result;
    }
    void subsetsRecursive(vector<int> &S, int pos, vector<int> &cur, vector<vector<int> > &result) {
        if (pos >= S.size()) {
            result.push_back(cur);
            return;
        }
        cur.push_back(S[pos]);
        subsetsRecursive(S, pos+1, cur, result);
        cur.pop_back();
        subsetsRecursive(S, pos+1, cur, result);
    }
};

#endif
