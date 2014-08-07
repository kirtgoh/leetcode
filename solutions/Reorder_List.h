/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 06, 2014
 *  Problem:     	Reorder List
 *  Difficulty:   Medium	
 *  Source:      	https://oj.leetcode.com/problems/reorder-list/
 *
 *  Notes:
 * 	Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * 	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * 	You must do this in-place without altering the nodes' values.
 *
 * 	For example,
 * 	Given {1,2,3,4}, reorder it to {1,4,2,3}
 *
 *  Solution: 		
*********************************************************************************/

#ifndef REORDER_LIST_H
#define REORDER_LIST_H

#include <singlelist.h>
#include <PrintMacros.h>
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
    void reorderList(ListNode *head);
};

void Solution::reorderList(ListNode *head)
{
  if (!head) return;

  // 1. Find mid and split list into two lists;
  ListNode *p1 = head;
  ListNode *p2 = head;

  // p2 points to the Mid of the list
  // NOTE: when greater 3 nodes, need loop
  while(p2->next && p2->next->next)
  {
    p1 = p1->next;
    p2 = p2->next->next;
  }

  p2 = p1->next;
  p1->next = NULL;
  p1 = head;

  // 2. Reverse list
  // NOTE: at least two nodes
  if (p2 && p2->next)
  {
    ListNode *pre = p2;
    ListNode *cur = p2->next;
    ListNode *nex = cur->next;
    pre->next = NULL;

    while(cur)
    {
      cur->next = pre;
      pre = cur;
      cur = nex;
      // NOTE: cur may NULL
      if (cur)
        nex = cur->next;
    }
    p2 = pre;
  }

  // 3. Merge two list
  ListNode *tmp;
  while(p1 && p2)
  {
    tmp = p1->next;

    p1->next = p2;
    p2 = p2->next;

    p1->next->next = tmp;
    p1 = tmp;
  }
}

#endif /* REORDER_LIST_H */
