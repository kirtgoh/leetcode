/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 30, 2014
 *  Problem:     	Binary Tree Maximum Path Sum
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 *
 *  Notes:
 * 	Given a binary tree, find the maximum path sum.
 *
 * 	The path may start and end at any node in the tree.
 *
 * 	For example:
 * 	Given the below binary tree,
 *
 * 	       1
 * 	      / \
 * 	     2   3
 *
 * 	Return 6.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef BINTREE_MAX_PATH_SUM_H
#define BINTREE_MAX_PATH_SUM_H

#include <climits>
#include <bintree.h>

/*
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
	int maxPathSum(TreeNode *root);
	int maxPathSumRe(TreeNode *root, int &res);
};

int Solution::maxPathSum(TreeNode *root)
{
	int res = INT_MIN;
	maxPathSumRe(root, res);
	return res;
}

int Solution::maxPathSumRe(TreeNode *root, int &res)
{
	if (!root) return 0;

	// sum is max path sum including current node's value 
	int sum = root->val, l, r;

	// compare with current node
	res = max(sum, res);
	
	l = maxPathSumRe(root->left, res);
	r = maxPathSumRe(root->right, res);

	sum = max(sum, sum + max(l, r));

	// compare with left and right node's value
	res = max(sum, res);
	// compare with all this link
	res = max(root->val + l + r, res);

	return sum;
}

#endif /* BINTREE_MAX_PATH_SUM_H */
