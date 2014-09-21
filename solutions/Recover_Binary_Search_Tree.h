/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 20, 2014
 *  Problem:     	Recover Binary Search Tree
 *  Difficulty:  	Medium	
 *  Source:      	https://oj.leetcode.com/problems/recover-binary-search-tree/
 *
 *  Notes:
 * 	Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * 	Recover the tree without changing its structure.
 *
 * 	Note:
 * 	A solution using O(n) space is pretty straight forward. Could you devise a
 * 	constant space solution?
 *
 *  Solution: 		
*********************************************************************************/

#ifndef RECOVER_BST
#define RECOVER_BST

#include <bintree.h>
#include <stack>

class Solution {
public:
	void recoverTree(TreeNode *root);
};

void Solution::recoverTree(TreeNode *root)
{
	// find 1st pointer, 2nd pointer
	// change their value
	stack<TreeNode *> stack;
	TreeNode *p = root;

	// p1, p2 indicate adjacent pointer
	TreeNode *e1, *e2, *p1, *p2;
	e1 = e2 = p1 = p2 = NULL;

	while(p || !stack.empty())
	{
		if (p)
		{
			stack.push(p);
			p = p->left; 
		}

		// p is may left null or right null
		else if (!stack.empty())
		{
			p = stack.top();
			stack.pop();

			p1 = p2; p2 = p;

			if (p1)
			{
				// e1 used to check if the first one
				if (!e1 && p1->val > p2->val) e1 = p1;
				if (p1->val > p2->val) e2 = p2;
			}

			p = p->right;
		}
	}

	swap(e1->val,e2->val);
}

#endif /* RECOVER_BST */

