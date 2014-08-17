/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 17, 2014
 *  Problem:     	Sum of all root-to-leaf numbers
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 *
 *  Notes:
 * 	Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * 	could represent a number.
 *
 * 	An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * 	Find the total sum of all root-to-leaf numbers.
 *
 * 	For example,
 *
 * 	    1
 * 	   / \
 * 	  2   3
 * 	The root-to-leaf path 1->2 represents the number 12.
 * 	The root-to-leaf path 1->3 represents the number 13.
 *
 * 	Return the sum = 12 + 13 = 25.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef ROOT_TO_LEAF_NUMBERS_H
#define ROOT_TO_LEAF_NUMBERS_H

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
    int sumNumbers(TreeNode *root);
    void dfs(TreeNode *root, int result, int &sum);
};

int Solution::sumNumbers(TreeNode *root)
{
    if (!root) return 0;
    int sum(0), result(0);

    dfs(root, result, sum);

    return sum;
}

void Solution::dfs(TreeNode *root, int result, int &sum)
{
    result += root->val;

    if (!root->left && !root->right)
    {
        sum += result;
        return;
    }

    if (root->left) dfs(root->left, result * 10, sum);
    if (root->right) dfs(root->right, result * 10, sum);
}

#endif /* ROOT_TO_LEAF_NUMBERS_H */
