//
//  main.cpp
//  LeetCode Solutions
//
//  Created by Yanling Zhi on 1/21/13.
//  Copyright (c) 2013 Dr. Zhi Inc. All rights reserved.
//

#include <iostream>
#include "ValidPalindromeSolution.h"
//#include "BinaryTreeMaximumPathSumSolution.h"
#include "BestTimetoBuyandSellStockSolutionI.h"
#include "BestTimetoBuyandSellStockSolutionII.h"
#include "BestTimetoBuyandSellStockSolutionIII.h"
#include "MinimumPathSumOnTriangleSolution.h"
#include "PascalTriangleSolution.h"
#include "PascalTriangleIISolution.h"
#include "PolulatingNextRightPointersInEachNodeIISolution.h"
#include "FlattenBinaryTreeToLinkedList.h"
#include "PathSumIISolution.h"
#include "MinimumDepthOfBinaryTreeSolution.h"
#include "BalancedBinaryTreeSolution.h"

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
    
    TreeNode node2(2);
    TreeNode node1(1);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    FlattenBinaryTreeToLinkedListSolution solution;
    solution.flatten(&node1);
    TreeNode * lpNode = &node1;
    while (lpNode) {
        cout << lpNode->val << "\t";
        lpNode = lpNode->right;
    }
    cout << endl;
    
    return EXIT_SUCCESS;
}

