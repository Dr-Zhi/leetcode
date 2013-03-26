//
//  ConvertSortedArrayToBinarySearchTreeSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/26/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ConvertSortedArrayToBinarySearchTreeSolution_h
#define OnlineJudge_ConvertSortedArrayToBinarySearchTreeSolution_h

#include <vector>

using std::vector;

/**
 * Definition for binary tree
 *
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() { // destroy subtrees, assume they are allocated by new
        delete left;
        delete right;
    }
};
 */

/** http://leetcode.com/onlinejudge#question_108
 * Given an array where elements are sorted in ascending order, convert it 
 * to a height balanced BST.
 */
class ConvertSortedArrayToBinarySearchTreeSolution {
public:
    TreeNode * sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode * root = sortedArrayToBSTRecursive(num, 0, num.size());
        return root;
    }
    
private:
    TreeNode * sortedArrayToBSTRecursive(const vector<int> & num,
                                         size_t startIndex, size_t endIndex) {
        if (startIndex >= endIndex) {
            return NULL;
        }
        size_t midIndex = startIndex + (endIndex-startIndex)/2;
        TreeNode * root = new TreeNode(num[midIndex]);
        root->left = sortedArrayToBSTRecursive(num, startIndex, midIndex);
        root->right = sortedArrayToBSTRecursive(num, midIndex+1, endIndex);
        return root;
    }
};

#endif
