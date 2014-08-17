#include <gtest/gtest.h>
#include <Palindrome_Partitioning.h>


class PalindromePartitioningTest : public :: testing :: Test
{
public:
    Solution slu;
    PalindromePartitioningTest() {}
};

TEST_F(PalindromePartitioningTest, partition)
{
    string s = "cdd";
    vector<vector<string> > res;
    res = slu.partition(s);

    // for (size_t i = 0; i < res.size(); i++)
    // {
    //    for (size_t j = 0; j < res[i].size(); j++)
    //    {
    //        cout << res[i][j] << ' ';
    //    }
    //    cout << endl;
    // }
}
