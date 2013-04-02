//
//  ConstructBinaryTreeFromPreorderAndInorderTraversalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 4/1/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ConstructBinaryTreeFromPreorderAndInorderTraversalSolution_h
#define OnlineJudge_ConstructBinaryTreeFromPreorderAndInorderTraversalSolution_h

#include <vector>
#include <cassert>

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

/** http://leetcode.com/onlinejudge#question_105
 * Given preorder and inorder traversal of a tree, construct the binary
 * tree. Note: you may assume that duplicates do not exist in the tree.
 */
class ConstructBinaryTreeFromPreorderAndInorderTraversalSolution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeRecursive(preorder, 0,
                                  inorder, 0, inorder.size());
    }
    
    TreeNode * buildTreeRecursive(vector<int> & preorder, size_t rootPos,
                                  vector<int> & inorder, size_t left,
                                  size_t right) {
        if (left >= right) {
            return NULL;
        }
        int value = preorder[rootPos]; // value for root
        TreeNode * root = new TreeNode(value);
        // linear search for the position of root in inorder traversal.
        size_t pos = left;
        while (pos < right && inorder[pos] != value) {
            ++pos;
        }
        if (pos > left) {
            root->left = buildTreeRecursive(preorder, rootPos+1,
                                            inorder, left, pos);
        }
        if (pos < right) {
            root->right = buildTreeRecursive(preorder, rootPos+pos-left+1,
                                             inorder, pos+1, right);
        }
        return root;
    }
};

#endif
