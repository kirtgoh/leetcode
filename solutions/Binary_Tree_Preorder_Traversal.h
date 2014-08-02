/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 02, 2014
 *  Problem:     	Binary Tree Preorder Traversal
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 *
 *  Notes:
 *  Given a binary tree, return the preorder traversal of its nodes' values.
 *
 *  For example:
 *  Given binary tree {1,#,2,3},
 *       1
 *        \
 *         2
 *        /
 *       3
 *  return [1,2,3].
 *  Note: Recursive solution is trivial, could you do it iteratively?
 * 	
 *  Solution: 		
 *********************************************************************************/

#ifndef PREORDER_TRAVERSAL_H
#define PREORDER_TRAVERSAL_H

#include <bintree.h>

// using namespace std;

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
    vector<int> preorderTraversal(TreeNode *root);
};

vector<int> Solution::preorderTraversal(TreeNode *root)
{
  vector<int> res;
  if(!root) return res;

  res.push_back(root->val);
  if (root->left) 
  {
    vector<int> left;
    left = preorderTraversal(root->left);
    res.insert(res.end(), left.begin(), left.end());
  }
  if (root->right)
  {
    vector<int> right;
    right = preorderTraversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
  }

  return res;
}

#endif /* PREORDER_TRAVERSAL_H */
