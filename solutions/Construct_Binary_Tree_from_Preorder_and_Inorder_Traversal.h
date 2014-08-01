/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 02, 2014
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

#ifndef BINARY_TREE_PRE_IN_ORDER_H
#define BINARY_TREE_PRE_IN_ORDER_H

#include <bintree.h>
#include <algorithm>

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
    TreeNode *buildTreeRecurse(vector<int>::iterator itPre, vector<int>::iterator itIn, int size);
                  
};

TreeNode *Solution::buildTreeRecurse(vector<int>::iterator itPre, vector<int>::iterator itIn, int size)
{
  if (size == 0) return NULL;

  vector<int>::iterator it = find(itIn,itIn + size, *itPre); 
  TreeNode *root = new TreeNode(*it);

  root->left = buildTreeRecurse(itPre + 1, itIn, it - itIn);
  root->right = buildTreeRecurse(itPre + (it - itIn) + 1, it + 1, size - (it - itIn) - 1);

  return root;
}

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
  return buildTreeRecurse(preorder.begin(), inorder.begin(), inorder.size());
}

#endif /* BINARY_TREE_PRE_IN_ORDER_H */

