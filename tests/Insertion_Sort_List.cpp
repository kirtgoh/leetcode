#include <gtest/gtest.h>

#include <fstream>
#include <Insertion_Sort_List.h>
#include <PrintMacros.h>

class InsertionSortList: public :: testing :: Test
{
public:
  Solution slu;
  SingleList sl;  // superstl/singlelist.h

  std::ifstream infile;

  InsertionSortList()
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


TEST_F(InsertionSortList, insertionSortList)
{
  // sl.printList(sl.head);
  slu.insertionSortList(sl.head);
  // sl.printList(slu.insertionSortList(sl.head));
}
