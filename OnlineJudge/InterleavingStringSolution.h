//
//  InterleavingStringSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/3/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_InterleavingStringSolution_h
#define OnlineJudge_InterleavingStringSolution_h

#include <string>

using std::string;

/** http://leetcode.com/onlinejudge#question_97
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1
 * and s2. For example, given: s1 = "aabcc", s2 = "dbbca",
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 * This algorithm is recursive: time limit exceeded for large test suites. 
 * Need to find a more efficient one.
 */
class InterleavingStringSolution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return (s1.size() + s2.size() == s3.size() &&
                isInterleaveRecursive(s1, s2, s3, 0, 0, 0));
    }
private:
    bool isInterleaveRecursive(string s1, string s2, string s3,
                               int i, int j, int k) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }
        
        bool interleave = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            interleave = isInterleaveRecursive(s1, s2, s3, i+1, j, k+1);
        }
        if (interleave) { // early return if yes
            return true;
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            interleave = isInterleaveRecursive(s1, s2, s3, i, j+1, k+1);
        }
        return interleave;
    }
};


#endif
