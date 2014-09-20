#include <gtest/gtest.h>

#include <fstream>
#include <PrintMacros.h>
#include <Convert_Sorted_Array_to_Binary_Search_Tree.h>

class SortedArrayToBinaryTree: public :: testing :: Test
{
public:
  Solution slu;

  BinaryTree bt;
  std::ifstream infile;

};


TEST_F(SortedArrayToBinaryTree, sortList)
{
  // sl.printList(sl.head);
  vector<int> num = {1,2,3,4,5,6};
  // vector<int> num = {}
  TreeNode *root = slu.sortedArrayToBST(num);
  // bt.printPretty(root, 1, 12, std::cout);
}

