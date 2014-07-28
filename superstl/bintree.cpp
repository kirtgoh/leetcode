//=====================================================================================
// bintree.cpp - BinaryTree Implementation
//
// Copyright (C) 2014 Kirt Goh <kirtgoh@gmail.com>
//=====================================================================================

#include "bintree.h"
#include <iostream>
#include <cstdlib>     // atoi
#include <iomanip>     // std::setw
#include <queue>
#include <math.h>
// #include <string>

void BinaryTree::serialize(TreeNode *p, ostream &out)
{
  if (!p) {
    out << "# ";
  } else {
    serialize(p->left, out);
    out << p->val << " ";
    serialize(p->right, out);
  }
}

void BinaryTree::deserialize(TreeNode *&p, istream &in)
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

void BinaryTree::buildBinaryTree(istream &in)
{
  deserialize(root, in);
}

void BinaryTree::storeBinaryTree(ostream &out)
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

int BinaryTree::maxDepth(TreeNode *root)
{
  if (!root) return 0;
  else return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}
void BinaryTree::printLevel(TreeNode *root)
{
  if (!root) return;

  queue<TreeNode *> curr, next;
  curr.push(root);

  while (!curr.empty()) {
    TreeNode *p = curr.front();
    curr.pop();
    if (p) {
      cout << p->val << " ";
      next.push(p->left);
      next.push(p->right);
    }
    if (curr.empty()) {
      cout << endl;
      swap(curr, next);
    }
  }
}
void BinaryTree::printLevel2(TreeNode *root)
{
  if (!root) return;

  queue<TreeNode *> queue;

  int currNodes = 1;
  int nextNodes = 0;

  queue.push(root);

  while (!queue.empty()) {
    TreeNode *p = queue.front();
    queue.pop();

    currNodes--;
    if (p) {
      cout << p->val << " ";
      queue.push(p->left);
      queue.push(p->right);
      nextNodes += 2;
    }
    if (currNodes == 0) {
      cout << endl;
      currNodes = nextNodes;
      nextNodes = 0;
    }
  }
}
// Print the arm branches (eg, /    \ ) on a line
void BinaryTree::printBranches(int len, int span, int start, int numNodes, const deque<TreeNode *>& queue, ostream& out)
{
  deque<TreeNode *>::const_iterator iter = queue.begin();

  for (int i = 0; i < numNodes / 2; i++) {  
    out << ((i == 0) ? setw(start - 1) : setw(span - 2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2 * len + 2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void BinaryTree::printLeaves(int indent, int level, int numNodes, const deque<TreeNode *>& queue, ostream& out)
{
  deque<TreeNode *>::const_iterator iter = queue.begin();
  for (int i = 0; i < numNodes; i++, iter++) {
    out << ((i == 0) ? setw(indent+2) : setw(2*level+2)) << ((*iter) ? to_string((*iter)->val) : "");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
void BinaryTree::printNodes(int len, int span, int start, int numNodes, const deque<TreeNode *>& queue, ostream& out)
{
  deque<TreeNode *>::const_iterator iter = queue.begin();
  for (int i = 0; i < numNodes; i++, iter++) {
    out << ((i == 0) ? setw(start) : setw(span)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(len+2) << ((*iter) ? to_string((*iter)->val) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(len) << "" << setfill(' ');
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void BinaryTree::printPretty(TreeNode *root, int level, int indent, ostream& out)
{
  int depth = maxDepth(root);

  // number of Nodes in current level
  int numNodes = 1;

  // eq of the length of branch for each node of each level
  int barWidth = 2 * (pow(2.0, depth) -1) - (3 - level) * (int)pow(2.0, depth-1);

  // distance between left neighbor node's right arm and right neighbor node's left arm
  int vBranchWidth = 2 + (level+1)*(int)pow(2.0,depth);  

  // starting space to the first node to print of each level (for the left most node of each level only)
  int startPos = barWidth + (3-level) + indent;  
    
  deque<TreeNode *> queue;
  queue.push_back(root);

  for (int i = 1; i < depth; i++)
  {
    printBranches(barWidth, vBranchWidth, startPos, numNodes, queue, out);
    barWidth = barWidth /2 - 1;
    vBranchWidth = vBranchWidth /2 + 1;
    startPos = barWidth + (3-level) + indent;
    printNodes(barWidth, vBranchWidth, startPos, numNodes, queue, out);

    for (int i = 0; i < numNodes; i++) {
      TreeNode *currNode = queue.front();
      queue.pop_front();
      if (currNode) {
	      queue.push_back(currNode->left);
	      queue.push_back(currNode->right);
      } else {
        queue.push_back(NULL);
        queue.push_back(NULL);
      }
    }
    numNodes *= 2;
  }
  printBranches(barWidth, vBranchWidth, startPos, numNodes, queue, out);
  printLeaves(indent, level, numNodes, queue, out);
}

