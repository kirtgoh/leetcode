#include <gtest/gtest.h>

#include <fstream>
#include <PrintMacros.h>
#include <Convert_Sorted_List_to_Binary_Search_Tree.h>

class SortedListToBinaryTree: public :: testing :: Test
{
public:
  Solution slu;
  SingleList sl;  // superstl/singlelist.h

  BinaryTree bt;
  std::ifstream infile;

  SortedListToBinaryTree()
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


TEST_F(SortedListToBinaryTree, sortList)
{
  // sl.printList(sl.head);
  TreeNode *root = slu.sortedListToBST(sl.head);
  // bt.printPretty(root, 1, 12, std::cout);
}
