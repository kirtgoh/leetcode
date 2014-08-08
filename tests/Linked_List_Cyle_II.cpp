#include <gtest/gtest.h>

#include <fstream>
#include <PrintMacros.h>
#include <Linked_List_Cycle_II.h>

class ListCycleTest : public :: testing :: Test
{
public:
  Solution slu;
  SingleList sl;

  std::ifstream infile;
  ListCycleTest()
  {
    infile.open("files/singlelist.file"); 
    if (!infile.is_open())
      ERROR("file is not opened!");

    sl.buildList(sl.head,infile);
  }

  void TearDown()
  {
    infile.close();
  }
};

TEST_F(ListCycleTest, detectCycle)
{
  ListNode *head = new ListNode(1);  
  ASSERT_EQ(slu.detectCycle(head),(ListNode *)0); 

  head->next = head;
  ASSERT_EQ(slu.detectCycle(head), head);

  head->next = new ListNode(2);
  ASSERT_EQ(slu.detectCycle(head), (ListNode *)0);

  // 1->2->3->4->5->6->2
  ListNode *p = head->next;

  p->next = new ListNode(3);
  p->next->next = new ListNode(4);
  p->next->next->next = new ListNode(5);
  p->next->next->next->next = new ListNode(6);
  p->next->next->next->next->next = p;

  // p = head;
  // for (size_t i = 0; i < 7; i++)
  // {
  //   std::cout << p->val << ' '; 
  //   p = p->next;
  // }
  ASSERT_EQ(slu.detectCycle(head)->val, 2);

  ASSERT_EQ(slu.detectCycle(sl.head), (ListNode*)0);
  

}
