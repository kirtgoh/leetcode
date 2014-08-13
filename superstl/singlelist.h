//=====================================================================================
// singlelist - SingleList Header
//
// Copyright (C) 2014 Kirt Goh <kirtgoh@gmail.com>
//=====================================================================================

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class SingleList
{ // class SingleList
public:
  SingleList (): head(NULL) {}

  void buildList(ListNode *&head,std::istream &in);
  void printList(ListNode *head);
  //field
  ListNode *head;
private:
  
};

#endif /* SINGLE_LIST_H */
