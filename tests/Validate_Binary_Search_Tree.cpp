#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <bintree.h>
#include <Validate_Binary_Search_Tree.h>

class ValidateBST: public :: testing :: Test
{
public:
	Solution slu;
  BinaryTree bt;
  ifstream infile;

  ValidateBST()
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

TEST_F(ValidateBST, isValidBST)
{
  // bt.printPretty(bt.root, 1, 12, std::cout);
	ASSERT_EQ(slu.isValidBST(bt.root), true);
}


