#include <gtest/gtest.h>
#include <Best_Time_to_Buy_and_Sell_Stock.h>

class BestTimetoBuyandSellStock: public :: testing :: Test
{
public:
    Solution slu;
    BestTimetoBuyandSellStock() {}
};

TEST_F(BestTimetoBuyandSellStock, maxProfit)
{
    vector<int> prices = { 1, 2, 1, 3, 4, 5, 2, 1, 7, 2, 4, 3, 6, 5, 2, 1};
    // vector<int> prices = { 1, 2 };
    ASSERT_EQ(slu.maxProfit(prices), 6);
}

