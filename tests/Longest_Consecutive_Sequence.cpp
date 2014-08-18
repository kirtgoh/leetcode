#include <gtest/gtest.h>
#include <Longest_Consecutive_Sequence.h>

class LongestConsecutiveSequenceTest : public :: testing :: Test
{
public:
	Solution slu;
	LongestConsecutiveSequenceTest () {}

};

TEST_F(LongestConsecutiveSequenceTest, longestConsecutive)
{
	vector<int> num = {100, 4, 200, 1, 3, 2};
	ASSERT_EQ(slu.longestConsecutive(num), 4);
}
