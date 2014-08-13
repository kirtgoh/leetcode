/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 13, 2014
 *  Problem:     	Find single elemnt in an array of integers
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/single-number/
 *
 *  Notes:
 * 	Given an array of integers, every element appears twice except for one. Find
 * 	that single one.
 *
 * 	Note:
 * 	Your algorithm should have a linear runtime complexity. Could you implement
 * 	it without using extra memory?
 *
 *  Solution:       XOR
*********************************************************************************/

#ifndef SINGLE_NUMBER_H
#define SINGLE_NUMBER_H

class Solution {
public:
    int singleNumber(int A[], int n);
};

int Solution::singleNumber(int A[], int n)
{
    for (int i = 1; i < n; i++)
        A[0] ^= A[i];
    return A[0];
}

#endif /* SINGLE_NUMBER_H */

