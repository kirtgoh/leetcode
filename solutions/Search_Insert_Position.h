/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 29, 2014
 *  Problem:     	Search Insert Position
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/search-insert-position
 *
 *  Notes:
 * 	Given a sorted array and a target value, return the index if the target is
 * 	found. If not, return the index where it would be if it were inserted in
 * 	order.
 *
 * 	You may assume no duplicates in the array.
 *
 * 	Here are few examples.
 * 	[1,3,5,6], 5 → 2
 * 	[1,3,5,6], 2 → 1
 * 	[1,3,5,6], 7 → 4
 * 	[1,3,5,6], 0 → 0
 *
 *  Solution: 		
*********************************************************************************/

#ifndef SEARCH_INSERTPOS_H
#define SEARCH_INSERTPOS_H

class Solution {
  public:
    int searchInsert(int A[], int n, int target);
};

int Solution::searchInsert(int A[], int n, int target)
{
  int left = 0 , right = n - 1;
  while (left < right)
  {
    int mid = (left + right) / 2;

    if (target > A[mid]) left = mid + 1;
    else right = mid - 1;
  }

  return  target <= A[left] ? left: left + 1;
}

#endif /* SEARCH_INSERTPOS_H */
