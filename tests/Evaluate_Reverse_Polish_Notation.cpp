#include <gtest/gtest.h>
#include <Evaluate_Reverse_Polish_Notation.h>

class ReversePolishNotation : public :: testing :: Test
{
public:
  Solution slu;
  ReversePolishNotation ()
  {
  }
};

TEST_F(ReversePolishNotation, evalRPN)
{
  vector<string> v_str1 = {"2", "1", "+", "3", "*"};
  vector<string> v_str2 = {"4", "13", "5", "/", "+"};

  ASSERT_EQ(slu.evalRPN(v_str1), 9);
  ASSERT_EQ(slu.evalRPN(v_str2), 6);
}

