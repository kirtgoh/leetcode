#include <gtest/gtest.h>
#include <fstream>
#include <PrintMacros.h>

#include <binders.h>
#include <Binary_Tree_Zigzag_Level_Order_Traversal.h>

class BinaryTreeZigzagTraversal : public :: testing :: Test
{
public:
  Solution slu;

  BinaryTree bt;
  ifstream infile;

  BinaryTreeZigzagTraversal ()
  {
    infile.open("files/preorder.file");
    if (!infile.is_open())
      ERROR("file is not opened!");

    bt.buildBinaryTree(infile);
  }

  void TearDown()
  {
    infile.close();
  }

};

TEST_F(BinaryTreeZigzagTraversal, zigzagLevelOrder)
{
  vector<vector<int> > da = {{3},{20,9},{15,7}};
  vector<vector<int> > re = slu.zigzagLevelOrder(bt.root);
  // bt.printPretty(bt.root, 1, 0, std::cout);

  ASSERT_EQ(da, re);

};

