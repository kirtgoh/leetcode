#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <bintree.h>
#include <Binary_Tree_Level_Order_Traversal.h>

class BinaryTreeLevelTraversal: public :: testing :: Test
{
public:
	Solution slu;
  BinaryTree bt;
  ifstream infile;

  BinaryTreeLevelTraversal()
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

TEST_F(BinaryTreeLevelTraversal, printPretty)
{
  // bt.printPretty(bt.root, 1, 12, std::cout);
  vector<vector<int> > res;
  res = slu.levelOrder(bt.root);
  // for (size_t i = 0; i < res.size(); i++)
  // {
	//   for (size_t j = 0; j < res[i].size(); j++)
	//   {
	//   	cout << res[i][j] << " ";	
	//   }
	//  	cout << endl; 
  // }
  
}

