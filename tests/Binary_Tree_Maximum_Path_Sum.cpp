#include <gtest/gtest.h>
#include <Binary_Tree_Maximum_Path_Sum.h>
#include <fstream>
#include <PrintMacros.h>

class BinaryTreeMaximumPathSum : public :: testing :: Test
{
public:
	Solution slu;

	BinaryTreeMaximumPathSum()
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

	BinaryTree bt;
	ifstream infile;
};


TEST_F(BinaryTreeMaximumPathSum, maxPathSum)
{
  // bt.printPretty(bt.root, 1, 12, std::cout);
  ASSERT_EQ(slu.maxPathSum(bt.root), 47);
}

