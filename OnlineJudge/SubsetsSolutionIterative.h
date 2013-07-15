//
//  SubsetsSolutionIterative.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 7/14/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_SubsetsSolutionIterative_h
#define OnlineJudge_SubsetsSolutionIterative_h

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
class SubsetsSolutionIterative {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        int n = S.size();
        vector<bool> status(n, false);
        vector<vector<int> > result;
        vector<int> cur;
        cur.reserve(n);
        while (true) {
            for (int i = 0; i < n; ++i) {
                if (status[i])
                    cur.push_back(S[i]);
            }
            result.push_back(cur);
            cur.clear();
            
            bool overflow = true;
            for (int i = 0; overflow && i < n; ++i) {
                overflow = overflow && status[i];
                status[i] = !status[i];
            }
            if (overflow)
                break;
        }
        return result;
    }
};
};

#endif
