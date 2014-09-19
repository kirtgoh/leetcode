#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <bintree.h>
#include <Balanced_Binary_Tree.h>

class BalancedBinaryTreeTest: public :: testing :: Test
{
public:
	Solution slu;
  BinaryTree bt;
  ifstream infile;

  BalancedBinaryTreeTest()
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

TEST_F(BalancedBinaryTreeTest, isBalanced)
{
  // bt.printPretty(bt.root, 1, 12, std::cout);
	ASSERT_EQ(slu.isBalanced(bt.root), true);
}

