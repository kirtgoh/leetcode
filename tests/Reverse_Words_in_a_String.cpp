#include <gtest/gtest.h>
#include <Reverse_Words_in_a_String.h>
#include <string>

class ReverseWordsTest : public :: testing::Test
{
public:
  Solution slu;

  ReverseWordsTest() {}

  void TearDown()
  {
  }

  
};

// TEST_F(ReverseWordsinaStringTest, reverseWords)
TEST_F(ReverseWordsTest, reverseWords)
{
  string s = "the sky is blue";
  slu.reverseWords(s);

  EXPECT_STREQ(s.c_str(), "blue is sky the");
}
