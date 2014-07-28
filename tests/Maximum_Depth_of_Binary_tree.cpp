#include <gtest/gtest.h>

#include <Maximum_Depth_of_Binary_tree.h>
#include <PrintMacros.h>
#include <fstream>

class BinaryTreeDepthTest : public :: testing :: Test
{
public:
  Solution slu;
  BinaryTree bt;    // superstl/bintree.h

  ifstream infile;

  BinaryTreeDepthTest() {}

  void TearDown()
  {
    infile.close();
  }
};

TEST_F(BinaryTreeDepthTest, maxDepth)
{
  // binary tree file
  infile.open("files/preorder.file");
  if (!infile.is_open())
    ERROR("file is not opened!");

  // deserialize binary tree
  bt.buildBinaryTree(infile);


  ASSERT_EQ(slu.maxDepth(bt.root),3);
}
