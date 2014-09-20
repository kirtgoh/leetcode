/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 20, 2014
 *  Problem:     	Convert Sorted List to Binary Search Tree
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 *
 *  Notes:
 * 	Given a singly linked list where elements are sorted in ascending order,
 * 	convert it to a height balanced BST.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef SORTED_LIST_TO_BINARYTREE
#define SORTED_LIST_TO_BINARYTREE

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 ** Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bintree.h>
#include <singlelist.h>

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head);
};

TreeNode* Solution::sortedListToBST(ListNode *head)
{
	if (!head) return NULL;

	// Find mid of the list; 
	ListNode *pre_slow = NULL;	// pre_slow is end of the former list
	ListNode *slow = head;	
	ListNode *fast = head;

	while(fast && fast->next)
	{
		pre_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *rear = slow->next;

	// gen root
	TreeNode *root = new TreeNode(slow->val);

	// gen left, NOTE: former list may NULL or head
	if(pre_slow)
	{
		pre_slow->next = NULL;
		root->left = sortedListToBST(head);
	}
	else
	{
		root->left = NULL;
	}

	// gen right
	root->right = sortedListToBST(rear);

	return root;
}
#endif /* SORTED_LIST_TO_BINARYTREE */

