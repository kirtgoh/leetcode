#include "superstl/bintree.h"
#include "superstl/PrintMacros.h"
#include <fstream>


int main(int , char **)
{
  BinaryTree bt;
  ifstream infile;
  ofstream outfile;

  // infile.open("./inorder.file");
  // infile.open("preorder.file");
  // if (!infile.is_open())
    // ERROR("file is not open!");


  // bt.buildBinaryTree(infile);
  // bt.printTree();

  // infile.close();
  
  infile.open("preorder.file");
  outfile.open("serialout.file");
  if (!outfile.is_open())
  {
    ERROR("file is not open!");
  }

  bt.buildBinaryTree(infile);
  bt.storeBinaryTree(outfile);


  return 0;

}
