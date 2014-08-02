#include <gtest/gtest.h>
#include <fstream>
#include <PrintMacros.h>

#include <binders.h>
#include <Binary_Tree_Preorder_Traversal.h>

class BinaryTreePreorderTraversal : public :: testing :: Test
{
public:
  Solution slu;

  BinaryTree bt;
  ifstream infile;

  BinaryTreePreorderTraversal ()
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

TEST_F(BinaryTreePreorderTraversal, preorderTraversal)
{
  // bt.printPretty(bt.root, 1, 0, std::cout);
  // vector<int> res = slu.preorderTraversal(bt.root);
  vector<int> res = slu.preorderTraversal(NULL);
  for(size_t i = 0; i < res.size(); i++)
    cout << res[i] << ' ';

};

