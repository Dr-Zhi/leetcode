//
//  ConstructBinaryTreeFromInorderAndPostorderTraversalSolution.h
//  OnlineJudge
//
//  Created by Yanling Zhi on 3/29/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#ifndef OnlineJudge_ConstructBinaryTreeFromInorderAndPostorderTraversalSolution_h
#define OnlineJudge_ConstructBinaryTreeFromInorderAndPostorderTraversalSolution_h

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

/** http://leetcode.com/onlinejudge#question_106
 * Given inorder and postorder traversal of a tree, construct the binary 
 * tree. Note: you may assume that duplicates do not exist in the tree.
 */
class ConstructBinaryTreeFromInorderAndPostorderTraversalSolution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeRecursive(inorder, 0, inorder.size(), postorder,
                                  postorder.size()-1);
    }
    
    TreeNode * buildTreeRecursive(vector<int> &inorder, size_t left, size_t right,
                                  vector<int> &postorder, size_t rootPos) {
        if (left >= right) {
            return NULL;
        }
        assert(rootPos < postorder.size());
        int value = postorder[rootPos];
        TreeNode * root = new TreeNode(value);
        // linear search for the position of root in inorder traversal.
        size_t pos = left;
        while (pos < right && inorder[pos] != value) {
            ++pos;
        }
        
        // inorder: left -> root -> right, postorder: left -> right -> root
        if (pos < right) {
            root->right = buildTreeRecursive(inorder, pos+1, right,
                                             postorder, rootPos-1);
        }
        if (pos > left) {
            root->left = buildTreeRecursive(inorder, left, pos,
                                            postorder, rootPos-(right-pos));
        }
        
        return root;
     }
};


#endif
