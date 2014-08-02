/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 02, 2014
 *  Problem:     	Insertion Sort List
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/insertion-sort-list/
 *
 *  Notes:
 *  Sort a linked list using insertion sort.
 * 	
 *  Solution: 		
*********************************************************************************/

#ifndef INSERTION_SORTLIST_H
#define INSERTION_SORTLIST_H

#include <singlelist.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *
 * };
 */

class Solution {
  public:
    ListNode *insertionSortList(ListNode *head);
};

ListNode *Solution::insertionSortList(ListNode *head)
{
  if (!head) return NULL;

  ListNode *unsorted= head->next;
  head->next = NULL;

  while(unsorted)
  {
    ListNode *sorted = head;
    ListNode *insPos = NULL;
    while(sorted && sorted->val <= unsorted->val)
    {
      insPos = sorted;
      sorted = sorted->next;
    }

    ListNode *tmp = unsorted;
    unsorted = unsorted->next;

    if (!insPos)
    {
      tmp->next = head;
      head = tmp;
    }
    else
    {
      tmp->next = insPos->next;
      insPos->next = tmp;
    }

  }
  return head;
}

#endif /* INSERTION_SORTLIST_H */
