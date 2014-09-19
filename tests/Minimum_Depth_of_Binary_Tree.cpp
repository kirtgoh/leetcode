#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <bintree.h>
#include <Minimum_Depth_of_Binary_Tree.h>

class MinDepthOfBinaryTree: public :: testing :: Test
{
public:
	Solution slu;
	BinaryTree bt;
	ifstream infile;

  MinDepthOfBinaryTree()
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

TEST_F(MinDepthOfBinaryTree, minDepth)
{
	// bt.printPretty(bt.root, 1, 12, std::cout);
	ASSERT_EQ(slu.minDepth(bt.root),2);
}

