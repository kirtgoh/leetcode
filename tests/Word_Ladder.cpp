#include <gtest/gtest.h>
#include <Word_Ladder.h>

class WordLadderTest : public :: testing :: Test
{
public:
	Solution slu;
	WordLadderTest() {}
};

TEST_F(WordLadderTest, ladderLength)
{
	unordered_set<string> dict = {"hot", "dot", "lot", "dog", "log"};
	ASSERT_EQ(slu.ladderLength("hit", "cog", dict), 5);
}
