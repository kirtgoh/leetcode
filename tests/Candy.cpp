#include <gtest/gtest.h>
#include <Candy.h>

class CandyTest : public :: testing :: Test
{
public:
    Solution slu;
    CandyTest() {}
};

TEST_F(CandyTest, candy)
{
    vector<int> ratings = { 1, 2, 1, 3, 4, 5, 2, 1, 7, 2, 4, 3, 6, 5, 2, 1};
    ASSERT_EQ(slu.candy(ratings), 32);
}
