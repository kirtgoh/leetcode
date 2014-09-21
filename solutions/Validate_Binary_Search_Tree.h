/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 21, 2014
 *  Problem:     	Validate Binary Search Tree
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/validate-binary-search-tree/
 *
 *  Notes:
 * 	Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * 	Assume a BST is defined as follows:
 *
 * 	The left subtree of a node contains only nodes with keys less than the
 * 	node's key. The right subtree of a node contains only nodes with keys
 * 	greater than the node's key. Both the left and right subtrees must also be
 * 	binary search trees.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef VALIDATE_BST_H
#define VALIDATE_BST_H

#include <bintree.h>

class Solution {
public:
	bool isValidBST(TreeNode *root);
};

bool Solution::isValidBST(TreeNode *root)
{
	if (!root) return true;

	if (root->left)
	{
		if (root->left->val >= root->val) return false;

		TreeNode *p = root->left->right;
		while(p && p->right) p = p->right;
		if (p && p->val >= root->val) return false;
	}

	if (root->right) 
	{
		if(root->right->val <= root->val) return false;

		TreeNode *p = root->right->left;
		while(p && p->left) p = p->left;
		if (p && p->val <= root->val) return false;
	}

	return isValidBST(root->left) && isValidBST(root->right);

}

#endif /* VALIDATE_BST_H */

