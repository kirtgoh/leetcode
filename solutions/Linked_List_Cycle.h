/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 08, 2014
 *  Problem:     	Linked List Cycle
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/linked-list-cycle/
 *
 *  Notes:
 * 	Given a linked list, determine if it has a cycle in it.
 *
 * 	Follow up:
 * 	Can you solve it without using extra space?
 *
 *  Solution: 		
 *********************************************************************************/

#ifndef LIST_CYCLE_H
#define LIST_CYCLE_H

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
  bool hasCycle(ListNode *head);
};

bool Solution::hasCycle(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }

  return false;
}

#endif /* LIST_CYCLE_H */
