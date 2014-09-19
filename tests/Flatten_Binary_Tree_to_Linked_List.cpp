#include <gtest/gtest.h>
#include <bintree.h>
#include <fstream>
#include <PrintMacros.h>

#include <Flatten_Binary_Tree_to_Linked_List.h>

class FlattenBinaryTreeTest : public :: testing :: Test
{
public:
  Solution slu;
  BinaryTree bt;

  ifstream infile;
  FlattenBinaryTreeTest()
  {
    // binary tree file
    infile.open("files/preorder.file");
    if (!infile.is_open())
      ERROR("file is not opened!");

    // deserialize binary tree
    bt.buildBinaryTree(infile);
  }

  void TearDown ()
  {
    infile.close();
  }
};

TEST_F(FlattenBinaryTreeTest, isSameTree)
{
  	// bt.printPretty(bt.root, 1, 12, std::cout);
	slu.flatten(bt.root);
  	// bt.printPretty(bt.root, 1, 12, std::cout);
}

