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

/** http://oj.leetcode.com/problems/path-sum-ii/
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
        vector<vector<int> > allPaths;
        vector<int> path;
        pathSumInternal(root, sum, path, allPaths);
        return allPaths;
    }
    
private:
    void pathSumInternal(TreeNode * root, int sum, vector<int> & path, vector<vector<int> > & allPaths) {
        if (root == nullptr) {
            return;
        }
        
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            allPaths.push_back(path);
        }
        
        pathSumInternal(root->left, sum, path, allPaths);
        pathSumInternal(root->right, sum, path, allPaths);
        path.pop_back();
    }
};

#endif
