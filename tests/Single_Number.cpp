#include <gtest/gtest.h>
#include <Single_Number.h>


class SingleNumberTest : public :: testing :: Test
{
public:
    Solution slu;
    SingleNumberTest() {}
};

TEST_F(SingleNumberTest,singleNumber)
{
    int A[] = {1,2,1,3,4,2,4};
    ASSERT_EQ(slu.singleNumber(A,7), 3);
} 
