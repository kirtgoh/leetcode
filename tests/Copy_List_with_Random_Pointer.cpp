#include <gtest/gtest.h>

#include <fstream>
#include <Copy_List_with_Random_Pointer.h>
#include <PrintMacros.h>

class DeepCopyListTest : public :: testing :: Test
{
public:
  Solution slu;

  DeepCopyListTest ()
  {
  }

  void TearDown()
  {
  }
};


TEST_F(DeepCopyListTest, copyRandomList)
{
  RandomListNode *list;
  list = new RandomListNode(12);
  list->next = new RandomListNode(13);
  list->next->next = new RandomListNode(14);
  list->next->next->next = new RandomListNode(15);

  list->random = list->next->next;
  list->next->next->next->random = list->next;

  RandomListNode *head;
  head = slu.copyRandomList(list);

  // cout << list->random->label;
  // cout << list->next->next->next->random->label;
  // cout << head->label;
  // cout << head->next->label;
  // cout << head->next->next->label;
  // cout << head->next->next->next->label;
}
