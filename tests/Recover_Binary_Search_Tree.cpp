#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <bintree.h>
#include <Recover_Binary_Search_Tree.h>

class RecoverBST: public :: testing :: Test
{
public:
	Solution slu;
  BinaryTree bt;
  ifstream infile;

  RecoverBST()
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

TEST_F(RecoverBST, isBalanced)
{
  // bt.printPretty(bt.root, 1, 12, std::cout);
	slu.recoverTree(bt.root);
  // bt.printPretty(bt.root, 1, 12, std::cout);
}


