//=====================================================================================
// bintree.cpp - BinaryTree Implementation
//
// Copyright (C) 2014 Kirt Goh <kirtgoh@gmail.com>
//=====================================================================================

#include "bintree.h"
#include <iostream>
#include <cstdlib>     // atoi
#include <iomanip>     // std::setw

void BinaryTree::serialize(TreeNode *p, ofstream &out)
{
  if (!p) {
    out << "# ";
  } else {
    serialize(p->left, out);
    out << p->val << " ";
    serialize(p->right, out);
  }
}

void BinaryTree::deserialize(TreeNode *&p, ifstream &in)
{

  string str;
  in >> str;

  // NOTE: Not first, otherwise extra TreeNode will create
  if (in.eof()) return;

  if (str != "#")
  {
    int i = atoi(str.c_str());
    p = new TreeNode(i);
    deserialize(p->left, in);
    deserialize(p->right, in);
  }
  return;
}

void BinaryTree::buildBinaryTree(ifstream &in)
{
  deserialize(root, in);
}

void BinaryTree::storeBinaryTree(ofstream &out)
{
  serialize(root,out);
}

void BinaryTree::printPostorder(TreeNode *p, int indent)
{
  if(p)
  {
    if(p->left) printPostorder(p->left, indent+4);
    if(p->right) printPostorder(p->right, indent+4);

    if (indent) {
      std::cout << std::setw(indent) << ' ';
    }
    cout<< p->val << "\n ";
  }
}

void BinaryTree::printTree()
{
  printPostorder(root,0);
}
