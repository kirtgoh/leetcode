#include <gtest/gtest.h>
#include <PrintMacros.h>
#include <fstream>

#include <Word_Break.h>

class WordBreakTest : public :: testing :: Test
{
public:
  Solution slu;
  
  WordBreakTest ()
  {
  }

  void TearDown()
  {
  }
};

TEST_F(WordBreakTest, wordBreak)
{
  string s = "leetcode";

  unordered_set<string> dict = {"leet", "code"};

  ASSERT_EQ(slu.wordBreak(s, dict), true);
}
