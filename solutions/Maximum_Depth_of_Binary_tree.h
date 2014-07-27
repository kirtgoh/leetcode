/********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 27, 2014
 *  Problem:     	Find Maximum Depth of Binary Tree
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 *  Notes:
 * 	The maximum depth is the number of nodes along the longest path from the root
 * 	node down to the farthest leaf node
 *
 *  Solution: 		
*********************************************************************************/

#ifndef DEPTH_OF_BINARY_H
#define DEPTH_OF_BINARY_H

#include <bintree.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    int maxDepth(TreeNode *root);

};

int Solution::maxDepth(TreeNode *root)
{
  if (!root) return 0;
  else return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}

#endif /* DEPTH_OF_BINARY_H */
