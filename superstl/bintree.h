//=====================================================================================
// bintree.h - BinaryTree Header
//
// Copyright (C) 2014 Kirt Goh <kirtgoh@gmail.com>
//=====================================================================================

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree
{
public:
  // constructor
  BinaryTree():root(NULL) {} 

  // functions
  void buildBinaryTree(istream &in);   // Build binary tree form file
  void storeBinaryTree(ostream &out);
  void printTree();                     // Print binary tree pretty
  int maxDepth(TreeNode *root);         // slu-2: Maximum_Depth_of_Binary_tree

  void printLevel(TreeNode *root);
  void printLevel2(TreeNode *root);     // one queue impel
  void printPretty(TreeNode *root, int level, int indent, ostream& out);
  // filed
  TreeNode *root;       // make it public, for test convenience

private:
  // functions
  void serialize(TreeNode *p, ostream &out);
  void deserialize(TreeNode *&p, istream &in);
  void printPostorder(TreeNode *p, int indent);

  void printBranches(int len, int span, int start, int numNodes, const deque<TreeNode *>& queue, ostream& out);
  void printNodes(int len, int span, int start, int numNodes, const deque<TreeNode *>& queue, ostream& out);
  void printLeaves(int indent, int level, int numNodes, const deque<TreeNode *>& queue, ostream& out);
};

#endif /* BINTREE_H */
