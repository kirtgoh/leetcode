#include <gtest/gtest.h>
#include <fstream>
#include <PrintMacros.h>

#include <binders.h>
#include <Binary_Tree_Postorder_Traversal.h>

class BinaryTreePostorderTraversal : public :: testing :: Test
{
public:
  Solution slu;

  BinaryTree bt;
  ifstream infile;

  BinaryTreePostorderTraversal ()
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

TEST_F(BinaryTreePostorderTraversal, postorderTraversal)
{
  // bt.printPretty(bt.root, 1, 0, std::cout);
  // vector<int> res = slu.preorderTraversal(bt.root);
  vector<int> res = slu.postorderTraversal(bt.root);
  // for(size_t i = 0; i < res.size(); i++)
  //   cout << res[i] << ' ';

};

