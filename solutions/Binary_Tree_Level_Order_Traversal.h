/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 20, 2014
 *  Problem:     	Binary Tree Level Order Traversal
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 *
 *  Notes:
 * 	Given a binary tree, return the level order traversal of its nodes' values.
 * 	(ie, from left to right, level by level).
 *
 * 	For example:
 * 	Given binary tree {3,9,20,#,#,15,7},
 * 	    3
 * 	   / \
 * 	  9  20
 * 	    /  \
 * 	   15   7
 * 	return its level order traversal as:
 * 	 [
 * 	  [3],
 * 	  [9,20],
 * 	  [15,7]
 * 	 ]
 *
 *  Solution: 		
*********************************************************************************/

#ifndef BINARYTREE_LEVELORDER_TRAVERSAL
#define BINARYTREE_LEVELORDER_TRAVERSAL

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
	vector<vector<int> > levelOrder(TreeNode *root);
};

vector<vector<int> > Solution::levelOrder(TreeNode *root)
{
	vector<vector<int> > res;
	if (!root) return res;

	queue<TreeNode *> queue;
	queue.push(root);
	// numbers of each level
	int currLevel= 1;

	while(!queue.empty())
	{
		int nextLevel= 0;
		vector<int> level;

		for (int i = 0; i < currLevel; i++)
		{
			TreeNode *cur = queue.front();
			queue.pop();
			level.push_back(cur->val);

			if (cur->left)
			{
				queue.push(cur->left);
				nextLevel++;
			}
			if (cur->right)
			{
				queue.push(cur->right);
				nextLevel++;
			}
		}

		res.push_back(level);		
		currLevel = nextLevel;
	}
}

#endif /* BINARYTREE_LEVELORDER_TRAVERSAL */
