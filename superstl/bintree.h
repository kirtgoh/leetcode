//=====================================================================================
// bintree.h - BinaryTree Header
//
// Copyright (C) 2014 Kirt Goh <kirtgoh@gmail.com>
//=====================================================================================

#ifndef BINTREE_H
#define BINTREE_H

#include <fstream>

using namespace std;

class BinaryTree
{
protected:
  struct TreeNode
  {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

public:
  // constructor
  BinaryTree():root(NULL) {} 

  // functions
  void buildBinaryTree(ifstream &in);   // Build binary tree form file
  void storeBinaryTree(ofstream &out);
  void printTree();                     // Print binary tree pretty

private:
  // functions
  void serialize(TreeNode *p, ofstream &out);
  void deserialize(TreeNode *&p, ifstream &in);
  void printPostorder(TreeNode *p, int indent);
  // filed
  TreeNode *root;

};

#endif /* BINTREE_H */
