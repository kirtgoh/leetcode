/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 20, 2014
 *  Problem:     	Balanced Binary Tree
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/balanced-binary-tree/
 *
 *  Notes:
 * 	Given a binary tree, determine if it is height-balanced.
 *
 * 	For this problem, a height-balanced binary tree is defined as a binary tree
 * 	in which the depth of the two subtrees of every node never differ by more
 * 	than 1.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef BALANCED_BINARYTREE
#define BALANCED_BINARYTREE

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
	bool isBalanced(TreeNode *root);
	int depth(TreeNode *root);
};

int Solution::depth(TreeNode *root)
{
	if (!root) return 0;
	
	if (!root->left && !root->right) return 1;

	return 1 + max(depth(root->left), depth(root->right));
}

bool Solution::isBalanced(TreeNode *root)
{
	if (!root) return true;

	if (abs(depth(root->left) - depth(root->right)) > 1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

#endif /* BALANCED_BINARYTREE */

