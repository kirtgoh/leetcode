#include <gtest/gtest.h>
#include <Gas_Station.h>

class GasStationTest : public :: testing :: Test
{
public:
    Solution slu;
    GasStationTest() {}
};


TEST_F(GasStationTest, canCompleteCircuit)
{
    vector<int> gas = {2, 4 ,3, 6,7};
    vector<int> cost = {3, 4, 5,5,5};
    // vector<int> gas = {5};
    // vector<int> cost = {4};
    ASSERT_EQ(slu.canCompleteCircuit(gas, cost), 3);
}
