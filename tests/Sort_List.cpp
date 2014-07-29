#include <gtest/gtest.h>

#include <fstream>
#include <Sort_List.h>
#include <PrintMacros.h>

class SortListTest : public :: testing :: Test
{
public:
  Solution slu;
  SingleList sl;  // superstl/singlelist.h

  std::ifstream infile;

  SortListTest ()
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


TEST_F(SortListTest, sortList)
{
  // sl.printList(sl.head);
  slu.sortList(sl.head);
  // sl.printList(slu.sortList(sl.head));
}
