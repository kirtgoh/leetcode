/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 02, 2014
 *  Problem:     	Same Tree
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/same-tree/
 *
 *  Notes:
 *  Given two binary trees, write a function to check if they are equal or not.
 *  Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 * 	
 *  Solution: 		
*********************************************************************************/

#ifndef SAME_TREE_H
#define SAME_TREE_H

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
        bool isSameTree(TreeNode *p, TreeNode *q);
};

bool Solution::isSameTree(TreeNode *p, TreeNode *q)
{
  if(!p && !q)
  {
    return true;
  }
  else if (p && q && (p->val == q->val))
  {
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
  else
  {
    return false;
  }

}

#endif /* SAME_TREE_H */
