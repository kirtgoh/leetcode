/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 02, 2014
 *  Problem:     	Binary Tree Inorder Traversal
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 *
 *  Notes:
 *  Given a binary tree, return the inorder traversal of its nodes' values.
 *
 *  For example:
 *  Given binary tree {1,#,2,3},
 *      1
 *       \
 *        2
 *       /
 *      3
 *  return [1,3,2].
 *  Note: Recursive solution is trivial, could you do it iteratively?
 * 	
 *  Solution: 		
 *********************************************************************************/

#ifndef INORDER_TRAVERAL_H
#define INORDER_TRAVERAL_H

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
    vector<int> inorderTraversal(TreeNode *root);
};

vector<int> Solution::inorderTraversal(TreeNode *root)
{
  vector<int> res;
  if(!root) return res;

  if (root->left) 
  {
    vector<int> left;
    left = inorderTraversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
  }

  res.push_back(root->val);

  if (root->right)
  {
    vector<int> right;
    right = inorderTraversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
  }

  return res;
}

#endif /* INORDER_TRAVERAL_H */
