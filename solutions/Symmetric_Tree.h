/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 20, 2014
 *  Problem:     	Symmetric Tree
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/symmetric-tree/
 *
 *  Notes:
 * 	Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * 	around its center).
 *
 * 	For example, this binary tree is symmetric:
 *
 * 	    1
 * 	   / \
 * 	  2   2
 * 	 / \ / \
 * 	3  4 4  3
 *
 *  But the following is not:
 * 	    1
 * 	   / \
 * 	  2   2
 * 	   \   \
 * 	    3   3
 *
 * 	Note:
 * 	Bonus points if you could solve it both recursively and iteratively.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef SYMMETRIC_TREE
#define SYMMETRIC_TREE

#include <bintree.h>

class Solution {
public:
	bool isSymmetric(TreeNode *root);
	bool isSymmetricRec(TreeNode *left, TreeNode *right);

};

bool Solution::isSymmetricRec(TreeNode *left, TreeNode *right)
{
	if (!left && !right)
		return true;
	else if (!left || !right)
		return false;
	else if (left->val == right->val)
		return isSymmetricRec(left->left, right->right) && isSymmetricRec(left->right, right->left);

	return false;
}

bool Solution::isSymmetric(TreeNode *root)
{
	if (!root) return true;

	return isSymmetricRec(root->left, root->right);
	
}

#endif /* SYMMETRIC_TREE */
