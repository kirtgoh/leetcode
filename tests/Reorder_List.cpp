#include <gtest/gtest.h>

#include <fstream>
#include <Reorder_List.h>
#include <PrintMacros.h>

class ReorderListTest: public :: testing :: Test
{
public:
  Solution slu;
  SingleList sl;  // superstl/singlelist.h

  std::ifstream infile;

  ReorderListTest()
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


TEST_F(ReorderListTest, reorderList)
{
  // sl.printList(sl.head);
  slu.reorderList(sl.head);
  // sl.printList(slu.reorderList(sl.head));
  // sl.printList(sl.head);
}
