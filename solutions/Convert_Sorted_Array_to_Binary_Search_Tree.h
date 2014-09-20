/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 20, 2014
 *  Problem:     	Convert Sorted Array to Binary Search Tree
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 *
 *  Notes:
 * 	Given an array where elements are sorted in ascending order, convert it to a
 * 	height balanced BST.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef SORTED_ARRAY_TO_BINARYTREE
#define SORTED_ARRAY_TO_BINARYTREE

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
	TreeNode *sortedArrayToBST(vector<int> &num);
	TreeNode *sortedArrayToBSTRe(vector<int> &num, int start, int end);
};

TreeNode *Solution::sortedArrayToBSTRe(vector<int> &num, int start, int end)
{
	if (start > end) return NULL;

	int mid = (start + end) /2;
	TreeNode *root = new TreeNode(num[mid]);

	root->left = sortedArrayToBSTRe(num, start, mid -1);
	root->right= sortedArrayToBSTRe(num, mid + 1, end);

	return root;
}
TreeNode *Solution::sortedArrayToBST(vector<int> &num)
{
	return sortedArrayToBSTRe(num, 0, num.size() - 1);
}

#endif /* SORTED_ARRAY_TO_BINARYTREE */

