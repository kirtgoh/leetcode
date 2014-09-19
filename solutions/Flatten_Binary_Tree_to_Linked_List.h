/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 19, 2014
 *  Problem:     	Flatten Binary Tree to Linked List
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 *
 *  Notes:
 * 	Given a binary tree, flatten it to a linked list in-place.
 *
 * 	For example,
 * 	Given
 *
 * 	         1
 * 	      	/ \
 * 	       2   5
 * 	      / \   \
 * 	     3   4   6
 * 	The flattened tree should look like:
 * 	    1
 * 	     \
 * 	      2
 * 	       \
 * 	        3
 * 	         \
 * 	          4
 * 	           \
 * 	            5
 * 	             \
 * 	              6
 *
 *  Solution: 		
 *********************************************************************************/

#ifndef FLATTEN_BINARY_TREE
#define FLATTEN_BINARY_TREE

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
	void flatten(TreeNode *root);
};

void Solution::flatten(TreeNode *root)
{
	if (root->right) flatten(root->right);
	if (root->left) flatten(root->left);

	TreeNode *p = root->left;
	// NOTE: only left tree exists, handle this
	if (p)
	{
		while(p->right) p = p->right;
		// apend right tree to left's most right
		p->right = root->right;

		// move left tree to right
		root->right = root->left;
		root->left = NULL;
	}

}

#endif /* FLATTEN_BINARY_TREE */

