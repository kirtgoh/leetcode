#include <gtest/gtest.h>
#include <bintree.h>
#include <PrintMacros.h>
#include <fstream>

#include <Path_Sum.h>

class PathSumTest: public :: testing :: Test
{
public:
	Solution slu;

	ifstream infile;
	BinaryTree bt;

	PathSumTest()
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

TEST_F(PathSumTest, hasPathSum)
{
  	// bt.printPretty(bt.root, 1, 12, std::cout);
	ASSERT_EQ(slu.hasPathSum(bt.root, 12), true);
}

