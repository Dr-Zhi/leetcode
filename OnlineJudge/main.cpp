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
#include "TriangleSolution.h"
#include "PascalTriangleSolution.h"
#include "PascalTriangleIISolution.h"
#include "PopulatingNextRightPointersInEachNodeSolution.h"
#include "PathSumIISolution.h"
#include "MinimumDepthOfBinaryTreeSolution.h"
#include "BalancedBinaryTreeSolution.h"
#include "BinaryTreeLevelOrderTraversalSolution.h"
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
#include "FlattenBinaryTreeToLinkedList.h"
#include "AddBinarySolution.h"
#include "ReverseIntegerSolution.h"
#include "LowestCommonAncestorOfBinaryTreePartISolution.h"
#include "LowestCommonAncestorOfBinaryTreePartIISolution.h"
#include "SwapNodesInPairsSolution.h"
#include "PathSumIISolution.h"
#include "PopulatingNextRightPointersInEachNodeIISolution.h"
#include "CombinationsSolution.h"
#include "TwoSumSolution.h"
#include "LongestConsecutiveSequenceSolution.h"
#include "SetMatrixZeroesSolution.h"
#include "SqrtSolution.h"
#include "NextPermutationSolution.h"
#include "ThreeSumSolution.h"
#include "RestoreIPAddressesSolution.h"

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
    
//    vector<int> inorder, postorder;
//    inorder.push_back(1);
//    inorder.push_back(3);
//    inorder.push_back(2);
//    postorder.push_back(3);
//    postorder.push_back(2);
//    postorder.push_back(1);
//    ConstructBinaryTreeFromInorderAndPostorderTraversalSolution solution;
//    solution.buildTree(inorder, postorder);
    
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
    
//    vector<Interval> intervals;
//    intervals.push_back(Interval(2, 4));
//    intervals.push_back(Interval(5, 7));
//    intervals.push_back(Interval(8, 10));
//    intervals.push_back(Interval(11, 13));
//    Interval newInterval(3, 8);
//    InsertIntervalSolution insertIntervalSolution;
//    insertIntervalSolution.insert(intervals, newInterval);
    
//    AddBinarySolution addBinary;
//    string a("0"), b("0");
//    string c = addBinary.addBinary(a, b);
//    cout << " a + b = " << c << endl;
    
//    ReverseIntegerSolution reverseInteger;
//    cout << reverseInteger.reverse(-123) << endl;
    
//    PathSumIISolution pathSumIISolution;
//    TreeNode * root = new TreeNode(1);
//    pathSumIISolution.pathSum(root, 1);
    
    
//    NextPermutationSolution nextPermutationSolution;
//    vector<int> array = {1, 3, 2};
//    nextPermutationSolution.nextPermutation(array);
//    for (auto x : array) {
//        cout << x << endl;
//    }    
    
//    BinaryTreeLevelOrderTraversalSolution levelOrderTraversalSolution;
//    levelOrderTraversalSolution.levelOrder(nullptr);
    
//    vector<int> num = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
//    ThreeSumSolution threeSumSolution;
//    threeSumSolution.threeSum(num);
    
    RestoreIPAddressesSolution restoreIpAddressesSolution;
    restoreIpAddressesSolution.restoreIpAddresses("0000");
    
    return EXIT_SUCCESS;
}

