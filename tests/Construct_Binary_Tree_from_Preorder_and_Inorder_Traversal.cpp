#include <gtest/gtest.h>

#include <bintree.h>
#include <Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.h>

class BuildBinaryTree : public :: testing :: Test {
public:
  Solution slu;
  BinaryTree bt;
  BuildBinaryTree()
  {

  }
};

TEST_F(BuildBinaryTree, PreAndInOrder)
{
  vector<int> preorder = {3,12,5};
  vector<int> inorder= {12,3,5};
  
  slu.buildTree(preorder, inorder);
  // bt.printPretty(slu.buildTree(preorder, inorder), 1, 0, std::cout);

}
