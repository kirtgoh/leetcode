/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 31, 2014
 *  Problem:     	Sort List
 *  Difficulty:   Medium	
 *  Source:      	https://oj.leetcode.com/problems/sort-list/
 *
 *  Notes:
 * 	Sort a linked list in O(nlogn) time using constant space complexity.
 *
 *  Solution: 	  merge sort	
 *********************************************************************************/

#ifndef SORT_LIST_H
#define SORT_LIST_H

#include <singlelist.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  public:
    ListNode *sortList(ListNode *head);
    ListNode *mergeList(ListNode *head1, ListNode *head2);
};

ListNode *Solution::mergeList(ListNode *head1, ListNode *head2)
{
  if (!head1) return head2;
  if (!head2) return head1;

  ListNode *root;
  if (head1->val <= head2->val)
  {  
    root = head1;
    head1 = head1->next;
  }
  else
  {
    root = head2;
    head2 = head2->next;
  }
  root->next = mergeList(head1, head2);
  return root;
}

ListNode *Solution::sortList(ListNode *head)
{
  if(!head) return NULL; 

  ListNode *head1 = head; 
  ListNode *head2 = head; 

  if(!head1->next)
    return head1; 

  while(head2->next && head2->next->next) 
  { 
    head1 = head1->next; 
    head2 = head2->next->next; 
  } 

  head2 = head1->next; 
  head1->next = NULL; 

  head1 = head; 
  return mergeList(sortList(head1), sortList(head2)); 
}

#endif /* SORT_LIST_H */
