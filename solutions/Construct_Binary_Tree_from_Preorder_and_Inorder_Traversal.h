/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 29, 2014
 *  Problem:     	Construct Binary Tree from Preorder and Inorder Traversal
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traveral
 *
 *  Notes:
 * 	You may assume that duplicates do not exist in the tree.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef CRE_BINARY_TREE_H
#define CRE_BINARY_TREE_H

#include <bintree.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
                  
};

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
}

#endif /* CRE_BINARY_TREE_H */

