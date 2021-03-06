/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 07, 2014
 *  Problem:     	Linked List Cycle II
 *  Difficulty:  	Medium
 *  Source:      	https://oj.leetcode.com/problems/linked-list-cycle-ii/
 *
 *  Notes:
 * 	Given a linked list, return the node where the cycle begins. If there is no
 * 	cycle, return null.
 *
 * 	Follow up:
 * 	Can you solve it without using extra space?
 *
 *  Solution: 		
*********************************************************************************/

#ifndef LIST_CYCLE_II_H
#define LIST_CYCLE_II_H

#include <singlelist.h>

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head);
};

ListNode *Solution::detectCycle(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;

  bool hasCycle = false;
  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      hasCycle = true;
      break;
    }
  }

  // Ring exists
  if (hasCycle)
  {
    slow = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
  return NULL;
}

#endif /* LIST_CYCLE_II_H */
