//
//  main.cpp
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 1/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include <iostream>


#include "ConvertSortedListToBinarySearchTreeSolution.h"
#include "ConvertSortedArrayToBinarySearchTreeSolution.h"
#include "ValidPalindromeSolution.h"
#include "BinaryTreeMaximumPathSumSolution.h"
#include "BestTimetoBuyandSellStockSolutionI.h"
#include "BestTimetoBuyandSellStockSolutionII.h"
#include "BestTimetoBuyandSellStockSolutionIII.h"
#include "MinimumPathSumOnTriangleSolution.h"
#include "PascalTriangleSolution.h"
#include "PascalTriangleIISolution.h"
#include "PolulatingNextRightPointersInEachNodeIISolution.h"
#include "PathSumIISolution.h"
#include "MinimumDepthOfBinaryTreeSolution.h"
#include "BalancedBinaryTreeSolution.h"
#include "BinaryTreeLevelOrderTraversalSolution.h"
#include "BinaryTreeLevelOrderTraversalSolutionII.h"
#include "ConstructBinaryTreeFromInorderAndPostorderTraversalSolution.h"
#include "ConstructBinaryTreeFromPreorderAndInorderTraversalSolution.h"
#include "MaximumDepthOfBinaryTreeSolution.h"
#include "BinaryTreeZigzagLevelOrderTraversalSolution.h"
#include "SymmetricTreeSolutionIterative.h"
#include "SymmetricTreeSolutionRecursive.h"
#include "SameTreeSolutionIterative.h"
#include "SameTreeSolutionRecursive.h"
#include "ValidateBinarySearchTreeSolution.h"
#include "InterleavingStringSolution.h"
#include "MergeTwoSortedListsSolution.h"
#include "InsertIntervalSolution.h"
#include "PowerOfXSolution.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[])
{
//    ValidPalindromeSolution solution;
//    std::string s("A man, a plan, a canal: Panama");
//    bool ispal = solution.isPalindrome(s);
//    std::cout << ispal << std::endl;

//    BinaryTreeMaximumPathSumSolution maxPathSumSolution;
//    TreeNode root(-2);
//    TreeNode left(1);
//    root.left = &left;
//    int maxSum = maxPathSumSolution.maxPathSum(&root);
//    cout << maxSum << endl;
    
//    BestTimetoBuyandSellStockSolutionIII bestTimeToBuyAndSellSolution;
//    vector<int> prices;
//    prices.push_back(2);
//    prices.push_back(1);
//    prices.push_back(2);
//    prices.push_back(0);
//    prices.push_back(1);
//    int maxProfit = bestTimeToBuyAndSellSolution.maxProfit(prices);
//    cout << maxProfit << endl;

//    vector<vector<int> > triangle;
//    vector<int> v(1, -1);
//    triangle.push_back(v);
//    v.clear();
//    v.push_back(2);
//    v.push_back(3);
//    triangle.push_back(v);
//    v.clear();
//    v.push_back(1);
//    v.push_back(-1);
//    v.push_back(-3);
//    triangle.push_back(v);
//    MinimumPathSumOnTriangleSolution minPathSumSolution;
//    cout << minPathSumSolution.minimumTotal(triangle);
    
//    PascalTriangleSolution pasacalTriangle;
//    vector<vector<int> > triangle = pasacalTriangle.generate(3);
    
//    PascalTriangleIISolution pasacalTriangleII;
//    vector<int> line = pasacalTriangleII.getRow(3);
//    for (size_t i = 0; i < line.size(); ++i) {
//        cout << line[i] << "\t";
//    }
//    cout << endl;
    
//    TreeNode node2(2);
//    TreeNode node1(1);
//    TreeNode node3(3);
//    node1.left = &node2;
//    node1.right = &node3;
//    FlattenBinaryTreeToLinkedListSolution solution;
//    solution.flatten(&node1);
//    TreeNode * lpNode = &node1;
//    while (lpNode) {
//        cout << lpNode->val << "\t";
//        lpNode = lpNode->right;
//    }
//    cout << endl;
    
    vector<int> inorder, postorder;
    inorder.push_back(1);
    inorder.push_back(3);
    inorder.push_back(2);
    postorder.push_back(3);
    postorder.push_back(2);
    postorder.push_back(1);
    ConstructBinaryTreeFromInorderAndPostorderTraversalSolution solution;
    solution.buildTree(inorder, postorder);
    
//    vector<int> preorder, inorder;
//    preorder.push_back(1);
//    preorder.push_back(2);
//    inorder.push_back(2);
//    inorder.push_back(1);
//    ConstructBinaryTreeFromPreorderAndInorderTraversalSolution solution;
//    solution.buildTree(preorder, inorder);
    
//    string s1("aa"), s2("ab"), s3("aaba");
//    InterleavingStringSolution solution;
//    solution.isInterleave(s1, s2, s3);
    
//    ListNode node1(1), node2(2), node4(4), node5(5);
//    node1.next = &node2;
//    node2.next = &node4;
//    MergeTwoSortedListsSolution solution;
//    solution.mergeTwoLists(&node1, &node5);
    
    vector<Interval> intervals;
    intervals.push_back(Interval(2, 4));
    intervals.push_back(Interval(5, 7));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(11, 13));
    Interval newInterval(3, 8);
    InsertIntervalSolution insertIntervalSolution;
    insertIntervalSolution.insert(intervals, newInterval);
    
    return EXIT_SUCCESS;
}

