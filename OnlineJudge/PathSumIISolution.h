//
//  PathSumIISolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/24/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PathSumIISolution_h
#define OnlineJudge_PathSumIISolution_h

#include <vector>

using std::vector;

/**
 * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */

/** http://leetcode.com/onlinejudge#question_113
 * Given a binary tree and a sum, find all root-to-leaf paths where each
 * path's sum equals the given sum. For example: given the below binary 
 * tree and sum = 22,
        5
       / \
      4   8
     /   / \
    11  13  4
    / \    / \
   7   2  5   1
 * return
   [
   [5,4,11,2],
   [5,8,4,5]
   ]
 */
class PathSumIISolution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > paths;
        vector<int> curPath;
        pathSumRecursive(root, sum, paths, curPath);
        return paths;
    }
    
private:
    void pathSumRecursive(TreeNode * root, int sum,
                          vector<vector<int> > & paths,
                          vector<int> & curPath) {
        if (root == NULL) {
            return;
        }
        
        curPath.push_back(root->val);
        sum -= root->val;
        if (root->left==NULL && root->right==NULL &&
            sum == 0) { // found a path
            paths.push_back(curPath);
        }
        
        pathSumRecursive(root->left, sum, paths, curPath);
        pathSumRecursive(root->right, sum, paths, curPath);
        curPath.pop_back();
    }
};

#endif
