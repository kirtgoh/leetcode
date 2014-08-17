#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <Sum_Root_to_Leaf_Numbers.h>
#include <bintree.h>

class SumRoottoLeafNumbers : public :: testing :: Test
{
public:
    Solution slu;
    BinaryTree bt;

    ifstream infile;
    SumRoottoLeafNumbers()
    {
        infile.open("files/root_leaf_numbers.file");
        if (!infile.is_open())
          ERROR("file is not opened!");

        bt.buildBinaryTree(infile);
    }
};

TEST_F(SumRoottoLeafNumbers, sumNumbers)
{
    // bt.printPretty(bt.root, 1 ,12, std::cout);
    ASSERT_EQ(slu.sumNumbers(bt.root), 53);
} 
