//
//  PathSumSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/23/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_PathSumSolution_h
#define OnlineJudge_PathSumSolution_h

/** 
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/** http://leetcode.com/onlinejudge#question_112
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf 
 * path such that adding up all the values along the path equals the given
 * sum. For example: given the below binary tree and sum = 22,
         5
        / \
       4   8
      /   / \
     11  13  4
    /  \      \
   7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is
 * 22.
 */
class PathSumSolution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        }
        
        sum -= root->val; // remaining sum
        if (root->left==NULL && root->right==NULL && // leaf node
            sum==0) {
            return true;
        }
        
        bool left = hasPathSum(root->left, sum);
        bool right = hasPathSum(root->right, sum);
        
        return left || right;
    }
};


#endif
