/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 02, 2014
 *  Problem:     	Binary Tree Postorder Traversal
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 *
 *  Notes:
 *  Given a binary tree, return the postorder traversal of its nodes' values.
 *
 *  For example:
 *  Given binary tree {1,#,2,3},
 *      1
 *       \
 *        2
 *       /
 *      3
 *  return [3,2,1].
 *  Note: Recursive solution is trivial, could you do it iteratively?
 * 	
 *  Solution: 		
 *********************************************************************************/

#ifndef POSTORDER_TRAVERAL_H
#define POSTORDER_TRAVERAL_H

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
    vector<int> postorderTraversal(TreeNode *root);
};

vector<int> Solution::postorderTraversal(TreeNode *root)
{
  vector<int> res;
  if(!root) return res;

  if (root->left) 
  {
    vector<int> left;
    left = postorderTraversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
  }
  if (root->right)
  {
    vector<int> right;
    right = postorderTraversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
  }
  res.push_back(root->val);

  return res;
}

#endif /* POSTORDER_TRAVERAL_H */
