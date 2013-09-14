//
//  LetterCombinationsOfAPhoneNumber.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 9/10/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_LetterCombinationsOfAPhoneNumber_h
#define OnlineJudge_LetterCombinationsOfAPhoneNumber_h

/** http://leetcode.com/onlinejudge#question_17
 * Given a digit string, return all possible letter combinations that the 
 * number could represent. A mapping of digit to letters is just like on the
 * telephone buttons.
 * For example, input:Digit string "23", output: ["ad", "ae", "af", "bd", 
 * "be", "bf", "cd", "ce", "cf"].
 * Note: although the above answer is in lexicographical order, your answer
 * could be in any order you want.
 */
class LetterCombinationsOfAPhoneNumber {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> results;
        string curStr;
        curStr.reserve(digits.size());
        letterCombinationsRecursive(digits, 0, curStr, results);
        return results;
    }
    void letterCombinationsRecursive(const string & digits, int pos,
                                     string & curStr, vector<string> & results) {
        const static string dict[] = {"0", "1", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"};
        if (pos == digits.size()) {
            results.push_back(curStr);
            return;
        }
        int value = digits[pos] - '0';
        for (int i = 0; i < dict[value].size(); ++i) {
            curStr.push_back(dict[value][i]);
            letterCombinationsRecursive(digits, pos+1, curStr, results);
            curStr.pop_back();
        }
    }
};

#endif
