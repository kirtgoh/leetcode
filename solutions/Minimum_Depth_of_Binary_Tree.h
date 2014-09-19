/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 19, 2014
 *  Problem:     	Minimum Depth of Binary Tree
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 *
 *  Notes:
 * 	Given a binary tree, find its minimum depth.
 *
 * 	The minimum depth is the number of nodes along the shortest path from the
 * 	root node down to the nearest leaf node.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef MIN_DEPTH_OF_BINARYTREE
#define MIN_DEPTH_OF_BINARYTREE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bintree.h>

class Solution {
public:
	int minDepth(TreeNode *root);
};

int Solution::minDepth(TreeNode *root)
{
	if (!root) return 0;

	if (!root->left && !root->right)
		return 1;

	if (!root->left)
		return 1 + minDepth(root->right);
	else if (!root->right)
		return 1 + minDepth(root->left);
	else 
		return 1 + min(minDepth(root->left), minDepth(root->right));
}

#endif /* MIN_DEPTH_OF_BINARYTREE */
