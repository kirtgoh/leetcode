#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <bintree.h>

class BinaryTreeTest : public :: testing :: Test
{
public:
  BinaryTree bt;
  ifstream infile;
  // ofstream outfile;

  BinaryTreeTest ()
  {
    infile.open("files/preorder.file");
    if (!infile.is_open())
      ERROR("file is not opened!");

    // outfile.open("files/pretty.file");
    // if (!outfile.is_open())
    //   ERROR("file is not opened!");
    //
    bt.buildBinaryTree(infile);
  }

  void TearDown()
  {
    infile.close();
    // outfile.close();
  }
};

// TEST_F(BinaryTreeTest, printLevel)
// {
//   bt.printLevel(bt.root);
// }
//
// TEST_F(BinaryTreeTest, printLevel2)
// {
//   bt.printLevel2(bt.root);
// }
//
TEST_F(BinaryTreeTest, printPretty)
{
  // bt.printPretty(bt.root, 1, 12, std::cout);
}
