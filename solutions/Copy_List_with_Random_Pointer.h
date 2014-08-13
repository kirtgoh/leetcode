/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 09, 2014
 *  Problem:     	Copy List with Random Pointer
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/copy-list-with-random-pointer/
 *
 *  Notes:
 * 	A linked list is given such that each node contains an additional random
 * 	pointer which could point to any node in the list or null.
 *
 * 	Return a deep copy of the list.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef COPY_RANDOM_POINTER_LIST_H
#define COPY_RANDOM_POINTER_LIST_H

#include <singlelist.h>
#include <unordered_map>

using namespace std;

/*
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution
{
public:
  RandomListNode *copyRandomList(RandomListNode *head);
};

RandomListNode *Solution::copyRandomList(RandomListNode *head)
{ // hash['originNode'] = targetNode;
  if (!head) return NULL;

  unordered_map<RandomListNode *, RandomListNode *> hash;

  // Init return list
  RandomListNode *list = new RandomListNode(head->label);
  hash[head] = list;

  RandomListNode *p = head->next;
  RandomListNode *q = list;

  while(p)
  { // while(head) construct random;
    q->next = new RandomListNode(p->label);
    hash[p] = q->next;

    p = p->next;
    q = q->next;
  }

  p = head;
  q = list;
  while(p)
  { //  when origin->random -->orignNode;
    //  target->random = hash['originNode'];
    if (p->random)
      q->random = hash[p->random];

    p = p->next;
    q = q->next;
  }

  return list;
}

#endif /* COPY_RANDOM_POINTER_LIST_H */
