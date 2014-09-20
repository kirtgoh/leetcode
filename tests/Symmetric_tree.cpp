#include <gtest/gtest.h>
#include <fstream>
#include <PrintMacros.h>

#include <binders.h>
#include <Symmetric_Tree.h>

class SymmetricTreeTest: public :: testing :: Test
{
public:
  Solution slu;

  BinaryTree bt;
  ifstream infile;

  SymmetricTreeTest()
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

TEST_F(SymmetricTreeTest, isSymmetric)
{
 	// bt.printPretty(bt.root, 1, 0, std::cout);
	ASSERT_EQ(slu.isSymmetric(bt.root), false);
};


