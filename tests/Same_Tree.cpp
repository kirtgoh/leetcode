#include <gtest/gtest.h>
#include <bintree.h>
#include <fstream>
#include <PrintMacros.h>

#include <Same_Tree.h>

class SameTreeTest : public :: testing :: Test
{
public:
  Solution slu;
  BinaryTree bt1;
  BinaryTree bt2;

  ifstream in1;
  ifstream in2;
  SameTreeTest()
  {
    // binary tree file
    in1.open("files/preorder.file");
    in2.open("files/preorder1.file");
    if (!in1.is_open() || !in2.is_open())
      ERROR("file is not opened!");

    // deserialize binary tree
    bt1.buildBinaryTree(in1);
    bt2.buildBinaryTree(in2);
  }

  void TearDown ()
  {
    in1.close();
    in2.close();
  }
};

TEST_F(SameTreeTest, isSameTree)
{
  ASSERT_EQ(slu.isSameTree(bt1.root, bt2.root), false);

}
